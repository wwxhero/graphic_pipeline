#include "libLogger.h"
#include "stdio.h"
#include <assert.h>
#include <iostream>
#define ROUND_UP_SIZE(Value,Pow2) ((SIZE_T) ((((ULONG)(Value)) + (Pow2) - 1) & (~(((LONG)(Pow2)) - 1))))
#if defined _WIN64
#define LOG2PHY(p_log) (c_base + (p_log % (unsigned int64_t)c_cap))
#elif defined _WIN32
#define LOG2PHY(p_log) (c_base + (p_log % c_cap))
#endif
class QueueMem
{
public:
	enum State {overflow = 0, fine};
	QueueMem() : c_base(NULL)
			   , c_cap(0)

	{
		m_range[0] = 0;
		m_range[1] = 0;
	}
	void Init(void *mem, unsigned int size)
	{
		c_base = (char*)mem;
		c_cap = size;
		m_range[0] = 0;
		m_range[1] = 0;
	}

	unsigned int size()
	{
		return m_range[head] - m_range[rear];
	}

	State push_front(char* data, unsigned int len)
	{
		if (len + size() > c_cap)
			return overflow;
		else
		{
			volatile LogPtr& p_dst = m_range[head];
			char* p_src = data;
			char* src_end = data + len;
			for (; p_src < src_end; p_src ++, p_dst ++)
			{
				*(LOG2PHY(p_dst)) = *p_src;
			}
			return fine;
		}
	}

	unsigned int pop_back(char* dst, unsigned int len)
	{
		unsigned int ret = m_range[head] - m_range[rear];
		if (len < ret)
			ret = len;
		volatile LogPtr& p_src = m_range[rear];
		char* dst_end = dst + ret;
		for (char* p_dst = dst; p_dst < dst_end; p_dst ++, p_src ++)
		{
			*p_dst = *(LOG2PHY(p_src));
		}
		return ret;
	}



public:
	char *c_base;
	unsigned int c_cap;
	enum {rear = 0, head};
#ifdef _WIN64
	typedef unsigned int64_t LogPtr;
#else
	typedef unsigned int LogPtr;
#endif
	volatile LogPtr m_range[2];
};

class CLogger
{
public:
	CLogger(const char* szPath) : c_nBuckets(2)
	{
		GetDiskFreeSpaceA(NULL, NULL, &c_secsize, NULL, NULL);
		SYSTEM_INFO sysInfo;
		GetSystemInfo(&sysInfo);
		DWORD buketsize;
		DWORD pagebytes = sysInfo.dwPageSize;
		if (pagebytes > c_secsize)
			buketsize = ROUND_UP_SIZE(c_secsize, pagebytes);
		else
			buketsize = ROUND_UP_SIZE(pagebytes, c_secsize);
		DWORD cap = c_nBuckets * buketsize;
		char *p = (char*)VirtualAlloc(NULL, cap, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		m_queue.Init(p, cap);
#ifdef OPTIMISED_DISK_IO
		m_threashold = c_secsize;
#else
		m_threashold = 128;
#endif
		m_pThresholder = (char *)malloc(c_secsize);
		m_hFile = ::CreateFileA(szPath
								, GENERIC_READ | GENERIC_WRITE
								, 0
								, NULL
								, CREATE_ALWAYS
								, FILE_ATTRIBUTE_NORMAL|FILE_FLAG_OVERLAPPED
								, NULL);
		m_aycOver.hEvent = CreateEvent(
			NULL,    // default security attribute
			TRUE,    // manual-reset event
			TRUE,    // initial state = signaled
			NULL);   // unnamed event object
	}
	~CLogger()
	{
		while (m_queue.size() > 0)
			DumpLogInSeq();
		::WaitForSingleObjectEx(m_aycOver.hEvent, INFINITE, TRUE); //wait till the asyc io is done

		VirtualFree(m_queue.c_base, m_queue.c_cap, MEM_RELEASE);
		CloseHandle(m_aycOver.hEvent);
		CloseHandle(m_hFile);
		free(m_pThresholder);
	}
	void LogOut(const LogItem* item)
	{
		char logItem[2048] = {0};
		int delta = sprintf_s(logItem
						, "%s\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%d\tfalse\n"
						, item->func
						, item->tmStartCPU
						, item->tmEndCPU
						, item->tmDurCPU
						, item->tmDurGPU
						, item->idThread
						, item->idProcess
						, item->filePath
						, item->nLine);
#ifdef TEST_CONSISTENCY_INPUT
		printf(logItem);
#endif
		bool overflow = (QueueMem::overflow == m_queue.push_front(logItem, delta));

		if ((m_queue.size() > m_threashold
			&& WAIT_OBJECT_0 == ::WaitForSingleObjectEx(m_aycOver.hEvent, 0, TRUE)) //wait till the asyc io is done
			|| overflow)
			DumpLogInSeq();

		while (overflow)
		{
			::SleepEx(30, TRUE); //yield cpu in order for the asyc routinue proceees data dump
			const char o_flag[] = "true \n";
			unsigned int len = sizeof(o_flag) - 1;
			char *p_flag = logItem + delta - len;
			for (int i = 0; i < len; i++)
				p_flag[i] = o_flag[i];
#ifdef TEST_CONSISTENCY_INPUT
			printf(logItem);
#endif
			overflow = (QueueMem::overflow == m_queue.push_front(logItem, delta));
		}
	}

	void DumpLogInSeq()
	{
		char *p = m_pThresholder;
		unsigned int size = 0;
		if ((size = m_queue.pop_back(p, c_secsize)) > 0)
		{
			m_aycOver.Offset = m_aycOver.OffsetHigh = 0xFFFFFFFF;
			ResetEvent(m_aycOver.hEvent);
			WriteFileEx(m_hFile, p, size, &m_aycOver, CompletedWriteRoutine);
		}
#ifdef TEST_CONSISTENCY_OUTPUT
		std::string str(p, size);
		std::cout  << str.c_str();
#endif
	}

	static VOID WINAPI CompletedWriteRoutine(DWORD, DWORD, LPOVERLAPPED);

private:
	const int c_nBuckets;
	DWORD c_secsize;
	QueueMem m_queue;
	DWORD m_threashold;
	char* m_pThresholder;
	HANDLE m_hFile;
	OVERLAPPED m_aycOver;

};

CLogger g_logger("glLog.log");

VOID WINAPI CLogger::CompletedWriteRoutine(DWORD dwErr, DWORD cbWritten, LPOVERLAPPED lpOverLap)
{
	if (g_logger.m_queue.size() > g_logger.m_threashold)
		g_logger.DumpLogInSeq();
	else
		SetEvent(lpOverLap->hEvent);
}



LOGGER_API void LOGGER_ENTRY LogOut(const LogItem* item)
{
	//this is mock implementation on windows, will be replaced with non-blocking output
	g_logger.LogOut(item);
}
#include "libGLTracer.h"
#include "traceGlFuncs.cpp"
#ifdef WIN32
#include "stdio.h"
#define DELIMITOR '\\'
#else
#define DELIMITOR '/'
#include "malloc.h"
#include <string.h>
#define strcpy_s strcpy
GLPerf thread_gl_perf;
#endif
extern "C" double getCPUTime();
inline const char* LocateFileName(const char* filePath)
{
	int i_offset_delimitor = -1;
	const char* p = filePath;
	while (*p != '\0')
	{
		if (*p == DELIMITOR)
			i_offset_delimitor = (p-filePath);
		p ++;
	}
	return filePath + i_offset_delimitor + 1;
}
LogItem* FuncLogStart(const char* funcName, const char* filePath, unsigned int nLine)
{
	LogItem* item = (LogItem *)malloc(sizeof(LogItem));
	strcpy_s(item->func, funcName);
#ifdef SYNC_LOGGING
	strcpy_s(item->filePath, filePath);
#else
	const char* s_fileName = LocateFileName(filePath);
	char* d_fileName = item->filePath;
	for (; d_fileName < item->filePath + GL_PATH_LEN && *s_fileName != '\0'; d_fileName ++, s_fileName ++)
		*d_fileName = *s_fileName;
	*d_fileName = '\0';
#endif
	item->nLine = nLine;

#ifdef WIN32
	item->tmStartCPU = ::GetTickCount();
	item->tmEndCPU = ::GetTickCount();
	item->tmDurGPU = 0;
	item->idThread = GetCurrentThreadId();
	item->idProcess = GetCurrentProcessId();
	item->tmDurCPU = ::GetTickCount(); //fixme: may require more accurate function fot time record
#else
    //fixme: linux implementation for collecting CPU time is not yet implemented
#endif

	return item;
}
void FuncLogEnd(LogItem* item)
{
#ifdef WIN32
	item->tmDurCPU = ::GetTickCount() - item->tmDurCPU;
#endif

#ifdef SYNC_LOGGING
	printf("%20s\t%10d\t%40s\t%d\n", item->func, item->tmDurCPU, item->filePath, item->nLine);
#else
	LogOut(item);
#endif
	free(item);
}

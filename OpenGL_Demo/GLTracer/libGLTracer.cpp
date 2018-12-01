#include "libGLTracer.h"
#include "traceGlFuncs.cpp"
extern "C" double getCPUTime();
LogItem* FuncLogStart(const char* funcName, const char* fileName, unsigned int nLine)
{
	LogItem* item = (LogItem *)malloc(sizeof(LogItem));
	strcpy_s(item->func, funcName);
#ifdef SYNC_LOGGING
	strcpy_s(item->filePath, fileName);
#else
	item->filePath[0] = '\0'; //don't waste space for fileName
#endif
	item->nLine = nLine;
	item->tmStartCPU = ::GetTickCount();
	item->tmEndCPU = ::GetTickCount();
	item->tmDurGPU = 0;
	item->idThread = GetCurrentThreadId();
	item->idProcess = GetCurrentProcessId();
#ifdef BENCH_MARK_TIMER
	item->tmDurCPU = getCPUTime() * 1000;
#else
	item->tmDurCPU = ::GetTickCount(); //fixme: may require more accurate function fot time record
#endif
	return item;
}
void FuncLogEnd(LogItem* item)
{
#ifdef BENCH_MARK_TIMER
	item->tmDurCPU = getCPUTime() * 1000 - item->tmDurCPU;
#else
	item->tmDurCPU = ::GetTickCount() - item->tmDurCPU;
#endif
#ifdef SYNC_LOGGING
	printf("%20s\t%10d\t%40s\t%d\n", item->func, item->tmDurCPU, item->filePath, item->nLine);
#else
	LogOut(item);
#endif
	free(item);
}

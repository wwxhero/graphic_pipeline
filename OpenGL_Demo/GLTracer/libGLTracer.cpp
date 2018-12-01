#include "libGLTracer.h"
#include "traceGlFuncs.cpp"
#ifdef WIN32
#include "stdio.h"
#else
#include "malloc.h"
#include <string.h>
#define strcpy_s strcpy
GLPerf thread_gl_perf;
#endif
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

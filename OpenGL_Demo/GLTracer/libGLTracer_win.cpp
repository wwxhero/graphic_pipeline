#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libGLTracer.h"
LogItem* FuncLogVoidStart(const char* funcName, const char* fileName, unsigned int nLine)
{
	LogItem* item = (LogItem *)malloc(sizeof(LogItem));
	strcpy_s(item->func, funcName);
	item->tmDurCPU = ::GetTickCount(); //fixme: may require more accurate function fot time record
	strcpy_s(item->filePath, fileName);
	item->nLine = nLine;
	return item;
}
void FuncLogVoidEnd(LogItem* item)
{
	item->tmDurCPU = ::GetTickCount() - item->tmDurCPU;
	printf("%20s\t%10d\t%40s\t%d\n", item->func, item->tmDurCPU, item->filePath, item->nLine);
	free(item);
}

LogItem* FuncLogSwapStart(const char* funcName, const char* fileName, unsigned int nLine)
{
	LogItem* item = FuncLogVoidStart(funcName, fileName, nLine);
	//fixme: collect GPU executing time since previous swap
	return item;
}

void FuncLogSwapEnd(LogItem* item)
{
	//fixme: leave GPU time stamp for next swap
	FuncLogVoidEnd(item);
}
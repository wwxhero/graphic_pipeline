#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "libGLTracer.h"
LogVoidItem* FuncLogVoidStart(const char* funcName, const char* fileName, unsigned int nLine)
{
	LogVoidItem* item = (LogVoidItem *)malloc(sizeof(LogVoidItem));
	strcpy_s(item->func, funcName);
	item->tmDur = ::GetTickCount(); //fixme: may require more accurate function fot time record
	strcpy_s(item->filePath, fileName);
	item->nLine = nLine;
	return item;
}
void FuncLogVoidEnd(LogVoidItem* item)
{
	item->tmDur = ::GetTickCount() - item->tmDur;
	printf("%20s\t%10d\t%40s\t%d\n", item->func, item->tmDur, item->filePath, item->nLine);
	free(item);
}
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include "libGLTracer.h"
LogVoidItem* FuncLogVoidStart(const char* funcName, const char* fileName, unsigned int nLine)
{
	LogVoidItem* item = (LogVoidItem *)malloc(sizeof(LogVoidItem));
	strncpy(item->func, funcName, GL_FUNC_LEN);
	item->tmDur = 0; //::GetTickCount(); //fixme: may require more accurate function fot time record
	strncpy(item->filePath, fileName, GL_PATH_LEN);
	item->nLine = nLine;
	return item;
}
void FuncLogVoidEnd(LogVoidItem* item)
{
	item->tmDur = 0; //::GetTickCount() - item->tmDur;
	printf("%20s\t%10d\t%40s\t%d\n", item->func, item->tmDur, item->filePath, item->nLine);
	free(item);
}

#include "libLogger.h"
#include "stdio.h"

LOGGER_API void LOGGER_ENTRY LogOut(const LogItem* item)
{
	//this is mock implementation on windows, will be replaced with non-blocking output
	printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%s\t%d\n"
		, item->func
		, item->tmStartCPU
		, item->tmEndCPU
		, item->tmDurCPU
		, item->tmDurGPU
		, item->idThread
		, item->idProcess
		, item->filePath
		, item->nLine);
}
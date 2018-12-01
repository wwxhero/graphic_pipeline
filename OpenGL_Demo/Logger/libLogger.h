#pragma once
#ifdef WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif
#ifndef _LIBLOGGER_
#define _LIBLOGGER_
#define GL_FUNC_LEN			64
#define GL_PATH_LEN			1024
typedef struct LogItem_t
{
	char func[GL_FUNC_LEN];
	unsigned int tmStartCPU;		//time stamp for the starting time of the funcation being called
	unsigned int tmEndCPU;			//time stamp for the ending time of the function
	unsigned int tmDurCPU; 			//on windows: in milliseconds, on linux: in microseconds
	unsigned int tmDurGPU;			//this field is available only from buffer swap functions
#ifdef WIN32
	DWORD idThread;
	DWORD idProcess;
#else		//linux
	pid_t idThread;
	pid_t idProcess;
#endif
	char filePath[GL_PATH_LEN];
	unsigned int nLine;
} LogItem;

#ifdef WIN32
	#ifdef LOGGER_EXPORTS
		#define LOGGER_API __declspec(dllexport)
	#else
		#define LOGGER_API __declspec(dllimport)
	#endif
	#define LOGGER_ENTRY __stdcall
#else
	#define LOGGER_API
	#define LOGGER_ENTRY
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	LOGGER_API void LOGGER_ENTRY LogOut(const LogItem* item);

#ifdef __cplusplus
}
#endif

#endif

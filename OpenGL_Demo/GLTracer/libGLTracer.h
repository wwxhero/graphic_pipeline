#ifndef _LIBGLTRACER_H
#define _LIBGLTRACER_H
#ifdef WIN32
#include <windows.h>
#endif
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
	#ifdef GLTRACER_EXPORTS
		#define _GLTRACER_API __declspec(dllexport)
	#else
		#define _GLTRACER_API __declspec(dllimport)
	#endif
#else
	#define _GLTRACER_API
#endif

#ifdef __cplusplus
extern "C"
{
#endif
	_GLTRACER_API LogItem* FuncLogVoidStart(const char* funName, const char* fileName, unsigned int nLine);
	_GLTRACER_API void FuncLogVoidEnd(LogItem* item);
	_GLTRACER_API LogItem* FuncLogSwapStart(const char* funName, const char* fileName, unsigned int nLine);
	_GLTRACER_API void FuncLogSwapEnd(LogItem* item);
#ifdef __cplusplus
}
#endif

#ifndef GLTRACE_VOID_0
#define GLTRACE_VOID_0(func)\
	{\
		LogItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func();\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_1
#define GLTRACE_VOID_1(func, p1)\
	{\
		LogItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_2
#define GLTRACE_VOID_2(func, p1, p2)\
	{\
		LogItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_3
#define GLTRACE_VOID_3(func, p1, p2, p3)\
	{\
		LogItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_4
#define GLTRACE_VOID_4(func, p1, p2, p3, p4)\
	{\
		LogItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_5
#define GLTRACE_VOID_5(func, p1, p2, p3, p4, p5)\
	{\
		LogItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4, p5);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_6
#define GLTRACE_VOID_6(func, p1, p2, p3, p4, p5, p6)\
	{\
		LogItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4, p5, p6);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_SWAP_0
#define GLTRACE_SWAP_0(func)\
	{\
		LogItem* item = FuncLogSwapStart(#func, __FILE__, __LINE__);\
		func();\
		FuncLogSwapEnd(item);\
	}
#endif

#ifndef GLTRACE_SWAP_1
#define GLTRACE_SWAP_1(func, p1)\
	{\
		LogItem* item = FuncLogSwapStart(#func, __FILE__, __LINE__);\
		func(p1);\
		FuncLogSwapEnd(item);\
	}
#endif

#ifndef GLTRACE_SWAP_2
#define GLTRACE_SWAP_2(func, p1, p2)\
	{\
		LogItem* item = FuncLogSwapStart(#func, __FILE__, __LINE__);\
		func(p1, p2);\
		FuncLogSwapEnd(item);\
	}
#endif

#endif
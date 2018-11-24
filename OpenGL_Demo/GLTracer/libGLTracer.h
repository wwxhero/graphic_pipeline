#ifndef _LIBGLTRACER_H
#define _LIBGLTRACER_H
#include "OpenGL.hpp"
#include "libLogger.h"

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
	_GLTRACER_API LogItem* FuncLogStart(const char* funName, const char* fileName, unsigned int nLine);
	_GLTRACER_API void FuncLogEnd(LogItem* item);
	_GLTRACER_API LogItem* FuncLogSwapStart(const char* funName, const char* fileName, unsigned int nLine);
	_GLTRACER_API void FuncLogSwapEnd(LogItem* item);

	#include "traceGlFuncs.h"
#ifdef __cplusplus
}
#endif

#ifndef GLTRACE_VOID_0
#define GLTRACE_VOID_0(func)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func();\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_1
#define GLTRACE_VOID_1(func, p1)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func(p1);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_2
#define GLTRACE_VOID_2(func, p1, p2)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func(p1, p2);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_3
#define GLTRACE_VOID_3(func, p1, p2, p3)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_4
#define GLTRACE_VOID_4(func, p1, p2, p3, p4)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_5
#define GLTRACE_VOID_5(func, p1, p2, p3, p4, p5)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4, p5);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_6
#define GLTRACE_VOID_6(func, p1, p2, p3, p4, p5, p6)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4, p5, p6);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_SYNC_0
#define GLTRACE_SYNC_0(func)\
	{\
		LogItem* item = FuncLogSwapStart(#func, __FILE__, __LINE__);\
		func();\
		FuncLogSwapEnd(item);\
	}
#endif

#ifndef GLTRACE_SYNC_1
#define GLTRACE_SYNC_1(func, p1)\
	{\
		LogItem* item = FuncLogSwapStart(#func, __FILE__, __LINE__);\
		func(p1);\
		FuncLogSwapEnd(item);\
	}
#endif

#ifndef GLTRACE_SYNC_2
#define GLTRACE_SYNC_2(func, p1, p2)\
	{\
		LogItem* item = FuncLogSwapStart(#func, __FILE__, __LINE__);\
		func(p1, p2);\
		FuncLogSwapEnd(item);\
	}
#endif

#ifndef GLTRACE_RET_0
#define GLTRACE_RET_0(func)\
	GLTrace_##func(func)
#endif

#ifndef GLTRACE_RET_1
#define GLTRACE_RET_1(func, p1)\
	GLTrace_##func(func, p1, __FILE__, __LINE__)
#endif

#endif
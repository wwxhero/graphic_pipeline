#ifndef _LIBGLTRACER_H
#define _LIBGLTRACER_H

#define GL_FUNC_LEN			64
#define GL_PATH_LEN			1024
typedef struct LogVoidItem_t
{
	char func[GL_FUNC_LEN];
	unsigned int tmDur; 			//on windows: in milliseconds, on linux: in microseconds
	char filePath[GL_PATH_LEN];
	unsigned int nLine;
} LogVoidItem;

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
	_GLTRACER_API LogVoidItem* FuncLogVoidStart(const char* funName, const char* fileName, unsigned int nLine);
	_GLTRACER_API void FuncLogVoidEnd(LogVoidItem* item);
#ifdef __cplusplus
}
#endif

#ifndef GLTRACE_VOID_0
#define GLTRACE_VOID_0(func)\
	{\
		LogVoidItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func();\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_1
#define GLTRACE_VOID_1(func, p1)\
	{\
		LogVoidItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_2
#define GLTRACE_VOID_2(func, p1, p2)\
	{\
		LogVoidItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_3
#define GLTRACE_VOID_3(func, p1, p2, p3)\
	{\
		LogVoidItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_4
#define GLTRACE_VOID_4(func, p1, p2, p3, p4)\
	{\
		LogVoidItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_5
#define GLTRACE_VOID_5(func, p1, p2, p3, p4, p5)\
	{\
		LogVoidItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4, p5);\
		FuncLogVoidEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_6
#define GLTRACE_VOID_6(func, p1, p2, p3, p4, p5, p6)\
	{\
		LogVoidItem* item = FuncLogVoidStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4, p5, p6);\
		FuncLogVoidEnd(item);\
	}
#endif

#endif
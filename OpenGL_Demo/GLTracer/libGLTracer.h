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
	_GLTRACER_API LogItem* FuncLogSyncStart(const char* funName, const char* fileName, unsigned int nLine);
	_GLTRACER_API void FuncLogSyncEnd(LogItem* item);

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

#ifndef GLTRACE_VOID_7
#define GLTRACE_VOID_7(func, p1, p2, p3, p4, p5, p6, p7)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4, p5, p6, p7);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_8
#define GLTRACE_VOID_8(func, p1, p2, p3, p4, p5, p6, p7, p8)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4, p5, p6, p7, p8);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_VOID_9
#define GLTRACE_VOID_9(func, p1, p2, p3, p4, p5, p6, p7, p8, p9)\
	{\
		LogItem* item = FuncLogStart(#func, __FILE__, __LINE__);\
		func(p1, p2, p3, p4, p5, p6, p7, p8, p9);\
		FuncLogEnd(item);\
	}
#endif

class GLPerf
{
public:
	GLPerf() : tls_gpu_couter_id(GL_INVALID_INDEX)
		, glDeleteQueries(NULL)
	{
	}
	~GLPerf()
	{
		if (GL_INVALID_INDEX != tls_gpu_couter_id)
			glDeleteQueries(1, &tls_gpu_couter_id);
	}
public:
	GLuint tls_gpu_couter_id;
	PFNGLDELETEQUERIESPROC glDeleteQueries;
};
#ifdef WIN32
__declspec(thread) GLPerf thread_gl_perf;
#endif // WIN32

#ifndef GLTRACE_SYNC_0
#define GLTRACE_SYNC_0(func)\
	{\
		LogItem* item = FuncLogStart("Sync", __FILE__, __LINE__);\
		if (GL_INVALID_INDEX == thread_gl_perf.tls_gpu_couter_id)\
		{\
			glGenQueries(1, &thread_gl_perf.tls_gpu_couter_id);\
			thread_gl_perf.glDeleteQueries = glDeleteQueries;\
		}\
		else\
		{\
			glEndQuery(GL_TIME_ELAPSED);\
			glGetQueryObjectiv(thread_gl_perf.tls_gpu_couter_id, GL_QUERY_RESULT, (GLint*)&item->tmDurGPU);\
		}\
		func();\
		glBeginQuery(GL_TIME_ELAPSED, thread_gl_perf.tls_gpu_couter_id);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_SYNC_1
#define GLTRACE_SYNC_1(func, p1)\
	{\
		LogItem* item = FuncLogStart("Sync", __FILE__, __LINE__);\
		if (GL_INVALID_INDEX == thread_gl_perf.tls_gpu_couter_id)\
		{\
			glGenQueries(1, &thread_gl_perf.tls_gpu_couter_id);\
			thread_gl_perf.glDeleteQueries = glDeleteQueries;\
		}\
		else\
		{\
			glEndQuery(GL_TIME_ELAPSED);\
			glGetQueryObjectiv(thread_gl_perf.tls_gpu_couter_id, GL_QUERY_RESULT, (GLint*)&item->tmDurGPU);\
		}\
		func(p1);\
		glBeginQuery(GL_TIME_ELAPSED, thread_gl_perf.tls_gpu_couter_id);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_SYNC_2
#define GLTRACE_SYNC_2(func, p1, p2)\
	{\
		LogItem* item = FuncLogStart("Sync", __FILE__, __LINE__);\
		if (GL_INVALID_INDEX == thread_gl_perf.tls_gpu_couter_id)\
		{\
			glGenQueries(1, &thread_gl_perf.tls_gpu_couter_id);\
			thread_gl_perf.glDeleteQueries = glDeleteQueries;\
		}\
		else\
		{\
			glEndQuery(GL_TIME_ELAPSED);\
			glGetQueryObjectiv(thread_gl_perf.tls_gpu_couter_id, GL_QUERY_RESULT, (GLint*)&item->tmDurGPU);\
		}\
		func(p1, p2);\
		glBeginQuery(GL_TIME_ELAPSED, thread_gl_perf.tls_gpu_couter_id);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_SYNC_3
#define GLTRACE_SYNC_3(func, p1, p2, p3)\
	{\
		LogItem* item = FuncLogStart("Sync", __FILE__, __LINE__);\
		if (GL_INVALID_INDEX == thread_gl_perf.tls_gpu_couter_id)\
		{\
			glGenQueries(1, &thread_gl_perf.tls_gpu_couter_id);\
			thread_gl_perf.glDeleteQueries = glDeleteQueries;\
		}\
		else\
		{\
			glEndQuery(GL_TIME_ELAPSED);\
			glGetQueryObjectiv(thread_gl_perf.tls_gpu_couter_id, GL_QUERY_RESULT, (GLint*)&item->tmDurGPU);\
		}\
		func(p1, p2, p3);\
		glBeginQuery(GL_TIME_ELAPSED, thread_gl_perf.tls_gpu_couter_id);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_SYNC_4
#define GLTRACE_SYNC_4(func, p1, p2, p3, p4)\
	{\
		LogItem* item = FuncLogStart("Sync", __FILE__, __LINE__);\
		if (GL_INVALID_INDEX == thread_gl_perf.tls_gpu_couter_id)\
		{\
			glGenQueries(1, &thread_gl_perf.tls_gpu_couter_id);\
			thread_gl_perf.glDeleteQueries = glDeleteQueries;\
		}\
		else\
		{\
			glEndQuery(GL_TIME_ELAPSED);\
			glGetQueryObjectiv(thread_gl_perf.tls_gpu_couter_id, GL_QUERY_RESULT, (GLint*)&item->tmDurGPU);\
		}\
		func(p1, p2, p3, p4);\
		glBeginQuery(GL_TIME_ELAPSED, thread_gl_perf.tls_gpu_couter_id);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_SYNC_5
#define GLTRACE_SYNC_5(func, p1, p2, p3, p4, p5)\
	{\
		LogItem* item = FuncLogStart("Sync", __FILE__, __LINE__);\
		if (GL_INVALID_INDEX == thread_gl_perf.tls_gpu_couter_id)\
		{\
			glGenQueries(1, &thread_gl_perf.tls_gpu_couter_id);\
			thread_gl_perf.glDeleteQueries = glDeleteQueries;\
		}\
		else\
		{\
			glEndQuery(GL_TIME_ELAPSED);\
			glGetQueryObjectiv(thread_gl_perf.tls_gpu_couter_id, GL_QUERY_RESULT, (GLint*)&item->tmDurGPU);\
		}\
		func(p1, p2, p3, p4, p5);\
		glBeginQuery(GL_TIME_ELAPSED, thread_gl_perf.tls_gpu_couter_id);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_SYNC_6
#define GLTRACE_SYNC_6(func, p1, p2, p3, p4, p5, p6)\
	{\
		LogItem* item = FuncLogStart("Sync", __FILE__, __LINE__);\
		if (GL_INVALID_INDEX == thread_gl_perf.tls_gpu_couter_id)\
		{\
			glGenQueries(1, &thread_gl_perf.tls_gpu_couter_id);\
			thread_gl_perf.glDeleteQueries = glDeleteQueries;\
		}\
		else\
		{\
			glEndQuery(GL_TIME_ELAPSED);\
			glGetQueryObjectiv(thread_gl_perf.tls_gpu_couter_id, GL_QUERY_RESULT, (GLint*)&item->tmDurGPU);\
		}\
		func(p1, p2, p3, p4, p5, p6);\
		glBeginQuery(GL_TIME_ELAPSED, thread_gl_perf.tls_gpu_couter_id);\
		FuncLogEnd(item);\
	}
#endif

#ifndef GLTRACE_RET_0
#define GLTRACE_RET_0(func)\
	GLTrace_##func(func, __FILE__, __LINE__)
#endif

#ifndef GLTRACE_RET_1
#define GLTRACE_RET_1(func, p1)\
	GLTrace_##func(func, p1, __FILE__, __LINE__)
#endif

#ifndef GLTRACE_RET_2
#define GLTRACE_RET_2(func, p1, p2)\
	GLTrace_##func(func, p1, p2, __FILE__, __LINE__)
#endif

#ifndef GLTRACE_RET_3
#define GLTRACE_RET_3(func, p1, p2, p3)\
	GLTrace_##func(func, p1, p2, p3, __FILE__, __LINE__)
#endif

#ifndef GLTRACE_RET_4
#define GLTRACE_RET_4(func, p1, p2, p3, p4)\
	GLTrace_##func(func, p1, p2, p3, p4, __FILE__, __LINE__)
#endif

#ifndef GLTRACE_RET_5
#define GLTRACE_RET_5(func, p1, p2, p3, p4, p5)\
	GLTrace_##func(func, p1, p2, p3, p4, p5, __FILE__, __LINE__)
#endif

#ifndef GLTRACE_RET_6
#define GLTRACE_RET_6(func, p1, p2, p3, p4, p5, p6)\
	GLTrace_##func(func, p1, p2, p3, p4, p5, p6, __FILE__, __LINE__)
#endif
#endif

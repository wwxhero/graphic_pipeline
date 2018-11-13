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

	//GLAPI GLboolean APIENTRY glIsProgram (GLuint program);
	typedef GLboolean (APIENTRY* GLISPROGRAM) (GLuint program);
	_GLTRACER_API GLboolean GLTrace_glIsProgram (GLISPROGRAM proc, GLuint program, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLenum GLTrace_glGetError(const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsEnabled(GLenum cap, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsTexture (GLuint texture, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsQuery (GLuint id, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsBuffer (GLuint buffer, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLvoid* GLTrace_glMapBuffer (GLenum target, GLenum access, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glUnmapBuffer (GLenum target, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLuint GLTrace_glCreateProgram (const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLuint GLTrace_glCreateShader (GLenum type, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsShader (GLuint shader, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsEnabledi (GLenum target, GLuint index, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsRenderbuffer (GLuint renderbuffer, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsFramebuffer (GLuint framebuffer, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLenum GLTrace_glCheckFramebufferStatus (GLenum target, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLvoid* GLTrace_glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsVertexArray (GLuint array, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLuint GLTrace_glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLsync GLTrace_glFenceSync (GLenum condition, GLbitfield flags, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsSync (GLsync sync, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLenum GLTrace_glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsNamedStringARB (GLint namelen, const GLchar *name, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsSampler (GLuint sampler, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLuint GLTrace_glGetSubroutineIndex (GLuint program, GLenum shadertype, const GLchar *name, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsTransformFeedback (GLuint id, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLuint GLTrace_glCreateShaderProgramv (GLenum type, GLsizei count, const GLchar* *strings, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLboolean GLTrace_glIsProgramPipeline (GLuint pipeline, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLsync GLTrace_glCreateSyncFromCLeventARB (struct _cl_context * context, struct _cl_event * event, GLbitfield flags, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLuint GLTrace_glGetDebugMessageLogARB (GLuint count, GLsizei bufsize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog, const char* fileName, unsigned int lineNum);
	_GLTRACER_API GLenum GLTrace_glGetGraphicsResetStatusARB (const char* fileName, unsigned int lineNum);
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

#ifndef GLTRACE_RET_0
#define GLTRACE_RET_0(func)\
	GLTrace_##func(func)
#endif

#ifndef GLTRACE_RET_1
#define GLTRACE_RET_1(func, p1)\
	GLTrace_##func(func, p1, __FILE__, __LINE__)
#endif

#endif
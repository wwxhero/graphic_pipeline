#include "libGLTracer.h"

GLboolean GLTrace_glIsProgram(PFNGLISPROGRAMPROC proc, GLuint program, const char* fileName, unsigned int LineNum)
{
	LogItem* item = FuncLogStart("glIsProgram", fileName, LineNum);
	GLboolean ret = proc(program);
	FuncLogEnd(item);
	return ret;
}

GLenum GLTrace_glGetError(const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetError", fileName, lineNum);
	GLenum ret = glGetError();
	FuncLogEnd(item);
	return ret;
}

GLboolean GLTrace_glIsEnabled(GLenum cap, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsEnabled", fileName, lineNum);
	GLboolean ret = glIsEnabled(cap);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsTexture (GLuint texture, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsTexture", fileName, lineNum);
	GLboolean ret = glIsTexture(texture);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsQuery (GLuint id, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsQuery", fileName, lineNum);
	GLboolean ret = glIsQuery(id);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsBuffer (GLuint buffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsBuffer", fileName, lineNum);
	GLboolean ret = glIsBuffer(buffer);
	FuncLogEnd(item);
	return ret;
}
GLvoid* GLTrace_glMapBuffer (GLenum target, GLenum access, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMapBuffer", fileName, lineNum);
	GLvoid* ret = glMapBuffer(target, access);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glUnmapBuffer (GLenum target, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUnmapBuffer", fileName, lineNum);
	GLboolean ret = glUnmapBuffer(target);
	FuncLogEnd(item);
	return ret;
}
GLuint GLTrace_glCreateProgram (const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCreateProgram", fileName, lineNum);
	GLuint ret = glCreateProgram();
	FuncLogEnd(item);
	return ret;
}
GLuint GLTrace_glCreateShader (GLenum type, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCreateShader", fileName, lineNum);
	GLuint ret = glCreateShader(type);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsShader (GLuint shader, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsShader", fileName, lineNum);
	GLboolean ret = glIsShader(shader);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsEnabledi (GLenum target, GLuint index, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsEnabledi", fileName, lineNum);
	GLboolean ret = glIsEnabledi(target, index);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsRenderbuffer (GLuint renderbuffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsRenderbuffer", fileName, lineNum);
	GLboolean ret = glIsRenderbuffer(renderbuffer);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsFramebuffer (GLuint framebuffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsFramebuffer", fileName, lineNum);
	GLboolean ret = glIsFramebuffer(framebuffer);
	FuncLogEnd(item);
	return ret;
}
GLenum GLTrace_glCheckFramebufferStatus (GLenum target, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCheckFramebufferStatus", fileName, lineNum);
	GLenum ret = glCheckFramebufferStatus(target);
	FuncLogEnd(item);
	return ret;
}
GLvoid* GLTrace_glMapBufferRange (GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMapBufferRange", fileName, lineNum);
	GLvoid* ret = glMapBufferRange(target, offset, length, access);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsVertexArray (GLuint array, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsVertexArray", fileName, lineNum);
	GLboolean ret = glIsVertexArray(array);
	FuncLogEnd(item);
	return ret;
}
GLuint GLTrace_glGetUniformBlockIndex (GLuint program, const GLchar *uniformBlockName, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetUniformBlockIndex", fileName, lineNum);
	GLuint ret = glGetUniformBlockIndex(program, uniformBlockName);
	FuncLogEnd(item);
	return ret;
}
GLsync GLTrace_glFenceSync (GLenum condition, GLbitfield flags, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFenceSync", fileName, lineNum);
	GLsync ret = glFenceSync(condition, flags);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsSync (GLsync sync, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsSync", fileName, lineNum);
	GLboolean ret = glIsSync (sync);
	FuncLogEnd(item);
	return ret;
}
GLenum GLTrace_glClientWaitSync (GLsync sync, GLbitfield flags, GLuint64 timeout, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClientWaitSync", fileName, lineNum);
	GLenum ret = glClientWaitSync(sync, flags, timeout);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsNamedStringARB (GLint namelen, const GLchar *name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsNamedStringARB", fileName, lineNum);
	GLboolean ret = glIsNamedStringARB(namelen, name);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsSampler (GLuint sampler, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsSampler", fileName, lineNum);
	GLboolean ret = glIsSampler(sampler);
	FuncLogEnd(item);
	return ret;
}
GLuint GLTrace_glGetSubroutineIndex (GLuint program, GLenum shadertype, const GLchar *name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetSubroutineIndex", fileName, lineNum);
	GLuint ret = glGetSubroutineIndex(program, shadertype, name);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsTransformFeedback (GLuint id, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsTransformFeedback", fileName, lineNum);
	GLboolean ret = glIsTransformFeedback(id);
	FuncLogEnd(item);
	return ret;
}
GLuint GLTrace_glCreateShaderProgramv (GLenum type, GLsizei count, const GLchar* *strings, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCreateShaderProgramv", fileName, lineNum);
	GLuint ret = glCreateShaderProgramv(type, count, strings);
	FuncLogEnd(item);
	return ret;
}
GLboolean GLTrace_glIsProgramPipeline (GLuint pipeline, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsProgramPipeline", fileName, lineNum);
	GLboolean ret = glIsProgramPipeline(pipeline);
	FuncLogEnd(item);
	return ret;
}
GLsync GLTrace_glCreateSyncFromCLeventARB (struct _cl_context * context, struct _cl_event * event, GLbitfield flags, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCreateSyncFromCLeventARB", fileName, lineNum);
	GLsync ret = glCreateSyncFromCLeventARB(context, event, flags);
	FuncLogEnd(item);
	return ret;
}
GLuint GLTrace_glGetDebugMessageLogARB (GLuint count, GLsizei bufsize, GLenum *sources, GLenum *types, GLuint *ids, GLenum *severities, GLsizei *lengths, GLchar *messageLog, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetDebugMessageLogARB", fileName, lineNum);
	GLuint ret = glGetDebugMessageLogARB(count, bufsize, sources, types, ids, severities, lengths, messageLog);
	FuncLogEnd(item);
	return ret;
}
GLenum GLTrace_glGetGraphicsResetStatusARB (const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetGraphicsResetStatusARB", fileName, lineNum);
	GLenum ret = glGetGraphicsResetStatusARB();
	FuncLogEnd(item);
	return ret;
}
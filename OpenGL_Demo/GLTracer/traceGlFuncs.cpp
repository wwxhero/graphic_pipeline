void GLTrace_glCullFace(FPglCullFace proc, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCullFace", fileName, lineNum);
	proc(a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glFrontFace(FPglFrontFace proc, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFrontFace", fileName, lineNum);
	proc(a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glHint(FPglHint proc, GLenum a_target, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glHint", fileName, lineNum);
	proc(a_target, a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glLineWidth(FPglLineWidth proc, GLfloat a_width, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glLineWidth", fileName, lineNum);
	proc(a_width); 
	FuncLogEnd(item);
}

void GLTrace_glPointSize(FPglPointSize proc, GLfloat a_size, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPointSize", fileName, lineNum);
	proc(a_size); 
	FuncLogEnd(item);
}

void GLTrace_glPolygonMode(FPglPolygonMode proc, GLenum a_face, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPolygonMode", fileName, lineNum);
	proc(a_face, a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glScissor(FPglScissor proc, GLint a_x, GLint a_y, GLsizei a_width, GLsizei a_height, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glScissor", fileName, lineNum);
	proc(a_x, a_y, a_width, a_height); 
	FuncLogEnd(item);
}

void GLTrace_glTexParameterf(FPglTexParameterf proc, GLenum a_target, GLenum a_pname, GLfloat a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexParameterf", fileName, lineNum);
	proc(a_target, a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glTexParameterfv(FPglTexParameterfv proc, GLenum a_target, GLenum a_pname, const GLfloat * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexParameterfv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glTexParameteri(FPglTexParameteri proc, GLenum a_target, GLenum a_pname, GLint a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexParameteri", fileName, lineNum);
	proc(a_target, a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glTexParameteriv(FPglTexParameteriv proc, GLenum a_target, GLenum a_pname, const GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexParameteriv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glTexImage1D(FPglTexImage1D proc, GLenum a_target, GLint a_level, GLint a_internalformat, GLsizei a_width, GLint a_border, GLenum a_format, GLenum a_type, const GLvoid * a_pixels, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexImage1D", fileName, lineNum);
	proc(a_target, a_level, a_internalformat, a_width, a_border, a_format, a_type, a_pixels); 
	FuncLogEnd(item);
}

void GLTrace_glTexImage2D(FPglTexImage2D proc, GLenum a_target, GLint a_level, GLint a_internalformat, GLsizei a_width, GLsizei a_height, GLint a_border, GLenum a_format, GLenum a_type, const GLvoid * a_pixels, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexImage2D", fileName, lineNum);
	proc(a_target, a_level, a_internalformat, a_width, a_height, a_border, a_format, a_type, a_pixels); 
	FuncLogEnd(item);
}

void GLTrace_glDrawBuffer(FPglDrawBuffer proc, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawBuffer", fileName, lineNum);
	proc(a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glClear(FPglClear proc, GLbitfield a_mask, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClear", fileName, lineNum);
	proc(a_mask); 
	FuncLogEnd(item);
}

void GLTrace_glClearColor(FPglClearColor proc, GLclampf a_red, GLclampf a_green, GLclampf a_blue, GLclampf a_alpha, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClearColor", fileName, lineNum);
	proc(a_red, a_green, a_blue, a_alpha); 
	FuncLogEnd(item);
}

void GLTrace_glClearStencil(FPglClearStencil proc, GLint a_s, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClearStencil", fileName, lineNum);
	proc(a_s); 
	FuncLogEnd(item);
}

void GLTrace_glClearDepth(FPglClearDepth proc, GLclampd a_depth, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClearDepth", fileName, lineNum);
	proc(a_depth); 
	FuncLogEnd(item);
}

void GLTrace_glStencilMask(FPglStencilMask proc, GLuint a_mask, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glStencilMask", fileName, lineNum);
	proc(a_mask); 
	FuncLogEnd(item);
}

void GLTrace_glColorMask(FPglColorMask proc, GLboolean a_red, GLboolean a_green, GLboolean a_blue, GLboolean a_alpha, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glColorMask", fileName, lineNum);
	proc(a_red, a_green, a_blue, a_alpha); 
	FuncLogEnd(item);
}

void GLTrace_glDepthMask(FPglDepthMask proc, GLboolean a_flag, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDepthMask", fileName, lineNum);
	proc(a_flag); 
	FuncLogEnd(item);
}

void GLTrace_glDisable(FPglDisable proc, GLenum a_cap, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDisable", fileName, lineNum);
	proc(a_cap); 
	FuncLogEnd(item);
}

void GLTrace_glEnable(FPglEnable proc, GLenum a_cap, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glEnable", fileName, lineNum);
	proc(a_cap); 
	FuncLogEnd(item);
}

void GLTrace_glFinish(FPglFinish proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFinish", fileName, lineNum);
	proc(); 
	FuncLogEnd(item);
}

void GLTrace_glFlush(FPglFlush proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFlush", fileName, lineNum);
	proc(); 
	FuncLogEnd(item);
}

void GLTrace_glBlendFunc(FPglBlendFunc proc, GLenum a_sfactor, GLenum a_dfactor, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendFunc", fileName, lineNum);
	proc(a_sfactor, a_dfactor); 
	FuncLogEnd(item);
}

void GLTrace_glLogicOp(FPglLogicOp proc, GLenum a_opcode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glLogicOp", fileName, lineNum);
	proc(a_opcode); 
	FuncLogEnd(item);
}

void GLTrace_glStencilFunc(FPglStencilFunc proc, GLenum a_func, GLint a_ref, GLuint a_mask, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glStencilFunc", fileName, lineNum);
	proc(a_func, a_ref, a_mask); 
	FuncLogEnd(item);
}

void GLTrace_glStencilOp(FPglStencilOp proc, GLenum a_fail, GLenum a_zfail, GLenum a_zpass, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glStencilOp", fileName, lineNum);
	proc(a_fail, a_zfail, a_zpass); 
	FuncLogEnd(item);
}

void GLTrace_glDepthFunc(FPglDepthFunc proc, GLenum a_func, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDepthFunc", fileName, lineNum);
	proc(a_func); 
	FuncLogEnd(item);
}

void GLTrace_glPixelStoref(FPglPixelStoref proc, GLenum a_pname, GLfloat a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPixelStoref", fileName, lineNum);
	proc(a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glPixelStorei(FPglPixelStorei proc, GLenum a_pname, GLint a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPixelStorei", fileName, lineNum);
	proc(a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glReadBuffer(FPglReadBuffer proc, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glReadBuffer", fileName, lineNum);
	proc(a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glReadPixels(FPglReadPixels proc, GLint a_x, GLint a_y, GLsizei a_width, GLsizei a_height, GLenum a_format, GLenum a_type, GLvoid * a_pixels, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glReadPixels", fileName, lineNum);
	proc(a_x, a_y, a_width, a_height, a_format, a_type, a_pixels); 
	FuncLogEnd(item);
}

void GLTrace_glGetBooleanv(FPglGetBooleanv proc, GLenum a_pname, GLboolean * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetBooleanv", fileName, lineNum);
	proc(a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetDoublev(FPglGetDoublev proc, GLenum a_pname, GLdouble * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetDoublev", fileName, lineNum);
	proc(a_pname, a_params); 
	FuncLogEnd(item);
}

GLenum GLTrace_glGetError(FPglGetError proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetError", fileName, lineNum);
	auto ret = proc(); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetFloatv(FPglGetFloatv proc, GLenum a_pname, GLfloat * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetFloatv", fileName, lineNum);
	proc(a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetIntegerv(FPglGetIntegerv proc, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetIntegerv", fileName, lineNum);
	proc(a_pname, a_params); 
	FuncLogEnd(item);
}

const GLubyte *  GLTrace_glGetString(FPglGetString proc, GLenum a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetString", fileName, lineNum);
	auto ret = proc(a_name); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetTexImage(FPglGetTexImage proc, GLenum a_target, GLint a_level, GLenum a_format, GLenum a_type, GLvoid * a_pixels, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetTexImage", fileName, lineNum);
	proc(a_target, a_level, a_format, a_type, a_pixels); 
	FuncLogEnd(item);
}

void GLTrace_glGetTexParameterfv(FPglGetTexParameterfv proc, GLenum a_target, GLenum a_pname, GLfloat * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetTexParameterfv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetTexParameteriv(FPglGetTexParameteriv proc, GLenum a_target, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetTexParameteriv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetTexLevelParameterfv(FPglGetTexLevelParameterfv proc, GLenum a_target, GLint a_level, GLenum a_pname, GLfloat * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetTexLevelParameterfv", fileName, lineNum);
	proc(a_target, a_level, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetTexLevelParameteriv(FPglGetTexLevelParameteriv proc, GLenum a_target, GLint a_level, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetTexLevelParameteriv", fileName, lineNum);
	proc(a_target, a_level, a_pname, a_params); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsEnabled(FPglIsEnabled proc, GLenum a_cap, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsEnabled", fileName, lineNum);
	auto ret = proc(a_cap); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glDepthRange(FPglDepthRange proc, GLclampd a_near, GLclampd a_far, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDepthRange", fileName, lineNum);
	proc(a_near, a_far); 
	FuncLogEnd(item);
}

void GLTrace_glViewport(FPglViewport proc, GLint a_x, GLint a_y, GLsizei a_width, GLsizei a_height, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glViewport", fileName, lineNum);
	proc(a_x, a_y, a_width, a_height); 
	FuncLogEnd(item);
}

void GLTrace_glDrawArrays(FPglDrawArrays proc, GLenum a_mode, GLint a_first, GLsizei a_count, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawArrays", fileName, lineNum);
	proc(a_mode, a_first, a_count); 
	FuncLogEnd(item);
}

void GLTrace_glDrawElements(FPglDrawElements proc, GLenum a_mode, GLsizei a_count, GLenum a_type, const GLvoid * a_indices, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawElements", fileName, lineNum);
	proc(a_mode, a_count, a_type, a_indices); 
	FuncLogEnd(item);
}

void GLTrace_glGetPointerv(FPglGetPointerv proc, GLenum a_pname, GLvoid* * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetPointerv", fileName, lineNum);
	proc(a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glPolygonOffset(FPglPolygonOffset proc, GLfloat a_factor, GLfloat a_units, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPolygonOffset", fileName, lineNum);
	proc(a_factor, a_units); 
	FuncLogEnd(item);
}

void GLTrace_glCopyTexImage1D(FPglCopyTexImage1D proc, GLenum a_target, GLint a_level, GLenum a_internalformat, GLint a_x, GLint a_y, GLsizei a_width, GLint a_border, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCopyTexImage1D", fileName, lineNum);
	proc(a_target, a_level, a_internalformat, a_x, a_y, a_width, a_border); 
	FuncLogEnd(item);
}

void GLTrace_glCopyTexImage2D(FPglCopyTexImage2D proc, GLenum a_target, GLint a_level, GLenum a_internalformat, GLint a_x, GLint a_y, GLsizei a_width, GLsizei a_height, GLint a_border, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCopyTexImage2D", fileName, lineNum);
	proc(a_target, a_level, a_internalformat, a_x, a_y, a_width, a_height, a_border); 
	FuncLogEnd(item);
}

void GLTrace_glCopyTexSubImage1D(FPglCopyTexSubImage1D proc, GLenum a_target, GLint a_level, GLint a_xoffset, GLint a_x, GLint a_y, GLsizei a_width, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCopyTexSubImage1D", fileName, lineNum);
	proc(a_target, a_level, a_xoffset, a_x, a_y, a_width); 
	FuncLogEnd(item);
}

void GLTrace_glCopyTexSubImage2D(FPglCopyTexSubImage2D proc, GLenum a_target, GLint a_level, GLint a_xoffset, GLint a_yoffset, GLint a_x, GLint a_y, GLsizei a_width, GLsizei a_height, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCopyTexSubImage2D", fileName, lineNum);
	proc(a_target, a_level, a_xoffset, a_yoffset, a_x, a_y, a_width, a_height); 
	FuncLogEnd(item);
}

void GLTrace_glTexSubImage1D(FPglTexSubImage1D proc, GLenum a_target, GLint a_level, GLint a_xoffset, GLsizei a_width, GLenum a_format, GLenum a_type, const GLvoid * a_pixels, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexSubImage1D", fileName, lineNum);
	proc(a_target, a_level, a_xoffset, a_width, a_format, a_type, a_pixels); 
	FuncLogEnd(item);
}

void GLTrace_glTexSubImage2D(FPglTexSubImage2D proc, GLenum a_target, GLint a_level, GLint a_xoffset, GLint a_yoffset, GLsizei a_width, GLsizei a_height, GLenum a_format, GLenum a_type, const GLvoid * a_pixels, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexSubImage2D", fileName, lineNum);
	proc(a_target, a_level, a_xoffset, a_yoffset, a_width, a_height, a_format, a_type, a_pixels); 
	FuncLogEnd(item);
}

void GLTrace_glBindTexture(FPglBindTexture proc, GLenum a_target, GLuint a_texture, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindTexture", fileName, lineNum);
	proc(a_target, a_texture); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteTextures(FPglDeleteTextures proc, GLsizei a_n, const GLuint * a_textures, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteTextures", fileName, lineNum);
	proc(a_n, a_textures); 
	FuncLogEnd(item);
}

void GLTrace_glGenTextures(FPglGenTextures proc, GLsizei a_n, GLuint * a_textures, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenTextures", fileName, lineNum);
	proc(a_n, a_textures); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsTexture(FPglIsTexture proc, GLuint a_texture, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsTexture", fileName, lineNum);
	auto ret = proc(a_texture); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glBlendColor(FPglBlendColor proc, GLclampf a_red, GLclampf a_green, GLclampf a_blue, GLclampf a_alpha, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendColor", fileName, lineNum);
	proc(a_red, a_green, a_blue, a_alpha); 
	FuncLogEnd(item);
}

void GLTrace_glBlendEquation(FPglBlendEquation proc, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendEquation", fileName, lineNum);
	proc(a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glDrawRangeElements(FPglDrawRangeElements proc, GLenum a_mode, GLuint a_start, GLuint a_end, GLsizei a_count, GLenum a_type, const GLvoid * a_indices, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawRangeElements", fileName, lineNum);
	proc(a_mode, a_start, a_end, a_count, a_type, a_indices); 
	FuncLogEnd(item);
}

void GLTrace_glTexImage3D(FPglTexImage3D proc, GLenum a_target, GLint a_level, GLint a_internalformat, GLsizei a_width, GLsizei a_height, GLsizei a_depth, GLint a_border, GLenum a_format, GLenum a_type, const GLvoid * a_pixels, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexImage3D", fileName, lineNum);
	proc(a_target, a_level, a_internalformat, a_width, a_height, a_depth, a_border, a_format, a_type, a_pixels); 
	FuncLogEnd(item);
}

void GLTrace_glTexSubImage3D(FPglTexSubImage3D proc, GLenum a_target, GLint a_level, GLint a_xoffset, GLint a_yoffset, GLint a_zoffset, GLsizei a_width, GLsizei a_height, GLsizei a_depth, GLenum a_format, GLenum a_type, const GLvoid * a_pixels, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexSubImage3D", fileName, lineNum);
	proc(a_target, a_level, a_xoffset, a_yoffset, a_zoffset, a_width, a_height, a_depth, a_format, a_type, a_pixels); 
	FuncLogEnd(item);
}

void GLTrace_glCopyTexSubImage3D(FPglCopyTexSubImage3D proc, GLenum a_target, GLint a_level, GLint a_xoffset, GLint a_yoffset, GLint a_zoffset, GLint a_x, GLint a_y, GLsizei a_width, GLsizei a_height, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCopyTexSubImage3D", fileName, lineNum);
	proc(a_target, a_level, a_xoffset, a_yoffset, a_zoffset, a_x, a_y, a_width, a_height); 
	FuncLogEnd(item);
}

void GLTrace_glActiveTexture(FPglActiveTexture proc, GLenum a_texture, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glActiveTexture", fileName, lineNum);
	proc(a_texture); 
	FuncLogEnd(item);
}

void GLTrace_glSampleCoverage(FPglSampleCoverage proc, GLclampf a_value, GLboolean a_invert, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSampleCoverage", fileName, lineNum);
	proc(a_value, a_invert); 
	FuncLogEnd(item);
}

void GLTrace_glCompressedTexImage3D(FPglCompressedTexImage3D proc, GLenum a_target, GLint a_level, GLenum a_internalformat, GLsizei a_width, GLsizei a_height, GLsizei a_depth, GLint a_border, GLsizei a_imageSize, const GLvoid * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCompressedTexImage3D", fileName, lineNum);
	proc(a_target, a_level, a_internalformat, a_width, a_height, a_depth, a_border, a_imageSize, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glCompressedTexImage2D(FPglCompressedTexImage2D proc, GLenum a_target, GLint a_level, GLenum a_internalformat, GLsizei a_width, GLsizei a_height, GLint a_border, GLsizei a_imageSize, const GLvoid * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCompressedTexImage2D", fileName, lineNum);
	proc(a_target, a_level, a_internalformat, a_width, a_height, a_border, a_imageSize, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glCompressedTexImage1D(FPglCompressedTexImage1D proc, GLenum a_target, GLint a_level, GLenum a_internalformat, GLsizei a_width, GLint a_border, GLsizei a_imageSize, const GLvoid * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCompressedTexImage1D", fileName, lineNum);
	proc(a_target, a_level, a_internalformat, a_width, a_border, a_imageSize, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glCompressedTexSubImage3D(FPglCompressedTexSubImage3D proc, GLenum a_target, GLint a_level, GLint a_xoffset, GLint a_yoffset, GLint a_zoffset, GLsizei a_width, GLsizei a_height, GLsizei a_depth, GLenum a_format, GLsizei a_imageSize, const GLvoid * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCompressedTexSubImage3D", fileName, lineNum);
	proc(a_target, a_level, a_xoffset, a_yoffset, a_zoffset, a_width, a_height, a_depth, a_format, a_imageSize, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glCompressedTexSubImage2D(FPglCompressedTexSubImage2D proc, GLenum a_target, GLint a_level, GLint a_xoffset, GLint a_yoffset, GLsizei a_width, GLsizei a_height, GLenum a_format, GLsizei a_imageSize, const GLvoid * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCompressedTexSubImage2D", fileName, lineNum);
	proc(a_target, a_level, a_xoffset, a_yoffset, a_width, a_height, a_format, a_imageSize, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glCompressedTexSubImage1D(FPglCompressedTexSubImage1D proc, GLenum a_target, GLint a_level, GLint a_xoffset, GLsizei a_width, GLenum a_format, GLsizei a_imageSize, const GLvoid * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCompressedTexSubImage1D", fileName, lineNum);
	proc(a_target, a_level, a_xoffset, a_width, a_format, a_imageSize, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glGetCompressedTexImage(FPglGetCompressedTexImage proc, GLenum a_target, GLint a_level, GLvoid * a_img, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetCompressedTexImage", fileName, lineNum);
	proc(a_target, a_level, a_img); 
	FuncLogEnd(item);
}

void GLTrace_glBlendFuncSeparate(FPglBlendFuncSeparate proc, GLenum a_sfactorRGB, GLenum a_dfactorRGB, GLenum a_sfactorAlpha, GLenum a_dfactorAlpha, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendFuncSeparate", fileName, lineNum);
	proc(a_sfactorRGB, a_dfactorRGB, a_sfactorAlpha, a_dfactorAlpha); 
	FuncLogEnd(item);
}

void GLTrace_glMultiDrawArrays(FPglMultiDrawArrays proc, GLenum a_mode, const GLint * a_first, const GLsizei * a_count, GLsizei a_primcount, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiDrawArrays", fileName, lineNum);
	proc(a_mode, a_first, a_count, a_primcount); 
	FuncLogEnd(item);
}

void GLTrace_glMultiDrawElements(FPglMultiDrawElements proc, GLenum a_mode, const GLsizei * a_count, GLenum a_type, const GLvoid* * a_indices, GLsizei a_primcount, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiDrawElements", fileName, lineNum);
	proc(a_mode, a_count, a_type, a_indices, a_primcount); 
	FuncLogEnd(item);
}

void GLTrace_glPointParameterf(FPglPointParameterf proc, GLenum a_pname, GLfloat a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPointParameterf", fileName, lineNum);
	proc(a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glPointParameterfv(FPglPointParameterfv proc, GLenum a_pname, const GLfloat * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPointParameterfv", fileName, lineNum);
	proc(a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glPointParameteri(FPglPointParameteri proc, GLenum a_pname, GLint a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPointParameteri", fileName, lineNum);
	proc(a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glPointParameteriv(FPglPointParameteriv proc, GLenum a_pname, const GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPointParameteriv", fileName, lineNum);
	proc(a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGenQueries(FPglGenQueries proc, GLsizei a_n, GLuint * a_ids, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenQueries", fileName, lineNum);
	proc(a_n, a_ids); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteQueries(FPglDeleteQueries proc, GLsizei a_n, const GLuint * a_ids, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteQueries", fileName, lineNum);
	proc(a_n, a_ids); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsQuery(FPglIsQuery proc, GLuint a_id, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsQuery", fileName, lineNum);
	auto ret = proc(a_id); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glBeginQuery(FPglBeginQuery proc, GLenum a_target, GLuint a_id, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBeginQuery", fileName, lineNum);
	proc(a_target, a_id); 
	FuncLogEnd(item);
}

void GLTrace_glEndQuery(FPglEndQuery proc, GLenum a_target, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glEndQuery", fileName, lineNum);
	proc(a_target); 
	FuncLogEnd(item);
}

void GLTrace_glGetQueryiv(FPglGetQueryiv proc, GLenum a_target, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetQueryiv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetQueryObjectiv(FPglGetQueryObjectiv proc, GLuint a_id, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetQueryObjectiv", fileName, lineNum);
	proc(a_id, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetQueryObjectuiv(FPglGetQueryObjectuiv proc, GLuint a_id, GLenum a_pname, GLuint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetQueryObjectuiv", fileName, lineNum);
	proc(a_id, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glBindBuffer(FPglBindBuffer proc, GLenum a_target, GLuint a_buffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindBuffer", fileName, lineNum);
	proc(a_target, a_buffer); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteBuffers(FPglDeleteBuffers proc, GLsizei a_n, const GLuint * a_buffers, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteBuffers", fileName, lineNum);
	proc(a_n, a_buffers); 
	FuncLogEnd(item);
}

void GLTrace_glGenBuffers(FPglGenBuffers proc, GLsizei a_n, GLuint * a_buffers, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenBuffers", fileName, lineNum);
	proc(a_n, a_buffers); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsBuffer(FPglIsBuffer proc, GLuint a_buffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsBuffer", fileName, lineNum);
	auto ret = proc(a_buffer); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glBufferData(FPglBufferData proc, GLenum a_target, GLsizeiptr a_size, const GLvoid * a_data, GLenum a_usage, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBufferData", fileName, lineNum);
	proc(a_target, a_size, a_data, a_usage); 
	FuncLogEnd(item);
}

void GLTrace_glBufferSubData(FPglBufferSubData proc, GLenum a_target, GLintptr a_offset, GLsizeiptr a_size, const GLvoid * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBufferSubData", fileName, lineNum);
	proc(a_target, a_offset, a_size, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glGetBufferSubData(FPglGetBufferSubData proc, GLenum a_target, GLintptr a_offset, GLsizeiptr a_size, GLvoid * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetBufferSubData", fileName, lineNum);
	proc(a_target, a_offset, a_size, a_data); 
	FuncLogEnd(item);
}

GLvoid*  GLTrace_glMapBuffer(FPglMapBuffer proc, GLenum a_target, GLenum a_access, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMapBuffer", fileName, lineNum);
	auto ret = proc(a_target, a_access); 
	FuncLogEnd(item);
	return ret;
}

GLboolean GLTrace_glUnmapBuffer(FPglUnmapBuffer proc, GLenum a_target, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUnmapBuffer", fileName, lineNum);
	auto ret = proc(a_target); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetBufferParameteriv(FPglGetBufferParameteriv proc, GLenum a_target, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetBufferParameteriv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetBufferPointerv(FPglGetBufferPointerv proc, GLenum a_target, GLenum a_pname, GLvoid* * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetBufferPointerv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glBlendEquationSeparate(FPglBlendEquationSeparate proc, GLenum a_modeRGB, GLenum a_modeAlpha, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendEquationSeparate", fileName, lineNum);
	proc(a_modeRGB, a_modeAlpha); 
	FuncLogEnd(item);
}

void GLTrace_glDrawBuffers(FPglDrawBuffers proc, GLsizei a_n, const GLenum * a_bufs, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawBuffers", fileName, lineNum);
	proc(a_n, a_bufs); 
	FuncLogEnd(item);
}

void GLTrace_glStencilOpSeparate(FPglStencilOpSeparate proc, GLenum a_face, GLenum a_sfail, GLenum a_dpfail, GLenum a_dppass, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glStencilOpSeparate", fileName, lineNum);
	proc(a_face, a_sfail, a_dpfail, a_dppass); 
	FuncLogEnd(item);
}

void GLTrace_glStencilFuncSeparate(FPglStencilFuncSeparate proc, GLenum a_face, GLenum a_func, GLint a_ref, GLuint a_mask, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glStencilFuncSeparate", fileName, lineNum);
	proc(a_face, a_func, a_ref, a_mask); 
	FuncLogEnd(item);
}

void GLTrace_glStencilMaskSeparate(FPglStencilMaskSeparate proc, GLenum a_face, GLuint a_mask, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glStencilMaskSeparate", fileName, lineNum);
	proc(a_face, a_mask); 
	FuncLogEnd(item);
}

void GLTrace_glAttachShader(FPglAttachShader proc, GLuint a_program, GLuint a_shader, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glAttachShader", fileName, lineNum);
	proc(a_program, a_shader); 
	FuncLogEnd(item);
}

void GLTrace_glBindAttribLocation(FPglBindAttribLocation proc, GLuint a_program, GLuint a_index, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindAttribLocation", fileName, lineNum);
	proc(a_program, a_index, a_name); 
	FuncLogEnd(item);
}

void GLTrace_glCompileShader(FPglCompileShader proc, GLuint a_shader, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCompileShader", fileName, lineNum);
	proc(a_shader); 
	FuncLogEnd(item);
}

GLuint GLTrace_glCreateProgram(FPglCreateProgram proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCreateProgram", fileName, lineNum);
	auto ret = proc(); 
	FuncLogEnd(item);
	return ret;
}

GLuint GLTrace_glCreateShader(FPglCreateShader proc, GLenum a_type, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCreateShader", fileName, lineNum);
	auto ret = proc(a_type); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glDeleteProgram(FPglDeleteProgram proc, GLuint a_program, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteProgram", fileName, lineNum);
	proc(a_program); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteShader(FPglDeleteShader proc, GLuint a_shader, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteShader", fileName, lineNum);
	proc(a_shader); 
	FuncLogEnd(item);
}

void GLTrace_glDetachShader(FPglDetachShader proc, GLuint a_program, GLuint a_shader, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDetachShader", fileName, lineNum);
	proc(a_program, a_shader); 
	FuncLogEnd(item);
}

void GLTrace_glDisableVertexAttribArray(FPglDisableVertexAttribArray proc, GLuint a_index, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDisableVertexAttribArray", fileName, lineNum);
	proc(a_index); 
	FuncLogEnd(item);
}

void GLTrace_glEnableVertexAttribArray(FPglEnableVertexAttribArray proc, GLuint a_index, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glEnableVertexAttribArray", fileName, lineNum);
	proc(a_index); 
	FuncLogEnd(item);
}

void GLTrace_glGetActiveAttrib(FPglGetActiveAttrib proc, GLuint a_program, GLuint a_index, GLsizei a_bufSize, GLsizei * a_length, GLint * a_size, GLenum * a_type, GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetActiveAttrib", fileName, lineNum);
	proc(a_program, a_index, a_bufSize, a_length, a_size, a_type, a_name); 
	FuncLogEnd(item);
}

void GLTrace_glGetActiveUniform(FPglGetActiveUniform proc, GLuint a_program, GLuint a_index, GLsizei a_bufSize, GLsizei * a_length, GLint * a_size, GLenum * a_type, GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetActiveUniform", fileName, lineNum);
	proc(a_program, a_index, a_bufSize, a_length, a_size, a_type, a_name); 
	FuncLogEnd(item);
}

void GLTrace_glGetAttachedShaders(FPglGetAttachedShaders proc, GLuint a_program, GLsizei a_maxCount, GLsizei * a_count, GLuint * a_obj, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetAttachedShaders", fileName, lineNum);
	proc(a_program, a_maxCount, a_count, a_obj); 
	FuncLogEnd(item);
}

GLint GLTrace_glGetAttribLocation(FPglGetAttribLocation proc, GLuint a_program, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetAttribLocation", fileName, lineNum);
	auto ret = proc(a_program, a_name); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetProgramiv(FPglGetProgramiv proc, GLuint a_program, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetProgramiv", fileName, lineNum);
	proc(a_program, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetProgramInfoLog(FPglGetProgramInfoLog proc, GLuint a_program, GLsizei a_bufSize, GLsizei * a_length, GLchar * a_infoLog, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetProgramInfoLog", fileName, lineNum);
	proc(a_program, a_bufSize, a_length, a_infoLog); 
	FuncLogEnd(item);
}

void GLTrace_glGetShaderiv(FPglGetShaderiv proc, GLuint a_shader, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetShaderiv", fileName, lineNum);
	proc(a_shader, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetShaderInfoLog(FPglGetShaderInfoLog proc, GLuint a_shader, GLsizei a_bufSize, GLsizei * a_length, GLchar * a_infoLog, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetShaderInfoLog", fileName, lineNum);
	proc(a_shader, a_bufSize, a_length, a_infoLog); 
	FuncLogEnd(item);
}

void GLTrace_glGetShaderSource(FPglGetShaderSource proc, GLuint a_shader, GLsizei a_bufSize, GLsizei * a_length, GLchar * a_source, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetShaderSource", fileName, lineNum);
	proc(a_shader, a_bufSize, a_length, a_source); 
	FuncLogEnd(item);
}

GLint GLTrace_glGetUniformLocation(FPglGetUniformLocation proc, GLuint a_program, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetUniformLocation", fileName, lineNum);
	auto ret = proc(a_program, a_name); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetUniformfv(FPglGetUniformfv proc, GLuint a_program, GLint a_location, GLfloat * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetUniformfv", fileName, lineNum);
	proc(a_program, a_location, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetUniformiv(FPglGetUniformiv proc, GLuint a_program, GLint a_location, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetUniformiv", fileName, lineNum);
	proc(a_program, a_location, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetVertexAttribdv(FPglGetVertexAttribdv proc, GLuint a_index, GLenum a_pname, GLdouble * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetVertexAttribdv", fileName, lineNum);
	proc(a_index, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetVertexAttribfv(FPglGetVertexAttribfv proc, GLuint a_index, GLenum a_pname, GLfloat * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetVertexAttribfv", fileName, lineNum);
	proc(a_index, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetVertexAttribiv(FPglGetVertexAttribiv proc, GLuint a_index, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetVertexAttribiv", fileName, lineNum);
	proc(a_index, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetVertexAttribPointerv(FPglGetVertexAttribPointerv proc, GLuint a_index, GLenum a_pname, GLvoid* * a_pointer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetVertexAttribPointerv", fileName, lineNum);
	proc(a_index, a_pname, a_pointer); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsProgram(FPglIsProgram proc, GLuint a_program, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsProgram", fileName, lineNum);
	auto ret = proc(a_program); 
	FuncLogEnd(item);
	return ret;
}

GLboolean GLTrace_glIsShader(FPglIsShader proc, GLuint a_shader, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsShader", fileName, lineNum);
	auto ret = proc(a_shader); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glLinkProgram(FPglLinkProgram proc, GLuint a_program, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glLinkProgram", fileName, lineNum);
	proc(a_program); 
	FuncLogEnd(item);
}

void GLTrace_glShaderSource(FPglShaderSource proc, GLuint a_shader, GLsizei a_count, const GLchar* * a_string, const GLint * a_length, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glShaderSource", fileName, lineNum);
	proc(a_shader, a_count, a_string, a_length); 
	FuncLogEnd(item);
}

void GLTrace_glUseProgram(FPglUseProgram proc, GLuint a_program, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUseProgram", fileName, lineNum);
	proc(a_program); 
	FuncLogEnd(item);
}

void GLTrace_glUniform1f(FPglUniform1f proc, GLint a_location, GLfloat a_v0, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform1f", fileName, lineNum);
	proc(a_location, a_v0); 
	FuncLogEnd(item);
}

void GLTrace_glUniform2f(FPglUniform2f proc, GLint a_location, GLfloat a_v0, GLfloat a_v1, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform2f", fileName, lineNum);
	proc(a_location, a_v0, a_v1); 
	FuncLogEnd(item);
}

void GLTrace_glUniform3f(FPglUniform3f proc, GLint a_location, GLfloat a_v0, GLfloat a_v1, GLfloat a_v2, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform3f", fileName, lineNum);
	proc(a_location, a_v0, a_v1, a_v2); 
	FuncLogEnd(item);
}

void GLTrace_glUniform4f(FPglUniform4f proc, GLint a_location, GLfloat a_v0, GLfloat a_v1, GLfloat a_v2, GLfloat a_v3, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform4f", fileName, lineNum);
	proc(a_location, a_v0, a_v1, a_v2, a_v3); 
	FuncLogEnd(item);
}

void GLTrace_glUniform1i(FPglUniform1i proc, GLint a_location, GLint a_v0, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform1i", fileName, lineNum);
	proc(a_location, a_v0); 
	FuncLogEnd(item);
}

void GLTrace_glUniform2i(FPglUniform2i proc, GLint a_location, GLint a_v0, GLint a_v1, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform2i", fileName, lineNum);
	proc(a_location, a_v0, a_v1); 
	FuncLogEnd(item);
}

void GLTrace_glUniform3i(FPglUniform3i proc, GLint a_location, GLint a_v0, GLint a_v1, GLint a_v2, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform3i", fileName, lineNum);
	proc(a_location, a_v0, a_v1, a_v2); 
	FuncLogEnd(item);
}

void GLTrace_glUniform4i(FPglUniform4i proc, GLint a_location, GLint a_v0, GLint a_v1, GLint a_v2, GLint a_v3, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform4i", fileName, lineNum);
	proc(a_location, a_v0, a_v1, a_v2, a_v3); 
	FuncLogEnd(item);
}

void GLTrace_glUniform1fv(FPglUniform1fv proc, GLint a_location, GLsizei a_count, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform1fv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform2fv(FPglUniform2fv proc, GLint a_location, GLsizei a_count, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform2fv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform3fv(FPglUniform3fv proc, GLint a_location, GLsizei a_count, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform3fv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform4fv(FPglUniform4fv proc, GLint a_location, GLsizei a_count, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform4fv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform1iv(FPglUniform1iv proc, GLint a_location, GLsizei a_count, const GLint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform1iv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform2iv(FPglUniform2iv proc, GLint a_location, GLsizei a_count, const GLint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform2iv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform3iv(FPglUniform3iv proc, GLint a_location, GLsizei a_count, const GLint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform3iv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform4iv(FPglUniform4iv proc, GLint a_location, GLsizei a_count, const GLint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform4iv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix2fv(FPglUniformMatrix2fv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix2fv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix3fv(FPglUniformMatrix3fv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix3fv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix4fv(FPglUniformMatrix4fv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix4fv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glValidateProgram(FPglValidateProgram proc, GLuint a_program, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glValidateProgram", fileName, lineNum);
	proc(a_program); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib1d(FPglVertexAttrib1d proc, GLuint a_index, GLdouble a_x, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib1d", fileName, lineNum);
	proc(a_index, a_x); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib1dv(FPglVertexAttrib1dv proc, GLuint a_index, const GLdouble * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib1dv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib1f(FPglVertexAttrib1f proc, GLuint a_index, GLfloat a_x, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib1f", fileName, lineNum);
	proc(a_index, a_x); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib1fv(FPglVertexAttrib1fv proc, GLuint a_index, const GLfloat * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib1fv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib1s(FPglVertexAttrib1s proc, GLuint a_index, GLshort a_x, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib1s", fileName, lineNum);
	proc(a_index, a_x); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib1sv(FPglVertexAttrib1sv proc, GLuint a_index, const GLshort * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib1sv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib2d(FPglVertexAttrib2d proc, GLuint a_index, GLdouble a_x, GLdouble a_y, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib2d", fileName, lineNum);
	proc(a_index, a_x, a_y); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib2dv(FPglVertexAttrib2dv proc, GLuint a_index, const GLdouble * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib2dv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib2f(FPglVertexAttrib2f proc, GLuint a_index, GLfloat a_x, GLfloat a_y, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib2f", fileName, lineNum);
	proc(a_index, a_x, a_y); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib2fv(FPglVertexAttrib2fv proc, GLuint a_index, const GLfloat * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib2fv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib2s(FPglVertexAttrib2s proc, GLuint a_index, GLshort a_x, GLshort a_y, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib2s", fileName, lineNum);
	proc(a_index, a_x, a_y); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib2sv(FPglVertexAttrib2sv proc, GLuint a_index, const GLshort * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib2sv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib3d(FPglVertexAttrib3d proc, GLuint a_index, GLdouble a_x, GLdouble a_y, GLdouble a_z, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib3d", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib3dv(FPglVertexAttrib3dv proc, GLuint a_index, const GLdouble * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib3dv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib3f(FPglVertexAttrib3f proc, GLuint a_index, GLfloat a_x, GLfloat a_y, GLfloat a_z, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib3f", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib3fv(FPglVertexAttrib3fv proc, GLuint a_index, const GLfloat * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib3fv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib3s(FPglVertexAttrib3s proc, GLuint a_index, GLshort a_x, GLshort a_y, GLshort a_z, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib3s", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib3sv(FPglVertexAttrib3sv proc, GLuint a_index, const GLshort * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib3sv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4Nbv(FPglVertexAttrib4Nbv proc, GLuint a_index, const GLbyte * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4Nbv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4Niv(FPglVertexAttrib4Niv proc, GLuint a_index, const GLint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4Niv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4Nsv(FPglVertexAttrib4Nsv proc, GLuint a_index, const GLshort * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4Nsv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4Nub(FPglVertexAttrib4Nub proc, GLuint a_index, GLubyte a_x, GLubyte a_y, GLubyte a_z, GLubyte a_w, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4Nub", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z, a_w); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4Nubv(FPglVertexAttrib4Nubv proc, GLuint a_index, const GLubyte * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4Nubv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4Nuiv(FPglVertexAttrib4Nuiv proc, GLuint a_index, const GLuint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4Nuiv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4Nusv(FPglVertexAttrib4Nusv proc, GLuint a_index, const GLushort * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4Nusv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4bv(FPglVertexAttrib4bv proc, GLuint a_index, const GLbyte * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4bv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4d(FPglVertexAttrib4d proc, GLuint a_index, GLdouble a_x, GLdouble a_y, GLdouble a_z, GLdouble a_w, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4d", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z, a_w); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4dv(FPglVertexAttrib4dv proc, GLuint a_index, const GLdouble * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4dv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4f(FPglVertexAttrib4f proc, GLuint a_index, GLfloat a_x, GLfloat a_y, GLfloat a_z, GLfloat a_w, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4f", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z, a_w); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4fv(FPglVertexAttrib4fv proc, GLuint a_index, const GLfloat * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4fv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4iv(FPglVertexAttrib4iv proc, GLuint a_index, const GLint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4iv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4s(FPglVertexAttrib4s proc, GLuint a_index, GLshort a_x, GLshort a_y, GLshort a_z, GLshort a_w, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4s", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z, a_w); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4sv(FPglVertexAttrib4sv proc, GLuint a_index, const GLshort * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4sv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4ubv(FPglVertexAttrib4ubv proc, GLuint a_index, const GLubyte * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4ubv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4uiv(FPglVertexAttrib4uiv proc, GLuint a_index, const GLuint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4uiv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttrib4usv(FPglVertexAttrib4usv proc, GLuint a_index, const GLushort * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttrib4usv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribPointer(FPglVertexAttribPointer proc, GLuint a_index, GLint a_size, GLenum a_type, GLboolean a_normalized, GLsizei a_stride, const GLvoid * a_pointer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribPointer", fileName, lineNum);
	proc(a_index, a_size, a_type, a_normalized, a_stride, a_pointer); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix2x3fv(FPglUniformMatrix2x3fv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix2x3fv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix3x2fv(FPglUniformMatrix3x2fv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix3x2fv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix2x4fv(FPglUniformMatrix2x4fv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix2x4fv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix4x2fv(FPglUniformMatrix4x2fv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix4x2fv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix3x4fv(FPglUniformMatrix3x4fv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix3x4fv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix4x3fv(FPglUniformMatrix4x3fv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix4x3fv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glColorMaski(FPglColorMaski proc, GLuint a_index, GLboolean a_r, GLboolean a_g, GLboolean a_b, GLboolean a_a, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glColorMaski", fileName, lineNum);
	proc(a_index, a_r, a_g, a_b, a_a); 
	FuncLogEnd(item);
}

void GLTrace_glGetBooleani_v(FPglGetBooleani_v proc, GLenum a_target, GLuint a_index, GLboolean * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetBooleani_v", fileName, lineNum);
	proc(a_target, a_index, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glGetIntegeri_v(FPglGetIntegeri_v proc, GLenum a_target, GLuint a_index, GLint * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetIntegeri_v", fileName, lineNum);
	proc(a_target, a_index, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glEnablei(FPglEnablei proc, GLenum a_target, GLuint a_index, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glEnablei", fileName, lineNum);
	proc(a_target, a_index); 
	FuncLogEnd(item);
}

void GLTrace_glDisablei(FPglDisablei proc, GLenum a_target, GLuint a_index, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDisablei", fileName, lineNum);
	proc(a_target, a_index); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsEnabledi(FPglIsEnabledi proc, GLenum a_target, GLuint a_index, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsEnabledi", fileName, lineNum);
	auto ret = proc(a_target, a_index); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glBeginTransformFeedback(FPglBeginTransformFeedback proc, GLenum a_primitiveMode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBeginTransformFeedback", fileName, lineNum);
	proc(a_primitiveMode); 
	FuncLogEnd(item);
}

void GLTrace_glEndTransformFeedback(FPglEndTransformFeedback proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glEndTransformFeedback", fileName, lineNum);
	proc(); 
	FuncLogEnd(item);
}

void GLTrace_glBindBufferRange(FPglBindBufferRange proc, GLenum a_target, GLuint a_index, GLuint a_buffer, GLintptr a_offset, GLsizeiptr a_size, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindBufferRange", fileName, lineNum);
	proc(a_target, a_index, a_buffer, a_offset, a_size); 
	FuncLogEnd(item);
}

void GLTrace_glBindBufferBase(FPglBindBufferBase proc, GLenum a_target, GLuint a_index, GLuint a_buffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindBufferBase", fileName, lineNum);
	proc(a_target, a_index, a_buffer); 
	FuncLogEnd(item);
}

void GLTrace_glTransformFeedbackVaryings(FPglTransformFeedbackVaryings proc, GLuint a_program, GLsizei a_count, const GLchar* * a_varyings, GLenum a_bufferMode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTransformFeedbackVaryings", fileName, lineNum);
	proc(a_program, a_count, a_varyings, a_bufferMode); 
	FuncLogEnd(item);
}

void GLTrace_glGetTransformFeedbackVarying(FPglGetTransformFeedbackVarying proc, GLuint a_program, GLuint a_index, GLsizei a_bufSize, GLsizei * a_length, GLsizei * a_size, GLenum * a_type, GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetTransformFeedbackVarying", fileName, lineNum);
	proc(a_program, a_index, a_bufSize, a_length, a_size, a_type, a_name); 
	FuncLogEnd(item);
}

void GLTrace_glClampColor(FPglClampColor proc, GLenum a_target, GLenum a_clamp, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClampColor", fileName, lineNum);
	proc(a_target, a_clamp); 
	FuncLogEnd(item);
}

void GLTrace_glBeginConditionalRender(FPglBeginConditionalRender proc, GLuint a_id, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBeginConditionalRender", fileName, lineNum);
	proc(a_id, a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glEndConditionalRender(FPglEndConditionalRender proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glEndConditionalRender", fileName, lineNum);
	proc(); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribIPointer(FPglVertexAttribIPointer proc, GLuint a_index, GLint a_size, GLenum a_type, GLsizei a_stride, const GLvoid * a_pointer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribIPointer", fileName, lineNum);
	proc(a_index, a_size, a_type, a_stride, a_pointer); 
	FuncLogEnd(item);
}

void GLTrace_glGetVertexAttribIiv(FPglGetVertexAttribIiv proc, GLuint a_index, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetVertexAttribIiv", fileName, lineNum);
	proc(a_index, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetVertexAttribIuiv(FPglGetVertexAttribIuiv proc, GLuint a_index, GLenum a_pname, GLuint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetVertexAttribIuiv", fileName, lineNum);
	proc(a_index, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI1i(FPglVertexAttribI1i proc, GLuint a_index, GLint a_x, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI1i", fileName, lineNum);
	proc(a_index, a_x); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI2i(FPglVertexAttribI2i proc, GLuint a_index, GLint a_x, GLint a_y, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI2i", fileName, lineNum);
	proc(a_index, a_x, a_y); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI3i(FPglVertexAttribI3i proc, GLuint a_index, GLint a_x, GLint a_y, GLint a_z, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI3i", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI4i(FPglVertexAttribI4i proc, GLuint a_index, GLint a_x, GLint a_y, GLint a_z, GLint a_w, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI4i", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z, a_w); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI1ui(FPglVertexAttribI1ui proc, GLuint a_index, GLuint a_x, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI1ui", fileName, lineNum);
	proc(a_index, a_x); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI2ui(FPglVertexAttribI2ui proc, GLuint a_index, GLuint a_x, GLuint a_y, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI2ui", fileName, lineNum);
	proc(a_index, a_x, a_y); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI3ui(FPglVertexAttribI3ui proc, GLuint a_index, GLuint a_x, GLuint a_y, GLuint a_z, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI3ui", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI4ui(FPglVertexAttribI4ui proc, GLuint a_index, GLuint a_x, GLuint a_y, GLuint a_z, GLuint a_w, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI4ui", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z, a_w); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI1iv(FPglVertexAttribI1iv proc, GLuint a_index, const GLint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI1iv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI2iv(FPglVertexAttribI2iv proc, GLuint a_index, const GLint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI2iv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI3iv(FPglVertexAttribI3iv proc, GLuint a_index, const GLint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI3iv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI4iv(FPglVertexAttribI4iv proc, GLuint a_index, const GLint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI4iv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI1uiv(FPglVertexAttribI1uiv proc, GLuint a_index, const GLuint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI1uiv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI2uiv(FPglVertexAttribI2uiv proc, GLuint a_index, const GLuint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI2uiv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI3uiv(FPglVertexAttribI3uiv proc, GLuint a_index, const GLuint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI3uiv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI4uiv(FPglVertexAttribI4uiv proc, GLuint a_index, const GLuint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI4uiv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI4bv(FPglVertexAttribI4bv proc, GLuint a_index, const GLbyte * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI4bv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI4sv(FPglVertexAttribI4sv proc, GLuint a_index, const GLshort * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI4sv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI4ubv(FPglVertexAttribI4ubv proc, GLuint a_index, const GLubyte * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI4ubv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribI4usv(FPglVertexAttribI4usv proc, GLuint a_index, const GLushort * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribI4usv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glGetUniformuiv(FPglGetUniformuiv proc, GLuint a_program, GLint a_location, GLuint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetUniformuiv", fileName, lineNum);
	proc(a_program, a_location, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glBindFragDataLocation(FPglBindFragDataLocation proc, GLuint a_program, GLuint a_color, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindFragDataLocation", fileName, lineNum);
	proc(a_program, a_color, a_name); 
	FuncLogEnd(item);
}

GLint GLTrace_glGetFragDataLocation(FPglGetFragDataLocation proc, GLuint a_program, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetFragDataLocation", fileName, lineNum);
	auto ret = proc(a_program, a_name); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glUniform1ui(FPglUniform1ui proc, GLint a_location, GLuint a_v0, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform1ui", fileName, lineNum);
	proc(a_location, a_v0); 
	FuncLogEnd(item);
}

void GLTrace_glUniform2ui(FPglUniform2ui proc, GLint a_location, GLuint a_v0, GLuint a_v1, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform2ui", fileName, lineNum);
	proc(a_location, a_v0, a_v1); 
	FuncLogEnd(item);
}

void GLTrace_glUniform3ui(FPglUniform3ui proc, GLint a_location, GLuint a_v0, GLuint a_v1, GLuint a_v2, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform3ui", fileName, lineNum);
	proc(a_location, a_v0, a_v1, a_v2); 
	FuncLogEnd(item);
}

void GLTrace_glUniform4ui(FPglUniform4ui proc, GLint a_location, GLuint a_v0, GLuint a_v1, GLuint a_v2, GLuint a_v3, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform4ui", fileName, lineNum);
	proc(a_location, a_v0, a_v1, a_v2, a_v3); 
	FuncLogEnd(item);
}

void GLTrace_glUniform1uiv(FPglUniform1uiv proc, GLint a_location, GLsizei a_count, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform1uiv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform2uiv(FPglUniform2uiv proc, GLint a_location, GLsizei a_count, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform2uiv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform3uiv(FPglUniform3uiv proc, GLint a_location, GLsizei a_count, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform3uiv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform4uiv(FPglUniform4uiv proc, GLint a_location, GLsizei a_count, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform4uiv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glTexParameterIiv(FPglTexParameterIiv proc, GLenum a_target, GLenum a_pname, const GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexParameterIiv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glTexParameterIuiv(FPglTexParameterIuiv proc, GLenum a_target, GLenum a_pname, const GLuint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexParameterIuiv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetTexParameterIiv(FPglGetTexParameterIiv proc, GLenum a_target, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetTexParameterIiv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetTexParameterIuiv(FPglGetTexParameterIuiv proc, GLenum a_target, GLenum a_pname, GLuint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetTexParameterIuiv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glClearBufferiv(FPglClearBufferiv proc, GLenum a_buffer, GLint a_drawbuffer, const GLint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClearBufferiv", fileName, lineNum);
	proc(a_buffer, a_drawbuffer, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glClearBufferuiv(FPglClearBufferuiv proc, GLenum a_buffer, GLint a_drawbuffer, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClearBufferuiv", fileName, lineNum);
	proc(a_buffer, a_drawbuffer, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glClearBufferfv(FPglClearBufferfv proc, GLenum a_buffer, GLint a_drawbuffer, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClearBufferfv", fileName, lineNum);
	proc(a_buffer, a_drawbuffer, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glClearBufferfi(FPglClearBufferfi proc, GLenum a_buffer, GLint a_drawbuffer, GLfloat a_depth, GLint a_stencil, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClearBufferfi", fileName, lineNum);
	proc(a_buffer, a_drawbuffer, a_depth, a_stencil); 
	FuncLogEnd(item);
}

const GLubyte *  GLTrace_glGetStringi(FPglGetStringi proc, GLenum a_name, GLuint a_index, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetStringi", fileName, lineNum);
	auto ret = proc(a_name, a_index); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glDrawArraysInstanced(FPglDrawArraysInstanced proc, GLenum a_mode, GLint a_first, GLsizei a_count, GLsizei a_primcount, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawArraysInstanced", fileName, lineNum);
	proc(a_mode, a_first, a_count, a_primcount); 
	FuncLogEnd(item);
}

void GLTrace_glDrawElementsInstanced(FPglDrawElementsInstanced proc, GLenum a_mode, GLsizei a_count, GLenum a_type, const GLvoid * a_indices, GLsizei a_primcount, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawElementsInstanced", fileName, lineNum);
	proc(a_mode, a_count, a_type, a_indices, a_primcount); 
	FuncLogEnd(item);
}

void GLTrace_glTexBuffer(FPglTexBuffer proc, GLenum a_target, GLenum a_internalformat, GLuint a_buffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexBuffer", fileName, lineNum);
	proc(a_target, a_internalformat, a_buffer); 
	FuncLogEnd(item);
}

void GLTrace_glPrimitiveRestartIndex(FPglPrimitiveRestartIndex proc, GLuint a_index, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPrimitiveRestartIndex", fileName, lineNum);
	proc(a_index); 
	FuncLogEnd(item);
}

void GLTrace_glGetInteger64i_v(FPglGetInteger64i_v proc, GLenum a_target, GLuint a_index, GLint64 * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetInteger64i_v", fileName, lineNum);
	proc(a_target, a_index, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glGetBufferParameteri64v(FPglGetBufferParameteri64v proc, GLenum a_target, GLenum a_pname, GLint64 * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetBufferParameteri64v", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glFramebufferTexture(FPglFramebufferTexture proc, GLenum a_target, GLenum a_attachment, GLuint a_texture, GLint a_level, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFramebufferTexture", fileName, lineNum);
	proc(a_target, a_attachment, a_texture, a_level); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribDivisor(FPglVertexAttribDivisor proc, GLuint a_index, GLuint a_divisor, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribDivisor", fileName, lineNum);
	proc(a_index, a_divisor); 
	FuncLogEnd(item);
}

void GLTrace_glMinSampleShading(FPglMinSampleShading proc, GLclampf a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMinSampleShading", fileName, lineNum);
	proc(a_value); 
	FuncLogEnd(item);
}

void GLTrace_glBlendEquationi(FPglBlendEquationi proc, GLuint a_buf, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendEquationi", fileName, lineNum);
	proc(a_buf, a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glBlendEquationSeparatei(FPglBlendEquationSeparatei proc, GLuint a_buf, GLenum a_modeRGB, GLenum a_modeAlpha, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendEquationSeparatei", fileName, lineNum);
	proc(a_buf, a_modeRGB, a_modeAlpha); 
	FuncLogEnd(item);
}

void GLTrace_glBlendFunci(FPglBlendFunci proc, GLuint a_buf, GLenum a_src, GLenum a_dst, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendFunci", fileName, lineNum);
	proc(a_buf, a_src, a_dst); 
	FuncLogEnd(item);
}

void GLTrace_glBlendFuncSeparatei(FPglBlendFuncSeparatei proc, GLuint a_buf, GLenum a_srcRGB, GLenum a_dstRGB, GLenum a_srcAlpha, GLenum a_dstAlpha, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendFuncSeparatei", fileName, lineNum);
	proc(a_buf, a_srcRGB, a_dstRGB, a_srcAlpha, a_dstAlpha); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsRenderbuffer(FPglIsRenderbuffer proc, GLuint a_renderbuffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsRenderbuffer", fileName, lineNum);
	auto ret = proc(a_renderbuffer); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glBindRenderbuffer(FPglBindRenderbuffer proc, GLenum a_target, GLuint a_renderbuffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindRenderbuffer", fileName, lineNum);
	proc(a_target, a_renderbuffer); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteRenderbuffers(FPglDeleteRenderbuffers proc, GLsizei a_n, const GLuint * a_renderbuffers, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteRenderbuffers", fileName, lineNum);
	proc(a_n, a_renderbuffers); 
	FuncLogEnd(item);
}

void GLTrace_glGenRenderbuffers(FPglGenRenderbuffers proc, GLsizei a_n, GLuint * a_renderbuffers, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenRenderbuffers", fileName, lineNum);
	proc(a_n, a_renderbuffers); 
	FuncLogEnd(item);
}

void GLTrace_glRenderbufferStorage(FPglRenderbufferStorage proc, GLenum a_target, GLenum a_internalformat, GLsizei a_width, GLsizei a_height, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glRenderbufferStorage", fileName, lineNum);
	proc(a_target, a_internalformat, a_width, a_height); 
	FuncLogEnd(item);
}

void GLTrace_glGetRenderbufferParameteriv(FPglGetRenderbufferParameteriv proc, GLenum a_target, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetRenderbufferParameteriv", fileName, lineNum);
	proc(a_target, a_pname, a_params); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsFramebuffer(FPglIsFramebuffer proc, GLuint a_framebuffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsFramebuffer", fileName, lineNum);
	auto ret = proc(a_framebuffer); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glBindFramebuffer(FPglBindFramebuffer proc, GLenum a_target, GLuint a_framebuffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindFramebuffer", fileName, lineNum);
	proc(a_target, a_framebuffer); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteFramebuffers(FPglDeleteFramebuffers proc, GLsizei a_n, const GLuint * a_framebuffers, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteFramebuffers", fileName, lineNum);
	proc(a_n, a_framebuffers); 
	FuncLogEnd(item);
}

void GLTrace_glGenFramebuffers(FPglGenFramebuffers proc, GLsizei a_n, GLuint * a_framebuffers, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenFramebuffers", fileName, lineNum);
	proc(a_n, a_framebuffers); 
	FuncLogEnd(item);
}

GLenum GLTrace_glCheckFramebufferStatus(FPglCheckFramebufferStatus proc, GLenum a_target, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCheckFramebufferStatus", fileName, lineNum);
	auto ret = proc(a_target); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glFramebufferTexture1D(FPglFramebufferTexture1D proc, GLenum a_target, GLenum a_attachment, GLenum a_textarget, GLuint a_texture, GLint a_level, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFramebufferTexture1D", fileName, lineNum);
	proc(a_target, a_attachment, a_textarget, a_texture, a_level); 
	FuncLogEnd(item);
}

void GLTrace_glFramebufferTexture2D(FPglFramebufferTexture2D proc, GLenum a_target, GLenum a_attachment, GLenum a_textarget, GLuint a_texture, GLint a_level, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFramebufferTexture2D", fileName, lineNum);
	proc(a_target, a_attachment, a_textarget, a_texture, a_level); 
	FuncLogEnd(item);
}

void GLTrace_glFramebufferTexture3D(FPglFramebufferTexture3D proc, GLenum a_target, GLenum a_attachment, GLenum a_textarget, GLuint a_texture, GLint a_level, GLint a_zoffset, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFramebufferTexture3D", fileName, lineNum);
	proc(a_target, a_attachment, a_textarget, a_texture, a_level, a_zoffset); 
	FuncLogEnd(item);
}

void GLTrace_glFramebufferRenderbuffer(FPglFramebufferRenderbuffer proc, GLenum a_target, GLenum a_attachment, GLenum a_renderbuffertarget, GLuint a_renderbuffer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFramebufferRenderbuffer", fileName, lineNum);
	proc(a_target, a_attachment, a_renderbuffertarget, a_renderbuffer); 
	FuncLogEnd(item);
}

void GLTrace_glGetFramebufferAttachmentParameteriv(FPglGetFramebufferAttachmentParameteriv proc, GLenum a_target, GLenum a_attachment, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetFramebufferAttachmentParameteriv", fileName, lineNum);
	proc(a_target, a_attachment, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGenerateMipmap(FPglGenerateMipmap proc, GLenum a_target, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenerateMipmap", fileName, lineNum);
	proc(a_target); 
	FuncLogEnd(item);
}

void GLTrace_glBlitFramebuffer(FPglBlitFramebuffer proc, GLint a_srcX0, GLint a_srcY0, GLint a_srcX1, GLint a_srcY1, GLint a_dstX0, GLint a_dstY0, GLint a_dstX1, GLint a_dstY1, GLbitfield a_mask, GLenum a_filter, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlitFramebuffer", fileName, lineNum);
	proc(a_srcX0, a_srcY0, a_srcX1, a_srcY1, a_dstX0, a_dstY0, a_dstX1, a_dstY1, a_mask, a_filter); 
	FuncLogEnd(item);
}

void GLTrace_glRenderbufferStorageMultisample(FPglRenderbufferStorageMultisample proc, GLenum a_target, GLsizei a_samples, GLenum a_internalformat, GLsizei a_width, GLsizei a_height, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glRenderbufferStorageMultisample", fileName, lineNum);
	proc(a_target, a_samples, a_internalformat, a_width, a_height); 
	FuncLogEnd(item);
}

void GLTrace_glFramebufferTextureLayer(FPglFramebufferTextureLayer proc, GLenum a_target, GLenum a_attachment, GLuint a_texture, GLint a_level, GLint a_layer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFramebufferTextureLayer", fileName, lineNum);
	proc(a_target, a_attachment, a_texture, a_level, a_layer); 
	FuncLogEnd(item);
}

GLvoid*  GLTrace_glMapBufferRange(FPglMapBufferRange proc, GLenum a_target, GLintptr a_offset, GLsizeiptr a_length, GLbitfield a_access, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMapBufferRange", fileName, lineNum);
	auto ret = proc(a_target, a_offset, a_length, a_access); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glFlushMappedBufferRange(FPglFlushMappedBufferRange proc, GLenum a_target, GLintptr a_offset, GLsizeiptr a_length, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFlushMappedBufferRange", fileName, lineNum);
	proc(a_target, a_offset, a_length); 
	FuncLogEnd(item);
}

void GLTrace_glBindVertexArray(FPglBindVertexArray proc, GLuint a_array, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindVertexArray", fileName, lineNum);
	proc(a_array); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteVertexArrays(FPglDeleteVertexArrays proc, GLsizei a_n, const GLuint * a_arrays, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteVertexArrays", fileName, lineNum);
	proc(a_n, a_arrays); 
	FuncLogEnd(item);
}

void GLTrace_glGenVertexArrays(FPglGenVertexArrays proc, GLsizei a_n, GLuint * a_arrays, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenVertexArrays", fileName, lineNum);
	proc(a_n, a_arrays); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsVertexArray(FPglIsVertexArray proc, GLuint a_array, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsVertexArray", fileName, lineNum);
	auto ret = proc(a_array); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetUniformIndices(FPglGetUniformIndices proc, GLuint a_program, GLsizei a_uniformCount, const GLchar* * a_uniformNames, GLuint * a_uniformIndices, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetUniformIndices", fileName, lineNum);
	proc(a_program, a_uniformCount, a_uniformNames, a_uniformIndices); 
	FuncLogEnd(item);
}

void GLTrace_glGetActiveUniformsiv(FPglGetActiveUniformsiv proc, GLuint a_program, GLsizei a_uniformCount, const GLuint * a_uniformIndices, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetActiveUniformsiv", fileName, lineNum);
	proc(a_program, a_uniformCount, a_uniformIndices, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetActiveUniformName(FPglGetActiveUniformName proc, GLuint a_program, GLuint a_uniformIndex, GLsizei a_bufSize, GLsizei * a_length, GLchar * a_uniformName, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetActiveUniformName", fileName, lineNum);
	proc(a_program, a_uniformIndex, a_bufSize, a_length, a_uniformName); 
	FuncLogEnd(item);
}

GLuint GLTrace_glGetUniformBlockIndex(FPglGetUniformBlockIndex proc, GLuint a_program, const GLchar * a_uniformBlockName, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetUniformBlockIndex", fileName, lineNum);
	auto ret = proc(a_program, a_uniformBlockName); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetActiveUniformBlockiv(FPglGetActiveUniformBlockiv proc, GLuint a_program, GLuint a_uniformBlockIndex, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetActiveUniformBlockiv", fileName, lineNum);
	proc(a_program, a_uniformBlockIndex, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetActiveUniformBlockName(FPglGetActiveUniformBlockName proc, GLuint a_program, GLuint a_uniformBlockIndex, GLsizei a_bufSize, GLsizei * a_length, GLchar * a_uniformBlockName, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetActiveUniformBlockName", fileName, lineNum);
	proc(a_program, a_uniformBlockIndex, a_bufSize, a_length, a_uniformBlockName); 
	FuncLogEnd(item);
}

void GLTrace_glUniformBlockBinding(FPglUniformBlockBinding proc, GLuint a_program, GLuint a_uniformBlockIndex, GLuint a_uniformBlockBinding, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformBlockBinding", fileName, lineNum);
	proc(a_program, a_uniformBlockIndex, a_uniformBlockBinding); 
	FuncLogEnd(item);
}

void GLTrace_glCopyBufferSubData(FPglCopyBufferSubData proc, GLenum a_readTarget, GLenum a_writeTarget, GLintptr a_readOffset, GLintptr a_writeOffset, GLsizeiptr a_size, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCopyBufferSubData", fileName, lineNum);
	proc(a_readTarget, a_writeTarget, a_readOffset, a_writeOffset, a_size); 
	FuncLogEnd(item);
}

void GLTrace_glDrawElementsBaseVertex(FPglDrawElementsBaseVertex proc, GLenum a_mode, GLsizei a_count, GLenum a_type, const GLvoid * a_indices, GLint a_basevertex, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawElementsBaseVertex", fileName, lineNum);
	proc(a_mode, a_count, a_type, a_indices, a_basevertex); 
	FuncLogEnd(item);
}

void GLTrace_glDrawRangeElementsBaseVertex(FPglDrawRangeElementsBaseVertex proc, GLenum a_mode, GLuint a_start, GLuint a_end, GLsizei a_count, GLenum a_type, const GLvoid * a_indices, GLint a_basevertex, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawRangeElementsBaseVertex", fileName, lineNum);
	proc(a_mode, a_start, a_end, a_count, a_type, a_indices, a_basevertex); 
	FuncLogEnd(item);
}

void GLTrace_glDrawElementsInstancedBaseVertex(FPglDrawElementsInstancedBaseVertex proc, GLenum a_mode, GLsizei a_count, GLenum a_type, const GLvoid * a_indices, GLsizei a_primcount, GLint a_basevertex, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawElementsInstancedBaseVertex", fileName, lineNum);
	proc(a_mode, a_count, a_type, a_indices, a_primcount, a_basevertex); 
	FuncLogEnd(item);
}

void GLTrace_glMultiDrawElementsBaseVertex(FPglMultiDrawElementsBaseVertex proc, GLenum a_mode, const GLsizei * a_count, GLenum a_type, const GLvoid* * a_indices, GLsizei a_primcount, const GLint * a_basevertex, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiDrawElementsBaseVertex", fileName, lineNum);
	proc(a_mode, a_count, a_type, a_indices, a_primcount, a_basevertex); 
	FuncLogEnd(item);
}

void GLTrace_glProvokingVertex(FPglProvokingVertex proc, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProvokingVertex", fileName, lineNum);
	proc(a_mode); 
	FuncLogEnd(item);
}

GLsync GLTrace_glFenceSync(FPglFenceSync proc, GLenum a_condition, GLbitfield a_flags, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glFenceSync", fileName, lineNum);
	auto ret = proc(a_condition, a_flags); 
	FuncLogEnd(item);
	return ret;
}

GLboolean GLTrace_glIsSync(FPglIsSync proc, GLsync a_sync, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsSync", fileName, lineNum);
	auto ret = proc(a_sync); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glDeleteSync(FPglDeleteSync proc, GLsync a_sync, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteSync", fileName, lineNum);
	proc(a_sync); 
	FuncLogEnd(item);
}

GLenum GLTrace_glClientWaitSync(FPglClientWaitSync proc, GLsync a_sync, GLbitfield a_flags, GLuint64 a_timeout, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClientWaitSync", fileName, lineNum);
	auto ret = proc(a_sync, a_flags, a_timeout); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glWaitSync(FPglWaitSync proc, GLsync a_sync, GLbitfield a_flags, GLuint64 a_timeout, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glWaitSync", fileName, lineNum);
	proc(a_sync, a_flags, a_timeout); 
	FuncLogEnd(item);
}

void GLTrace_glGetInteger64v(FPglGetInteger64v proc, GLenum a_pname, GLint64 * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetInteger64v", fileName, lineNum);
	proc(a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetSynciv(FPglGetSynciv proc, GLsync a_sync, GLenum a_pname, GLsizei a_bufSize, GLsizei * a_length, GLint * a_values, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetSynciv", fileName, lineNum);
	proc(a_sync, a_pname, a_bufSize, a_length, a_values); 
	FuncLogEnd(item);
}

void GLTrace_glTexImage2DMultisample(FPglTexImage2DMultisample proc, GLenum a_target, GLsizei a_samples, GLint a_internalformat, GLsizei a_width, GLsizei a_height, GLboolean a_fixedsamplelocations, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexImage2DMultisample", fileName, lineNum);
	proc(a_target, a_samples, a_internalformat, a_width, a_height, a_fixedsamplelocations); 
	FuncLogEnd(item);
}

void GLTrace_glTexImage3DMultisample(FPglTexImage3DMultisample proc, GLenum a_target, GLsizei a_samples, GLint a_internalformat, GLsizei a_width, GLsizei a_height, GLsizei a_depth, GLboolean a_fixedsamplelocations, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexImage3DMultisample", fileName, lineNum);
	proc(a_target, a_samples, a_internalformat, a_width, a_height, a_depth, a_fixedsamplelocations); 
	FuncLogEnd(item);
}

void GLTrace_glGetMultisamplefv(FPglGetMultisamplefv proc, GLenum a_pname, GLuint a_index, GLfloat * a_val, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetMultisamplefv", fileName, lineNum);
	proc(a_pname, a_index, a_val); 
	FuncLogEnd(item);
}

void GLTrace_glSampleMaski(FPglSampleMaski proc, GLuint a_index, GLbitfield a_mask, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSampleMaski", fileName, lineNum);
	proc(a_index, a_mask); 
	FuncLogEnd(item);
}

void GLTrace_glBlendEquationiARB(FPglBlendEquationiARB proc, GLuint a_buf, GLenum a_mode, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendEquationiARB", fileName, lineNum);
	proc(a_buf, a_mode); 
	FuncLogEnd(item);
}

void GLTrace_glBlendEquationSeparateiARB(FPglBlendEquationSeparateiARB proc, GLuint a_buf, GLenum a_modeRGB, GLenum a_modeAlpha, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendEquationSeparateiARB", fileName, lineNum);
	proc(a_buf, a_modeRGB, a_modeAlpha); 
	FuncLogEnd(item);
}

void GLTrace_glBlendFunciARB(FPglBlendFunciARB proc, GLuint a_buf, GLenum a_src, GLenum a_dst, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendFunciARB", fileName, lineNum);
	proc(a_buf, a_src, a_dst); 
	FuncLogEnd(item);
}

void GLTrace_glBlendFuncSeparateiARB(FPglBlendFuncSeparateiARB proc, GLuint a_buf, GLenum a_srcRGB, GLenum a_dstRGB, GLenum a_srcAlpha, GLenum a_dstAlpha, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBlendFuncSeparateiARB", fileName, lineNum);
	proc(a_buf, a_srcRGB, a_dstRGB, a_srcAlpha, a_dstAlpha); 
	FuncLogEnd(item);
}

void GLTrace_glMinSampleShadingARB(FPglMinSampleShadingARB proc, GLclampf a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMinSampleShadingARB", fileName, lineNum);
	proc(a_value); 
	FuncLogEnd(item);
}

void GLTrace_glNamedStringARB(FPglNamedStringARB proc, GLenum a_type, GLint a_namelen, const GLchar * a_name, GLint a_stringlen, const GLchar * a_string, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glNamedStringARB", fileName, lineNum);
	proc(a_type, a_namelen, a_name, a_stringlen, a_string); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteNamedStringARB(FPglDeleteNamedStringARB proc, GLint a_namelen, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteNamedStringARB", fileName, lineNum);
	proc(a_namelen, a_name); 
	FuncLogEnd(item);
}

void GLTrace_glCompileShaderIncludeARB(FPglCompileShaderIncludeARB proc, GLuint a_shader, GLsizei a_count, const GLchar* * a_path, const GLint * a_length, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCompileShaderIncludeARB", fileName, lineNum);
	proc(a_shader, a_count, a_path, a_length); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsNamedStringARB(FPglIsNamedStringARB proc, GLint a_namelen, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsNamedStringARB", fileName, lineNum);
	auto ret = proc(a_namelen, a_name); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetNamedStringARB(FPglGetNamedStringARB proc, GLint a_namelen, const GLchar * a_name, GLsizei a_bufSize, GLint * a_stringlen, GLchar * a_string, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetNamedStringARB", fileName, lineNum);
	proc(a_namelen, a_name, a_bufSize, a_stringlen, a_string); 
	FuncLogEnd(item);
}

void GLTrace_glGetNamedStringivARB(FPglGetNamedStringivARB proc, GLint a_namelen, const GLchar * a_name, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetNamedStringivARB", fileName, lineNum);
	proc(a_namelen, a_name, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glBindFragDataLocationIndexed(FPglBindFragDataLocationIndexed proc, GLuint a_program, GLuint a_colorNumber, GLuint a_index, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindFragDataLocationIndexed", fileName, lineNum);
	proc(a_program, a_colorNumber, a_index, a_name); 
	FuncLogEnd(item);
}

GLint GLTrace_glGetFragDataIndex(FPglGetFragDataIndex proc, GLuint a_program, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetFragDataIndex", fileName, lineNum);
	auto ret = proc(a_program, a_name); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGenSamplers(FPglGenSamplers proc, GLsizei a_count, GLuint * a_samplers, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenSamplers", fileName, lineNum);
	proc(a_count, a_samplers); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteSamplers(FPglDeleteSamplers proc, GLsizei a_count, const GLuint * a_samplers, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteSamplers", fileName, lineNum);
	proc(a_count, a_samplers); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsSampler(FPglIsSampler proc, GLuint a_sampler, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsSampler", fileName, lineNum);
	auto ret = proc(a_sampler); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glBindSampler(FPglBindSampler proc, GLuint a_unit, GLuint a_sampler, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindSampler", fileName, lineNum);
	proc(a_unit, a_sampler); 
	FuncLogEnd(item);
}

void GLTrace_glSamplerParameteri(FPglSamplerParameteri proc, GLuint a_sampler, GLenum a_pname, GLint a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSamplerParameteri", fileName, lineNum);
	proc(a_sampler, a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glSamplerParameteriv(FPglSamplerParameteriv proc, GLuint a_sampler, GLenum a_pname, const GLint * a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSamplerParameteriv", fileName, lineNum);
	proc(a_sampler, a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glSamplerParameterf(FPglSamplerParameterf proc, GLuint a_sampler, GLenum a_pname, GLfloat a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSamplerParameterf", fileName, lineNum);
	proc(a_sampler, a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glSamplerParameterfv(FPglSamplerParameterfv proc, GLuint a_sampler, GLenum a_pname, const GLfloat * a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSamplerParameterfv", fileName, lineNum);
	proc(a_sampler, a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glSamplerParameterIiv(FPglSamplerParameterIiv proc, GLuint a_sampler, GLenum a_pname, const GLint * a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSamplerParameterIiv", fileName, lineNum);
	proc(a_sampler, a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glSamplerParameterIuiv(FPglSamplerParameterIuiv proc, GLuint a_sampler, GLenum a_pname, const GLuint * a_param, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSamplerParameterIuiv", fileName, lineNum);
	proc(a_sampler, a_pname, a_param); 
	FuncLogEnd(item);
}

void GLTrace_glGetSamplerParameteriv(FPglGetSamplerParameteriv proc, GLuint a_sampler, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetSamplerParameteriv", fileName, lineNum);
	proc(a_sampler, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetSamplerParameterIiv(FPglGetSamplerParameterIiv proc, GLuint a_sampler, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetSamplerParameterIiv", fileName, lineNum);
	proc(a_sampler, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetSamplerParameterfv(FPglGetSamplerParameterfv proc, GLuint a_sampler, GLenum a_pname, GLfloat * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetSamplerParameterfv", fileName, lineNum);
	proc(a_sampler, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetSamplerParameterIuiv(FPglGetSamplerParameterIuiv proc, GLuint a_sampler, GLenum a_pname, GLuint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetSamplerParameterIuiv", fileName, lineNum);
	proc(a_sampler, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glQueryCounter(FPglQueryCounter proc, GLuint a_id, GLenum a_target, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glQueryCounter", fileName, lineNum);
	proc(a_id, a_target); 
	FuncLogEnd(item);
}

void GLTrace_glGetQueryObjecti64v(FPglGetQueryObjecti64v proc, GLuint a_id, GLenum a_pname, GLint64 * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetQueryObjecti64v", fileName, lineNum);
	proc(a_id, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetQueryObjectui64v(FPglGetQueryObjectui64v proc, GLuint a_id, GLenum a_pname, GLuint64 * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetQueryObjectui64v", fileName, lineNum);
	proc(a_id, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glVertexP2ui(FPglVertexP2ui proc, GLenum a_type, GLuint a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexP2ui", fileName, lineNum);
	proc(a_type, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexP2uiv(FPglVertexP2uiv proc, GLenum a_type, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexP2uiv", fileName, lineNum);
	proc(a_type, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexP3ui(FPglVertexP3ui proc, GLenum a_type, GLuint a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexP3ui", fileName, lineNum);
	proc(a_type, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexP3uiv(FPglVertexP3uiv proc, GLenum a_type, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexP3uiv", fileName, lineNum);
	proc(a_type, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexP4ui(FPglVertexP4ui proc, GLenum a_type, GLuint a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexP4ui", fileName, lineNum);
	proc(a_type, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexP4uiv(FPglVertexP4uiv proc, GLenum a_type, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexP4uiv", fileName, lineNum);
	proc(a_type, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glTexCoordP1ui(FPglTexCoordP1ui proc, GLenum a_type, GLuint a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexCoordP1ui", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glTexCoordP1uiv(FPglTexCoordP1uiv proc, GLenum a_type, const GLuint * a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexCoordP1uiv", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glTexCoordP2ui(FPglTexCoordP2ui proc, GLenum a_type, GLuint a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexCoordP2ui", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glTexCoordP2uiv(FPglTexCoordP2uiv proc, GLenum a_type, const GLuint * a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexCoordP2uiv", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glTexCoordP3ui(FPglTexCoordP3ui proc, GLenum a_type, GLuint a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexCoordP3ui", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glTexCoordP3uiv(FPglTexCoordP3uiv proc, GLenum a_type, const GLuint * a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexCoordP3uiv", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glTexCoordP4ui(FPglTexCoordP4ui proc, GLenum a_type, GLuint a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexCoordP4ui", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glTexCoordP4uiv(FPglTexCoordP4uiv proc, GLenum a_type, const GLuint * a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glTexCoordP4uiv", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glMultiTexCoordP1ui(FPglMultiTexCoordP1ui proc, GLenum a_texture, GLenum a_type, GLuint a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiTexCoordP1ui", fileName, lineNum);
	proc(a_texture, a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glMultiTexCoordP1uiv(FPglMultiTexCoordP1uiv proc, GLenum a_texture, GLenum a_type, const GLuint * a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiTexCoordP1uiv", fileName, lineNum);
	proc(a_texture, a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glMultiTexCoordP2ui(FPglMultiTexCoordP2ui proc, GLenum a_texture, GLenum a_type, GLuint a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiTexCoordP2ui", fileName, lineNum);
	proc(a_texture, a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glMultiTexCoordP2uiv(FPglMultiTexCoordP2uiv proc, GLenum a_texture, GLenum a_type, const GLuint * a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiTexCoordP2uiv", fileName, lineNum);
	proc(a_texture, a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glMultiTexCoordP3ui(FPglMultiTexCoordP3ui proc, GLenum a_texture, GLenum a_type, GLuint a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiTexCoordP3ui", fileName, lineNum);
	proc(a_texture, a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glMultiTexCoordP3uiv(FPglMultiTexCoordP3uiv proc, GLenum a_texture, GLenum a_type, const GLuint * a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiTexCoordP3uiv", fileName, lineNum);
	proc(a_texture, a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glMultiTexCoordP4ui(FPglMultiTexCoordP4ui proc, GLenum a_texture, GLenum a_type, GLuint a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiTexCoordP4ui", fileName, lineNum);
	proc(a_texture, a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glMultiTexCoordP4uiv(FPglMultiTexCoordP4uiv proc, GLenum a_texture, GLenum a_type, const GLuint * a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glMultiTexCoordP4uiv", fileName, lineNum);
	proc(a_texture, a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glNormalP3ui(FPglNormalP3ui proc, GLenum a_type, GLuint a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glNormalP3ui", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glNormalP3uiv(FPglNormalP3uiv proc, GLenum a_type, const GLuint * a_coords, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glNormalP3uiv", fileName, lineNum);
	proc(a_type, a_coords); 
	FuncLogEnd(item);
}

void GLTrace_glColorP3ui(FPglColorP3ui proc, GLenum a_type, GLuint a_color, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glColorP3ui", fileName, lineNum);
	proc(a_type, a_color); 
	FuncLogEnd(item);
}

void GLTrace_glColorP3uiv(FPglColorP3uiv proc, GLenum a_type, const GLuint * a_color, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glColorP3uiv", fileName, lineNum);
	proc(a_type, a_color); 
	FuncLogEnd(item);
}

void GLTrace_glColorP4ui(FPglColorP4ui proc, GLenum a_type, GLuint a_color, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glColorP4ui", fileName, lineNum);
	proc(a_type, a_color); 
	FuncLogEnd(item);
}

void GLTrace_glColorP4uiv(FPglColorP4uiv proc, GLenum a_type, const GLuint * a_color, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glColorP4uiv", fileName, lineNum);
	proc(a_type, a_color); 
	FuncLogEnd(item);
}

void GLTrace_glSecondaryColorP3ui(FPglSecondaryColorP3ui proc, GLenum a_type, GLuint a_color, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSecondaryColorP3ui", fileName, lineNum);
	proc(a_type, a_color); 
	FuncLogEnd(item);
}

void GLTrace_glSecondaryColorP3uiv(FPglSecondaryColorP3uiv proc, GLenum a_type, const GLuint * a_color, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glSecondaryColorP3uiv", fileName, lineNum);
	proc(a_type, a_color); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribP1ui(FPglVertexAttribP1ui proc, GLuint a_index, GLenum a_type, GLboolean a_normalized, GLuint a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribP1ui", fileName, lineNum);
	proc(a_index, a_type, a_normalized, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribP1uiv(FPglVertexAttribP1uiv proc, GLuint a_index, GLenum a_type, GLboolean a_normalized, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribP1uiv", fileName, lineNum);
	proc(a_index, a_type, a_normalized, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribP2ui(FPglVertexAttribP2ui proc, GLuint a_index, GLenum a_type, GLboolean a_normalized, GLuint a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribP2ui", fileName, lineNum);
	proc(a_index, a_type, a_normalized, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribP2uiv(FPglVertexAttribP2uiv proc, GLuint a_index, GLenum a_type, GLboolean a_normalized, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribP2uiv", fileName, lineNum);
	proc(a_index, a_type, a_normalized, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribP3ui(FPglVertexAttribP3ui proc, GLuint a_index, GLenum a_type, GLboolean a_normalized, GLuint a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribP3ui", fileName, lineNum);
	proc(a_index, a_type, a_normalized, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribP3uiv(FPglVertexAttribP3uiv proc, GLuint a_index, GLenum a_type, GLboolean a_normalized, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribP3uiv", fileName, lineNum);
	proc(a_index, a_type, a_normalized, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribP4ui(FPglVertexAttribP4ui proc, GLuint a_index, GLenum a_type, GLboolean a_normalized, GLuint a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribP4ui", fileName, lineNum);
	proc(a_index, a_type, a_normalized, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribP4uiv(FPglVertexAttribP4uiv proc, GLuint a_index, GLenum a_type, GLboolean a_normalized, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribP4uiv", fileName, lineNum);
	proc(a_index, a_type, a_normalized, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glDrawArraysIndirect(FPglDrawArraysIndirect proc, GLenum a_mode, const GLvoid * a_indirect, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawArraysIndirect", fileName, lineNum);
	proc(a_mode, a_indirect); 
	FuncLogEnd(item);
}

void GLTrace_glDrawElementsIndirect(FPglDrawElementsIndirect proc, GLenum a_mode, GLenum a_type, const GLvoid * a_indirect, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawElementsIndirect", fileName, lineNum);
	proc(a_mode, a_type, a_indirect); 
	FuncLogEnd(item);
}

void GLTrace_glUniform1d(FPglUniform1d proc, GLint a_location, GLdouble a_x, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform1d", fileName, lineNum);
	proc(a_location, a_x); 
	FuncLogEnd(item);
}

void GLTrace_glUniform2d(FPglUniform2d proc, GLint a_location, GLdouble a_x, GLdouble a_y, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform2d", fileName, lineNum);
	proc(a_location, a_x, a_y); 
	FuncLogEnd(item);
}

void GLTrace_glUniform3d(FPglUniform3d proc, GLint a_location, GLdouble a_x, GLdouble a_y, GLdouble a_z, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform3d", fileName, lineNum);
	proc(a_location, a_x, a_y, a_z); 
	FuncLogEnd(item);
}

void GLTrace_glUniform4d(FPglUniform4d proc, GLint a_location, GLdouble a_x, GLdouble a_y, GLdouble a_z, GLdouble a_w, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform4d", fileName, lineNum);
	proc(a_location, a_x, a_y, a_z, a_w); 
	FuncLogEnd(item);
}

void GLTrace_glUniform1dv(FPglUniform1dv proc, GLint a_location, GLsizei a_count, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform1dv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform2dv(FPglUniform2dv proc, GLint a_location, GLsizei a_count, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform2dv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform3dv(FPglUniform3dv proc, GLint a_location, GLsizei a_count, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform3dv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniform4dv(FPglUniform4dv proc, GLint a_location, GLsizei a_count, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniform4dv", fileName, lineNum);
	proc(a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix2dv(FPglUniformMatrix2dv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix2dv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix3dv(FPglUniformMatrix3dv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix3dv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix4dv(FPglUniformMatrix4dv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix4dv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix2x3dv(FPglUniformMatrix2x3dv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix2x3dv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix2x4dv(FPglUniformMatrix2x4dv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix2x4dv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix3x2dv(FPglUniformMatrix3x2dv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix3x2dv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix3x4dv(FPglUniformMatrix3x4dv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix3x4dv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix4x2dv(FPglUniformMatrix4x2dv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix4x2dv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUniformMatrix4x3dv(FPglUniformMatrix4x3dv proc, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformMatrix4x3dv", fileName, lineNum);
	proc(a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glGetUniformdv(FPglGetUniformdv proc, GLuint a_program, GLint a_location, GLdouble * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetUniformdv", fileName, lineNum);
	proc(a_program, a_location, a_params); 
	FuncLogEnd(item);
}

GLint GLTrace_glGetSubroutineUniformLocation(FPglGetSubroutineUniformLocation proc, GLuint a_program, GLenum a_shadertype, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetSubroutineUniformLocation", fileName, lineNum);
	auto ret = proc(a_program, a_shadertype, a_name); 
	FuncLogEnd(item);
	return ret;
}

GLuint GLTrace_glGetSubroutineIndex(FPglGetSubroutineIndex proc, GLuint a_program, GLenum a_shadertype, const GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetSubroutineIndex", fileName, lineNum);
	auto ret = proc(a_program, a_shadertype, a_name); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetActiveSubroutineUniformiv(FPglGetActiveSubroutineUniformiv proc, GLuint a_program, GLenum a_shadertype, GLuint a_index, GLenum a_pname, GLint * a_values, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetActiveSubroutineUniformiv", fileName, lineNum);
	proc(a_program, a_shadertype, a_index, a_pname, a_values); 
	FuncLogEnd(item);
}

void GLTrace_glGetActiveSubroutineUniformName(FPglGetActiveSubroutineUniformName proc, GLuint a_program, GLenum a_shadertype, GLuint a_index, GLsizei a_bufsize, GLsizei * a_length, GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetActiveSubroutineUniformName", fileName, lineNum);
	proc(a_program, a_shadertype, a_index, a_bufsize, a_length, a_name); 
	FuncLogEnd(item);
}

void GLTrace_glGetActiveSubroutineName(FPglGetActiveSubroutineName proc, GLuint a_program, GLenum a_shadertype, GLuint a_index, GLsizei a_bufsize, GLsizei * a_length, GLchar * a_name, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetActiveSubroutineName", fileName, lineNum);
	proc(a_program, a_shadertype, a_index, a_bufsize, a_length, a_name); 
	FuncLogEnd(item);
}

void GLTrace_glUniformSubroutinesuiv(FPglUniformSubroutinesuiv proc, GLenum a_shadertype, GLsizei a_count, const GLuint * a_indices, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUniformSubroutinesuiv", fileName, lineNum);
	proc(a_shadertype, a_count, a_indices); 
	FuncLogEnd(item);
}

void GLTrace_glGetUniformSubroutineuiv(FPglGetUniformSubroutineuiv proc, GLenum a_shadertype, GLint a_location, GLuint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetUniformSubroutineuiv", fileName, lineNum);
	proc(a_shadertype, a_location, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetProgramStageiv(FPglGetProgramStageiv proc, GLuint a_program, GLenum a_shadertype, GLenum a_pname, GLint * a_values, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetProgramStageiv", fileName, lineNum);
	proc(a_program, a_shadertype, a_pname, a_values); 
	FuncLogEnd(item);
}

void GLTrace_glPatchParameteri(FPglPatchParameteri proc, GLenum a_pname, GLint a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPatchParameteri", fileName, lineNum);
	proc(a_pname, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glPatchParameterfv(FPglPatchParameterfv proc, GLenum a_pname, const GLfloat * a_values, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPatchParameterfv", fileName, lineNum);
	proc(a_pname, a_values); 
	FuncLogEnd(item);
}

void GLTrace_glBindTransformFeedback(FPglBindTransformFeedback proc, GLenum a_target, GLuint a_id, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindTransformFeedback", fileName, lineNum);
	proc(a_target, a_id); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteTransformFeedbacks(FPglDeleteTransformFeedbacks proc, GLsizei a_n, const GLuint * a_ids, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteTransformFeedbacks", fileName, lineNum);
	proc(a_n, a_ids); 
	FuncLogEnd(item);
}

void GLTrace_glGenTransformFeedbacks(FPglGenTransformFeedbacks proc, GLsizei a_n, GLuint * a_ids, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenTransformFeedbacks", fileName, lineNum);
	proc(a_n, a_ids); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsTransformFeedback(FPglIsTransformFeedback proc, GLuint a_id, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsTransformFeedback", fileName, lineNum);
	auto ret = proc(a_id); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glPauseTransformFeedback(FPglPauseTransformFeedback proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glPauseTransformFeedback", fileName, lineNum);
	proc(); 
	FuncLogEnd(item);
}

void GLTrace_glResumeTransformFeedback(FPglResumeTransformFeedback proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glResumeTransformFeedback", fileName, lineNum);
	proc(); 
	FuncLogEnd(item);
}

void GLTrace_glDrawTransformFeedback(FPglDrawTransformFeedback proc, GLenum a_mode, GLuint a_id, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawTransformFeedback", fileName, lineNum);
	proc(a_mode, a_id); 
	FuncLogEnd(item);
}

void GLTrace_glDrawTransformFeedbackStream(FPglDrawTransformFeedbackStream proc, GLenum a_mode, GLuint a_id, GLuint a_stream, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDrawTransformFeedbackStream", fileName, lineNum);
	proc(a_mode, a_id, a_stream); 
	FuncLogEnd(item);
}

void GLTrace_glBeginQueryIndexed(FPglBeginQueryIndexed proc, GLenum a_target, GLuint a_index, GLuint a_id, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBeginQueryIndexed", fileName, lineNum);
	proc(a_target, a_index, a_id); 
	FuncLogEnd(item);
}

void GLTrace_glEndQueryIndexed(FPglEndQueryIndexed proc, GLenum a_target, GLuint a_index, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glEndQueryIndexed", fileName, lineNum);
	proc(a_target, a_index); 
	FuncLogEnd(item);
}

void GLTrace_glGetQueryIndexediv(FPglGetQueryIndexediv proc, GLenum a_target, GLuint a_index, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetQueryIndexediv", fileName, lineNum);
	proc(a_target, a_index, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glReleaseShaderCompiler(FPglReleaseShaderCompiler proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glReleaseShaderCompiler", fileName, lineNum);
	proc(); 
	FuncLogEnd(item);
}

void GLTrace_glShaderBinary(FPglShaderBinary proc, GLsizei a_count, const GLuint * a_shaders, GLenum a_binaryformat, const GLvoid * a_binary, GLsizei a_length, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glShaderBinary", fileName, lineNum);
	proc(a_count, a_shaders, a_binaryformat, a_binary, a_length); 
	FuncLogEnd(item);
}

void GLTrace_glGetShaderPrecisionFormat(FPglGetShaderPrecisionFormat proc, GLenum a_shadertype, GLenum a_precisiontype, GLint * a_range, GLint * a_precision, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetShaderPrecisionFormat", fileName, lineNum);
	proc(a_shadertype, a_precisiontype, a_range, a_precision); 
	FuncLogEnd(item);
}

void GLTrace_glDepthRangef(FPglDepthRangef proc, GLclampf a_n, GLclampf a_f, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDepthRangef", fileName, lineNum);
	proc(a_n, a_f); 
	FuncLogEnd(item);
}

void GLTrace_glClearDepthf(FPglClearDepthf proc, GLclampf a_d, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glClearDepthf", fileName, lineNum);
	proc(a_d); 
	FuncLogEnd(item);
}

void GLTrace_glGetProgramBinary(FPglGetProgramBinary proc, GLuint a_program, GLsizei a_bufSize, GLsizei * a_length, GLenum * a_binaryFormat, GLvoid * a_binary, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetProgramBinary", fileName, lineNum);
	proc(a_program, a_bufSize, a_length, a_binaryFormat, a_binary); 
	FuncLogEnd(item);
}

void GLTrace_glProgramBinary(FPglProgramBinary proc, GLuint a_program, GLenum a_binaryFormat, const GLvoid * a_binary, GLsizei a_length, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramBinary", fileName, lineNum);
	proc(a_program, a_binaryFormat, a_binary, a_length); 
	FuncLogEnd(item);
}

void GLTrace_glProgramParameteri(FPglProgramParameteri proc, GLuint a_program, GLenum a_pname, GLint a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramParameteri", fileName, lineNum);
	proc(a_program, a_pname, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glUseProgramStages(FPglUseProgramStages proc, GLuint a_pipeline, GLbitfield a_stages, GLuint a_program, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glUseProgramStages", fileName, lineNum);
	proc(a_pipeline, a_stages, a_program); 
	FuncLogEnd(item);
}

void GLTrace_glActiveShaderProgram(FPglActiveShaderProgram proc, GLuint a_pipeline, GLuint a_program, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glActiveShaderProgram", fileName, lineNum);
	proc(a_pipeline, a_program); 
	FuncLogEnd(item);
}

GLuint GLTrace_glCreateShaderProgramv(FPglCreateShaderProgramv proc, GLenum a_type, GLsizei a_count, const GLchar* * a_strings, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glCreateShaderProgramv", fileName, lineNum);
	auto ret = proc(a_type, a_count, a_strings); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glBindProgramPipeline(FPglBindProgramPipeline proc, GLuint a_pipeline, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glBindProgramPipeline", fileName, lineNum);
	proc(a_pipeline); 
	FuncLogEnd(item);
}

void GLTrace_glDeleteProgramPipelines(FPglDeleteProgramPipelines proc, GLsizei a_n, const GLuint * a_pipelines, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDeleteProgramPipelines", fileName, lineNum);
	proc(a_n, a_pipelines); 
	FuncLogEnd(item);
}

void GLTrace_glGenProgramPipelines(FPglGenProgramPipelines proc, GLsizei a_n, GLuint * a_pipelines, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGenProgramPipelines", fileName, lineNum);
	proc(a_n, a_pipelines); 
	FuncLogEnd(item);
}

GLboolean GLTrace_glIsProgramPipeline(FPglIsProgramPipeline proc, GLuint a_pipeline, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glIsProgramPipeline", fileName, lineNum);
	auto ret = proc(a_pipeline); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetProgramPipelineiv(FPglGetProgramPipelineiv proc, GLuint a_pipeline, GLenum a_pname, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetProgramPipelineiv", fileName, lineNum);
	proc(a_pipeline, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform1i(FPglProgramUniform1i proc, GLuint a_program, GLint a_location, GLint a_v0, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform1i", fileName, lineNum);
	proc(a_program, a_location, a_v0); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform1iv(FPglProgramUniform1iv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform1iv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform1f(FPglProgramUniform1f proc, GLuint a_program, GLint a_location, GLfloat a_v0, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform1f", fileName, lineNum);
	proc(a_program, a_location, a_v0); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform1fv(FPglProgramUniform1fv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform1fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform1d(FPglProgramUniform1d proc, GLuint a_program, GLint a_location, GLdouble a_v0, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform1d", fileName, lineNum);
	proc(a_program, a_location, a_v0); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform1dv(FPglProgramUniform1dv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform1dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform1ui(FPglProgramUniform1ui proc, GLuint a_program, GLint a_location, GLuint a_v0, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform1ui", fileName, lineNum);
	proc(a_program, a_location, a_v0); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform1uiv(FPglProgramUniform1uiv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform1uiv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform2i(FPglProgramUniform2i proc, GLuint a_program, GLint a_location, GLint a_v0, GLint a_v1, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform2i", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform2iv(FPglProgramUniform2iv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform2iv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform2f(FPglProgramUniform2f proc, GLuint a_program, GLint a_location, GLfloat a_v0, GLfloat a_v1, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform2f", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform2fv(FPglProgramUniform2fv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform2fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform2d(FPglProgramUniform2d proc, GLuint a_program, GLint a_location, GLdouble a_v0, GLdouble a_v1, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform2d", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform2dv(FPglProgramUniform2dv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform2dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform2ui(FPglProgramUniform2ui proc, GLuint a_program, GLint a_location, GLuint a_v0, GLuint a_v1, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform2ui", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform2uiv(FPglProgramUniform2uiv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform2uiv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform3i(FPglProgramUniform3i proc, GLuint a_program, GLint a_location, GLint a_v0, GLint a_v1, GLint a_v2, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform3i", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1, a_v2); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform3iv(FPglProgramUniform3iv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform3iv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform3f(FPglProgramUniform3f proc, GLuint a_program, GLint a_location, GLfloat a_v0, GLfloat a_v1, GLfloat a_v2, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform3f", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1, a_v2); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform3fv(FPglProgramUniform3fv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform3fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform3d(FPglProgramUniform3d proc, GLuint a_program, GLint a_location, GLdouble a_v0, GLdouble a_v1, GLdouble a_v2, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform3d", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1, a_v2); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform3dv(FPglProgramUniform3dv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform3dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform3ui(FPglProgramUniform3ui proc, GLuint a_program, GLint a_location, GLuint a_v0, GLuint a_v1, GLuint a_v2, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform3ui", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1, a_v2); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform3uiv(FPglProgramUniform3uiv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform3uiv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform4i(FPglProgramUniform4i proc, GLuint a_program, GLint a_location, GLint a_v0, GLint a_v1, GLint a_v2, GLint a_v3, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform4i", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1, a_v2, a_v3); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform4iv(FPglProgramUniform4iv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform4iv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform4f(FPglProgramUniform4f proc, GLuint a_program, GLint a_location, GLfloat a_v0, GLfloat a_v1, GLfloat a_v2, GLfloat a_v3, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform4f", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1, a_v2, a_v3); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform4fv(FPglProgramUniform4fv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform4fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform4d(FPglProgramUniform4d proc, GLuint a_program, GLint a_location, GLdouble a_v0, GLdouble a_v1, GLdouble a_v2, GLdouble a_v3, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform4d", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1, a_v2, a_v3); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform4dv(FPglProgramUniform4dv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform4dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform4ui(FPglProgramUniform4ui proc, GLuint a_program, GLint a_location, GLuint a_v0, GLuint a_v1, GLuint a_v2, GLuint a_v3, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform4ui", fileName, lineNum);
	proc(a_program, a_location, a_v0, a_v1, a_v2, a_v3); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniform4uiv(FPglProgramUniform4uiv proc, GLuint a_program, GLint a_location, GLsizei a_count, const GLuint * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniform4uiv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix2fv(FPglProgramUniformMatrix2fv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix2fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix3fv(FPglProgramUniformMatrix3fv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix3fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix4fv(FPglProgramUniformMatrix4fv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix4fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix2dv(FPglProgramUniformMatrix2dv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix2dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix3dv(FPglProgramUniformMatrix3dv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix3dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix4dv(FPglProgramUniformMatrix4dv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix4dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix2x3fv(FPglProgramUniformMatrix2x3fv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix2x3fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix3x2fv(FPglProgramUniformMatrix3x2fv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix3x2fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix2x4fv(FPglProgramUniformMatrix2x4fv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix2x4fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix4x2fv(FPglProgramUniformMatrix4x2fv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix4x2fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix3x4fv(FPglProgramUniformMatrix3x4fv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix3x4fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix4x3fv(FPglProgramUniformMatrix4x3fv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLfloat * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix4x3fv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix2x3dv(FPglProgramUniformMatrix2x3dv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix2x3dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix3x2dv(FPglProgramUniformMatrix3x2dv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix3x2dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix2x4dv(FPglProgramUniformMatrix2x4dv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix2x4dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix4x2dv(FPglProgramUniformMatrix4x2dv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix4x2dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix3x4dv(FPglProgramUniformMatrix3x4dv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix3x4dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glProgramUniformMatrix4x3dv(FPglProgramUniformMatrix4x3dv proc, GLuint a_program, GLint a_location, GLsizei a_count, GLboolean a_transpose, const GLdouble * a_value, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glProgramUniformMatrix4x3dv", fileName, lineNum);
	proc(a_program, a_location, a_count, a_transpose, a_value); 
	FuncLogEnd(item);
}

void GLTrace_glValidateProgramPipeline(FPglValidateProgramPipeline proc, GLuint a_pipeline, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glValidateProgramPipeline", fileName, lineNum);
	proc(a_pipeline); 
	FuncLogEnd(item);
}

void GLTrace_glGetProgramPipelineInfoLog(FPglGetProgramPipelineInfoLog proc, GLuint a_pipeline, GLsizei a_bufSize, GLsizei * a_length, GLchar * a_infoLog, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetProgramPipelineInfoLog", fileName, lineNum);
	proc(a_pipeline, a_bufSize, a_length, a_infoLog); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribL1d(FPglVertexAttribL1d proc, GLuint a_index, GLdouble a_x, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribL1d", fileName, lineNum);
	proc(a_index, a_x); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribL2d(FPglVertexAttribL2d proc, GLuint a_index, GLdouble a_x, GLdouble a_y, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribL2d", fileName, lineNum);
	proc(a_index, a_x, a_y); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribL3d(FPglVertexAttribL3d proc, GLuint a_index, GLdouble a_x, GLdouble a_y, GLdouble a_z, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribL3d", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribL4d(FPglVertexAttribL4d proc, GLuint a_index, GLdouble a_x, GLdouble a_y, GLdouble a_z, GLdouble a_w, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribL4d", fileName, lineNum);
	proc(a_index, a_x, a_y, a_z, a_w); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribL1dv(FPglVertexAttribL1dv proc, GLuint a_index, const GLdouble * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribL1dv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribL2dv(FPglVertexAttribL2dv proc, GLuint a_index, const GLdouble * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribL2dv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribL3dv(FPglVertexAttribL3dv proc, GLuint a_index, const GLdouble * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribL3dv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribL4dv(FPglVertexAttribL4dv proc, GLuint a_index, const GLdouble * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribL4dv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glVertexAttribLPointer(FPglVertexAttribLPointer proc, GLuint a_index, GLint a_size, GLenum a_type, GLsizei a_stride, const GLvoid * a_pointer, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glVertexAttribLPointer", fileName, lineNum);
	proc(a_index, a_size, a_type, a_stride, a_pointer); 
	FuncLogEnd(item);
}

void GLTrace_glGetVertexAttribLdv(FPglGetVertexAttribLdv proc, GLuint a_index, GLenum a_pname, GLdouble * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetVertexAttribLdv", fileName, lineNum);
	proc(a_index, a_pname, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glViewportArrayv(FPglViewportArrayv proc, GLuint a_first, GLsizei a_count, const GLfloat * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glViewportArrayv", fileName, lineNum);
	proc(a_first, a_count, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glViewportIndexedf(FPglViewportIndexedf proc, GLuint a_index, GLfloat a_x, GLfloat a_y, GLfloat a_w, GLfloat a_h, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glViewportIndexedf", fileName, lineNum);
	proc(a_index, a_x, a_y, a_w, a_h); 
	FuncLogEnd(item);
}

void GLTrace_glViewportIndexedfv(FPglViewportIndexedfv proc, GLuint a_index, const GLfloat * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glViewportIndexedfv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glScissorArrayv(FPglScissorArrayv proc, GLuint a_first, GLsizei a_count, const GLint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glScissorArrayv", fileName, lineNum);
	proc(a_first, a_count, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glScissorIndexed(FPglScissorIndexed proc, GLuint a_index, GLint a_left, GLint a_bottom, GLsizei a_width, GLsizei a_height, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glScissorIndexed", fileName, lineNum);
	proc(a_index, a_left, a_bottom, a_width, a_height); 
	FuncLogEnd(item);
}

void GLTrace_glScissorIndexedv(FPglScissorIndexedv proc, GLuint a_index, const GLint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glScissorIndexedv", fileName, lineNum);
	proc(a_index, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glDepthRangeArrayv(FPglDepthRangeArrayv proc, GLuint a_first, GLsizei a_count, const GLclampd * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDepthRangeArrayv", fileName, lineNum);
	proc(a_first, a_count, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glDepthRangeIndexed(FPglDepthRangeIndexed proc, GLuint a_index, GLclampd a_n, GLclampd a_f, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDepthRangeIndexed", fileName, lineNum);
	proc(a_index, a_n, a_f); 
	FuncLogEnd(item);
}

void GLTrace_glGetFloati_v(FPglGetFloati_v proc, GLenum a_target, GLuint a_index, GLfloat * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetFloati_v", fileName, lineNum);
	proc(a_target, a_index, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glGetDoublei_v(FPglGetDoublei_v proc, GLenum a_target, GLuint a_index, GLdouble * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetDoublei_v", fileName, lineNum);
	proc(a_target, a_index, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glDebugMessageControlARB(FPglDebugMessageControlARB proc, GLenum a_source, GLenum a_type, GLenum a_severity, GLsizei a_count, const GLuint * a_ids, GLboolean a_enabled, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDebugMessageControlARB", fileName, lineNum);
	proc(a_source, a_type, a_severity, a_count, a_ids, a_enabled); 
	FuncLogEnd(item);
}

void GLTrace_glDebugMessageInsertARB(FPglDebugMessageInsertARB proc, GLenum a_source, GLenum a_type, GLuint a_id, GLenum a_severity, GLsizei a_length, const GLchar * a_buf, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDebugMessageInsertARB", fileName, lineNum);
	proc(a_source, a_type, a_id, a_severity, a_length, a_buf); 
	FuncLogEnd(item);
}

void GLTrace_glDebugMessageCallbackARB(FPglDebugMessageCallbackARB proc, GLDEBUGPROCARB a_callback, const GLvoid * a_userParam, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glDebugMessageCallbackARB", fileName, lineNum);
	proc(a_callback, a_userParam); 
	FuncLogEnd(item);
}

GLuint GLTrace_glGetDebugMessageLogARB(FPglGetDebugMessageLogARB proc, GLuint a_count, GLsizei a_bufsize, GLenum * a_sources, GLenum * a_types, GLuint * a_ids, GLenum * a_severities, GLsizei * a_lengths, GLchar * a_messageLog, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetDebugMessageLogARB", fileName, lineNum);
	auto ret = proc(a_count, a_bufsize, a_sources, a_types, a_ids, a_severities, a_lengths, a_messageLog); 
	FuncLogEnd(item);
	return ret;
}

GLenum GLTrace_glGetGraphicsResetStatusARB(FPglGetGraphicsResetStatusARB proc, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetGraphicsResetStatusARB", fileName, lineNum);
	auto ret = proc(); 
	FuncLogEnd(item);
	return ret;
}

void GLTrace_glGetnMapdvARB(FPglGetnMapdvARB proc, GLenum a_target, GLenum a_query, GLsizei a_bufSize, GLdouble * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnMapdvARB", fileName, lineNum);
	proc(a_target, a_query, a_bufSize, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glGetnMapfvARB(FPglGetnMapfvARB proc, GLenum a_target, GLenum a_query, GLsizei a_bufSize, GLfloat * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnMapfvARB", fileName, lineNum);
	proc(a_target, a_query, a_bufSize, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glGetnMapivARB(FPglGetnMapivARB proc, GLenum a_target, GLenum a_query, GLsizei a_bufSize, GLint * a_v, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnMapivARB", fileName, lineNum);
	proc(a_target, a_query, a_bufSize, a_v); 
	FuncLogEnd(item);
}

void GLTrace_glGetnPixelMapfvARB(FPglGetnPixelMapfvARB proc, GLenum a_map, GLsizei a_bufSize, GLfloat * a_values, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnPixelMapfvARB", fileName, lineNum);
	proc(a_map, a_bufSize, a_values); 
	FuncLogEnd(item);
}

void GLTrace_glGetnPixelMapuivARB(FPglGetnPixelMapuivARB proc, GLenum a_map, GLsizei a_bufSize, GLuint * a_values, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnPixelMapuivARB", fileName, lineNum);
	proc(a_map, a_bufSize, a_values); 
	FuncLogEnd(item);
}

void GLTrace_glGetnPixelMapusvARB(FPglGetnPixelMapusvARB proc, GLenum a_map, GLsizei a_bufSize, GLushort * a_values, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnPixelMapusvARB", fileName, lineNum);
	proc(a_map, a_bufSize, a_values); 
	FuncLogEnd(item);
}

void GLTrace_glGetnPolygonStippleARB(FPglGetnPolygonStippleARB proc, GLsizei a_bufSize, GLubyte * a_pattern, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnPolygonStippleARB", fileName, lineNum);
	proc(a_bufSize, a_pattern); 
	FuncLogEnd(item);
}

void GLTrace_glGetnColorTableARB(FPglGetnColorTableARB proc, GLenum a_target, GLenum a_format, GLenum a_type, GLsizei a_bufSize, GLvoid * a_table, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnColorTableARB", fileName, lineNum);
	proc(a_target, a_format, a_type, a_bufSize, a_table); 
	FuncLogEnd(item);
}

void GLTrace_glGetnConvolutionFilterARB(FPglGetnConvolutionFilterARB proc, GLenum a_target, GLenum a_format, GLenum a_type, GLsizei a_bufSize, GLvoid * a_image, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnConvolutionFilterARB", fileName, lineNum);
	proc(a_target, a_format, a_type, a_bufSize, a_image); 
	FuncLogEnd(item);
}

void GLTrace_glGetnSeparableFilterARB(FPglGetnSeparableFilterARB proc, GLenum a_target, GLenum a_format, GLenum a_type, GLsizei a_rowBufSize, GLvoid * a_row, GLsizei a_columnBufSize, GLvoid * a_column, GLvoid * a_span, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnSeparableFilterARB", fileName, lineNum);
	proc(a_target, a_format, a_type, a_rowBufSize, a_row, a_columnBufSize, a_column, a_span); 
	FuncLogEnd(item);
}

void GLTrace_glGetnHistogramARB(FPglGetnHistogramARB proc, GLenum a_target, GLboolean a_reset, GLenum a_format, GLenum a_type, GLsizei a_bufSize, GLvoid * a_values, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnHistogramARB", fileName, lineNum);
	proc(a_target, a_reset, a_format, a_type, a_bufSize, a_values); 
	FuncLogEnd(item);
}

void GLTrace_glGetnMinmaxARB(FPglGetnMinmaxARB proc, GLenum a_target, GLboolean a_reset, GLenum a_format, GLenum a_type, GLsizei a_bufSize, GLvoid * a_values, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnMinmaxARB", fileName, lineNum);
	proc(a_target, a_reset, a_format, a_type, a_bufSize, a_values); 
	FuncLogEnd(item);
}

void GLTrace_glGetnTexImageARB(FPglGetnTexImageARB proc, GLenum a_target, GLint a_level, GLenum a_format, GLenum a_type, GLsizei a_bufSize, GLvoid * a_img, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnTexImageARB", fileName, lineNum);
	proc(a_target, a_level, a_format, a_type, a_bufSize, a_img); 
	FuncLogEnd(item);
}

void GLTrace_glReadnPixelsARB(FPglReadnPixelsARB proc, GLint a_x, GLint a_y, GLsizei a_width, GLsizei a_height, GLenum a_format, GLenum a_type, GLsizei a_bufSize, GLvoid * a_data, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glReadnPixelsARB", fileName, lineNum);
	proc(a_x, a_y, a_width, a_height, a_format, a_type, a_bufSize, a_data); 
	FuncLogEnd(item);
}

void GLTrace_glGetnCompressedTexImageARB(FPglGetnCompressedTexImageARB proc, GLenum a_target, GLint a_lod, GLsizei a_bufSize, GLvoid * a_img, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnCompressedTexImageARB", fileName, lineNum);
	proc(a_target, a_lod, a_bufSize, a_img); 
	FuncLogEnd(item);
}

void GLTrace_glGetnUniformfvARB(FPglGetnUniformfvARB proc, GLuint a_program, GLint a_location, GLsizei a_bufSize, GLfloat * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnUniformfvARB", fileName, lineNum);
	proc(a_program, a_location, a_bufSize, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetnUniformivARB(FPglGetnUniformivARB proc, GLuint a_program, GLint a_location, GLsizei a_bufSize, GLint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnUniformivARB", fileName, lineNum);
	proc(a_program, a_location, a_bufSize, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetnUniformuivARB(FPglGetnUniformuivARB proc, GLuint a_program, GLint a_location, GLsizei a_bufSize, GLuint * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnUniformuivARB", fileName, lineNum);
	proc(a_program, a_location, a_bufSize, a_params); 
	FuncLogEnd(item);
}

void GLTrace_glGetnUniformdvARB(FPglGetnUniformdvARB proc, GLuint a_program, GLint a_location, GLsizei a_bufSize, GLdouble * a_params, const char* fileName, unsigned int lineNum)
{
	LogItem* item = FuncLogStart("glGetnUniformdvARB", fileName, lineNum);
	proc(a_program, a_location, a_bufSize, a_params); 
	FuncLogEnd(item);
}


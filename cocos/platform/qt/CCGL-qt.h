/****************************************************************************
Copyright (c) 2020 Alexandra Cherdantseva

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#pragma once

#include "platform/CCPlatformConfig.h"

#if defined(CC_USE_QT_OPENGL) || (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)

#ifndef CC_USE_QT_OPENGL
#define CC_USE_QT_OPENGL
#endif

#include <QOpenGLContext>
#include <QOpenGLFunctions>

#define CC_QT_OPENGL_FUNCTIONS QOpenGLContext::currentContext()->functions()

namespace cocos2d
{

inline void glEnable(GLenum cap)
{
	CC_QT_OPENGL_FUNCTIONS->glEnable(cap);
}

inline const GLubyte *glGetString(GLenum name)
{
 return CC_QT_OPENGL_FUNCTIONS->glGetString(name);
}

inline void glActiveTexture(GLenum texture)
{
	CC_QT_OPENGL_FUNCTIONS->glActiveTexture(texture);
}

inline void glAttachShader(GLuint program, GLuint shader)
{
	CC_QT_OPENGL_FUNCTIONS->glAttachShader(program, shader);
}

inline void glBindAttribLocation(GLuint program, GLuint index, const char *name)
{
	CC_QT_OPENGL_FUNCTIONS->glBindAttribLocation(program, index, name);
}

inline void glBindBuffer(GLenum target, GLuint buffer)
{
	CC_QT_OPENGL_FUNCTIONS->glBindBuffer(target, buffer);
}

inline void glBindFramebuffer(GLenum target, GLuint framebuffer)
{
	CC_QT_OPENGL_FUNCTIONS->glBindFramebuffer(target, framebuffer);
}

inline void glBindRenderbuffer(GLenum target, GLuint renderbuffer)
{
	CC_QT_OPENGL_FUNCTIONS->glBindRenderbuffer(target, renderbuffer);
}

inline void glBlendColor(GLclampf red, GLclampf green, GLclampf blue, GLclampf alpha)
{
	CC_QT_OPENGL_FUNCTIONS->glBlendColor(red, green, blue, alpha);
}

inline void glBlendEquation(GLenum mode)
{
	CC_QT_OPENGL_FUNCTIONS->glBlendEquation(mode);
}

inline void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha)
{
	CC_QT_OPENGL_FUNCTIONS->glBlendEquationSeparate(modeRGB, modeAlpha);
}

inline void glBlendFuncSeparate(GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha)
{
	CC_QT_OPENGL_FUNCTIONS->glBlendFuncSeparate(srcRGB, dstRGB, srcAlpha, dstAlpha);
}

inline void glBufferData(GLenum target, qopengl_GLsizeiptr size, const void *data, GLenum usage)
{
	CC_QT_OPENGL_FUNCTIONS->glBufferData(target, size, data, usage);
}

inline void glBufferSubData(GLenum target, qopengl_GLintptr offset, qopengl_GLsizeiptr size, const void *data)
{
	CC_QT_OPENGL_FUNCTIONS->glBufferSubData(target, offset, size, data);
}

inline GLenum glCheckFramebufferStatus(GLenum target)
{
	return CC_QT_OPENGL_FUNCTIONS->glCheckFramebufferStatus(target);
}

inline void glClearDepthf(GLclampf depth)
{
	CC_QT_OPENGL_FUNCTIONS->glClearDepthf(depth);
}

inline void glCompileShader(GLuint shader)
{
	CC_QT_OPENGL_FUNCTIONS->glCompileShader(shader);
}

inline void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void *data)
{
	CC_QT_OPENGL_FUNCTIONS->glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

inline void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void *data)
{
	CC_QT_OPENGL_FUNCTIONS->glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

inline GLuint glCreateProgram()
{
	return CC_QT_OPENGL_FUNCTIONS->glCreateProgram();
}

inline GLuint glCreateShader(GLenum type)
{
	return CC_QT_OPENGL_FUNCTIONS->glCreateShader(type);
}

inline void glDeleteBuffers(GLsizei n, const GLuint *buffers)
{
	CC_QT_OPENGL_FUNCTIONS->glDeleteBuffers(n, buffers);
}

inline void glDeleteFramebuffers(GLsizei n, const GLuint *framebuffers)
{
	CC_QT_OPENGL_FUNCTIONS->glDeleteFramebuffers(n, framebuffers);
}

inline void glDeleteProgram(GLuint program)
{
	CC_QT_OPENGL_FUNCTIONS->glDeleteProgram(program);
}

inline void glDeleteRenderbuffers(GLsizei n, const GLuint *renderbuffers)
{
	CC_QT_OPENGL_FUNCTIONS->glDeleteRenderbuffers(n, renderbuffers);
}

inline void glDeleteShader(GLuint shader)
{
	CC_QT_OPENGL_FUNCTIONS->glDeleteShader(shader);
}

inline void glDepthRangef(GLclampf zNear, GLclampf zFar)
{
	CC_QT_OPENGL_FUNCTIONS->glDepthRangef(zNear, zFar);
}

inline void glDetachShader(GLuint program, GLuint shader)
{
	CC_QT_OPENGL_FUNCTIONS->glDetachShader(program, shader);
}

inline void glDisableVertexAttribArray(GLuint index)
{
	CC_QT_OPENGL_FUNCTIONS->glDisableVertexAttribArray(index);
}

inline void glEnableVertexAttribArray(GLuint index)
{
	CC_QT_OPENGL_FUNCTIONS->glEnableVertexAttribArray(index);
}

inline void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer)
{
	CC_QT_OPENGL_FUNCTIONS->glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

inline void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level)
{
	CC_QT_OPENGL_FUNCTIONS->glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

inline void glGenBuffers(GLsizei n, GLuint *buffers)
{
	CC_QT_OPENGL_FUNCTIONS->glGenBuffers(n, buffers);
}

inline void glGenerateMipmap(GLenum target)
{
	CC_QT_OPENGL_FUNCTIONS->glGenerateMipmap(target);
}

inline void glGenFramebuffers(GLsizei n, GLuint *framebuffers)
{
	CC_QT_OPENGL_FUNCTIONS->glGenFramebuffers(n, framebuffers);
}

inline void glGenRenderbuffers(GLsizei n, GLuint *renderbuffers)
{
	CC_QT_OPENGL_FUNCTIONS->glGenRenderbuffers(n, renderbuffers);
}

inline void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, char *name)
{
	CC_QT_OPENGL_FUNCTIONS->glGetActiveAttrib(program, index, bufsize, length, size, type, name);
}

inline void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufsize, GLsizei *length, GLint *size, GLenum *type, char *name)
{
	CC_QT_OPENGL_FUNCTIONS->glGetActiveUniform(program, index, bufsize, length, size, type, name);
}

inline void glGetAttachedShaders(GLuint program, GLsizei maxcount, GLsizei *count, GLuint *shaders)
{
	CC_QT_OPENGL_FUNCTIONS->glGetAttachedShaders(program, maxcount, count, shaders);
}

inline void glGetAttribLocation(GLuint program, const char *name)
{
	CC_QT_OPENGL_FUNCTIONS->glGetAttribLocation(program, name);
}

inline void glGetBufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
	CC_QT_OPENGL_FUNCTIONS->glGetBufferParameteriv(target, pname, params);
}

inline void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint *params)
{
	CC_QT_OPENGL_FUNCTIONS->glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

inline void glGetProgramiv(GLuint program, GLenum pname, GLint *params)
{
	CC_QT_OPENGL_FUNCTIONS->glGetProgramiv(program, pname, params);
}

inline void glGetProgramInfoLog(GLuint program, GLsizei bufsize, GLsizei *length, char *infolog)
{
	CC_QT_OPENGL_FUNCTIONS->glGetProgramInfoLog(program, bufsize, length, infolog);
}

inline void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint *params)
{
	CC_QT_OPENGL_FUNCTIONS->glGetRenderbufferParameteriv(target, pname, params);
}

inline void glGetShaderiv(GLuint shader, GLenum pname, GLint *params)
{
	CC_QT_OPENGL_FUNCTIONS->glGetShaderiv(shader, pname, params);
}

inline void glGetShaderInfoLog(GLuint shader, GLsizei bufsize, GLsizei *length, char *infolog)
{
	CC_QT_OPENGL_FUNCTIONS->glGetShaderInfoLog(shader, bufsize, length, infolog);
}

inline void glGetShaderPrecisionFormat(GLenum shadertype, GLenum precisiontype, GLint *range, GLint *precision)
{
	CC_QT_OPENGL_FUNCTIONS->glGetShaderPrecisionFormat(shadertype, precisiontype, range, precision);
}

inline void glGetShaderSource(GLuint shader, GLsizei bufsize, GLsizei *length, char *source)
{
	CC_QT_OPENGL_FUNCTIONS->glGetShaderSource(shader, bufsize, length, source);
}

inline void glGetUniformfv(GLuint program, GLint location, GLfloat *params)
{
	CC_QT_OPENGL_FUNCTIONS->glGetUniformfv(program, location, params);
}

inline void glGetUniformiv(GLuint program, GLint location, GLint *params)
{
	CC_QT_OPENGL_FUNCTIONS->glGetUniformiv(program, location, params);
}

inline GLint glGetUniformLocation(GLuint program, const char *name)
{
	return CC_QT_OPENGL_FUNCTIONS->glGetUniformLocation(program, name);
}

inline void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat *params)
{
	CC_QT_OPENGL_FUNCTIONS->glGetVertexAttribfv(index, pname, params);
}

inline void glGetVertexAttribiv(GLuint index, GLenum pname, GLint *params)
{
	CC_QT_OPENGL_FUNCTIONS->glGetVertexAttribiv(index, pname, params);
}

inline void glGetVertexAttribPointerv(GLuint index, GLenum pname, void **pointer)
{
	CC_QT_OPENGL_FUNCTIONS->glGetVertexAttribPointerv(index, pname, pointer);
}

inline GLboolean glIsBuffer(GLuint buffer)
{
	return CC_QT_OPENGL_FUNCTIONS->glIsBuffer(buffer);
}

inline GLboolean glIsFramebuffer(GLuint framebuffer)
{
	return CC_QT_OPENGL_FUNCTIONS->glIsFramebuffer(framebuffer);
}

inline GLboolean glIsProgram(GLuint program)
{
	return CC_QT_OPENGL_FUNCTIONS->glIsProgram(program);
}

inline GLboolean glIsRenderbuffer(GLuint renderbuffer)
{
	return CC_QT_OPENGL_FUNCTIONS->glIsRenderbuffer(renderbuffer);
}

inline GLboolean glIsShader(GLuint shader)
{
	return CC_QT_OPENGL_FUNCTIONS->glIsShader(shader);
}

inline void glLinkProgram(GLuint program)
{
	CC_QT_OPENGL_FUNCTIONS->glLinkProgram(program);
}

inline void glReleaseShaderCompiler()
{
	CC_QT_OPENGL_FUNCTIONS->glReleaseShaderCompiler();
}

inline void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height)
{
	CC_QT_OPENGL_FUNCTIONS->glRenderbufferStorage(target, internalformat, width, height);
}

inline void glSampleCoverage(GLclampf value, GLboolean invert)
{
	CC_QT_OPENGL_FUNCTIONS->glSampleCoverage(value, invert);
}

inline void glShaderBinary(GLint n, const GLuint *shaders, GLenum binaryformat, const void *binary, GLint length)
{
	CC_QT_OPENGL_FUNCTIONS->glShaderBinary(n, shaders, binaryformat, binary, length);
}

inline void glShaderSource(GLuint shader, GLsizei count, const char **string, const GLint *length)
{
	CC_QT_OPENGL_FUNCTIONS->glShaderSource(shader, count, string, length);
}

inline void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask)
{
	CC_QT_OPENGL_FUNCTIONS->glStencilFuncSeparate(face, func, ref, mask);
}

inline void glStencilMaskSeparate(GLenum face, GLuint mask)
{
	CC_QT_OPENGL_FUNCTIONS->glStencilMaskSeparate(face, mask);
}

inline void glStencilOpSeparate(GLenum face, GLenum fail, GLenum zfail, GLenum zpass)
{
	CC_QT_OPENGL_FUNCTIONS->glStencilOpSeparate(face, fail, zfail, zpass);
}

inline void glUniform1f(GLint location, GLfloat x)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform1f(location, x);
}

inline void glUniform1fv(GLint location, GLsizei count, const GLfloat *v)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform1fv(location, count, v);
}

inline void glUniform1i(GLint location, GLint x)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform1i(location, x);
}

inline void glUniform1iv(GLint location, GLsizei count, const GLint *v)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform1iv(location, count, v);
}

inline void glUniform2f(GLint location, GLfloat x, GLfloat y)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform2f(location, x, y);
}

inline void glUniform2fv(GLint location, GLsizei count, const GLfloat *v)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform2fv(location, count, v);
}

inline void glUniform2i(GLint location, GLint x, GLint y)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform2i(location, x, y);
}

inline void glUniform2iv(GLint location, GLsizei count, const GLint *v)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform2iv(location, count, v);
}

inline void glUniform3f(GLint location, GLfloat x, GLfloat y, GLfloat z)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform3f(location, x, y, z);
}

inline void glUniform3fv(GLint location, GLsizei count, const GLfloat *v)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform3fv(location, count, v);
}

inline void glUniform3i(GLint location, GLint x, GLint y, GLint z)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform3i(location, x, y, z);
}

inline void glUniform3iv(GLint location, GLsizei count, const GLint *v)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform3iv(location, count, v);
}

inline void glUniform4f(GLint location, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform4f(location, x, y, z, w);
}

inline void glUniform4fv(GLint location, GLsizei count, const GLfloat *v)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform4fv(location, count, v);
}

inline void glUniform4i(GLint location, GLint x, GLint y, GLint z, GLint w)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform4i(location, x, y, z, w);
}

inline void glUniform4iv(GLint location, GLsizei count, const GLint *v)
{
	CC_QT_OPENGL_FUNCTIONS->glUniform4iv(location, count, v);
}

inline void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	CC_QT_OPENGL_FUNCTIONS->glUniformMatrix2fv(location, count, transpose, value);
}

inline void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	CC_QT_OPENGL_FUNCTIONS->glUniformMatrix3fv(location, count, transpose, value);
}

inline void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat *value)
{
	CC_QT_OPENGL_FUNCTIONS->glUniformMatrix4fv(location, count, transpose, value);
}

inline void glUseProgram(GLuint program)
{
	CC_QT_OPENGL_FUNCTIONS->glUseProgram(program);
}

inline void glValidateProgram(GLuint program)
{
	CC_QT_OPENGL_FUNCTIONS->glValidateProgram(program);
}

inline void glVertexAttrib1f(GLuint indx, GLfloat x)
{
	CC_QT_OPENGL_FUNCTIONS->glVertexAttrib1f(indx, x);
}

inline void glVertexAttrib1fv(GLuint indx, const GLfloat *values)
{
	CC_QT_OPENGL_FUNCTIONS->glVertexAttrib1fv(indx, values);
}

inline void glVertexAttrib2f(GLuint indx, GLfloat x, GLfloat y)
{
	CC_QT_OPENGL_FUNCTIONS->glVertexAttrib2f(indx, x, y);
}

inline void glVertexAttrib2fv(GLuint indx, const GLfloat *values)
{
	CC_QT_OPENGL_FUNCTIONS->glVertexAttrib2fv(indx, values);
}

inline void glVertexAttrib3f(GLuint indx, GLfloat x, GLfloat y, GLfloat z)
{
	CC_QT_OPENGL_FUNCTIONS->glVertexAttrib3f(indx, x, y, z);
}

inline void glVertexAttrib3fv(GLuint indx, const GLfloat *values)
{
	CC_QT_OPENGL_FUNCTIONS->glVertexAttrib3fv(indx, values);
}

inline void glVertexAttrib4f(GLuint indx, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	CC_QT_OPENGL_FUNCTIONS->glVertexAttrib4f(indx, x, y, z, w);
}

inline void glVertexAttrib4fv(GLuint indx, const GLfloat *values)
{
	CC_QT_OPENGL_FUNCTIONS->glVertexAttrib4fv(indx, values);
}

inline void glVertexAttribPointer(GLuint indx, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void *ptr)
{
	CC_QT_OPENGL_FUNCTIONS->glVertexAttribPointer(indx, size, type, normalized, stride, ptr);
}

}

#else

#if CC_TARGET_PLATFORM == CC_PLATFORM_EMSCRIPTEN
#include "platform/emscripten/CCGL-emscripten.h"
#elif CC_TARGET_PLATFORM == CC_PLATFORM_MAC
#include "platform/mac/CCGL-mac.h"
#endif

#endif

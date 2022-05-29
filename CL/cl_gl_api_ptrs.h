/*******************************************************************************
 * Copyright (c) 2008-2020 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#ifndef OPENCL_CL_GL_API_PTRS_H_
#define OPENCL_CL_GL_API_PTRS_H_

#include <CL/cl_gl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef cl_mem (CL_API_CALL *cl_api_clCreateFromGLBuffer)(
    cl_context context,
    cl_mem_flags flags,
    cl_GLuint bufobj,
    int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef cl_mem (CL_API_CALL *cl_api_clCreateFromGLTexture)(
    cl_context    context,
    cl_mem_flags  flags,
    cl_GLenum     target,
    cl_GLint      miplevel,
    cl_GLuint     texture,
    cl_int       *errcode_ret) CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clCreateFromGLTexture;

#endif

typedef cl_mem (CL_API_CALL *cl_api_clCreateFromGLRenderbuffer)(
    cl_context    context,
    cl_mem_flags  flags,
    cl_GLuint     renderbuffer,
    cl_int       *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int (CL_API_CALL *cl_api_clGetGLObjectInfo)(
    cl_mem             memobj,
    cl_gl_object_type *gl_object_type,
    cl_GLuint         *gl_object_name) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int (CL_API_CALL *cl_api_clGetGLTextureInfo)(
    cl_mem              memobj,
    cl_gl_texture_info  param_name,
    size_t              param_value_size,
    void               *param_value,
    size_t             *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int (CL_API_CALL *cl_api_clEnqueueAcquireGLObjects)(
    cl_command_queue  command_queue,
    cl_uint           num_objects,
    const cl_mem     *mem_objects,
    cl_uint           num_events_in_wait_list,
    const cl_event   *event_wait_list,
    cl_event         *event) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int (CL_API_CALL *cl_api_clEnqueueReleaseGLObjects)(
    cl_command_queue  command_queue,
    cl_uint           num_objects,
    const cl_mem     *mem_objects,
    cl_uint           num_events_in_wait_list,
    const cl_event   *event_wait_list,
    cl_event         *event) CL_API_SUFFIX__VERSION_1_0;

/* Deprecated OpenCL 1.1 APIs */

typedef cl_mem (CL_API_CALL *cl_api_clCreateFromGLTexture2D)(
    cl_context    context,
    cl_mem_flags  flags,
    cl_GLenum     target,
    cl_GLint      miplevel,
    cl_GLuint     texture,
    cl_int       *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_mem (CL_API_CALL *cl_api_clCreateFromGLTexture3D)(
    cl_context    context,
    cl_mem_flags  flags,
    cl_GLenum     target,
    cl_GLint      miplevel,
    cl_GLuint     texture,
    cl_int       *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

/* cl_khr_gl_sharing */

typedef cl_int (CL_API_CALL *cl_api_clGetGLContextInfoKHR)(
    const cl_context_properties *properties,
    cl_gl_context_info           param_name,
    size_t                       param_value_size,
    void                        *param_value,
    size_t                      *param_value_size_ret);

/* cl_khr_gl_event */

typedef cl_event (CL_API_CALL *cl_api_clCreateEventFromGLsyncKHR)(
    cl_context  context,
    cl_GLsync   sync,
    cl_int     *errcode_ret);

#ifdef __cplusplus
}
#endif

#endif  /* OPENCL_CL_GL_API_PTRS_H_ */

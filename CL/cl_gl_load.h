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

#ifndef OPENCL_CL_GL_LOAD_H_
#define OPENCL_CL_GL_LOAD_H_

#include <CL/opencl_load.h>
#ifdef OPENCL_LOAD

#ifdef __cplusplus
extern "C" {
#endif

CLLD_INLINE CL_API_ENTRY cl_mem CL_API_CALL
clCreateFromGLBuffer(cl_context     context,
                     cl_mem_flags   flags,
                     cl_GLuint      bufobj,
                     cl_int *       errcode_ret) {
    CLLD_FETCH_ERR(clCreateFromGLBuffer, errcode_ret);
    return CLLD_PTR(clCreateFromGLBuffer)(
        context, flags, bufobj, errcode_ret);
}

#ifdef CL_VERSION_1_2

CLLD_INLINE CL_API_ENTRY cl_mem CL_API_CALL
clCreateFromGLTexture(cl_context      context,
                      cl_mem_flags    flags,
                      cl_GLenum       target,
                      cl_GLint        miplevel,
                      cl_GLuint       texture,
                      cl_int *        errcode_ret) {
    CLLD_FETCH_ERR(clCreateFromGLTexture, errcode_ret);
    return CLLD_PTR(clCreateFromGLTexture)(
        context, flags, target, miplevel, texture, errcode_ret);
}

#endif

CLLD_INLINE CL_API_ENTRY cl_mem CL_API_CALL
clCreateFromGLRenderbuffer(cl_context   context,
                           cl_mem_flags flags,
                           cl_GLuint    renderbuffer,
                           cl_int *     errcode_ret) {
    CLLD_FETCH_ERR(clCreateFromGLRenderbuffer, errcode_ret);
    return CLLD_PTR(clCreateFromGLRenderbuffer)(
        context, flags, renderbuffer, errcode_ret);
}

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clGetGLObjectInfo(cl_mem                memobj,
                  cl_gl_object_type *   gl_object_type,
                  cl_GLuint *           gl_object_name) {
    CLLD_FETCH(clGetGLObjectInfo);
    return CLLD_PTR(clGetGLObjectInfo)(
        memobj, gl_object_type, gl_object_name);
}

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clGetGLTextureInfo(cl_mem               memobj,
                   cl_gl_texture_info   param_name,
                   size_t               param_value_size,
                   void *               param_value,
                   size_t *             param_value_size_ret) {
    CLLD_FETCH(clGetGLTextureInfo);
    return CLLD_PTR(clGetGLTextureInfo)(
        memobj, param_name, param_value_size, param_value, param_value_size_ret);
}


CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clEnqueueAcquireGLObjects(cl_command_queue      command_queue,
                          cl_uint               num_objects,
                          const cl_mem *        mem_objects,
                          cl_uint               num_events_in_wait_list,
                          const cl_event *      event_wait_list,
                          cl_event *            event) {
    CLLD_FETCH(clEnqueueAcquireGLObjects);
    return CLLD_PTR(clEnqueueAcquireGLObjects)(
        command_queue, num_objects, mem_objects,
        num_events_in_wait_list, event_wait_list, event);
}

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clEnqueueReleaseGLObjects(cl_command_queue      command_queue,
                          cl_uint               num_objects,
                          const cl_mem *        mem_objects,
                          cl_uint               num_events_in_wait_list,
                          const cl_event *      event_wait_list,
                          cl_event *            event) {
    CLLD_FETCH(clEnqueueReleaseGLObjects);
    return CLLD_PTR(clEnqueueReleaseGLObjects)(
        command_queue, num_objects, mem_objects,
        num_events_in_wait_list, event_wait_list, event);
}

/* Deprecated OpenCL 1.1 APIs */

CLLD_INLINE CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
clCreateFromGLTexture2D(cl_context      context,
                        cl_mem_flags    flags,
                        cl_GLenum       target,
                        cl_GLint        miplevel,
                        cl_GLuint       texture,
                        cl_int *        errcode_ret) {
    CLLD_FETCH_ERR(clCreateFromGLTexture2D, errcode_ret);
    return CLLD_PTR(clCreateFromGLTexture2D)(
        context, flags, target, miplevel, texture, errcode_ret);
}

CLLD_INLINE CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
clCreateFromGLTexture3D(cl_context      context,
                        cl_mem_flags    flags,
                        cl_GLenum       target,
                        cl_GLint        miplevel,
                        cl_GLuint       texture,
                        cl_int *        errcode_ret) {
    CLLD_FETCH_ERR(clCreateFromGLTexture3D, errcode_ret);
    return CLLD_PTR(clCreateFromGLTexture3D)(
        context, flags, target, miplevel, texture, errcode_ret);
}

/* cl_khr_gl_sharing extension  */

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clGetGLContextInfoKHR(const cl_context_properties * properties,
                      cl_gl_context_info            param_name,
                      size_t                        param_value_size,
                      void *                        param_value,
                      size_t *                      param_value_size_ret) {
    CLLD_FETCH(clGetGLContextInfoKHR);
    return CLLD_PTR(clGetGLContextInfoKHR)(
        properties, param_name, param_value_size, param_value, param_value_size_ret);
}

CLLD_INLINE CL_API_ENTRY cl_event CL_API_CALL
clCreateEventFromGLsyncKHR(cl_context context,
                           cl_GLsync  sync,
                           cl_int *   errcode_ret) {
    CLLD_FETCH_ERR(clCreateEventFromGLsyncKHR, errcode_ret);
    return CLLD_PTR(clCreateEventFromGLsyncKHR)(
        context, sync, errcode_ret);
}

#ifdef __cplusplus
}
#endif

#endif /* OPENCL_LOAD */

#endif  /* OPENCL_CL_GL_LOAD_H_ */

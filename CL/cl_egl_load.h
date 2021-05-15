/*******************************************************************************
 * Copyright (c) 2008-2021 The Khronos Group Inc.
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

#ifndef OPENCL_CL_EGL_LOAD_H_
#define OPENCL_CL_EGL_LOAD_H_

#include <CL/opencl_load.h>
#ifdef OPENCL_LOAD

#ifdef __cplusplus
extern "C" {
#endif

CLLD_INLINE CL_API_ENTRY cl_mem CL_API_CALL
clCreateFromEGLImageKHR(cl_context                  context,
                        CLeglDisplayKHR             egldisplay,
                        CLeglImageKHR               eglimage,
                        cl_mem_flags                flags,
                        const cl_egl_image_properties_khr * properties,
                        cl_int *                    errcode_ret) {
    CLLD_FETCH_ERR(clCreateFromEGLImageKHR, errcode_ret);
    return CLLD_PTR(clCreateFromEGLImageKHR)(
        context, egldisplay, eglimage, flags, properties, errcode_ret);
}

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clEnqueueAcquireEGLObjectsKHR(cl_command_queue command_queue,
                              cl_uint          num_objects,
                              const cl_mem *   mem_objects,
                              cl_uint          num_events_in_wait_list,
                              const cl_event * event_wait_list,
                              cl_event *       event) {
    CLLD_FETCH(clEnqueueAcquireEGLObjectsKHR);
    return CLLD_PTR(clEnqueueAcquireEGLObjectsKHR)(
        command_queue, num_objects, mem_objects,
        num_events_in_wait_list, event_wait_list, event);
}

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clEnqueueReleaseEGLObjectsKHR(cl_command_queue command_queue,
                              cl_uint          num_objects,
                              const cl_mem *   mem_objects,
                              cl_uint          num_events_in_wait_list,
                              const cl_event * event_wait_list,
                              cl_event *       event) {
    CLLD_FETCH(clEnqueueReleaseEGLObjectsKHR);
    return CLLD_PTR(clEnqueueReleaseEGLObjectsKHR)(
        command_queue, num_objects, mem_objects,
        num_events_in_wait_list, event_wait_list, event);
}

CLLD_INLINE CL_API_ENTRY cl_event CL_API_CALL
clCreateEventFromEGLSyncKHR(cl_context      context,
                            CLeglSyncKHR    sync,
                            CLeglDisplayKHR display,
                            cl_int *        errcode_ret) {
    CLLD_FETCH_ERR(clCreateEventFromEGLSyncKHR, errcode_ret);
    return CLLD_PTR(clCreateEventFromEGLSyncKHR)(
        context, sync, display, errcode_ret);
}

#ifdef __cplusplus
}
#endif

#endif /* OPENCL_LOAD */

#endif  /* OPENCL_CL_EGL_LOAD_H_ */

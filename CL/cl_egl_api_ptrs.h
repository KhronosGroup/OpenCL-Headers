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

#ifndef OPENCL_CL_EGL_API_PTRS_H_
#define OPENCL_CL_EGL_API_PTRS_H_

#include <CL/cl_egl.h>

#ifdef __cplusplus
extern "C" {
#endif

/* cl_khr_egl_image */

typedef cl_mem (CL_API_CALL *cl_api_clCreateFromEGLImageKHR)(
    cl_context                         context,
    CLeglDisplayKHR                    display,
    CLeglImageKHR                      image,
    cl_mem_flags                       flags,
    const cl_egl_image_properties_khr *properties,
    cl_int                            *errcode_ret);

typedef cl_int (CL_API_CALL *cl_api_clEnqueueAcquireEGLObjectsKHR)(
    cl_command_queue  command_queue,
    cl_uint           num_objects,
    const cl_mem     *mem_objects,
    cl_uint           num_events_in_wait_list,
    const cl_event   *event_wait_list,
    cl_event         *event);

typedef cl_int (CL_API_CALL *cl_api_clEnqueueReleaseEGLObjectsKHR)(
    cl_command_queue  command_queue,
    cl_uint           num_objects,
    const cl_mem     *mem_objects,
    cl_uint           num_events_in_wait_list,
    const cl_event   *event_wait_list,
    cl_event         *event);

/* cl_khr_egl_event */

typedef cl_event(CL_API_CALL *cl_api_clCreateEventFromEGLSyncKHR)(
    cl_context       context,
    CLeglSyncKHR     sync,
    CLeglDisplayKHR  display,
    cl_int          *errcode_ret);

#ifdef __cplusplus
}
#endif

#endif  /* OPENCL_CL_EGL_API_PTRS_H_ */

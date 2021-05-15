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

#ifndef OPENCL_CL_EXT_API_PTRS_H_
#define OPENCL_CL_EXT_API_PTRS_H_

#include <CL/cl_ext.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef CL_VERSION_2_0

typedef cl_int (CL_API_CALL *cl_api_clGetKernelSubGroupInfoKHR)(
    cl_kernel                 in_kernel,
    cl_device_id              in_device,
    cl_kernel_sub_group_info  param_name,
    size_t                    input_value_size,
    const void               *input_value,
    size_t                    param_value_size,
    void                     *param_value,
    size_t                   *param_value_size_ret) CL_API_SUFFIX__VERSION_2_0;

#else

typedef void *cl_api_clGetKernelSubGroupInfoKHR;

#endif

typedef cl_int (CL_API_CALL *cl_api_clCreateSubDevicesEXT)(
    cl_device_id                            in_device,
    const cl_device_partition_property_ext *partition_properties,
    cl_uint                                 num_entries,
    cl_device_id                           *out_devices,
    cl_uint                                *num_devices);

typedef cl_int (CL_API_CALL *cl_api_clRetainDeviceEXT)(
    cl_device_id device) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int (CL_API_CALL *cl_api_clReleaseDeviceEXT)(
    cl_device_id device) CL_API_SUFFIX__VERSION_1_0;

#ifdef __cplusplus
}
#endif

#endif  /* OPENCL_CL_EXT_API_PTRS_H_ */

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

#ifndef OPENCL_CL_EXT_LOAD_H_
#define OPENCL_CL_EXT_LOAD_H_

#include <CL/opencl_load.h>
#ifdef OPENCL_LOAD

#ifdef __cplusplus
extern "C" {
#endif

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clGetKernelSubGroupInfoKHR(cl_kernel    in_kernel,
                           cl_device_id in_device,
                           cl_kernel_sub_group_info param_name,
                           size_t       input_value_size,
                           const void * input_value,
                           size_t       param_value_size,
                           void *       param_value,
                           size_t *     param_value_size_ret) {
    CLLD_FETCH(clGetKernelSubGroupInfoKHR);
    return CLLD_PTR(clGetKernelSubGroupInfoKHR)(
        in_kernel, in_device, param_name, input_value_size, input_value,
        param_value_size, param_value, param_value_size_ret);
}

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clReleaseDeviceEXT(cl_device_id device) {
    CLLD_FETCH(clReleaseDeviceEXT);
    return CLLD_PTR(clReleaseDeviceEXT)(device);
}

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clRetainDeviceEXT(cl_device_id device) {
    CLLD_FETCH(clRetainDeviceEXT);
    return CLLD_PTR(clRetainDeviceEXT)(device);
}

CLLD_INLINE CL_API_ENTRY cl_int CL_API_CALL
clCreateSubDevicesEXT(cl_device_id   in_device,
                      const cl_device_partition_property_ext * properties,
                      cl_uint        num_entries,
                      cl_device_id * out_devices,
                      cl_uint *      num_devices) {
    CLLD_FETCH(clCreateSubDevicesEXT);
    return CLLD_PTR(clCreateSubDevicesEXT)(
        in_device, properties, num_entries, out_devices, num_devices);
}

#ifdef __cplusplus
}
#endif

#endif /* OPENCL_LOAD */

#endif  /* OPENCL_CL_EXT_LOAD_H_ */

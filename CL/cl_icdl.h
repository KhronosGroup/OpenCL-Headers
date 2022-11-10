/*
 * Copyright (c) 2016-2020 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * OpenCL is a trademark of Apple Inc. used under license by Khronos.
 */

#ifndef OPENCL_CL_ICDL_H
#define OPENCL_CL_ICDL_H

#include <CL/cl.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef cl_uint cl_icdl_info;

#define CL_ICDL_OCL_VERSION 1
#define CL_ICDL_VERSION     2
#define CL_ICDL_NAME        3
#define CL_ICDL_VENDOR      4

typedef cl_int
(CL_API_CALL * pfn_clGetICDLoaderInfoOCLICD)(cl_icdl_info param_name,
                                             size_t       param_value_size,
                                             void *       param_value,
                                             size_t *     param_value_size_ret);

#ifdef __cplusplus
}
#endif


#endif /* OPENCL_CL_ICDL_H */

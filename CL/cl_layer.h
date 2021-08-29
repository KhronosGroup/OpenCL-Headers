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

#ifndef OPENCL_CL_LAYER_H_
#define OPENCL_CL_LAYER_H_

#include <CL/cl_icd.h>
#include <CL/cl.h>

#ifdef __cplusplus
extern "C" {
#endif

/***************************************************************
* cl_loader_layers
***************************************************************/
#define cl_loader_layers 1
#define CL_LOADER_LAYERS_EXTENSION_NAME \
    "cl_loader_layers"

typedef cl_uint             cl_layer_info;
typedef cl_uint             cl_layer_api_version;

/* cl_layer_info */
#define CL_LAYER_API_VERSION                                0x4240

/* Misc API enums */
#define CL_LAYER_API_VERSION_100                            100


typedef cl_int (CL_API_CALL *
pfn_clGetLayerInfo)(
    size_t param_value_size,
    cl_layer_info param_name,
    void* param_value,
    size_t* param_value_size_ret) ;

typedef cl_int (CL_API_CALL *
pfn_clInitLayer)(
    cl_uint num_entries,
    const cl_icd_dispatch* target_dispatch,
    cl_uint* num_entries_ret,
    const cl_icd_dispatch** layer_dispatch) ;

#ifndef CL_NO_PROTOTYPES

extern CL_API_ENTRY cl_int CL_API_CALL
clGetLayerInfo(
    size_t param_value_size,
    cl_layer_info param_name,
    void* param_value,
    size_t* param_value_size_ret) ;

extern CL_API_ENTRY cl_int CL_API_CALL
clInitLayer(
    cl_uint num_entries,
    const cl_icd_dispatch* target_dispatch,
    cl_uint* num_entries_ret,
    const cl_icd_dispatch** layer_dispatch) ;

#endif /* CL_NO_PROTOTYPES */

#ifdef __cplusplus
}
#endif

#endif /* OPENCL_CL_LAYER_H_ */

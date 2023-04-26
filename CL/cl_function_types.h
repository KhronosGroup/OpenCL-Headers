/*
 * Copyright (c) 2023 The Khronos Group Inc.
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

#include <CL/cl.h>

typedef cl_int CL_API_CALL clGetPlatformIDs_t(
    cl_uint num_entries,
    cl_platform_id* platforms,
    cl_uint* num_platforms);

typedef cl_int CL_API_CALL clGetPlatformInfo_t(
    cl_platform_id platform,
    cl_platform_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clGetDeviceIDs_t(
    cl_platform_id platform,
    cl_device_type device_type,
    cl_uint num_entries,
    cl_device_id* devices,
    cl_uint* num_devices);

typedef cl_int CL_API_CALL clGetDeviceInfo_t(
    cl_device_id device,
    cl_device_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_context CL_API_CALL clCreateContext_t(
    const cl_context_properties* properties,
    cl_uint num_devices,
    const cl_device_id* devices,
    void (CL_CALLBACK* pfn_notify)(const char* errinfo, const void* private_info, size_t cb, void* user_data),
    void* user_data,
    cl_int* errcode_ret);

typedef cl_context CL_API_CALL clCreateContextFromType_t(
    const cl_context_properties* properties,
    cl_device_type device_type,
    void (CL_CALLBACK* pfn_notify)(const char* errinfo, const void* private_info, size_t cb, void* user_data),
    void* user_data,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clRetainContext_t(
    cl_context context);

typedef cl_int CL_API_CALL clReleaseContext_t(
    cl_context context);

typedef cl_int CL_API_CALL clGetContextInfo_t(
    cl_context context,
    cl_context_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clRetainCommandQueue_t(
    cl_command_queue command_queue);

typedef cl_int CL_API_CALL clReleaseCommandQueue_t(
    cl_command_queue command_queue);

typedef cl_int CL_API_CALL clGetCommandQueueInfo_t(
    cl_command_queue command_queue,
    cl_command_queue_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_mem CL_API_CALL clCreateBuffer_t(
    cl_context context,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clRetainMemObject_t(
    cl_mem memobj);

typedef cl_int CL_API_CALL clReleaseMemObject_t(
    cl_mem memobj);

typedef cl_int CL_API_CALL clGetSupportedImageFormats_t(
    cl_context context,
    cl_mem_flags flags,
    cl_mem_object_type image_type,
    cl_uint num_entries,
    cl_image_format* image_formats,
    cl_uint* num_image_formats);

typedef cl_int CL_API_CALL clGetMemObjectInfo_t(
    cl_mem memobj,
    cl_mem_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clGetImageInfo_t(
    cl_mem image,
    cl_image_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clRetainSampler_t(
    cl_sampler sampler);

typedef cl_int CL_API_CALL clReleaseSampler_t(
    cl_sampler sampler);

typedef cl_int CL_API_CALL clGetSamplerInfo_t(
    cl_sampler sampler,
    cl_sampler_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_program CL_API_CALL clCreateProgramWithSource_t(
    cl_context context,
    cl_uint count,
    const char** strings,
    const size_t* lengths,
    cl_int* errcode_ret);

typedef cl_program CL_API_CALL clCreateProgramWithBinary_t(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const size_t* lengths,
    const unsigned char** binaries,
    cl_int* binary_status,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clRetainProgram_t(
    cl_program program);

typedef cl_int CL_API_CALL clReleaseProgram_t(
    cl_program program);

typedef cl_int CL_API_CALL clBuildProgram_t(
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data);

typedef cl_int CL_API_CALL clGetProgramInfo_t(
    cl_program program,
    cl_program_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clGetProgramBuildInfo_t(
    cl_program program,
    cl_device_id device,
    cl_program_build_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_kernel CL_API_CALL clCreateKernel_t(
    cl_program program,
    const char* kernel_name,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clCreateKernelsInProgram_t(
    cl_program program,
    cl_uint num_kernels,
    cl_kernel* kernels,
    cl_uint* num_kernels_ret);

typedef cl_int CL_API_CALL clRetainKernel_t(
    cl_kernel kernel);

typedef cl_int CL_API_CALL clReleaseKernel_t(
    cl_kernel kernel);

typedef cl_int CL_API_CALL clSetKernelArg_t(
    cl_kernel kernel,
    cl_uint arg_index,
    size_t arg_size,
    const void* arg_value);

typedef cl_int CL_API_CALL clGetKernelInfo_t(
    cl_kernel kernel,
    cl_kernel_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clGetKernelWorkGroupInfo_t(
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_work_group_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clWaitForEvents_t(
    cl_uint num_events,
    const cl_event* event_list);

typedef cl_int CL_API_CALL clGetEventInfo_t(
    cl_event event,
    cl_event_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clRetainEvent_t(
    cl_event event);

typedef cl_int CL_API_CALL clReleaseEvent_t(
    cl_event event);

typedef cl_int CL_API_CALL clGetEventProfilingInfo_t(
    cl_event event,
    cl_profiling_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clFlush_t(
    cl_command_queue command_queue);

typedef cl_int CL_API_CALL clFinish_t(
    cl_command_queue command_queue);

typedef cl_int CL_API_CALL clEnqueueReadBuffer_t(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    size_t offset,
    size_t size,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueWriteBuffer_t(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    size_t offset,
    size_t size,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueCopyBuffer_t(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    size_t src_offset,
    size_t dst_offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueReadImage_t(
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_read,
    const size_t* origin,
    const size_t* region,
    size_t row_pitch,
    size_t slice_pitch,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueWriteImage_t(
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_write,
    const size_t* origin,
    const size_t* region,
    size_t input_row_pitch,
    size_t input_slice_pitch,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueCopyImage_t(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_image,
    const size_t* src_origin,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueCopyImageToBuffer_t(
    cl_command_queue command_queue,
    cl_mem src_image,
    cl_mem dst_buffer,
    const size_t* src_origin,
    const size_t* region,
    size_t dst_offset,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueCopyBufferToImage_t(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_image,
    size_t src_offset,
    const size_t* dst_origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef void* CL_API_CALL clEnqueueMapBuffer_t(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_map,
    cl_map_flags map_flags,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event,
    cl_int* errcode_ret);

typedef void* CL_API_CALL clEnqueueMapImage_t(
    cl_command_queue command_queue,
    cl_mem image,
    cl_bool blocking_map,
    cl_map_flags map_flags,
    const size_t* origin,
    const size_t* region,
    size_t* image_row_pitch,
    size_t* image_slice_pitch,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clEnqueueUnmapMemObject_t(
    cl_command_queue command_queue,
    cl_mem memobj,
    void* mapped_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueNDRangeKernel_t(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint work_dim,
    const size_t* global_work_offset,
    const size_t* global_work_size,
    const size_t* local_work_size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueNativeKernel_t(
    cl_command_queue command_queue,
    void (CL_CALLBACK* user_func)(void*),
    void* args,
    size_t cb_args,
    cl_uint num_mem_objects,
    const cl_mem* mem_list,
    const void** args_mem_loc,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clSetCommandQueueProperty_t(
    cl_command_queue command_queue,
    cl_command_queue_properties properties,
    cl_bool enable,
    cl_command_queue_properties* old_properties);

typedef cl_mem CL_API_CALL clCreateImage2D_t(
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    size_t image_width,
    size_t image_height,
    size_t image_row_pitch,
    void* host_ptr,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreateImage3D_t(
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    size_t image_width,
    size_t image_height,
    size_t image_depth,
    size_t image_row_pitch,
    size_t image_slice_pitch,
    void* host_ptr,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clEnqueueMarker_t(
    cl_command_queue command_queue,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueWaitForEvents_t(
    cl_command_queue command_queue,
    cl_uint num_events,
    const cl_event* event_list);

typedef cl_int CL_API_CALL clEnqueueBarrier_t(
    cl_command_queue command_queue);

typedef cl_int CL_API_CALL clUnloadCompiler_t(
    void );

typedef void* CL_API_CALL clGetExtensionFunctionAddress_t(
    const char* func_name);

typedef cl_command_queue CL_API_CALL clCreateCommandQueue_t(
    cl_context context,
    cl_device_id device,
    cl_command_queue_properties properties,
    cl_int* errcode_ret);

typedef cl_sampler CL_API_CALL clCreateSampler_t(
    cl_context context,
    cl_bool normalized_coords,
    cl_addressing_mode addressing_mode,
    cl_filter_mode filter_mode,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clEnqueueTask_t(
    cl_command_queue command_queue,
    cl_kernel kernel,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

#ifdef CL_VERSION_1_1
typedef cl_mem CL_API_CALL clCreateSubBuffer_t(
    cl_mem buffer,
    cl_mem_flags flags,
    cl_buffer_create_type buffer_create_type,
    const void* buffer_create_info,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clSetMemObjectDestructorCallback_t(
    cl_mem memobj,
    void (CL_CALLBACK* pfn_notify)(cl_mem memobj, void* user_data),
    void* user_data);

typedef cl_event CL_API_CALL clCreateUserEvent_t(
    cl_context context,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clSetUserEventStatus_t(
    cl_event event,
    cl_int execution_status);

typedef cl_int CL_API_CALL clSetEventCallback_t(
    cl_event event,
    cl_int command_exec_callback_type,
    void (CL_CALLBACK* pfn_notify)(cl_event event, cl_int event_command_status, void *user_data),
    void* user_data);

typedef cl_int CL_API_CALL clEnqueueReadBufferRect_t(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_read,
    const size_t* buffer_origin,
    const size_t* host_origin,
    const size_t* region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueWriteBufferRect_t(
    cl_command_queue command_queue,
    cl_mem buffer,
    cl_bool blocking_write,
    const size_t* buffer_origin,
    const size_t* host_origin,
    const size_t* region,
    size_t buffer_row_pitch,
    size_t buffer_slice_pitch,
    size_t host_row_pitch,
    size_t host_slice_pitch,
    const void* ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueCopyBufferRect_t(
    cl_command_queue command_queue,
    cl_mem src_buffer,
    cl_mem dst_buffer,
    const size_t* src_origin,
    const size_t* dst_origin,
    const size_t* region,
    size_t src_row_pitch,
    size_t src_slice_pitch,
    size_t dst_row_pitch,
    size_t dst_slice_pitch,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

#endif /* CL_VERSION_1_1 */

#ifdef CL_VERSION_1_2
typedef cl_int CL_API_CALL clCreateSubDevices_t(
    cl_device_id in_device,
    const cl_device_partition_property* properties,
    cl_uint num_devices,
    cl_device_id* out_devices,
    cl_uint* num_devices_ret);

typedef cl_int CL_API_CALL clRetainDevice_t(
    cl_device_id device);

typedef cl_int CL_API_CALL clReleaseDevice_t(
    cl_device_id device);

typedef cl_mem CL_API_CALL clCreateImage_t(
    cl_context context,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    const cl_image_desc* image_desc,
    void* host_ptr,
    cl_int* errcode_ret);

typedef cl_program CL_API_CALL clCreateProgramWithBuiltInKernels_t(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* kernel_names,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clCompileProgram_t(
    cl_program program,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_headers,
    const cl_program* input_headers,
    const char** header_include_names,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data);

typedef cl_program CL_API_CALL clLinkProgram_t(
    cl_context context,
    cl_uint num_devices,
    const cl_device_id* device_list,
    const char* options,
    cl_uint num_input_programs,
    const cl_program* input_programs,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clUnloadPlatformCompiler_t(
    cl_platform_id platform);

typedef cl_int CL_API_CALL clGetKernelArgInfo_t(
    cl_kernel kernel,
    cl_uint arg_index,
    cl_kernel_arg_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clEnqueueFillBuffer_t(
    cl_command_queue command_queue,
    cl_mem buffer,
    const void* pattern,
    size_t pattern_size,
    size_t offset,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueFillImage_t(
    cl_command_queue command_queue,
    cl_mem image,
    const void* fill_color,
    const size_t* origin,
    const size_t* region,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueMigrateMemObjects_t(
    cl_command_queue command_queue,
    cl_uint num_mem_objects,
    const cl_mem* mem_objects,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueMarkerWithWaitList_t(
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueBarrierWithWaitList_t(
    cl_command_queue command_queue,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef void* CL_API_CALL clGetExtensionFunctionAddressForPlatform_t(
    cl_platform_id platform,
    const char* func_name);

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_0
typedef cl_command_queue CL_API_CALL clCreateCommandQueueWithProperties_t(
    cl_context context,
    cl_device_id device,
    const cl_queue_properties* properties,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreatePipe_t(
    cl_context context,
    cl_mem_flags flags,
    cl_uint pipe_packet_size,
    cl_uint pipe_max_packets,
    const cl_pipe_properties* properties,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clGetPipeInfo_t(
    cl_mem pipe,
    cl_pipe_info param_name,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef void* CL_API_CALL clSVMAlloc_t(
    cl_context context,
    cl_svm_mem_flags flags,
    size_t size,
    cl_uint alignment);

typedef void CL_API_CALL clSVMFree_t(
    cl_context context,
    void* svm_pointer);

typedef cl_sampler CL_API_CALL clCreateSamplerWithProperties_t(
    cl_context context,
    const cl_sampler_properties* sampler_properties,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clSetKernelArgSVMPointer_t(
    cl_kernel kernel,
    cl_uint arg_index,
    const void* arg_value);

typedef cl_int CL_API_CALL clSetKernelExecInfo_t(
    cl_kernel kernel,
    cl_kernel_exec_info param_name,
    size_t param_value_size,
    const void* param_value);

typedef cl_int CL_API_CALL clEnqueueSVMFree_t(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    void* svm_pointers[],
    void (CL_CALLBACK* pfn_free_func)(cl_command_queue queue, cl_uint num_svm_pointers, void* svm_pointers[], void* user_data),
    void* user_data,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueSVMMemcpy_t(
    cl_command_queue command_queue,
    cl_bool blocking_copy,
    void* dst_ptr,
    const void* src_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueSVMMemFill_t(
    cl_command_queue command_queue,
    void* svm_ptr,
    const void* pattern,
    size_t pattern_size,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueSVMMap_t(
    cl_command_queue command_queue,
    cl_bool blocking_map,
    cl_map_flags flags,
    void* svm_ptr,
    size_t size,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

typedef cl_int CL_API_CALL clEnqueueSVMUnmap_t(
    cl_command_queue command_queue,
    void* svm_ptr,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

#endif /* CL_VERSION_2_0 */

#ifdef CL_VERSION_2_1
typedef cl_int CL_API_CALL clSetDefaultDeviceCommandQueue_t(
    cl_context context,
    cl_device_id device,
    cl_command_queue command_queue);

typedef cl_int CL_API_CALL clGetDeviceAndHostTimer_t(
    cl_device_id device,
    cl_ulong* device_timestamp,
    cl_ulong* host_timestamp);

typedef cl_int CL_API_CALL clGetHostTimer_t(
    cl_device_id device,
    cl_ulong* host_timestamp);

typedef cl_program CL_API_CALL clCreateProgramWithIL_t(
    cl_context context,
    const void* il,
    size_t length,
    cl_int* errcode_ret);

typedef cl_kernel CL_API_CALL clCloneKernel_t(
    cl_kernel source_kernel,
    cl_int* errcode_ret);

typedef cl_int CL_API_CALL clGetKernelSubGroupInfo_t(
    cl_kernel kernel,
    cl_device_id device,
    cl_kernel_sub_group_info param_name,
    size_t input_value_size,
    const void* input_value,
    size_t param_value_size,
    void* param_value,
    size_t* param_value_size_ret);

typedef cl_int CL_API_CALL clEnqueueSVMMigrateMem_t(
    cl_command_queue command_queue,
    cl_uint num_svm_pointers,
    const void** svm_pointers,
    const size_t* sizes,
    cl_mem_migration_flags flags,
    cl_uint num_events_in_wait_list,
    const cl_event* event_wait_list,
    cl_event* event);

#endif /* CL_VERSION_2_1 */

#ifdef CL_VERSION_2_2
typedef cl_int CL_API_CALL clSetProgramSpecializationConstant_t(
    cl_program program,
    cl_uint spec_id,
    size_t spec_size,
    const void* spec_value);

typedef cl_int CL_API_CALL clSetProgramReleaseCallback_t(
    cl_program program,
    void (CL_CALLBACK* pfn_notify)(cl_program program, void* user_data),
    void* user_data);

#endif /* CL_VERSION_2_2 */

#ifdef CL_VERSION_3_0
typedef cl_int CL_API_CALL clSetContextDestructorCallback_t(
    cl_context context,
    void (CL_CALLBACK* pfn_notify)(cl_context context, void* user_data),
    void* user_data);

typedef cl_mem CL_API_CALL clCreateBufferWithProperties_t(
    cl_context context,
    const cl_mem_properties* properties,
    cl_mem_flags flags,
    size_t size,
    void* host_ptr,
    cl_int* errcode_ret);

typedef cl_mem CL_API_CALL clCreateImageWithProperties_t(
    cl_context context,
    const cl_mem_properties* properties,
    cl_mem_flags flags,
    const cl_image_format* image_format,
    const cl_image_desc* image_desc,
    void* host_ptr,
    cl_int* errcode_ret);

#endif /* CL_VERSION_3_0 */


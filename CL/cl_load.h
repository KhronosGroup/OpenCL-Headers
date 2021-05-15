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

#ifndef OPENCL_CL_LOAD_H_
#define OPENCL_CL_LOAD_H_

#include <CL/cl.h>
#ifdef OPENCL_LOAD
#include <CL/opencl_load.h>
#include <CL/cl_api_ptrs.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Platform API */

CLLD_DECL(clGetPlatformIDs);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetPlatformIDs(cl_uint          num_entries,
                 cl_platform_id * platforms,
                 cl_uint *        num_platforms) {
    CLLD_FETCH(clGetPlatformIDs);
    return CLLD_PTR(clGetPlatformIDs)(num_entries, platforms, num_platforms);
}

CLLD_DECL(clGetPlatformInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetPlatformInfo(cl_platform_id   platform,
                  cl_platform_info param_name,
                  size_t           param_value_size,
                  void *           param_value,
                  size_t *         param_value_size_ret) {
    CLLD_FETCH(clGetPlatformInfo);
    return CLLD_PTR(clGetPlatformInfo)(
        platform, param_name, param_value_size,
        param_value, param_value_size_ret);
}

/* Device APIs */

CLLD_DECL(clGetDeviceIDs);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetDeviceIDs(cl_platform_id   platform,
               cl_device_type   device_type,
               cl_uint          num_entries,
               cl_device_id *   devices,
               cl_uint *        num_devices) {
    CLLD_FETCH(clGetDeviceIDs);
    return CLLD_PTR(clGetDeviceIDs)(
        platform, device_type, num_entries,
        devices, num_devices);
}

CLLD_DECL(clGetDeviceInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetDeviceInfo(cl_device_id    device,
                cl_device_info  param_name,
                size_t          param_value_size,
                void *          param_value,
                size_t *        param_value_size_ret) {
    CLLD_FETCH(clGetDeviceInfo);
    return CLLD_PTR(clGetDeviceInfo)(
        device, param_name, param_value_size,
        param_value, param_value_size_ret);
}

#ifdef CL_VERSION_1_2

CLLD_DECL(clCreateSubDevices);
inline CL_API_ENTRY cl_int CL_API_CALL
clCreateSubDevices(cl_device_id                         in_device,
                   const cl_device_partition_property * properties,
                   cl_uint                              num_devices,
                   cl_device_id *                       out_devices,
                   cl_uint *                            num_devices_ret) {
    CLLD_FETCH(clCreateSubDevices);
    return CLLD_PTR(clCreateSubDevices)(
        in_device, properties, num_devices,
        out_devices, num_devices_ret);
}

CLLD_DECL(clRetainDevice);
inline CL_API_ENTRY cl_int CL_API_CALL
clRetainDevice(cl_device_id device) {
    CLLD_FETCH(clRetainDevice);
    return CLLD_PTR(clRetainDevice)(device);
}

CLLD_DECL(clReleaseDevice);
inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseDevice(cl_device_id device) {
    CLLD_FETCH(clReleaseDevice);
    return CLLD_PTR(clReleaseDevice)(device);
}

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_1

CLLD_DECL(clSetDefaultDeviceCommandQueue);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetDefaultDeviceCommandQueue(cl_context           context,
                               cl_device_id         device,
                               cl_command_queue     command_queue) {
    CLLD_FETCH(clSetDefaultDeviceCommandQueue);
    return CLLD_PTR(clSetDefaultDeviceCommandQueue)(
        context, device, command_queue);
}

CLLD_DECL(clGetDeviceAndHostTimer);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetDeviceAndHostTimer(cl_device_id    device,
                        cl_ulong*       device_timestamp,
                        cl_ulong*       host_timestamp) {
    CLLD_FETCH(clGetDeviceAndHostTimer);
    return CLLD_PTR(clGetDeviceAndHostTimer)(
        device, device_timestamp, host_timestamp);
}

CLLD_DECL(clGetHostTimer);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetHostTimer(cl_device_id device,
               cl_ulong *   host_timestamp) {
    CLLD_FETCH(clGetHostTimer);
    return CLLD_PTR(clGetHostTimer)(
        device, host_timestamp);
}

#endif /*CL_VERSION_2_1 */

/* Context APIs */

CLLD_DECL(clCreateContext);
inline CL_API_ENTRY cl_context CL_API_CALL
clCreateContext(const cl_context_properties * properties,
                cl_uint              num_devices,
                const cl_device_id * devices,
                void (CL_CALLBACK * pfn_notify)(const char * errinfo,
                                                const void * private_info,
                                                size_t       cb,
                                                void *       user_data),
                void *               user_data,
                cl_int *             errcode_ret) {
    CLLD_FETCH_ERR(clCreateContext, errcode_ret);
    return CLLD_PTR(clCreateContext)(
        properties, num_devices, devices,
        pfn_notify, user_data, errcode_ret);
}

CLLD_DECL(clCreateContextFromType);
inline CL_API_ENTRY cl_context CL_API_CALL
clCreateContextFromType(const cl_context_properties * properties,
                        cl_device_type      device_type,
                        void (CL_CALLBACK * pfn_notify)(const char * errinfo,
                                                        const void * private_info,
                                                        size_t       cb,
                                                        void *       user_data),
                        void *              user_data,
                        cl_int *            errcode_ret) {
    CLLD_FETCH_ERR(clCreateContextFromType, errcode_ret);
    return CLLD_PTR(clCreateContextFromType)(
        properties, device_type, pfn_notify,
        user_data, errcode_ret);
}

CLLD_DECL(clRetainContext);
inline CL_API_ENTRY cl_int CL_API_CALL
clRetainContext(cl_context context) {
    CLLD_FETCH(clRetainContext);
    return CLLD_PTR(clRetainContext)(context);
}

CLLD_DECL(clReleaseContext);
inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseContext(cl_context context) {
    CLLD_FETCH(clReleaseContext);
    return CLLD_PTR(clReleaseContext)(context);
}

CLLD_DECL(clGetContextInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetContextInfo(cl_context         context,
                 cl_context_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) {
    CLLD_FETCH(clGetContextInfo);
    return CLLD_PTR(clGetContextInfo)(
        context, param_name, param_value_size,
        param_value, param_value_size_ret);
}

#ifdef CL_VERSION_3_0

CLLD_DECL(clSetContextDestructorCallback);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetContextDestructorCallback(cl_context         context,
                               void (CL_CALLBACK* pfn_notify)(cl_context context,
                                                              void* user_data),
                               void*              user_data) {
    CLLD_DECL(clSetContextDestructorCallback);
    return CLLD_PTR(clSetContextDestructorCallback)(
        context, pfn_notify, user_data);
}

#endif /* CL_VERSION_3 */

/* Command Queue APIs */

#ifdef CL_VERSION_2_0

CLLD_DECL(clCreateCommandQueueWithProperties);
inline CL_API_ENTRY cl_command_queue CL_API_CALL
clCreateCommandQueueWithProperties(cl_context               context,
                                   cl_device_id             device,
                                   const cl_queue_properties *    properties,
                                   cl_int *                 errcode_ret) {
    CLLD_FETCH_ERR(clCreateCommandQueueWithProperties, errcode_ret);
    return CLLD_PTR(clCreateCommandQueueWithProperties)(
        context, device, properties, errcode_ret);
}

#endif /* CL_VERSION_2_0 */

CLLD_DECL(clRetainCommandQueue);
inline CL_API_ENTRY cl_int CL_API_CALL
clRetainCommandQueue(cl_command_queue command_queue) {
    CLLD_FETCH(clRetainCommandQueue);
    return CLLD_PTR(clRetainCommandQueue)(command_queue);
}

CLLD_DECL(clReleaseCommandQueue);
inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseCommandQueue(cl_command_queue command_queue) {
    CLLD_FETCH(clReleaseCommandQueue);
    return CLLD_PTR(clReleaseCommandQueue)(command_queue);
}

CLLD_DECL(clGetCommandQueueInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetCommandQueueInfo(cl_command_queue      command_queue,
                      cl_command_queue_info param_name,
                      size_t                param_value_size,
                      void *                param_value,
                      size_t *              param_value_size_ret) {
    CLLD_FETCH(clGetCommandQueueInfo);
    return CLLD_PTR(clGetCommandQueueInfo)(
        command_queue, param_name, param_value_size,
        param_value, param_value_size_ret);
}

/* Memory Object APIs */

CLLD_DECL(clCreateBuffer);
inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateBuffer(cl_context   context,
               cl_mem_flags flags,
               size_t       size,
               void *       host_ptr,
               cl_int *     errcode_ret) {
    CLLD_FETCH_ERR(clCreateBuffer, errcode_ret);
    return CLLD_PTR(clCreateBuffer)(
        context, flags, size, host_ptr, errcode_ret);
}

#ifdef CL_VERSION_1_1

CLLD_DECL(clCreateSubBuffer);
inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateSubBuffer(cl_mem                   buffer,
                  cl_mem_flags             flags,
                  cl_buffer_create_type    buffer_create_type,
                  const void *             buffer_create_info,
                  cl_int *                 errcode_ret) {
    CLLD_FETCH_ERR(clCreateSubBuffer, errcode_ret);
    return CLLD_PTR(clCreateSubBuffer)(
        buffer, flags, buffer_create_type, buffer_create_info, errcode_ret);
}

#endif /* CL_VERSION_1_1 */

#ifdef CL_VERSION_1_2

CLLD_DECL(clCreateImage);
inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateImage(cl_context              context,
              cl_mem_flags            flags,
              const cl_image_format * image_format,
              const cl_image_desc *   image_desc,
              void *                  host_ptr,
              cl_int *                errcode_ret) {
    CLLD_FETCH_ERR(clCreateImage, errcode_ret);
    return CLLD_PTR(clCreateImage)(
        context, flags, image_format, image_desc, host_ptr, errcode_ret);
}

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_0

CLLD_DECL(clCreatePipe);
inline CL_API_ENTRY cl_mem CL_API_CALL
clCreatePipe(cl_context                 context,
             cl_mem_flags               flags,
             cl_uint                    pipe_packet_size,
             cl_uint                    pipe_max_packets,
             const cl_pipe_properties * properties,
             cl_int *                   errcode_ret) {
    CLLD_FETCH_ERR(clCreatePipe, errcode_ret);
    return CLLD_PTR(clCreatePipe)(
        context, flags, pipe_packet_size, pipe_max_packets, properties, errcode_ret);
}

#endif /* CL_VERSION_2_0 */

#ifdef CL_VERSION_3_0

CLLD_DECL(clCreateBufferWithProperties);
inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateBufferWithProperties(cl_context                context,
                             const cl_mem_properties * properties,
                             cl_mem_flags              flags,
                             size_t                    size,
                             void *                    host_ptr,
                             cl_int *                  errcode_ret) {
    CLLD_FETCH_ERR(clCreateBufferWithProperties, errcode_ret);
    return CLLD_PTR(clCreateBufferWithProperties)(
        context, properties, flags, size, host_ptr, errcode_ret);
}

CLLD_DECL(clCreateImageWithProperties);
inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateImageWithProperties(cl_context                context,
                            const cl_mem_properties * properties,
                            cl_mem_flags              flags,
                            const cl_image_format *   image_format,
                            const cl_image_desc *     image_desc,
                            void *                    host_ptr,
                            cl_int *                  errcode_ret) {
    CLLD_FETCH_ERR(clCreateImageWithProperties, errcode_ret);
    return CLLD_PTR(clCreateImageWithProperties)(
        context, properties, flags, image_format, image_desc, host_ptr, errcode_ret);
}

#endif /* CL_VERSION_3_0 */

CLLD_DECL(clRetainMemObject);
inline CL_API_ENTRY cl_int CL_API_CALL
clRetainMemObject(cl_mem memobj) {
    CLLD_FETCH(clRetainMemObject);
    return CLLD_PTR(clRetainMemObject)(memobj);
}

CLLD_DECL(clReleaseMemObject);
inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseMemObject(cl_mem memobj) {
    CLLD_FETCH(clReleaseMemObject);
    return CLLD_PTR(clReleaseMemObject)(memobj);
}

CLLD_DECL(clGetSupportedImageFormats);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetSupportedImageFormats(cl_context           context,
                           cl_mem_flags         flags,
                           cl_mem_object_type   image_type,
                           cl_uint              num_entries,
                           cl_image_format *    image_formats,
                           cl_uint *            num_image_formats) {
    CLLD_FETCH(clGetSupportedImageFormats);
    return CLLD_PTR(clGetSupportedImageFormats)(
        context, flags, image_type, num_entries, image_formats, num_image_formats);
}

CLLD_DECL(clGetMemObjectInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetMemObjectInfo(cl_mem           memobj,
                   cl_mem_info      param_name,
                   size_t           param_value_size,
                   void *           param_value,
                   size_t *         param_value_size_ret) {
    CLLD_FETCH(clGetMemObjectInfo);
    return CLLD_PTR(clGetMemObjectInfo)(
        memobj, param_name, param_value_size, param_value, param_value_size_ret);
}

CLLD_DECL(clGetImageInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetImageInfo(cl_mem           image,
               cl_image_info    param_name,
               size_t           param_value_size,
               void *           param_value,
               size_t *         param_value_size_ret) {
    CLLD_FETCH(clGetImageInfo);
    return CLLD_PTR(clGetImageInfo)(
        image, param_name, param_value_size, param_value, param_value_size_ret);
}

#ifdef CL_VERSION_2_0

CLLD_DECL(clGetPipeInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetPipeInfo(cl_mem           pipe,
              cl_pipe_info     param_name,
              size_t           param_value_size,
              void *           param_value,
              size_t *         param_value_size_ret) {
    CLLD_FETCH(clGetPipeInfo);
    return CLLD_PTR(clGetPipeInfo)(
        pipe, param_name, param_value_size, param_value, param_value_size_ret);
}

#endif /* CL_VERSION_2_0 */

#ifdef CL_VERSION_1_1

CLLD_DECL(clSetMemObjectDestructorCallback);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetMemObjectDestructorCallback(cl_mem memobj,
                                 void (CL_CALLBACK * pfn_notify)(cl_mem memobj,
                                                                 void * user_data),
                                 void * user_data) {
    CLLD_FETCH(clSetMemObjectDestructorCallback);
    return CLLD_PTR(clSetMemObjectDestructorCallback)(
        memobj, pfn_notify, user_data);
}

#endif /* CL_VERSION_1_1 */

/* SVM Allocation APIs */

#ifdef CL_VERSION_2_0

CLLD_DECL(clSVMAlloc);
inline CL_API_ENTRY void * CL_API_CALL
clSVMAlloc(cl_context       context,
           cl_svm_mem_flags flags,
           size_t           size,
           cl_uint          alignment) {
    CLLD_FETCH_NULL(clSVMAlloc);
    return CLLD_PTR(clSVMAlloc)(
        context, flags, size, alignment);
}

CLLD_DECL(clSVMFree);
inline CL_API_ENTRY void CL_API_CALL
clSVMFree(cl_context        context,
          void *            svm_pointer) {
    CLLD_FETCH_NOERR(clSVMFree);
    CLLD_PTR(clSVMFree)(context, svm_pointer);
}

#endif /* CL_VERSION_2_0 */

/* Sampler APIs */

#ifdef CL_VERSION_2_0

CLLD_DECL(clCreateSamplerWithProperties);
inline CL_API_ENTRY cl_sampler CL_API_CALL
clCreateSamplerWithProperties(cl_context                     context,
                              const cl_sampler_properties *  sampler_properties,
                              cl_int *                       errcode_ret) {
    CLLD_FETCH_ERR(clCreateSamplerWithProperties, errcode_ret);
    return CLLD_PTR(clCreateSamplerWithProperties)(
        context, sampler_properties, errcode_ret);
}

#endif /* CL_VERSION_2_0 */

CLLD_DECL(clRetainSampler);
inline CL_API_ENTRY cl_int CL_API_CALL
clRetainSampler(cl_sampler sampler) {
    CLLD_FETCH(clRetainSampler);
    return CLLD_PTR(clRetainSampler)(sampler);
}

CLLD_DECL(clReleaseSampler);
inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseSampler(cl_sampler sampler) {
    CLLD_FETCH(clReleaseSampler);
    return CLLD_PTR(clReleaseSampler)(sampler);
}

CLLD_DECL(clGetSamplerInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetSamplerInfo(cl_sampler         sampler,
                 cl_sampler_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) {
    CLLD_FETCH(clGetSamplerInfo);
    return CLLD_PTR(clGetSamplerInfo)(
        sampler, param_name, param_value_size, param_value, param_value_size_ret);
}

/* Program Object APIs */

CLLD_DECL(clCreateProgramWithSource);
inline CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithSource(cl_context        context,
                          cl_uint           count,
                          const char **     strings,
                          const size_t *    lengths,
                          cl_int *          errcode_ret) {
    CLLD_FETCH_ERR(clCreateProgramWithSource, errcode_ret);
    return CLLD_PTR(clCreateProgramWithSource)(
        context, count, strings, lengths, errcode_ret);
}

CLLD_DECL(clCreateProgramWithBinary);
inline CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithBinary(cl_context                     context,
                          cl_uint                        num_devices,
                          const cl_device_id *           device_list,
                          const size_t *                 lengths,
                          const unsigned char **         binaries,
                          cl_int *                       binary_status,
                          cl_int *                       errcode_ret) {
    CLLD_FETCH_ERR(clCreateProgramWithBinary, errcode_ret);
    return CLLD_PTR(clCreateProgramWithBinary)(
        context, num_devices, device_list, lengths, binaries, binary_status, errcode_ret);
}

#ifdef CL_VERSION_1_2

CLLD_DECL(clCreateProgramWithBuiltInKernels);
inline CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithBuiltInKernels(cl_context            context,
                                  cl_uint               num_devices,
                                  const cl_device_id *  device_list,
                                  const char *          kernel_names,
                                  cl_int *              errcode_ret) {
    CLLD_FETCH_ERR(clCreateProgramWithBuiltInKernels, errcode_ret);
    return CLLD_PTR(clCreateProgramWithBuiltInKernels)(
        context, num_devices, device_list, kernel_names, errcode_ret);
}

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_1

CLLD_DECL(clCreateProgramWithIL);
inline CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithIL(cl_context    context,
                     const void*    il,
                     size_t         length,
                     cl_int*        errcode_ret) {
    CLLD_FETCH_ERR(clCreateProgramWithIL, errcode_ret);
    return CLLD_PTR(clCreateProgramWithIL)(
        context, il, length, errcode_ret);
}

#endif /* CL_VERSION_2_1 */

CLLD_DECL(clRetainProgram);
inline CL_API_ENTRY cl_int CL_API_CALL
clRetainProgram(cl_program program) {
    CLLD_FETCH(clRetainProgram);
    return CLLD_PTR(clRetainProgram)(program);
}

CLLD_DECL(clReleaseProgram);
inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseProgram(cl_program program) {
    CLLD_FETCH(clReleaseProgram);
    return CLLD_PTR(clReleaseProgram)(program);
}

CLLD_DECL(clBuildProgram);
inline CL_API_ENTRY cl_int CL_API_CALL
clBuildProgram(cl_program           program,
               cl_uint              num_devices,
               const cl_device_id * device_list,
               const char *         options,
               void (CL_CALLBACK *  pfn_notify)(cl_program program,
                                                void * user_data),
               void *               user_data) {
    CLLD_FETCH(clBuildProgram);
    return CLLD_PTR(clBuildProgram)(
        program, num_devices, device_list, options, pfn_notify, user_data);
}

#ifdef CL_VERSION_1_2

CLLD_DECL(clCompileProgram);
inline CL_API_ENTRY cl_int CL_API_CALL
clCompileProgram(cl_program           program,
                 cl_uint              num_devices,
                 const cl_device_id * device_list,
                 const char *         options,
                 cl_uint              num_input_headers,
                 const cl_program *   input_headers,
                 const char **        header_include_names,
                 void (CL_CALLBACK *  pfn_notify)(cl_program program,
                                                  void * user_data),
                 void *               user_data) {
    CLLD_FETCH(clCompileProgram);
    return CLLD_PTR(clCompileProgram)(
        program, num_devices, device_list, options, num_input_headers, input_headers,
        header_include_names, pfn_notify, user_data);
}

CLLD_DECL(clLinkProgram);
inline CL_API_ENTRY cl_program CL_API_CALL
clLinkProgram(cl_context           context,
              cl_uint              num_devices,
              const cl_device_id * device_list,
              const char *         options,
              cl_uint              num_input_programs,
              const cl_program *   input_programs,
              void (CL_CALLBACK *  pfn_notify)(cl_program program,
                                               void * user_data),
              void *               user_data,
              cl_int *             errcode_ret) {
    CLLD_FETCH_ERR(clLinkProgram, errcode_ret);
    return CLLD_PTR(clLinkProgram)(
        context, num_devices, device_list, options, num_input_programs,
        input_programs, pfn_notify, user_data, errcode_ret);
}

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_2

CLLD_DECL(clSetProgramReleaseCallback);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_2_2_DEPRECATED cl_int CL_API_CALL
clSetProgramReleaseCallback(cl_program          program,
                            void (CL_CALLBACK * pfn_notify)(cl_program program,
                                                            void * user_data),
                            void *              user_data) {
    CLLD_FETCH(clSetProgramReleaseCallback);
    return CLLD_PTR(clSetProgramReleaseCallback)(
        program, pfn_notify, user_data);
}

CLLD_DECL(clSetProgramSpecializationConstant);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetProgramSpecializationConstant(cl_program  program,
                                   cl_uint     spec_id,
                                   size_t      spec_size,
                                   const void* spec_value) {
    CLLD_FETCH(clSetProgramSpecializationConstant);
    return CLLD_PTR(clSetProgramSpecializationConstant)(
        program, spec_id, spec_size, spec_value);
}

#endif /* CL_VERSION_2_2 */

#ifdef CL_VERSION_1_2

CLLD_DECL(clUnloadPlatformCompiler);
inline CL_API_ENTRY cl_int CL_API_CALL
clUnloadPlatformCompiler(cl_platform_id platform) {
    CLLD_FETCH(clUnloadPlatformCompiler);
    return CLLD_PTR(clUnloadPlatformCompiler)(platform);
}

#endif /* CL_VERSION_1_2 */

CLLD_DECL(clGetProgramInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetProgramInfo(cl_program         program,
                 cl_program_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) {
    CLLD_FETCH(clGetProgramInfo);
    return CLLD_PTR(clGetProgramInfo)(
        program, param_name, param_value_size, param_value, param_value_size_ret);
}

CLLD_DECL(clGetProgramBuildInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetProgramBuildInfo(cl_program            program,
                      cl_device_id          device,
                      cl_program_build_info param_name,
                      size_t                param_value_size,
                      void *                param_value,
                      size_t *              param_value_size_ret) {
    CLLD_FETCH(clGetProgramBuildInfo);
    return CLLD_PTR(clGetProgramBuildInfo)(
        program, device, param_name, param_value_size, param_value, param_value_size_ret);
}

/* Kernel Object APIs */

CLLD_DECL(clCreateKernel);
inline CL_API_ENTRY cl_kernel CL_API_CALL
clCreateKernel(cl_program      program,
               const char *    kernel_name,
               cl_int *        errcode_ret) {
    CLLD_FETCH_ERR(clCreateKernel, errcode_ret);
    return CLLD_PTR(clCreateKernel)(
        program, kernel_name, errcode_ret);
}

CLLD_DECL(clCreateKernelsInProgram);
inline CL_API_ENTRY cl_int CL_API_CALL
clCreateKernelsInProgram(cl_program     program,
                         cl_uint        num_kernels,
                         cl_kernel *    kernels,
                         cl_uint *      num_kernels_ret) {
    CLLD_FETCH(clCreateKernelsInProgram);
    return CLLD_PTR(clCreateKernelsInProgram)(
        program, num_kernels, kernels, num_kernels_ret);
}

#ifdef CL_VERSION_2_1

CLLD_DECL(clCloneKernel);
inline CL_API_ENTRY cl_kernel CL_API_CALL
clCloneKernel(cl_kernel     source_kernel,
              cl_int*       errcode_ret) {
    CLLD_FETCH_ERR(clCloneKernel, errcode_ret);
    return CLLD_PTR(clCloneKernel)(
        source_kernel, errcode_ret);
}

#endif /* CL_VERSION_2_1 */

CLLD_DECL(clRetainKernel);
inline CL_API_ENTRY cl_int CL_API_CALL
clRetainKernel(cl_kernel    kernel) {
    CLLD_FETCH(clRetainKernel);
    return CLLD_PTR(clRetainKernel)(kernel);
}

CLLD_DECL(clReleaseKernel);
inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseKernel(cl_kernel    kernel) {
    CLLD_FETCH(clReleaseKernel);
    return CLLD_PTR(clReleaseKernel)(kernel);
}

CLLD_DECL(clSetKernelArg);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetKernelArg(cl_kernel    kernel,
               cl_uint      arg_index,
               size_t       arg_size,
               const void * arg_value) {
    CLLD_FETCH(clSetKernelArg);
    return CLLD_PTR(clSetKernelArg)(
        kernel, arg_index, arg_size, arg_value);
}

#ifdef CL_VERSION_2_0

CLLD_DECL(clSetKernelArgSVMPointer);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetKernelArgSVMPointer(cl_kernel    kernel,
                         cl_uint      arg_index,
                         const void * arg_value) {
    CLLD_FETCH(clSetKernelArgSVMPointer);
    return CLLD_PTR(clSetKernelArgSVMPointer)(
         kernel, arg_index, arg_value);
}

CLLD_DECL(clSetKernelExecInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetKernelExecInfo(cl_kernel            kernel,
                    cl_kernel_exec_info  param_name,
                    size_t               param_value_size,
                    const void *         param_value) {
    CLLD_FETCH(clSetKernelExecInfo);
    return CLLD_PTR(clSetKernelExecInfo)(
        kernel, param_name, param_value_size, param_value);
}

#endif /* CL_VERSION_2_0 */

CLLD_DECL(clGetKernelInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetKernelInfo(cl_kernel       kernel,
                cl_kernel_info  param_name,
                size_t          param_value_size,
                void *          param_value,
                size_t *        param_value_size_ret) {
    CLLD_FETCH(clGetKernelInfo);
    return CLLD_PTR(clGetKernelInfo)(
        kernel, param_name, param_value_size, param_value, param_value_size_ret);
}

#ifdef CL_VERSION_1_2

CLLD_DECL(clGetKernelArgInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetKernelArgInfo(cl_kernel       kernel,
                   cl_uint         arg_indx,
                   cl_kernel_arg_info  param_name,
                   size_t          param_value_size,
                   void *          param_value,
                   size_t *        param_value_size_ret) {
    CLLD_FETCH(clGetKernelArgInfo);
    return CLLD_PTR(clGetKernelArgInfo)(
        kernel, arg_indx, param_name, param_value_size,
        param_value, param_value_size_ret);
}

#endif /* CL_VERSION_1_2 */

CLLD_DECL(clGetKernelWorkGroupInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetKernelWorkGroupInfo(cl_kernel                  kernel,
                         cl_device_id               device,
                         cl_kernel_work_group_info  param_name,
                         size_t                     param_value_size,
                         void *                     param_value,
                         size_t *                   param_value_size_ret) {
    CLLD_FETCH(clGetKernelWorkGroupInfo);
    return CLLD_PTR(clGetKernelWorkGroupInfo)(
        kernel, device, param_name, param_value_size, param_value, param_value_size_ret);
}

#ifdef CL_VERSION_2_1

CLLD_DECL(clGetKernelSubGroupInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetKernelSubGroupInfo(cl_kernel                   kernel,
                        cl_device_id                device,
                        cl_kernel_sub_group_info    param_name,
                        size_t                      input_value_size,
                        const void*                 input_value,
                        size_t                      param_value_size,
                        void*                       param_value,
                        size_t*                     param_value_size_ret) {
    CLLD_FETCH(clGetKernelSubGroupInfo);
    return CLLD_PTR(clGetKernelSubGroupInfo)(
        kernel, device, param_name, input_value_size, input_value,
        param_value_size, param_value, param_value_size_ret);
}

#endif /* CL_VERSION_2_1 */

/* Event Object APIs */

CLLD_DECL(clWaitForEvents);
inline CL_API_ENTRY cl_int CL_API_CALL
clWaitForEvents(cl_uint             num_events,
                const cl_event *    event_list) {
    CLLD_FETCH(clWaitForEvents);
    return CLLD_PTR(clWaitForEvents)(
        num_events, event_list);
}

CLLD_DECL(clGetEventInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetEventInfo(cl_event         event,
               cl_event_info    param_name,
               size_t           param_value_size,
               void *           param_value,
               size_t *         param_value_size_ret) {
    CLLD_FETCH(clGetEventInfo);
    return CLLD_PTR(clGetEventInfo)(
        event, param_name, param_value_size, param_value, param_value_size_ret);
}

#ifdef CL_VERSION_1_1

CLLD_DECL(clCreateUserEvent);
inline CL_API_ENTRY cl_event CL_API_CALL
clCreateUserEvent(cl_context    context,
                  cl_int *      errcode_ret) {
    CLLD_FETCH_ERR(clCreateUserEvent, errcode_ret);
    return CLLD_PTR(clCreateUserEvent)(
        context, errcode_ret);
}

#endif /* CL_VERSION_1_1 */

CLLD_DECL(clRetainEvent);
inline CL_API_ENTRY cl_int CL_API_CALL
clRetainEvent(cl_event event) {
    CLLD_FETCH(clRetainEvent);
    return CLLD_PTR(clRetainEvent)(event);
}

CLLD_DECL(clReleaseEvent);
inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseEvent(cl_event event) {
    CLLD_FETCH(clReleaseEvent);
    return CLLD_PTR(clReleaseEvent)(event);
}

#ifdef CL_VERSION_1_1

CLLD_DECL(clSetUserEventStatus);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetUserEventStatus(cl_event   event,
                     cl_int     execution_status) {
    CLLD_FETCH(clSetUserEventStatus);
    return CLLD_PTR(clSetUserEventStatus)(
        event, execution_status);
}

CLLD_DECL(clSetEventCallback);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetEventCallback(cl_event    event,
                   cl_int      command_exec_callback_type,
                   void (CL_CALLBACK * pfn_notify)(cl_event event,
                                                   cl_int   event_command_status,
                                                   void *   user_data),
                   void *      user_data) {
    CLLD_FETCH(clSetEventCallback);
    return CLLD_PTR(clSetEventCallback)(
        event, command_exec_callback_type, pfn_notify, user_data);
}

#endif /* CL_VERSION_1_1 */

/* Profiling APIs */

CLLD_DECL(clGetEventProfilingInfo);
inline CL_API_ENTRY cl_int CL_API_CALL
clGetEventProfilingInfo(cl_event            event,
                        cl_profiling_info   param_name,
                        size_t              param_value_size,
                        void *              param_value,
                        size_t *            param_value_size_ret) {
    CLLD_FETCH(clGetEventProfilingInfo);
    return CLLD_PTR(clGetEventProfilingInfo)(
        event, param_name, param_value_size, param_value, param_value_size_ret);
}

/* Flush and Finish APIs */

CLLD_DECL(clFlush);
inline CL_API_ENTRY cl_int CL_API_CALL
clFlush(cl_command_queue command_queue) {
    CLLD_FETCH(clFlush);
    return CLLD_PTR(clFlush)(command_queue);
}

CLLD_DECL(clFinish);
inline CL_API_ENTRY cl_int CL_API_CALL
clFinish(cl_command_queue command_queue) {
    CLLD_FETCH(clFinish);
    return CLLD_PTR(clFinish)(command_queue);
}

/* Enqueued Commands APIs */

CLLD_DECL(clEnqueueReadBuffer);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueReadBuffer(cl_command_queue    command_queue,
                    cl_mem              buffer,
                    cl_bool             blocking_read,
                    size_t              offset,
                    size_t              size,
                    void *              ptr,
                    cl_uint             num_events_in_wait_list,
                    const cl_event *    event_wait_list,
                    cl_event *          event) {
    CLLD_FETCH(clEnqueueReadBuffer);
    return CLLD_PTR(clEnqueueReadBuffer)(
        command_queue, buffer, blocking_read, offset, size,
        ptr, num_events_in_wait_list, event_wait_list, event);
}

#ifdef CL_VERSION_1_1

CLLD_DECL(clEnqueueReadBufferRect);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueReadBufferRect(cl_command_queue    command_queue,
                        cl_mem              buffer,
                        cl_bool             blocking_read,
                        const size_t *      buffer_origin,
                        const size_t *      host_origin,
                        const size_t *      region,
                        size_t              buffer_row_pitch,
                        size_t              buffer_slice_pitch,
                        size_t              host_row_pitch,
                        size_t              host_slice_pitch,
                        void *              ptr,
                        cl_uint             num_events_in_wait_list,
                        const cl_event *    event_wait_list,
                        cl_event *          event) {
    CLLD_FETCH(clEnqueueReadBufferRect);
    return CLLD_PTR(clEnqueueReadBufferRect)(
        command_queue, buffer, blocking_read, buffer_origin, host_origin, region,
        buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch,
        ptr, num_events_in_wait_list, event_wait_list, event);
}

#endif /* CL_VERSION_1_1 */

CLLD_DECL(clEnqueueWriteBuffer);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueWriteBuffer(cl_command_queue   command_queue,
                     cl_mem             buffer,
                     cl_bool            blocking_write,
                     size_t             offset,
                     size_t             size,
                     const void *       ptr,
                     cl_uint            num_events_in_wait_list,
                     const cl_event *   event_wait_list,
                     cl_event *         event) {
    CLLD_FETCH(clEnqueueWriteBuffer);
    return CLLD_PTR(clEnqueueWriteBuffer)(
        command_queue, buffer, blocking_write, offset, size,
        ptr, num_events_in_wait_list, event_wait_list, event);
}

#ifdef CL_VERSION_1_1

CLLD_DECL(clEnqueueWriteBufferRect);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueWriteBufferRect(cl_command_queue    command_queue,
                         cl_mem              buffer,
                         cl_bool             blocking_write,
                         const size_t *      buffer_origin,
                         const size_t *      host_origin,
                         const size_t *      region,
                         size_t              buffer_row_pitch,
                         size_t              buffer_slice_pitch,
                         size_t              host_row_pitch,
                         size_t              host_slice_pitch,
                         const void *        ptr,
                         cl_uint             num_events_in_wait_list,
                         const cl_event *    event_wait_list,
                         cl_event *          event) {
    CLLD_FETCH(clEnqueueWriteBufferRect);
    return CLLD_PTR(clEnqueueWriteBufferRect)(
        command_queue, buffer, blocking_write, buffer_origin, host_origin, region,
        buffer_row_pitch, buffer_slice_pitch, host_row_pitch, host_slice_pitch,
        ptr, num_events_in_wait_list, event_wait_list, event);
}

#endif /* CL_VERSION_1_1 */

#ifdef CL_VERSION_1_2

CLLD_DECL(clEnqueueFillBuffer);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueFillBuffer(cl_command_queue   command_queue,
                    cl_mem             buffer,
                    const void *       pattern,
                    size_t             pattern_size,
                    size_t             offset,
                    size_t             size,
                    cl_uint            num_events_in_wait_list,
                    const cl_event *   event_wait_list,
                    cl_event *         event) {
    CLLD_FETCH(clEnqueueFillBuffer);
    return CLLD_PTR(clEnqueueFillBuffer)(
        command_queue, buffer, pattern, pattern_size, offset, size,
        num_events_in_wait_list, event_wait_list, event);
}

#endif /* CL_VERSION_1_2 */

CLLD_DECL(clEnqueueCopyBuffer);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBuffer(cl_command_queue    command_queue,
                    cl_mem              src_buffer,
                    cl_mem              dst_buffer,
                    size_t              src_offset,
                    size_t              dst_offset,
                    size_t              size,
                    cl_uint             num_events_in_wait_list,
                    const cl_event *    event_wait_list,
                    cl_event *          event) {
    CLLD_FETCH(clEnqueueCopyBuffer);
    return CLLD_PTR(clEnqueueCopyBuffer)(
        command_queue, src_buffer, dst_buffer, src_offset, dst_offset,
        size, num_events_in_wait_list, event_wait_list, event);
}

#ifdef CL_VERSION_1_1

CLLD_DECL(clEnqueueCopyBufferRect);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferRect(cl_command_queue    command_queue,
                        cl_mem              src_buffer,
                        cl_mem              dst_buffer,
                        const size_t *      src_origin,
                        const size_t *      dst_origin,
                        const size_t *      region,
                        size_t              src_row_pitch,
                        size_t              src_slice_pitch,
                        size_t              dst_row_pitch,
                        size_t              dst_slice_pitch,
                        cl_uint             num_events_in_wait_list,
                        const cl_event *    event_wait_list,
                        cl_event *          event) {
    CLLD_FETCH(clEnqueueCopyBufferRect);
    return CLLD_PTR(clEnqueueCopyBufferRect)(
        command_queue, src_buffer, dst_buffer, src_origin, dst_origin,
        region, src_row_pitch, src_slice_pitch, dst_row_pitch, dst_slice_pitch,
        num_events_in_wait_list, event_wait_list, event);
}

#endif /* CL_VERSION_1_1 */

CLLD_DECL(clEnqueueReadImage);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueReadImage(cl_command_queue     command_queue,
                   cl_mem               image,
                   cl_bool              blocking_read,
                   const size_t *       origin,
                   const size_t *       region,
                   size_t               row_pitch,
                   size_t               slice_pitch,
                   void *               ptr,
                   cl_uint              num_events_in_wait_list,
                   const cl_event *     event_wait_list,
                   cl_event *           event) {
    CLLD_FETCH(clEnqueueReadImage);
    return CLLD_PTR(clEnqueueReadImage)(
        command_queue, image, blocking_read, origin, region, row_pitch,
        slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueWriteImage);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueWriteImage(cl_command_queue    command_queue,
                    cl_mem              image,
                    cl_bool             blocking_write,
                    const size_t *      origin,
                    const size_t *      region,
                    size_t              input_row_pitch,
                    size_t              input_slice_pitch,
                    const void *        ptr,
                    cl_uint             num_events_in_wait_list,
                    const cl_event *    event_wait_list,
                    cl_event *          event) {
    CLLD_FETCH(clEnqueueWriteImage);
    return CLLD_PTR(clEnqueueWriteImage)(
        command_queue, image, blocking_write, origin, region, input_row_pitch,
        input_slice_pitch, ptr, num_events_in_wait_list, event_wait_list, event);
}

#ifdef CL_VERSION_1_2

CLLD_DECL(clEnqueueFillImage);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueFillImage(cl_command_queue   command_queue,
                   cl_mem             image,
                   const void *       fill_color,
                   const size_t *     origin,
                   const size_t *     region,
                   cl_uint            num_events_in_wait_list,
                   const cl_event *   event_wait_list,
                   cl_event *         event) {
    CLLD_FETCH(clEnqueueFillImage);
    return CLLD_PTR(clEnqueueFillImage)(
        command_queue, image, fill_color, origin, region,
       num_events_in_wait_list, event_wait_list, event);
}

#endif /* CL_VERSION_1_2 */

CLLD_DECL(clEnqueueCopyImage);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyImage(cl_command_queue     command_queue,
                   cl_mem               src_image,
                   cl_mem               dst_image,
                   const size_t *       src_origin,
                   const size_t *       dst_origin,
                   const size_t *       region,
                   cl_uint              num_events_in_wait_list,
                   const cl_event *     event_wait_list,
                   cl_event *           event) {
    CLLD_FETCH(clEnqueueCopyImage);
    return CLLD_PTR(clEnqueueCopyImage)(
        command_queue, src_image, dst_image, src_origin, dst_origin,
        region, num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueCopyImageToBuffer);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyImageToBuffer(cl_command_queue command_queue,
                           cl_mem           src_image,
                           cl_mem           dst_buffer,
                           const size_t *   src_origin,
                           const size_t *   region,
                           size_t           dst_offset,
                           cl_uint          num_events_in_wait_list,
                           const cl_event * event_wait_list,
                           cl_event *       event) {
    CLLD_FETCH(clEnqueueCopyImageToBuffer);
    return CLLD_PTR(clEnqueueCopyImageToBuffer)(
        command_queue, src_image, dst_buffer, src_origin, region,
        dst_offset, num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueCopyBufferToImage);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferToImage(cl_command_queue command_queue,
                           cl_mem           src_buffer,
                           cl_mem           dst_image,
                           size_t           src_offset,
                           const size_t *   dst_origin,
                           const size_t *   region,
                           cl_uint          num_events_in_wait_list,
                           const cl_event * event_wait_list,
                           cl_event *       event) {
    CLLD_FETCH(clEnqueueCopyBufferToImage);
    return CLLD_PTR(clEnqueueCopyBufferToImage)(
        command_queue, src_buffer, dst_image, src_offset,dst_origin,
        region, num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueMapBuffer);
inline CL_API_ENTRY void * CL_API_CALL
clEnqueueMapBuffer(cl_command_queue command_queue,
                   cl_mem           buffer,
                   cl_bool          blocking_map,
                   cl_map_flags     map_flags,
                   size_t           offset,
                   size_t           size,
                   cl_uint          num_events_in_wait_list,
                   const cl_event * event_wait_list,
                   cl_event *       event,
                   cl_int *         errcode_ret) {
    CLLD_FETCH_ERR(clEnqueueMapBuffer, errcode_ret);
    return CLLD_PTR(clEnqueueMapBuffer)(
        command_queue, buffer, blocking_map, map_flags, offset, size,
        num_events_in_wait_list, event_wait_list, event, errcode_ret);
}

CLLD_DECL(clEnqueueMapImage);
inline CL_API_ENTRY void * CL_API_CALL
clEnqueueMapImage(cl_command_queue  command_queue,
                  cl_mem            image,
                  cl_bool           blocking_map,
                  cl_map_flags      map_flags,
                  const size_t *    origin,
                  const size_t *    region,
                  size_t *          image_row_pitch,
                  size_t *          image_slice_pitch,
                  cl_uint           num_events_in_wait_list,
                  const cl_event *  event_wait_list,
                  cl_event *        event,
                  cl_int *          errcode_ret) {
    CLLD_FETCH_ERR(clEnqueueMapImage, errcode_ret);
    return CLLD_PTR(clEnqueueMapImage)(
        command_queue, image, blocking_map, map_flags, origin, region,
        image_row_pitch, image_slice_pitch, num_events_in_wait_list,
        event_wait_list, event, errcode_ret);
}

CLLD_DECL(clEnqueueUnmapMemObject);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueUnmapMemObject(cl_command_queue command_queue,
                        cl_mem           memobj,
                        void *           mapped_ptr,
                        cl_uint          num_events_in_wait_list,
                        const cl_event * event_wait_list,
                        cl_event *       event) {
    CLLD_FETCH(clEnqueueUnmapMemObject);
    return CLLD_PTR(clEnqueueUnmapMemObject)(
        command_queue, memobj, mapped_ptr,
        num_events_in_wait_list, event_wait_list, event);
}

#ifdef CL_VERSION_1_2

CLLD_DECL(clEnqueueMigrateMemObjects);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMigrateMemObjects(cl_command_queue       command_queue,
                           cl_uint                num_mem_objects,
                           const cl_mem *         mem_objects,
                           cl_mem_migration_flags flags,
                           cl_uint                num_events_in_wait_list,
                           const cl_event *       event_wait_list,
                           cl_event *             event) {
    CLLD_FETCH(clEnqueueMigrateMemObjects);
    return CLLD_PTR(clEnqueueMigrateMemObjects)(
        command_queue, num_mem_objects, mem_objects, flags,
        num_events_in_wait_list, event_wait_list, event);
}

#endif /* CL_VERSION_1_2 */

CLLD_DECL(clEnqueueNDRangeKernel);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueNDRangeKernel(cl_command_queue command_queue,
                       cl_kernel        kernel,
                       cl_uint          work_dim,
                       const size_t *   global_work_offset,
                       const size_t *   global_work_size,
                       const size_t *   local_work_size,
                       cl_uint          num_events_in_wait_list,
                       const cl_event * event_wait_list,
                       cl_event *       event) {
    CLLD_FETCH(clEnqueueNDRangeKernel);
    return CLLD_PTR(clEnqueueNDRangeKernel)(
        command_queue, kernel, work_dim, global_work_offset,global_work_size,
        local_work_size, num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueNativeKernel);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueNativeKernel(cl_command_queue  command_queue,
                      void (CL_CALLBACK * user_func)(void *),
                      void *            args,
                      size_t            cb_args,
                      cl_uint           num_mem_objects,
                      const cl_mem *    mem_list,
                      const void **     args_mem_loc,
                      cl_uint           num_events_in_wait_list,
                      const cl_event *  event_wait_list,
                      cl_event *        event) {
    CLLD_FETCH(clEnqueueNativeKernel);
    return CLLD_PTR(clEnqueueNativeKernel)(
        command_queue, user_func, args, cb_args, num_mem_objects, mem_list,
        args_mem_loc, num_events_in_wait_list, event_wait_list, event);
}

#ifdef CL_VERSION_1_2

CLLD_DECL(clEnqueueMarkerWithWaitList);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMarkerWithWaitList(cl_command_queue  command_queue,
                            cl_uint           num_events_in_wait_list,
                            const cl_event *  event_wait_list,
                            cl_event *        event) {
    CLLD_FETCH(clEnqueueMarkerWithWaitList);
    return CLLD_PTR(clEnqueueMarkerWithWaitList)(
        command_queue, num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueBarrierWithWaitList);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueBarrierWithWaitList(cl_command_queue  command_queue,
                             cl_uint           num_events_in_wait_list,
                             const cl_event *  event_wait_list,
                             cl_event *        event) {
    CLLD_FETCH(clEnqueueBarrierWithWaitList);
    return CLLD_PTR(clEnqueueBarrierWithWaitList)(
        command_queue, num_events_in_wait_list, event_wait_list, event);
}

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_0

CLLD_DECL(clEnqueueSVMFree);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMFree(cl_command_queue  command_queue,
                 cl_uint           num_svm_pointers,
                 void *            svm_pointers[],
                 void (CL_CALLBACK * pfn_free_func)(cl_command_queue queue,
                                                    cl_uint          num_svm_pointers,
                                                    void *           svm_pointers[],
                                                    void *           user_data),
                 void *            user_data,
                 cl_uint           num_events_in_wait_list,
                 const cl_event *  event_wait_list,
                 cl_event *        event) {
    CLLD_FETCH(clEnqueueSVMFree);
    return CLLD_PTR(clEnqueueSVMFree)(
        command_queue, num_svm_pointers, svm_pointers, pfn_free_func,
        user_data, num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueSVMMemcpy);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMemcpy(cl_command_queue  command_queue,
                   cl_bool           blocking_copy,
                   void *            dst_ptr,
                   const void *      src_ptr,
                   size_t            size,
                   cl_uint           num_events_in_wait_list,
                   const cl_event *  event_wait_list,
                   cl_event *        event) {
    CLLD_FETCH(clEnqueueSVMMemcpy);
    return CLLD_PTR(clEnqueueSVMMemcpy)(
        command_queue, blocking_copy, dst_ptr, src_ptr, size,
        num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueSVMMemFill);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMemFill(cl_command_queue  command_queue,
                    void *            svm_ptr,
                    const void *      pattern,
                    size_t            pattern_size,
                    size_t            size,
                    cl_uint           num_events_in_wait_list,
                    const cl_event *  event_wait_list,
                    cl_event *        event) {
    CLLD_FETCH(clEnqueueSVMMemFill);
    return CLLD_PTR(clEnqueueSVMMemFill)(
        command_queue, svm_ptr, pattern, pattern_size, size,
        num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueSVMMap);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMap(cl_command_queue  command_queue,
                cl_bool           blocking_map,
                cl_map_flags      flags,
                void *            svm_ptr,
                size_t            size,
                cl_uint           num_events_in_wait_list,
                const cl_event *  event_wait_list,
                cl_event *        event) {
    CLLD_FETCH(clEnqueueSVMMap);
    return CLLD_PTR(clEnqueueSVMMap)(
        command_queue, blocking_map, flags, svm_ptr, size,
        num_events_in_wait_list, event_wait_list, event);
}

CLLD_DECL(clEnqueueSVMUnmap);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMUnmap(cl_command_queue  command_queue,
                  void *            svm_ptr,
                  cl_uint           num_events_in_wait_list,
                  const cl_event *  event_wait_list,
                  cl_event *        event) {
    CLLD_FETCH(clEnqueueSVMUnmap);
    return CLLD_PTR(clEnqueueSVMUnmap)(
        command_queue, svm_ptr, num_events_in_wait_list,
        event_wait_list, event);
}

#endif /* CL_VERSION_2_0 */

#ifdef CL_VERSION_2_1

CLLD_DECL(clEnqueueSVMMigrateMem);
inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMigrateMem(cl_command_queue         command_queue,
                       cl_uint                  num_svm_pointers,
                       const void **            svm_pointers,
                       const size_t *           sizes,
                       cl_mem_migration_flags   flags,
                       cl_uint                  num_events_in_wait_list,
                       const cl_event *         event_wait_list,
                       cl_event *               event) {
    CLLD_FETCH(clEnqueueSVMMigrateMem);
    return CLLD_PTR(clEnqueueSVMMigrateMem)(
        command_queue, num_svm_pointers, svm_pointers, sizes,
        flags, num_events_in_wait_list, event_wait_list, event);
}

#endif /* CL_VERSION_2_1 */

#ifdef CL_VERSION_1_2

CLLD_DECL(clGetExtensionFunctionAddressForPlatform);
inline CL_API_ENTRY void * CL_API_CALL
clGetExtensionFunctionAddressForPlatform(cl_platform_id platform,
                                         const char *   func_name) {
    CLLD_FETCH_NULL(clGetExtensionFunctionAddressForPlatform);
    return CLLD_PTR(clGetExtensionFunctionAddressForPlatform)(
        platform, func_name);
}

#endif /* CL_VERSION_1_2 */

#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS

CLLD_DECL(clSetCommandQueueProperty);
inline CL_API_ENTRY cl_int CL_API_CALL
clSetCommandQueueProperty(cl_command_queue              command_queue,
                          cl_command_queue_properties   properties,
                          cl_bool                       enable,
                          cl_command_queue_properties * old_properties) {
    CLLD_FETCH(clSetCommandQueueProperty);
    return CLLD_PTR(clSetCommandQueueProperty)(
        command_queue, properties, enable, old_properties);
}

#endif /* CL_USE_DEPRECATED_OPENCL_1_0_APIS */

/* Deprecated OpenCL 1.1 APIs */

CLLD_DECL(clCreateImage2D);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
clCreateImage2D(cl_context              context,
                cl_mem_flags            flags,
                const cl_image_format * image_format,
                size_t                  image_width,
                size_t                  image_height,
                size_t                  image_row_pitch,
                void *                  host_ptr,
                cl_int *                errcode_ret) {
    CLLD_FETCH_ERR(clCreateImage2D, errcode_ret);
    return CLLD_PTR(clCreateImage2D)(
        context, flags, image_format, image_width,
        image_height, image_row_pitch, host_ptr, errcode_ret);
}

CLLD_DECL(clCreateImage3D);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
clCreateImage3D(cl_context              context,
                cl_mem_flags            flags,
                const cl_image_format * image_format,
                size_t                  image_width,
                size_t                  image_height,
                size_t                  image_depth,
                size_t                  image_row_pitch,
                size_t                  image_slice_pitch,
                void *                  host_ptr,
                cl_int *                errcode_ret) {
    CLLD_FETCH_ERR(clCreateImage3D, errcode_ret);
    return CLLD_PTR(clCreateImage3D)(
        context, flags, image_format, image_width, image_height, image_depth,
        image_row_pitch, image_slice_pitch, host_ptr, errcode_ret);
}

CLLD_DECL(clEnqueueMarker);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
clEnqueueMarker(cl_command_queue    command_queue,
                cl_event *          event) {
    CLLD_FETCH(clEnqueueMarker);
    return CLLD_PTR(clEnqueueMarker)(command_queue, event);
}

CLLD_DECL(clEnqueueWaitForEvents);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
clEnqueueWaitForEvents(cl_command_queue  command_queue,
                       cl_uint           num_events,
                       const cl_event *  event_list) {
    CLLD_FETCH(clEnqueueWaitForEvents);
    return CLLD_PTR(clEnqueueWaitForEvents)(
        command_queue, num_events, event_list);
}

CLLD_DECL(clEnqueueBarrier);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
clEnqueueBarrier(cl_command_queue command_queue) {
    CLLD_FETCH(clEnqueueBarrier);
    return CLLD_PTR(clEnqueueBarrier)(command_queue);
}

CLLD_DECL(clUnloadCompiler);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
clUnloadCompiler(void) {
    CLLD_FETCH(clUnloadCompiler);
    return CLLD_PTR(clUnloadCompiler)();
}

CLLD_DECL(clGetExtensionFunctionAddress);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED void * CL_API_CALL
clGetExtensionFunctionAddress(const char * func_name) {
    CLLD_FETCH_NULL(clGetExtensionFunctionAddress);
    return CLLD_PTR(clGetExtensionFunctionAddress)(func_name);
}

/* Deprecated OpenCL 2.0 APIs */

CLLD_DECL(clCreateCommandQueue);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_command_queue CL_API_CALL
clCreateCommandQueue(cl_context                     context,
                     cl_device_id                   device,
                     cl_command_queue_properties    properties,
                     cl_int *                       errcode_ret) {
    CLLD_FETCH_ERR(clCreateCommandQueue, errcode_ret);
    return CLLD_PTR(clCreateCommandQueue)(
        context, device, properties, errcode_ret);
}

CLLD_DECL(clCreateSampler);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_sampler CL_API_CALL
clCreateSampler(cl_context          context,
                cl_bool             normalized_coords,
                cl_addressing_mode  addressing_mode,
                cl_filter_mode      filter_mode,
                cl_int *            errcode_ret) {
    CLLD_FETCH_ERR(clCreateSampler, errcode_ret);
    return CLLD_PTR(clCreateSampler)(
        context, normalized_coords, addressing_mode, filter_mode, errcode_ret);
}

CLLD_DECL(clEnqueueTask);
inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_int CL_API_CALL
clEnqueueTask(cl_command_queue  command_queue,
              cl_kernel         kernel,
              cl_uint           num_events_in_wait_list,
              const cl_event *  event_wait_list,
              cl_event *        event) {
    CLLD_FETCH(clEnqueueTask);
    return CLLD_PTR(clEnqueueTask)(
        command_queue, kernel, num_events_in_wait_list, event_wait_list, event);
}

#ifdef __cplusplus
}
#endif

#endif /* OPENCL_LOAD */

#endif  /* OPENCL_CL_LOAD_H_ */

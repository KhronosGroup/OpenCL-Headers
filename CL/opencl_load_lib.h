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

#ifndef OPENCL_DLOPEN_LIB_H
#define OPENCL_DLOPEN_LIB_H

#ifdef OPENCL_LOAD

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#include <pthread.h>
#endif

#include <CL/opencl.h>

#ifdef _WIN32
static INIT_ONCE initialized = INIT_ONCE_STATIC_INIT;
HMODULE opencl_lib_handle;
#else
static pthread_once_t initialized = PTHREAD_ONCE_INIT;
void *opencl_lib_handle;
#endif

#ifdef _WIN32
static void extOpenOpenCL_impl(PINIT_ONCE InitOnce, PVOID Parameter, PVOID *lpContext) {
    (void)InitOnce; (void)Parameter; (void)lpContext;
    opencl_lib_handle = LoadLibraryExA(libraryName, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (!opencl_lib_handle && GetLastError() == ERROR_INVALID_PARAMETER)
    {
        opencl_lib_handle = LoadLibraryExA("OpencL", NULL, 0);
    }
}
#else
static void extOpenOpenCL_impl() {
    opencl_lib_handle = dlopen("libOpenCL.so", RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
}
#endif

cl_int extOpenOpenCL() {
#ifdef _WIN32
    InitOnceExecuteOnce(&initialized, extOpenOpenCL_impl, NULL, NULL);
#else
    pthread_once(&initialized, extOpenOpenCL_impl);
#endif
    if (!opencl_lib_handle) {
        return CL_PLATFORM_NOT_FOUND_KHR;
    } else {
        return CL_SUCCESS;
    }
}

extern inline cl_int
extFindOpenCLSymbol(void **pVar, const char *symbolName);

/* Platform APIs */

CLLD_DEF(clGetPlatformIDs);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetPlatformIDs(cl_uint          num_entries,
                 cl_platform_id * platforms,
                 cl_uint *        num_platforms) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetPlatformInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetPlatformInfo(cl_platform_id   platform,
                  cl_platform_info param_name,
                  size_t           param_value_size,
                  void *           param_value,
                  size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Device APIs */

CLLD_DEF(clGetDeviceIDs);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetDeviceIDs(cl_platform_id   platform,
               cl_device_type   device_type,
               cl_uint          num_entries,
               cl_device_id *   devices,
               cl_uint *        num_devices) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetDeviceInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetDeviceInfo(cl_device_id    device,
                cl_device_info  param_name,
                size_t          param_value_size,
                void *          param_value,
                size_t *        param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

CLLD_DEF(clCreateSubDevices);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clCreateSubDevices(cl_device_id                         in_device,
                   const cl_device_partition_property * properties,
                   cl_uint                              num_devices,
                   cl_device_id *                       out_devices,
                   cl_uint *                            num_devices_ret) CL_API_SUFFIX__VERSION_1_2;

CLLD_DEF(clRetainDevice);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clRetainDevice(cl_device_id device) CL_API_SUFFIX__VERSION_1_2;

CLLD_DEF(clReleaseDevice);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseDevice(cl_device_id device) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_1

CLLD_DEF(clSetDefaultDeviceCommandQueue);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetDefaultDeviceCommandQueue(cl_context           context,
                               cl_device_id         device,
                               cl_command_queue     command_queue) CL_API_SUFFIX__VERSION_2_1;

CLLD_DEF(clGetDeviceAndHostTimer);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetDeviceAndHostTimer(cl_device_id    device,
                        cl_ulong*       device_timestamp,
                        cl_ulong*       host_timestamp) CL_API_SUFFIX__VERSION_2_1;

CLLD_DEF(clGetHostTimer);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetHostTimer(cl_device_id device,
               cl_ulong *   host_timestamp) CL_API_SUFFIX__VERSION_2_1;

#endif /* CL_VERSION_2_1 */

/* Context APIs */

CLLD_DEF(clCreateContext);
extern inline CL_API_ENTRY cl_context CL_API_CALL
clCreateContext(const cl_context_properties * properties,
                cl_uint              num_devices,
                const cl_device_id * devices,
                void (CL_CALLBACK * pfn_notify)(const char * errinfo,
                                                const void * private_info,
                                                size_t       cb,
                                                void *       user_data),
                void *               user_data,
                cl_int *             errcode_ret) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clCreateContextFromType);
extern inline CL_API_ENTRY cl_context CL_API_CALL
clCreateContextFromType(const cl_context_properties * properties,
                        cl_device_type      device_type,
                        void (CL_CALLBACK * pfn_notify)(const char * errinfo,
                                                        const void * private_info,
                                                        size_t       cb,
                                                        void *       user_data),
                        void *              user_data,
                        cl_int *            errcode_ret) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clRetainContext);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clRetainContext(cl_context context) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clReleaseContext);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseContext(cl_context context) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetContextInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetContextInfo(cl_context         context,
                 cl_context_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_3_0

CLLD_DEF(clSetContextDestructorCallback);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetContextDestructorCallback(cl_context         context,
                               void (CL_CALLBACK* pfn_notify)(cl_context context,
                                                              void* user_data),
                               void*              user_data) CL_API_SUFFIX__VERSION_3_0;

#endif /* CL_VERSION_3_0 */

/* Command Queue APIs */

#ifdef CL_VERSION_2_0

CLLD_DEF(clCreateCommandQueueWithProperties);
extern inline CL_API_ENTRY cl_command_queue CL_API_CALL
clCreateCommandQueueWithProperties(cl_context               context,
                                   cl_device_id             device,
                                   const cl_queue_properties *    properties,
                                   cl_int *                 errcode_ret) CL_API_SUFFIX__VERSION_2_0;

#endif /* CL_VERSION_2_0 */

CLLD_DEF(clRetainCommandQueue);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clRetainCommandQueue(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clReleaseCommandQueue);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseCommandQueue(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetCommandQueueInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetCommandQueueInfo(cl_command_queue      command_queue,
                      cl_command_queue_info param_name,
                      size_t                param_value_size,
                      void *                param_value,
                      size_t *              param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Memory Object APIs */

CLLD_DEF(clCreateBuffer);
extern inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateBuffer(cl_context   context,
               cl_mem_flags flags,
               size_t       size,
               void *       host_ptr,
               cl_int *     errcode_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

CLLD_DEF(clCreateSubBuffer);
extern inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateSubBuffer(cl_mem                   buffer,
                  cl_mem_flags             flags,
                  cl_buffer_create_type    buffer_create_type,
                  const void *             buffer_create_info,
                  cl_int *                 errcode_ret) CL_API_SUFFIX__VERSION_1_1;
 
#endif /* CL_VERSION_1_1 */

#ifdef CL_VERSION_1_2

CLLD_DEF(clCreateImage);
extern inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateImage(cl_context              context,
              cl_mem_flags            flags,
              const cl_image_format * image_format,
              const cl_image_desc *   image_desc,
              void *                  host_ptr,
              cl_int *                errcode_ret) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_0

CLLD_DEF(clCreatePipe);
extern inline CL_API_ENTRY cl_mem CL_API_CALL
clCreatePipe(cl_context                 context,
             cl_mem_flags               flags,
             cl_uint                    pipe_packet_size,
             cl_uint                    pipe_max_packets,
             const cl_pipe_properties * properties,
             cl_int *                   errcode_ret) CL_API_SUFFIX__VERSION_2_0;

#endif /* CL_VERSION_2_0 */

#ifdef CL_VERSION_3_0

CLLD_DEF(clCreateBufferWithProperties);
extern inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateBufferWithProperties(cl_context                context,
                             const cl_mem_properties * properties,
                             cl_mem_flags              flags,
                             size_t                    size,
                             void *                    host_ptr,
                             cl_int *                  errcode_ret) CL_API_SUFFIX__VERSION_3_0;

CLLD_DEF(clCreateImageWithProperties);
extern inline CL_API_ENTRY cl_mem CL_API_CALL
clCreateImageWithProperties(cl_context                context,
                            const cl_mem_properties * properties,
                            cl_mem_flags              flags,
                            const cl_image_format *   image_format,
                            const cl_image_desc *     image_desc,
                            void *                    host_ptr,
                            cl_int *                  errcode_ret) CL_API_SUFFIX__VERSION_3_0;

#endif /* CL_VERSION_3_0 */

CLLD_DEF(clRetainMemObject);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clRetainMemObject(cl_mem memobj) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clReleaseMemObject);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseMemObject(cl_mem memobj) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetSupportedImageFormats);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetSupportedImageFormats(cl_context           context,
                           cl_mem_flags         flags,
                           cl_mem_object_type   image_type,
                           cl_uint              num_entries,
                           cl_image_format *    image_formats,
                           cl_uint *            num_image_formats) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetMemObjectInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetMemObjectInfo(cl_mem           memobj,
                   cl_mem_info      param_name,
                   size_t           param_value_size,
                   void *           param_value,
                   size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetImageInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetImageInfo(cl_mem           image,
               cl_image_info    param_name,
               size_t           param_value_size,
               void *           param_value,
               size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_0

CLLD_DEF(clGetPipeInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetPipeInfo(cl_mem           pipe,
              cl_pipe_info     param_name,
              size_t           param_value_size,
              void *           param_value,
              size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_2_0;

#endif /* CL_VERSION_2_0 */

#ifdef CL_VERSION_1_1

CLLD_DEF(clSetMemObjectDestructorCallback);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetMemObjectDestructorCallback(cl_mem memobj,
                                 void (CL_CALLBACK * pfn_notify)(cl_mem memobj,
                                                                 void * user_data),
                                 void * user_data) CL_API_SUFFIX__VERSION_1_1;

#endif /* CL_VERSION_1_1 */

#ifdef CL_VERSION_2_0

CLLD_DEF(clSVMAlloc);
extern inline CL_API_ENTRY void * CL_API_CALL
clSVMAlloc(cl_context       context,
           cl_svm_mem_flags flags,
           size_t           size,
           cl_uint          alignment) CL_API_SUFFIX__VERSION_2_0;

CLLD_DEF(clSVMFree);
extern inline CL_API_ENTRY void CL_API_CALL
clSVMFree(cl_context        context,
          void *            svm_pointer) CL_API_SUFFIX__VERSION_2_0;

#endif /* CL_VERSION_2_0 */

/* Sampler APIs */

#ifdef CL_VERSION_2_0

CLLD_DEF(clCreateSamplerWithProperties);
extern inline CL_API_ENTRY cl_sampler CL_API_CALL
clCreateSamplerWithProperties(cl_context                     context,
                              const cl_sampler_properties *  sampler_properties,
                              cl_int *                       errcode_ret) CL_API_SUFFIX__VERSION_2_0;

#endif /* CL_VERSION_2_0 */

CLLD_DEF(clRetainSampler);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clRetainSampler(cl_sampler sampler) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clReleaseSampler);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseSampler(cl_sampler sampler) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetSamplerInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetSamplerInfo(cl_sampler         sampler,
                 cl_sampler_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Program Object APIs */

CLLD_DEF(clCreateProgramWithSource);
extern inline CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithSource(cl_context        context,
                          cl_uint           count,
                          const char **     strings,
                          const size_t *    lengths,
                          cl_int *          errcode_ret) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clCreateProgramWithBinary);
extern inline CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithBinary(cl_context                     context,
                          cl_uint                        num_devices,
                          const cl_device_id *           device_list,
                          const size_t *                 lengths,
                          const unsigned char **         binaries,
                          cl_int *                       binary_status,
                          cl_int *                       errcode_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

CLLD_DEF(clCreateProgramWithBuiltInKernels);
extern inline CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithBuiltInKernels(cl_context            context,
                                  cl_uint               num_devices,
                                  const cl_device_id *  device_list,
                                  const char *          kernel_names,
                                  cl_int *              errcode_ret) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_1

CLLD_DEF(clCreateProgramWithIL);
extern inline CL_API_ENTRY cl_program CL_API_CALL
clCreateProgramWithIL(cl_context    context,
                     const void*    il,
                     size_t         length,
                     cl_int*        errcode_ret) CL_API_SUFFIX__VERSION_2_1;

#endif /* CL_VERSION_2_1 */

CLLD_DEF(clRetainProgram);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clRetainProgram(cl_program program) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clReleaseProgram);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseProgram(cl_program program) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clBuildProgram);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clBuildProgram(cl_program           program,
               cl_uint              num_devices,
               const cl_device_id * device_list,
               const char *         options,
               void (CL_CALLBACK *  pfn_notify)(cl_program program,
                                                void * user_data),
               void *               user_data) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

CLLD_DEF(clCompileProgram);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clCompileProgram(cl_program           program,
                 cl_uint              num_devices,
                 const cl_device_id * device_list,
                 const char *         options,
                 cl_uint              num_input_headers,
                 const cl_program *   input_headers,
                 const char **        header_include_names,
                 void (CL_CALLBACK *  pfn_notify)(cl_program program,
                                                  void * user_data),
                 void *               user_data) CL_API_SUFFIX__VERSION_1_2;

CLLD_DEF(clLinkProgram);
extern inline CL_API_ENTRY cl_program CL_API_CALL
clLinkProgram(cl_context           context,
              cl_uint              num_devices,
              const cl_device_id * device_list,
              const char *         options,
              cl_uint              num_input_programs,
              const cl_program *   input_programs,
              void (CL_CALLBACK *  pfn_notify)(cl_program program,
                                               void * user_data),
              void *               user_data,
              cl_int *             errcode_ret) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_2

CLLD_DEF(clSetProgramReleaseCallback);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_2_2_DEPRECATED cl_int CL_API_CALL
clSetProgramReleaseCallback(cl_program          program,
                            void (CL_CALLBACK * pfn_notify)(cl_program program,
                                                            void * user_data),
                            void *              user_data) CL_API_SUFFIX__VERSION_2_2_DEPRECATED;

CLLD_DEF(clSetProgramSpecializationConstant);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetProgramSpecializationConstant(cl_program  program,
                                   cl_uint     spec_id,
                                   size_t      spec_size,
                                   const void* spec_value) CL_API_SUFFIX__VERSION_2_2;

#endif /* CL_VERSION_2_2 */

#ifdef CL_VERSION_1_2

CLLD_DEF(clUnloadPlatformCompiler);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clUnloadPlatformCompiler(cl_platform_id platform) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

CLLD_DEF(clGetProgramInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetProgramInfo(cl_program         program,
                 cl_program_info    param_name,
                 size_t             param_value_size,
                 void *             param_value,
                 size_t *           param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetProgramBuildInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetProgramBuildInfo(cl_program            program,
                      cl_device_id          device,
                      cl_program_build_info param_name,
                      size_t                param_value_size,
                      void *                param_value,
                      size_t *              param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Kernel Object APIs */

CLLD_DEF(clCreateKernel);
extern inline CL_API_ENTRY cl_kernel CL_API_CALL
clCreateKernel(cl_program      program,
               const char *    kernel_name,
               cl_int *        errcode_ret) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clCreateKernelsInProgram);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clCreateKernelsInProgram(cl_program     program,
                         cl_uint        num_kernels,
                         cl_kernel *    kernels,
                         cl_uint *      num_kernels_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_1

CLLD_DEF(clCloneKernel);
extern inline CL_API_ENTRY cl_kernel CL_API_CALL
clCloneKernel(cl_kernel     source_kernel,
              cl_int*       errcode_ret) CL_API_SUFFIX__VERSION_2_1;

#endif /* CL_VERSION_2_1 */

CLLD_DEF(clRetainKernel);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clRetainKernel(cl_kernel    kernel) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clReleaseKernel);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseKernel(cl_kernel    kernel) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clSetKernelArg);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetKernelArg(cl_kernel    kernel,
               cl_uint      arg_index,
               size_t       arg_size,
               const void * arg_value) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_0

CLLD_DEF(clSetKernelArgSVMPointer);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetKernelArgSVMPointer(cl_kernel    kernel,
                         cl_uint      arg_index,
                         const void * arg_value) CL_API_SUFFIX__VERSION_2_0;

CLLD_DEF(clSetKernelExecInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetKernelExecInfo(cl_kernel            kernel,
                    cl_kernel_exec_info  param_name,
                    size_t               param_value_size,
                    const void *         param_value) CL_API_SUFFIX__VERSION_2_0;

#endif /* CL_VERSION_2_0 */

CLLD_DEF(clGetKernelInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetKernelInfo(cl_kernel       kernel,
                cl_kernel_info  param_name,
                size_t          param_value_size,
                void *          param_value,
                size_t *        param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

CLLD_DEF(clGetKernelArgInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetKernelArgInfo(cl_kernel       kernel,
                   cl_uint         arg_indx,
                   cl_kernel_arg_info  param_name,
                   size_t          param_value_size,
                   void *          param_value,
                   size_t *        param_value_size_ret) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

CLLD_DEF(clGetKernelWorkGroupInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetKernelWorkGroupInfo(cl_kernel                  kernel,
                         cl_device_id               device,
                         cl_kernel_work_group_info  param_name,
                         size_t                     param_value_size,
                         void *                     param_value,
                         size_t *                   param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_1

CLLD_DEF(clGetKernelSubGroupInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetKernelSubGroupInfo(cl_kernel                   kernel,
                        cl_device_id                device,
                        cl_kernel_sub_group_info    param_name,
                        size_t                      input_value_size,
                        const void*                 input_value,
                        size_t                      param_value_size,
                        void*                       param_value,
                        size_t*                     param_value_size_ret) CL_API_SUFFIX__VERSION_2_1;

#endif /* CL_VERSION_2_1 */

/* Event Object APIs */

CLLD_DEF(clWaitForEvents);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clWaitForEvents(cl_uint             num_events,
                const cl_event *    event_list) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clGetEventInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetEventInfo(cl_event         event,
               cl_event_info    param_name,
               size_t           param_value_size,
               void *           param_value,
               size_t *         param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

CLLD_DEF(clCreateUserEvent);
extern inline CL_API_ENTRY cl_event CL_API_CALL
clCreateUserEvent(cl_context    context,
                  cl_int *      errcode_ret) CL_API_SUFFIX__VERSION_1_1;

#endif /* CL_VERSION_1_1 */

CLLD_DEF(clRetainEvent);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clRetainEvent(cl_event event) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clReleaseEvent);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clReleaseEvent(cl_event event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

CLLD_DEF(clSetUserEventStatus);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetUserEventStatus(cl_event   event,
                     cl_int     execution_status) CL_API_SUFFIX__VERSION_1_1;

CLLD_DEF(clSetEventCallback);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetEventCallback(cl_event    event,
                   cl_int      command_exec_callback_type,
                   void (CL_CALLBACK * pfn_notify)(cl_event event,
                                                   cl_int   event_command_status,
                                                   void *   user_data),
                   void *      user_data) CL_API_SUFFIX__VERSION_1_1;

#endif /* CL_VERSION_1_1 */

/* Profiling APIs */

CLLD_DEF(clGetEventProfilingInfo);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clGetEventProfilingInfo(cl_event            event,
                        cl_profiling_info   param_name,
                        size_t              param_value_size,
                        void *              param_value,
                        size_t *            param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

/* Flush and Finish APIs */

CLLD_DEF(clFlush);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clFlush(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clFinish);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clFinish(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_0;

/* Enqueued Commands APIs */

CLLD_DEF(clEnqueueReadBuffer);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueReadBuffer(cl_command_queue    command_queue,
                    cl_mem              buffer,
                    cl_bool             blocking_read,
                    size_t              offset,
                    size_t              size,
                    void *              ptr,
                    cl_uint             num_events_in_wait_list,
                    const cl_event *    event_wait_list,
                    cl_event *          event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

CLLD_DEF(clEnqueueReadBufferRect);
extern inline CL_API_ENTRY cl_int CL_API_CALL
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
                        cl_event *          event) CL_API_SUFFIX__VERSION_1_1;

#endif /* CL_VERSION_1_1 */

CLLD_DEF(clEnqueueWriteBuffer);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueWriteBuffer(cl_command_queue   command_queue,
                     cl_mem             buffer,
                     cl_bool            blocking_write,
                     size_t             offset,
                     size_t             size,
                     const void *       ptr,
                     cl_uint            num_events_in_wait_list,
                     const cl_event *   event_wait_list,
                     cl_event *         event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

CLLD_DEF(clEnqueueWriteBufferRect);
extern inline CL_API_ENTRY cl_int CL_API_CALL
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
                         cl_event *          event) CL_API_SUFFIX__VERSION_1_1;

#endif /* CL_VERSION_1_1 */

#ifdef CL_VERSION_1_2

CLLD_DEF(clEnqueueFillBuffer);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueFillBuffer(cl_command_queue   command_queue,
                    cl_mem             buffer,
                    const void *       pattern,
                    size_t             pattern_size,
                    size_t             offset,
                    size_t             size,
                    cl_uint            num_events_in_wait_list,
                    const cl_event *   event_wait_list,
                    cl_event *         event) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

CLLD_DEF(clEnqueueCopyBuffer);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBuffer(cl_command_queue    command_queue,
                    cl_mem              src_buffer,
                    cl_mem              dst_buffer,
                    size_t              src_offset,
                    size_t              dst_offset,
                    size_t              size,
                    cl_uint             num_events_in_wait_list,
                    const cl_event *    event_wait_list,
                    cl_event *          event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

CLLD_DEF(clEnqueueCopyBufferRect);
extern inline CL_API_ENTRY cl_int CL_API_CALL
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
                        cl_event *          event) CL_API_SUFFIX__VERSION_1_1;

#endif /* CL_VERSION_1_1 */

CLLD_DEF(clEnqueueReadImage);
extern inline CL_API_ENTRY cl_int CL_API_CALL
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
                   cl_event *           event) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clEnqueueWriteImage);
extern inline CL_API_ENTRY cl_int CL_API_CALL
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
                    cl_event *          event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

CLLD_DEF(clEnqueueFillImage);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueFillImage(cl_command_queue   command_queue,
                   cl_mem             image,
                   const void *       fill_color,
                   const size_t *     origin,
                   const size_t *     region,
                   cl_uint            num_events_in_wait_list,
                   const cl_event *   event_wait_list,
                   cl_event *         event) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

CLLD_DEF(clEnqueueCopyImage);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyImage(cl_command_queue     command_queue,
                   cl_mem               src_image,
                   cl_mem               dst_image,
                   const size_t *       src_origin,
                   const size_t *       dst_origin,
                   const size_t *       region,
                   cl_uint              num_events_in_wait_list,
                   const cl_event *     event_wait_list,
                   cl_event *           event) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clEnqueueCopyImageToBuffer);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyImageToBuffer(cl_command_queue command_queue,
                           cl_mem           src_image,
                           cl_mem           dst_buffer,
                           const size_t *   src_origin,
                           const size_t *   region,
                           size_t           dst_offset,
                           cl_uint          num_events_in_wait_list,
                           const cl_event * event_wait_list,
                           cl_event *       event) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clEnqueueCopyBufferToImage);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueCopyBufferToImage(cl_command_queue command_queue,
                           cl_mem           src_buffer,
                           cl_mem           dst_image,
                           size_t           src_offset,
                           const size_t *   dst_origin,
                           const size_t *   region,
                           cl_uint          num_events_in_wait_list,
                           const cl_event * event_wait_list,
                           cl_event *       event) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clEnqueueMapBuffer);
extern inline CL_API_ENTRY void * CL_API_CALL
clEnqueueMapBuffer(cl_command_queue command_queue,
                   cl_mem           buffer,
                   cl_bool          blocking_map,
                   cl_map_flags     map_flags,
                   size_t           offset,
                   size_t           size,
                   cl_uint          num_events_in_wait_list,
                   const cl_event * event_wait_list,
                   cl_event *       event,
                   cl_int *         errcode_ret) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clEnqueueMapImage);
extern inline CL_API_ENTRY void * CL_API_CALL
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
                  cl_int *          errcode_ret) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clEnqueueUnmapMemObject);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueUnmapMemObject(cl_command_queue command_queue,
                        cl_mem           memobj,
                        void *           mapped_ptr,
                        cl_uint          num_events_in_wait_list,
                        const cl_event * event_wait_list,
                        cl_event *       event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

CLLD_DEF(clEnqueueMigrateMemObjects);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMigrateMemObjects(cl_command_queue       command_queue,
                           cl_uint                num_mem_objects,
                           const cl_mem *         mem_objects,
                           cl_mem_migration_flags flags,
                           cl_uint                num_events_in_wait_list,
                           const cl_event *       event_wait_list,
                           cl_event *             event) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

CLLD_DEF(clEnqueueNDRangeKernel);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueNDRangeKernel(cl_command_queue command_queue,
                       cl_kernel        kernel,
                       cl_uint          work_dim,
                       const size_t *   global_work_offset,
                       const size_t *   global_work_size,
                       const size_t *   local_work_size,
                       cl_uint          num_events_in_wait_list,
                       const cl_event * event_wait_list,
                       cl_event *       event) CL_API_SUFFIX__VERSION_1_0;

CLLD_DEF(clEnqueueNativeKernel);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueNativeKernel(cl_command_queue  command_queue,
                      void (CL_CALLBACK * user_func)(void *),
                      void *            args,
                      size_t            cb_args,
                      cl_uint           num_mem_objects,
                      const cl_mem *    mem_list,
                      const void **     args_mem_loc,
                      cl_uint           num_events_in_wait_list,
                      const cl_event *  event_wait_list,
                      cl_event *        event) CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

CLLD_DEF(clEnqueueMarkerWithWaitList);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMarkerWithWaitList(cl_command_queue  command_queue,
                            cl_uint           num_events_in_wait_list,
                            const cl_event *  event_wait_list,
                            cl_event *        event) CL_API_SUFFIX__VERSION_1_2;

CLLD_DEF(clEnqueueBarrierWithWaitList);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueBarrierWithWaitList(cl_command_queue  command_queue,
                             cl_uint           num_events_in_wait_list,
                             const cl_event *  event_wait_list,
                             cl_event *        event) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

#ifdef CL_VERSION_2_0

CLLD_DEF(clEnqueueSVMFree);
extern inline CL_API_ENTRY cl_int CL_API_CALL
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
                 cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

CLLD_DEF(clEnqueueSVMMemcpy);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMemcpy(cl_command_queue  command_queue,
                   cl_bool           blocking_copy,
                   void *            dst_ptr,
                   const void *      src_ptr,
                   size_t            size,
                   cl_uint           num_events_in_wait_list,
                   const cl_event *  event_wait_list,
                   cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

CLLD_DEF(clEnqueueSVMMemFill);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMemFill(cl_command_queue  command_queue,
                    void *            svm_ptr,
                    const void *      pattern,
                    size_t            pattern_size,
                    size_t            size,
                    cl_uint           num_events_in_wait_list,
                    const cl_event *  event_wait_list,
                    cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

CLLD_DEF(clEnqueueSVMMap);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMap(cl_command_queue  command_queue,
                cl_bool           blocking_map,
                cl_map_flags      flags,
                void *            svm_ptr,
                size_t            size,
                cl_uint           num_events_in_wait_list,
                const cl_event *  event_wait_list,
                cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

CLLD_DEF(clEnqueueSVMUnmap);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMUnmap(cl_command_queue  command_queue,
                  void *            svm_ptr,
                  cl_uint           num_events_in_wait_list,
                  const cl_event *  event_wait_list,
                  cl_event *        event) CL_API_SUFFIX__VERSION_2_0;

#endif /* CL_VERSION_2_0 */

#ifdef CL_VERSION_2_1

CLLD_DEF(clEnqueueSVMMigrateMem);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clEnqueueSVMMigrateMem(cl_command_queue         command_queue,
                       cl_uint                  num_svm_pointers,
                       const void **            svm_pointers,
                       const size_t *           sizes,
                       cl_mem_migration_flags   flags,
                       cl_uint                  num_events_in_wait_list,
                       const cl_event *         event_wait_list,
                       cl_event *               event) CL_API_SUFFIX__VERSION_2_1;

#endif /* CL_VERSION_2_1 */

#ifdef CL_VERSION_1_2

CLLD_DEF(clGetExtensionFunctionAddressForPlatform);
extern inline CL_API_ENTRY void * CL_API_CALL
clGetExtensionFunctionAddressForPlatform(cl_platform_id platform,
                                         const char *   func_name) CL_API_SUFFIX__VERSION_1_2;

#endif /* CL_VERSION_1_2 */

#ifdef CL_USE_DEPRECATED_OPENCL_1_0_APIS

CLLD_DEF(clSetCommandQueueProperty);
extern inline CL_API_ENTRY cl_int CL_API_CALL
clSetCommandQueueProperty(cl_command_queue              command_queue,
                          cl_command_queue_properties   properties,
                          cl_bool                       enable,
                          cl_command_queue_properties * old_properties) CL_API_SUFFIX__VERSION_1_0_DEPRECATED;

#endif /* CL_USE_DEPRECATED_OPENCL_1_0_APIS */

CLLD_DEF(clCreateImage2D);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
clCreateImage2D(cl_context              context,
                cl_mem_flags            flags,
                const cl_image_format * image_format,
                size_t                  image_width,
                size_t                  image_height,
                size_t                  image_row_pitch,
                void *                  host_ptr,
                cl_int *                errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

CLLD_DEF(clCreateImage3D);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_mem CL_API_CALL
clCreateImage3D(cl_context              context,
                cl_mem_flags            flags,
                const cl_image_format * image_format,
                size_t                  image_width,
                size_t                  image_height,
                size_t                  image_depth,
                size_t                  image_row_pitch,
                size_t                  image_slice_pitch,
                void *                  host_ptr,
                cl_int *                errcode_ret) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

CLLD_DEF(clEnqueueMarker);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
clEnqueueMarker(cl_command_queue    command_queue,
                cl_event *          event) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

CLLD_DEF(clEnqueueWaitForEvents);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
clEnqueueWaitForEvents(cl_command_queue  command_queue,
                       cl_uint           num_events,
                       const cl_event *  event_list) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

CLLD_DEF(clEnqueueBarrier);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
clEnqueueBarrier(cl_command_queue command_queue) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

CLLD_DEF(clUnloadCompiler);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED cl_int CL_API_CALL
clUnloadCompiler(void) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

CLLD_DEF(clGetExtensionFunctionAddress);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_1_DEPRECATED void * CL_API_CALL
clGetExtensionFunctionAddress(const char * func_name) CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

CLLD_DEF(clCreateCommandQueue);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_command_queue CL_API_CALL
clCreateCommandQueue(cl_context                     context,
                     cl_device_id                   device,
                     cl_command_queue_properties    properties,
                     cl_int *                       errcode_ret) CL_API_SUFFIX__VERSION_1_2_DEPRECATED;

CLLD_DEF(clCreateSampler);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_sampler CL_API_CALL
clCreateSampler(cl_context          context,
                cl_bool             normalized_coords,
                cl_addressing_mode  addressing_mode,
                cl_filter_mode      filter_mode,
                cl_int *            errcode_ret) CL_API_SUFFIX__VERSION_1_2_DEPRECATED;

CLLD_DEF(clEnqueueTask);
extern inline CL_API_ENTRY CL_API_PREFIX__VERSION_1_2_DEPRECATED cl_int CL_API_CALL
clEnqueueTask(cl_command_queue  command_queue,
              cl_kernel         kernel,
              cl_uint           num_events_in_wait_list,
              const cl_event *  event_wait_list,
              cl_event *        event) CL_API_SUFFIX__VERSION_1_2_DEPRECATED;

#endif /* OPENCL_LOAD */

#endif /* OPENCL_DLOPEN_lib_H */

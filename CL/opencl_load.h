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

#ifndef OPENCL_DLOPEN_H
#define OPENCL_DLOPEN_H

#ifdef OPENCL_LOAD

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#include <pthread.h>
#endif
#include<CL/cl_api_ptrs.h>
#include<CL/cl_egl_api_ptrs.h>
#include<CL/cl_ext_api_ptrs.h>
#include<CL/cl_gl_api_ptrs.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
extern HMODULE opencl_lib_handle;
#else
extern void * opencl_lib_handle;
#endif

typedef struct _opencl_load_dispatch {
  /* OpenCL 1.0 */
  cl_api_clGetPlatformIDs clGetPlatformIDs;
  cl_api_clGetPlatformInfo clGetPlatformInfo;
  cl_api_clGetDeviceIDs clGetDeviceIDs;
  cl_api_clGetDeviceInfo clGetDeviceInfo;
  cl_api_clCreateContext clCreateContext;
  cl_api_clCreateContextFromType clCreateContextFromType;
  cl_api_clRetainContext clRetainContext;
  cl_api_clReleaseContext clReleaseContext;
  cl_api_clGetContextInfo clGetContextInfo;
  cl_api_clCreateCommandQueue clCreateCommandQueue;
  cl_api_clRetainCommandQueue clRetainCommandQueue;
  cl_api_clReleaseCommandQueue clReleaseCommandQueue;
  cl_api_clGetCommandQueueInfo clGetCommandQueueInfo;
  cl_api_clSetCommandQueueProperty clSetCommandQueueProperty;
  cl_api_clCreateBuffer clCreateBuffer;
  cl_api_clCreateImage2D clCreateImage2D;
  cl_api_clCreateImage3D clCreateImage3D;
  cl_api_clRetainMemObject clRetainMemObject;
  cl_api_clReleaseMemObject clReleaseMemObject;
  cl_api_clGetSupportedImageFormats clGetSupportedImageFormats;
  cl_api_clGetMemObjectInfo clGetMemObjectInfo;
  cl_api_clGetImageInfo clGetImageInfo;
  cl_api_clCreateSampler clCreateSampler;
  cl_api_clRetainSampler clRetainSampler;
  cl_api_clReleaseSampler clReleaseSampler;
  cl_api_clGetSamplerInfo clGetSamplerInfo;
  cl_api_clCreateProgramWithSource clCreateProgramWithSource;
  cl_api_clCreateProgramWithBinary clCreateProgramWithBinary;
  cl_api_clRetainProgram clRetainProgram;
  cl_api_clReleaseProgram clReleaseProgram;
  cl_api_clBuildProgram clBuildProgram;
  cl_api_clUnloadCompiler clUnloadCompiler;
  cl_api_clGetProgramInfo clGetProgramInfo;
  cl_api_clGetProgramBuildInfo clGetProgramBuildInfo;
  cl_api_clCreateKernel clCreateKernel;
  cl_api_clCreateKernelsInProgram clCreateKernelsInProgram;
  cl_api_clRetainKernel clRetainKernel;
  cl_api_clReleaseKernel clReleaseKernel;
  cl_api_clSetKernelArg clSetKernelArg;
  cl_api_clGetKernelInfo clGetKernelInfo;
  cl_api_clGetKernelWorkGroupInfo clGetKernelWorkGroupInfo;
  cl_api_clWaitForEvents clWaitForEvents;
  cl_api_clGetEventInfo clGetEventInfo;
  cl_api_clRetainEvent clRetainEvent;
  cl_api_clReleaseEvent clReleaseEvent;
  cl_api_clGetEventProfilingInfo clGetEventProfilingInfo;
  cl_api_clFlush clFlush;
  cl_api_clFinish clFinish;
  cl_api_clEnqueueReadBuffer clEnqueueReadBuffer;
  cl_api_clEnqueueWriteBuffer clEnqueueWriteBuffer;
  cl_api_clEnqueueCopyBuffer clEnqueueCopyBuffer;
  cl_api_clEnqueueReadImage clEnqueueReadImage;
  cl_api_clEnqueueWriteImage clEnqueueWriteImage;
  cl_api_clEnqueueCopyImage clEnqueueCopyImage;
  cl_api_clEnqueueCopyImageToBuffer clEnqueueCopyImageToBuffer;
  cl_api_clEnqueueCopyBufferToImage clEnqueueCopyBufferToImage;
  cl_api_clEnqueueMapBuffer clEnqueueMapBuffer;
  cl_api_clEnqueueMapImage clEnqueueMapImage;
  cl_api_clEnqueueUnmapMemObject clEnqueueUnmapMemObject;
  cl_api_clEnqueueNDRangeKernel clEnqueueNDRangeKernel;
  cl_api_clEnqueueTask clEnqueueTask;
  cl_api_clEnqueueNativeKernel clEnqueueNativeKernel;
  cl_api_clEnqueueMarker clEnqueueMarker;
  cl_api_clEnqueueWaitForEvents clEnqueueWaitForEvents;
  cl_api_clEnqueueBarrier clEnqueueBarrier;
  cl_api_clGetExtensionFunctionAddress clGetExtensionFunctionAddress;
  cl_api_clCreateFromGLBuffer clCreateFromGLBuffer;
  cl_api_clCreateFromGLTexture2D clCreateFromGLTexture2D;
  cl_api_clCreateFromGLTexture3D clCreateFromGLTexture3D;
  cl_api_clCreateFromGLRenderbuffer clCreateFromGLRenderbuffer;
  cl_api_clGetGLObjectInfo clGetGLObjectInfo;
  cl_api_clGetGLTextureInfo clGetGLTextureInfo;
  cl_api_clEnqueueAcquireGLObjects clEnqueueAcquireGLObjects;
  cl_api_clEnqueueReleaseGLObjects clEnqueueReleaseGLObjects;
  cl_api_clGetGLContextInfoKHR clGetGLContextInfoKHR;

  /* OpenCL 1.1 */
  cl_api_clSetEventCallback clSetEventCallback;
  cl_api_clCreateSubBuffer clCreateSubBuffer;
  cl_api_clSetMemObjectDestructorCallback clSetMemObjectDestructorCallback;
  cl_api_clCreateUserEvent clCreateUserEvent;
  cl_api_clSetUserEventStatus clSetUserEventStatus;
  cl_api_clEnqueueReadBufferRect clEnqueueReadBufferRect;
  cl_api_clEnqueueWriteBufferRect clEnqueueWriteBufferRect;
  cl_api_clEnqueueCopyBufferRect clEnqueueCopyBufferRect;

  /* cl_ext_device_fission */
  cl_api_clCreateSubDevicesEXT clCreateSubDevicesEXT;
  cl_api_clRetainDeviceEXT clRetainDeviceEXT;
  cl_api_clReleaseDeviceEXT clReleaseDeviceEXT;

  /* cl_khr_gl_event */
  cl_api_clCreateEventFromGLsyncKHR clCreateEventFromGLsyncKHR;

  /* OpenCL 1.2 */
  cl_api_clCreateSubDevices clCreateSubDevices;
  cl_api_clRetainDevice clRetainDevice;
  cl_api_clReleaseDevice clReleaseDevice;
  cl_api_clCreateImage clCreateImage;
  cl_api_clCreateProgramWithBuiltInKernels clCreateProgramWithBuiltInKernels;
  cl_api_clCompileProgram clCompileProgram;
  cl_api_clLinkProgram clLinkProgram;
  cl_api_clUnloadPlatformCompiler clUnloadPlatformCompiler;
  cl_api_clGetKernelArgInfo clGetKernelArgInfo;
  cl_api_clEnqueueFillBuffer clEnqueueFillBuffer;
  cl_api_clEnqueueFillImage clEnqueueFillImage;
  cl_api_clEnqueueMigrateMemObjects clEnqueueMigrateMemObjects;
  cl_api_clEnqueueMarkerWithWaitList clEnqueueMarkerWithWaitList;
  cl_api_clEnqueueBarrierWithWaitList clEnqueueBarrierWithWaitList;
  cl_api_clGetExtensionFunctionAddressForPlatform
  clGetExtensionFunctionAddressForPlatform;
  cl_api_clCreateFromGLTexture clCreateFromGLTexture;

  /* cl_khr_egl_image */
  cl_api_clCreateFromEGLImageKHR clCreateFromEGLImageKHR;
  cl_api_clEnqueueAcquireEGLObjectsKHR clEnqueueAcquireEGLObjectsKHR;
  cl_api_clEnqueueReleaseEGLObjectsKHR clEnqueueReleaseEGLObjectsKHR;

  /* cl_khr_egl_event */
  cl_api_clCreateEventFromEGLSyncKHR clCreateEventFromEGLSyncKHR;

  /* OpenCL 2.0 */
  cl_api_clCreateCommandQueueWithProperties clCreateCommandQueueWithProperties;
  cl_api_clCreatePipe clCreatePipe;
  cl_api_clGetPipeInfo clGetPipeInfo;
  cl_api_clSVMAlloc clSVMAlloc;
  cl_api_clSVMFree clSVMFree;
  cl_api_clEnqueueSVMFree clEnqueueSVMFree;
  cl_api_clEnqueueSVMMemcpy clEnqueueSVMMemcpy;
  cl_api_clEnqueueSVMMemFill clEnqueueSVMMemFill;
  cl_api_clEnqueueSVMMap clEnqueueSVMMap;
  cl_api_clEnqueueSVMUnmap clEnqueueSVMUnmap;
  cl_api_clCreateSamplerWithProperties clCreateSamplerWithProperties;
  cl_api_clSetKernelArgSVMPointer clSetKernelArgSVMPointer;
  cl_api_clSetKernelExecInfo clSetKernelExecInfo;

  /* cl_khr_sub_groups */
  cl_api_clGetKernelSubGroupInfoKHR clGetKernelSubGroupInfoKHR;

  /* OpenCL 2.1 */
  cl_api_clCloneKernel clCloneKernel;
  cl_api_clCreateProgramWithIL clCreateProgramWithIL;
  cl_api_clEnqueueSVMMigrateMem clEnqueueSVMMigrateMem;
  cl_api_clGetDeviceAndHostTimer clGetDeviceAndHostTimer;
  cl_api_clGetHostTimer clGetHostTimer;
  cl_api_clGetKernelSubGroupInfo clGetKernelSubGroupInfo;
  cl_api_clSetDefaultDeviceCommandQueue clSetDefaultDeviceCommandQueue;

  /* OpenCL 2.2 */
  cl_api_clSetProgramReleaseCallback clSetProgramReleaseCallback;
  cl_api_clSetProgramSpecializationConstant clSetProgramSpecializationConstant;

  /* OpenCL 3.0 */
  cl_api_clCreateBufferWithProperties clCreateBufferWithProperties;
  cl_api_clCreateImageWithProperties clCreateImageWithProperties;
  cl_api_clSetContextDestructorCallback clSetContextDestructorCallback;

} opencl_load_dispatch;



extern opencl_load_dispatch opencl_lib_dispatch;

cl_int extOpenOpenCL();

static inline cl_int
extFindOpenCLSymbol(void **pVar, const char *symbolName) {
  if(!opencl_lib_handle) {
    cl_int err = extOpenOpenCL();
    if(err != CL_SUCCESS)
      return err;
  }
  *pVar = dlsym(opencl_lib_handle, symbolName);
  if (!*pVar)
    return CL_INVALID_OPERATION;
  else
    return CL_SUCCESS;
}

#define CLLD_INLINE static inline

#define CLLD_PTR_NAME(name) opencl_lib_dispatch.name

#define CLLD_PTR CLLD_PTR_NAME

#define CLLD_FETCH_SYMBOL(name) \
extFindOpenCLSymbol((void**)&CLLD_PTR_NAME(name), #name)

#define CLLD_FETCH_RET(name, ret) \
do { \
    if (!CLLD_PTR_NAME(name)) { \
        cl_int _err = CLLD_FETCH_SYMBOL(name); \
        if (_err != CL_SUCCESS) return ret; \
    } \
} while(0)

#define CLLD_FETCH(name) CLLD_FETCH_RET(name, _err)
#define CLLD_FETCH_NULL(name) CLLD_FETCH_RET(name, NULL)
#define CLLD_FETCH_NOERR(name) CLLD_FETCH_RET(name, )

#define CLLD_FETCH_ERR(name, errcode_ret) \
do { \
    if (!CLLD_PTR(name)) { \
        cl_int _err = CLLD_FETCH_SYMBOL(name); \
        if (_err != CL_SUCCESS) { \
            if (errcode_ret) \
              *errcode_ret = _err; \
            return NULL; \
        } \
    } \
} while(0)

#include<CL/cl_load.h>
#include<CL/cl_egl_load.h>
#include<CL/cl_ext_load.h>
#include<CL/cl_gl_load.h>

#ifdef __cplusplus
}
#endif

#endif /* OPENCL_LOAD */

#endif /* OPENCL_DLOPEN_H */

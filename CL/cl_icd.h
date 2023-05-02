/*******************************************************************************
 * Copyright (c) 2019-2020 The Khronos Group Inc.
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

#ifndef OPENCL_CL_ICD_H
#define OPENCL_CL_ICD_H

#include <CL/cl.h>
#include <CL/cl_function_types.h>
#include <CL/cl_egl.h>
#include <CL/cl_ext.h>
#include <CL/cl_gl.h>

#if defined(_WIN32)
#include <CL/cl_d3d11.h>
#include <CL/cl_d3d10.h>
#include <CL/cl_dx9_media_sharing.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CL_VERSION_1_1

typedef void *clSetEventCallback_fn;
typedef void *clCreateSubBuffer_fn;
typedef void *clSetMemObjectDestructorCallback_fn;
typedef void *clCreateUserEvent_fn;
typedef void *clSetUserEventStatus_fn;
typedef void *clEnqueueReadBufferRect_fn;
typedef void *clEnqueueWriteBufferRect_fn;
typedef void *clEnqueueCopyBufferRect_fn;

#endif

#ifndef CL_VERSION_1_2

typedef void *clCreateSubDevices_fn;
typedef void *clRetainDevice_fn;
typedef void *clReleaseDevice_fn;
typedef void *clCreateImage_fn;
typedef void *clCreateProgramWithBuiltInKernels_fn;
typedef void *clCompileProgram_fn;
typedef void *clLinkProgram_fn;
typedef void *clUnloadPlatformCompiler_fn;
typedef void *clGetKernelArgInfo_fn;
typedef void *clEnqueueFillBuffer_fn;
typedef void *clEnqueueFillImage_fn;
typedef void *clEnqueueMigrateMemObjects_fn;
typedef void *clEnqueueMarkerWithWaitList_fn;
typedef void *clEnqueueBarrierWithWaitList_fn;
typedef void *clGetExtensionFunctionAddressForPlatform_fn;
typedef void *clCreateFromGLTexture_fn;

#endif

#ifndef CL_VERSION_2_0

typedef void *clCreateCommandQueueWithProperties_fn;
typedef void *clCreatePipe_fn;
typedef void *clGetPipeInfo_fn;
typedef void *clSVMAlloc_fn;
typedef void *clSVMFree_fn;
typedef void *clEnqueueSVMFree_fn;
typedef void *clEnqueueSVMMemcpy_fn;
typedef void *clEnqueueSVMMemFill_fn;
typedef void *clEnqueueSVMMap_fn;
typedef void *clEnqueueSVMUnmap_fn;
typedef void *clCreateSamplerWithProperties_fn;
typedef void *clSetKernelArgSVMPointer_fn;
typedef void *clSetKernelExecInfo_fn;

#endif

#ifndef CL_VERSION_2_1

typedef void *clCloneKernel_fn;
typedef void *clCreateProgramWithIL_fn;
typedef void *clEnqueueSVMMigrateMem_fn;
typedef void *clGetDeviceAndHostTimer_fn;
typedef void *clGetHostTimer_fn;
typedef void *clGetKernelSubGroupInfo_fn;
typedef void *clSetDefaultDeviceCommandQueue_fn;

#endif

#ifndef CL_VERSION_2_2

typedef void *clSetProgramReleaseCallback_fn;
typedef void *clSetProgramSpecializationConstant_fn;

#endif

#ifndef CL_VERSION_3_0

typedef void *clCreateBufferWithProperties_fn;
typedef void *clCreateImageWithProperties_fn;
typedef void *clSetContextDestructorCallback_fn;

#endif

#ifndef _WIN32

/* cl_khr_d3d10_sharing */
typedef void *clGetDeviceIDsFromD3D10KHR_fn;
typedef void *clCreateFromD3D10BufferKHR_fn;
typedef void *clCreateFromD3D10Texture2DKHR_fn;
typedef void *clCreateFromD3D10Texture3DKHR_fn;
typedef void *clEnqueueAcquireD3D10ObjectsKHR_fn;
typedef void *clEnqueueReleaseD3D10ObjectsKHR_fn;

/* cl_khr_d3d11_sharing */
typedef void *clGetDeviceIDsFromD3D11KHR_fn;
typedef void *clCreateFromD3D11BufferKHR_fn;
typedef void *clCreateFromD3D11Texture2DKHR_fn;
typedef void *clCreateFromD3D11Texture3DKHR_fn;
typedef void *clEnqueueAcquireD3D11ObjectsKHR_fn;
typedef void *clEnqueueReleaseD3D11ObjectsKHR_fn;

/* cl_khr_dx9_media_sharing */
typedef void *clCreateFromDX9MediaSurfaceKHR_fn;
typedef void *clEnqueueAcquireDX9MediaSurfacesKHR_fn;
typedef void *clEnqueueReleaseDX9MediaSurfacesKHR_fn;
typedef void *clGetDeviceIDsFromDX9MediaAdapterKHR_fn;

#endif

/* Vendor dispatch table structure */

typedef struct _cl_icd_dispatch {
  /* OpenCL 1.0 */
  clGetPlatformIDs_fn clGetPlatformIDs;
  clGetPlatformInfo_fn clGetPlatformInfo;
  clGetDeviceIDs_fn clGetDeviceIDs;
  clGetDeviceInfo_fn clGetDeviceInfo;
  clCreateContext_fn clCreateContext;
  clCreateContextFromType_fn clCreateContextFromType;
  clRetainContext_fn clRetainContext;
  clReleaseContext_fn clReleaseContext;
  clGetContextInfo_fn clGetContextInfo;
  clCreateCommandQueue_fn clCreateCommandQueue;
  clRetainCommandQueue_fn clRetainCommandQueue;
  clReleaseCommandQueue_fn clReleaseCommandQueue;
  clGetCommandQueueInfo_fn clGetCommandQueueInfo;
  clSetCommandQueueProperty_fn clSetCommandQueueProperty;
  clCreateBuffer_fn clCreateBuffer;
  clCreateImage2D_fn clCreateImage2D;
  clCreateImage3D_fn clCreateImage3D;
  clRetainMemObject_fn clRetainMemObject;
  clReleaseMemObject_fn clReleaseMemObject;
  clGetSupportedImageFormats_fn clGetSupportedImageFormats;
  clGetMemObjectInfo_fn clGetMemObjectInfo;
  clGetImageInfo_fn clGetImageInfo;
  clCreateSampler_fn clCreateSampler;
  clRetainSampler_fn clRetainSampler;
  clReleaseSampler_fn clReleaseSampler;
  clGetSamplerInfo_fn clGetSamplerInfo;
  clCreateProgramWithSource_fn clCreateProgramWithSource;
  clCreateProgramWithBinary_fn clCreateProgramWithBinary;
  clRetainProgram_fn clRetainProgram;
  clReleaseProgram_fn clReleaseProgram;
  clBuildProgram_fn clBuildProgram;
  clUnloadCompiler_fn clUnloadCompiler;
  clGetProgramInfo_fn clGetProgramInfo;
  clGetProgramBuildInfo_fn clGetProgramBuildInfo;
  clCreateKernel_fn clCreateKernel;
  clCreateKernelsInProgram_fn clCreateKernelsInProgram;
  clRetainKernel_fn clRetainKernel;
  clReleaseKernel_fn clReleaseKernel;
  clSetKernelArg_fn clSetKernelArg;
  clGetKernelInfo_fn clGetKernelInfo;
  clGetKernelWorkGroupInfo_fn clGetKernelWorkGroupInfo;
  clWaitForEvents_fn clWaitForEvents;
  clGetEventInfo_fn clGetEventInfo;
  clRetainEvent_fn clRetainEvent;
  clReleaseEvent_fn clReleaseEvent;
  clGetEventProfilingInfo_fn clGetEventProfilingInfo;
  clFlush_fn clFlush;
  clFinish_fn clFinish;
  clEnqueueReadBuffer_fn clEnqueueReadBuffer;
  clEnqueueWriteBuffer_fn clEnqueueWriteBuffer;
  clEnqueueCopyBuffer_fn clEnqueueCopyBuffer;
  clEnqueueReadImage_fn clEnqueueReadImage;
  clEnqueueWriteImage_fn clEnqueueWriteImage;
  clEnqueueCopyImage_fn clEnqueueCopyImage;
  clEnqueueCopyImageToBuffer_fn clEnqueueCopyImageToBuffer;
  clEnqueueCopyBufferToImage_fn clEnqueueCopyBufferToImage;
  clEnqueueMapBuffer_fn clEnqueueMapBuffer;
  clEnqueueMapImage_fn clEnqueueMapImage;
  clEnqueueUnmapMemObject_fn clEnqueueUnmapMemObject;
  clEnqueueNDRangeKernel_fn clEnqueueNDRangeKernel;
  clEnqueueTask_fn clEnqueueTask;
  clEnqueueNativeKernel_fn clEnqueueNativeKernel;
  clEnqueueMarker_fn clEnqueueMarker;
  clEnqueueWaitForEvents_fn clEnqueueWaitForEvents;
  clEnqueueBarrier_fn clEnqueueBarrier;
  clGetExtensionFunctionAddress_fn clGetExtensionFunctionAddress;
  clCreateFromGLBuffer_fn clCreateFromGLBuffer;
  clCreateFromGLTexture2D_fn clCreateFromGLTexture2D;
  clCreateFromGLTexture3D_fn clCreateFromGLTexture3D;
  clCreateFromGLRenderbuffer_fn clCreateFromGLRenderbuffer;
  clGetGLObjectInfo_fn clGetGLObjectInfo;
  clGetGLTextureInfo_fn clGetGLTextureInfo;
  clEnqueueAcquireGLObjects_fn clEnqueueAcquireGLObjects;
  clEnqueueReleaseGLObjects_fn clEnqueueReleaseGLObjects;
  clGetGLContextInfoKHR_fn clGetGLContextInfoKHR;

  /* cl_khr_d3d10_sharing */
  clGetDeviceIDsFromD3D10KHR_fn clGetDeviceIDsFromD3D10KHR;
  clCreateFromD3D10BufferKHR_fn clCreateFromD3D10BufferKHR;
  clCreateFromD3D10Texture2DKHR_fn clCreateFromD3D10Texture2DKHR;
  clCreateFromD3D10Texture3DKHR_fn clCreateFromD3D10Texture3DKHR;
  clEnqueueAcquireD3D10ObjectsKHR_fn clEnqueueAcquireD3D10ObjectsKHR;
  clEnqueueReleaseD3D10ObjectsKHR_fn clEnqueueReleaseD3D10ObjectsKHR;

  /* OpenCL 1.1 */
  clSetEventCallback_fn clSetEventCallback;
  clCreateSubBuffer_fn clCreateSubBuffer;
  clSetMemObjectDestructorCallback_fn clSetMemObjectDestructorCallback;
  clCreateUserEvent_fn clCreateUserEvent;
  clSetUserEventStatus_fn clSetUserEventStatus;
  clEnqueueReadBufferRect_fn clEnqueueReadBufferRect;
  clEnqueueWriteBufferRect_fn clEnqueueWriteBufferRect;
  clEnqueueCopyBufferRect_fn clEnqueueCopyBufferRect;

  /* cl_ext_device_fission */
  clCreateSubDevicesEXT_fn clCreateSubDevicesEXT;
  clRetainDeviceEXT_fn clRetainDeviceEXT;
  clReleaseDeviceEXT_fn clReleaseDeviceEXT;

  /* cl_khr_gl_event */
  clCreateEventFromGLsyncKHR_fn clCreateEventFromGLsyncKHR;

  /* OpenCL 1.2 */
  clCreateSubDevices_fn clCreateSubDevices;
  clRetainDevice_fn clRetainDevice;
  clReleaseDevice_fn clReleaseDevice;
  clCreateImage_fn clCreateImage;
  clCreateProgramWithBuiltInKernels_fn clCreateProgramWithBuiltInKernels;
  clCompileProgram_fn clCompileProgram;
  clLinkProgram_fn clLinkProgram;
  clUnloadPlatformCompiler_fn clUnloadPlatformCompiler;
  clGetKernelArgInfo_fn clGetKernelArgInfo;
  clEnqueueFillBuffer_fn clEnqueueFillBuffer;
  clEnqueueFillImage_fn clEnqueueFillImage;
  clEnqueueMigrateMemObjects_fn clEnqueueMigrateMemObjects;
  clEnqueueMarkerWithWaitList_fn clEnqueueMarkerWithWaitList;
  clEnqueueBarrierWithWaitList_fn clEnqueueBarrierWithWaitList;
  clGetExtensionFunctionAddressForPlatform_fn
      clGetExtensionFunctionAddressForPlatform;
  clCreateFromGLTexture_fn clCreateFromGLTexture;

  /* cl_khr_d3d11_sharing */
  clGetDeviceIDsFromD3D11KHR_fn clGetDeviceIDsFromD3D11KHR;
  clCreateFromD3D11BufferKHR_fn clCreateFromD3D11BufferKHR;
  clCreateFromD3D11Texture2DKHR_fn clCreateFromD3D11Texture2DKHR;
  clCreateFromD3D11Texture3DKHR_fn clCreateFromD3D11Texture3DKHR;
  clCreateFromDX9MediaSurfaceKHR_fn clCreateFromDX9MediaSurfaceKHR;
  clEnqueueAcquireD3D11ObjectsKHR_fn clEnqueueAcquireD3D11ObjectsKHR;
  clEnqueueReleaseD3D11ObjectsKHR_fn clEnqueueReleaseD3D11ObjectsKHR;

  /* cl_khr_dx9_media_sharing */
  clGetDeviceIDsFromDX9MediaAdapterKHR_fn
      clGetDeviceIDsFromDX9MediaAdapterKHR;
  clEnqueueAcquireDX9MediaSurfacesKHR_fn
      clEnqueueAcquireDX9MediaSurfacesKHR;
  clEnqueueReleaseDX9MediaSurfacesKHR_fn
      clEnqueueReleaseDX9MediaSurfacesKHR;

  /* cl_khr_egl_image */
  clCreateFromEGLImageKHR_fn clCreateFromEGLImageKHR;
  clEnqueueAcquireEGLObjectsKHR_fn clEnqueueAcquireEGLObjectsKHR;
  clEnqueueReleaseEGLObjectsKHR_fn clEnqueueReleaseEGLObjectsKHR;

  /* cl_khr_egl_event */
  clCreateEventFromEGLSyncKHR_fn clCreateEventFromEGLSyncKHR;

  /* OpenCL 2.0 */
  clCreateCommandQueueWithProperties_fn clCreateCommandQueueWithProperties;
  clCreatePipe_fn clCreatePipe;
  clGetPipeInfo_fn clGetPipeInfo;
  clSVMAlloc_fn clSVMAlloc;
  clSVMFree_fn clSVMFree;
  clEnqueueSVMFree_fn clEnqueueSVMFree;
  clEnqueueSVMMemcpy_fn clEnqueueSVMMemcpy;
  clEnqueueSVMMemFill_fn clEnqueueSVMMemFill;
  clEnqueueSVMMap_fn clEnqueueSVMMap;
  clEnqueueSVMUnmap_fn clEnqueueSVMUnmap;
  clCreateSamplerWithProperties_fn clCreateSamplerWithProperties;
  clSetKernelArgSVMPointer_fn clSetKernelArgSVMPointer;
  clSetKernelExecInfo_fn clSetKernelExecInfo;

  /* cl_khr_sub_groups */
  clGetKernelSubGroupInfoKHR_fn clGetKernelSubGroupInfoKHR;

  /* OpenCL 2.1 */
  clCloneKernel_fn clCloneKernel;
  clCreateProgramWithIL_fn clCreateProgramWithIL;
  clEnqueueSVMMigrateMem_fn clEnqueueSVMMigrateMem;
  clGetDeviceAndHostTimer_fn clGetDeviceAndHostTimer;
  clGetHostTimer_fn clGetHostTimer;
  clGetKernelSubGroupInfo_fn clGetKernelSubGroupInfo;
  clSetDefaultDeviceCommandQueue_fn clSetDefaultDeviceCommandQueue;

  /* OpenCL 2.2 */
  clSetProgramReleaseCallback_fn clSetProgramReleaseCallback;
  clSetProgramSpecializationConstant_fn clSetProgramSpecializationConstant;

  /* OpenCL 3.0 */
  clCreateBufferWithProperties_fn clCreateBufferWithProperties;
  clCreateImageWithProperties_fn clCreateImageWithProperties;
  clSetContextDestructorCallback_fn clSetContextDestructorCallback;

} cl_icd_dispatch;

#ifdef __cplusplus
}
#endif

#endif /* #ifndef OPENCL_CL_ICD_H */

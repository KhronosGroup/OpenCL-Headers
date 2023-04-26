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

/*
 * This file contains pointer type definitions for each of the CL API calls as
 * well as a type definition for the dispatch table used by the Khronos ICD
 * loader (see cl_khr_icd extension specification for background).
 */

/* API function pointer definitions */

// Platform APIs
typedef clGetPlatformIDs_t *
cl_api_clGetPlatformIDs CL_API_SUFFIX__VERSION_1_0;

typedef clGetPlatformInfo_t *
cl_api_clGetPlatformInfo CL_API_SUFFIX__VERSION_1_0;

// Device APIs
typedef clGetDeviceIDs_t *
cl_api_clGetDeviceIDs CL_API_SUFFIX__VERSION_1_0;

typedef clGetDeviceInfo_t *
cl_api_clGetDeviceInfo CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef clCreateSubDevices_t *
cl_api_clCreateSubDevices CL_API_SUFFIX__VERSION_1_2;

typedef clRetainDevice_t *
cl_api_clRetainDevice CL_API_SUFFIX__VERSION_1_2;

typedef clReleaseDevice_t *
cl_api_clReleaseDevice CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clCreateSubDevices;
typedef void *cl_api_clRetainDevice;
typedef void *cl_api_clReleaseDevice;

#endif

// Context APIs
typedef clCreateContext_t *
cl_api_clCreateContext CL_API_SUFFIX__VERSION_1_0;

typedef clCreateContextFromType_t *
cl_api_clCreateContextFromType CL_API_SUFFIX__VERSION_1_0;

typedef clRetainContext_t *
cl_api_clRetainContext CL_API_SUFFIX__VERSION_1_0;

typedef clReleaseContext_t *
cl_api_clReleaseContext CL_API_SUFFIX__VERSION_1_0;

typedef clGetContextInfo_t *
cl_api_clGetContextInfo CL_API_SUFFIX__VERSION_1_0;

// Command Queue APIs
typedef clCreateCommandQueue_t *
cl_api_clCreateCommandQueue CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_0

typedef clCreateCommandQueueWithProperties_t *
cl_api_clCreateCommandQueueWithProperties CL_API_SUFFIX__VERSION_2_0;

#else

typedef void *cl_api_clCreateCommandQueueWithProperties;

#endif

typedef clRetainCommandQueue_t *
cl_api_clRetainCommandQueue CL_API_SUFFIX__VERSION_1_0;

typedef clReleaseCommandQueue_t *
cl_api_clReleaseCommandQueue CL_API_SUFFIX__VERSION_1_0;

typedef clGetCommandQueueInfo_t *
cl_api_clGetCommandQueueInfo CL_API_SUFFIX__VERSION_1_0;

// Memory Object APIs
typedef clCreateBuffer_t *
cl_api_clCreateBuffer CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef clCreateImage_t *
cl_api_clCreateImage CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clCreateImage;

#endif

#ifdef CL_VERSION_3_0

typedef clCreateBufferWithProperties_t *
cl_api_clCreateBufferWithProperties CL_API_SUFFIX__VERSION_3_0;

typedef clCreateImageWithProperties_t *
cl_api_clCreateImageWithProperties CL_API_SUFFIX__VERSION_3_0;

typedef clSetContextDestructorCallback_t *
cl_api_clSetContextDestructorCallback CL_API_SUFFIX__VERSION_3_0;

#else

typedef void *cl_api_clCreateBufferWithProperties;
typedef void *cl_api_clCreateImageWithProperties;
typedef void *cl_api_clSetContextDestructorCallback;

#endif

typedef clRetainMemObject_t *
cl_api_clRetainMemObject CL_API_SUFFIX__VERSION_1_0;

typedef clReleaseMemObject_t *
cl_api_clReleaseMemObject CL_API_SUFFIX__VERSION_1_0;

typedef clGetSupportedImageFormats_t *
cl_api_clGetSupportedImageFormats CL_API_SUFFIX__VERSION_1_0;

typedef clGetMemObjectInfo_t *
cl_api_clGetMemObjectInfo CL_API_SUFFIX__VERSION_1_0;

typedef clGetImageInfo_t *
cl_api_clGetImageInfo CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_0

typedef clCreatePipe_t *
cl_api_clCreatePipe CL_API_SUFFIX__VERSION_2_0;

typedef clGetPipeInfo_t *
cl_api_clGetPipeInfo CL_API_SUFFIX__VERSION_2_0;

typedef clSVMAlloc_t *
cl_api_clSVMAlloc CL_API_SUFFIX__VERSION_2_0;

typedef clSVMFree_t *
cl_api_clSVMFree CL_API_SUFFIX__VERSION_2_0;

#else

typedef void *cl_api_clCreatePipe;
typedef void *cl_api_clGetPipeInfo;
typedef void *cl_api_clSVMAlloc;
typedef void *cl_api_clSVMFree;

#endif

// Sampler APIs
typedef clCreateSampler_t *
cl_api_clCreateSampler CL_API_SUFFIX__VERSION_1_0;

typedef clRetainSampler_t *
cl_api_clRetainSampler CL_API_SUFFIX__VERSION_1_0;

typedef clReleaseSampler_t *
cl_api_clReleaseSampler CL_API_SUFFIX__VERSION_1_0;

typedef clGetSamplerInfo_t *
cl_api_clGetSamplerInfo CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_0

typedef clCreateSamplerWithProperties_t *
cl_api_clCreateSamplerWithProperties CL_API_SUFFIX__VERSION_2_0;

#else

typedef void *cl_api_clCreateSamplerWithProperties;

#endif

// Program Object APIs
typedef clCreateProgramWithSource_t *
cl_api_clCreateProgramWithSource CL_API_SUFFIX__VERSION_1_0;

typedef clCreateProgramWithBinary_t *
cl_api_clCreateProgramWithBinary CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef clCreateProgramWithBuiltInKernels_t *
cl_api_clCreateProgramWithBuiltInKernels CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clCreateProgramWithBuiltInKernels;

#endif

typedef clRetainProgram_t *
cl_api_clRetainProgram CL_API_SUFFIX__VERSION_1_0;

typedef clReleaseProgram_t *
cl_api_clReleaseProgram CL_API_SUFFIX__VERSION_1_0;

typedef clBuildProgram_t *
cl_api_clBuildProgram CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef clCompileProgram_t *
cl_api_clCompileProgram CL_API_SUFFIX__VERSION_1_2;

typedef clLinkProgram_t *
cl_api_clLinkProgram CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clCompileProgram;
typedef void *cl_api_clLinkProgram;

#endif

#ifdef CL_VERSION_2_2

typedef clSetProgramSpecializationConstant_t *
cl_api_clSetProgramSpecializationConstant CL_API_SUFFIX__VERSION_2_2;

typedef clSetProgramReleaseCallback_t *
cl_api_clSetProgramReleaseCallback CL_API_SUFFIX__VERSION_2_2;

#else

typedef void *cl_api_clSetProgramSpecializationConstant;
typedef void *cl_api_clSetProgramReleaseCallback;

#endif

#ifdef CL_VERSION_1_2

typedef clUnloadPlatformCompiler_t *
cl_api_clUnloadPlatformCompiler CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clUnloadPlatformCompiler;

#endif

typedef clGetProgramInfo_t *
cl_api_clGetProgramInfo CL_API_SUFFIX__VERSION_1_0;

typedef clGetProgramBuildInfo_t *
cl_api_clGetProgramBuildInfo CL_API_SUFFIX__VERSION_1_0;

// Kernel Object APIs
typedef clCreateKernel_t *
cl_api_clCreateKernel CL_API_SUFFIX__VERSION_1_0;

typedef clCreateKernelsInProgram_t *
cl_api_clCreateKernelsInProgram CL_API_SUFFIX__VERSION_1_0;

typedef clRetainKernel_t *
cl_api_clRetainKernel CL_API_SUFFIX__VERSION_1_0;

typedef clReleaseKernel_t *
cl_api_clReleaseKernel CL_API_SUFFIX__VERSION_1_0;

typedef clSetKernelArg_t *
cl_api_clSetKernelArg CL_API_SUFFIX__VERSION_1_0;

typedef clGetKernelInfo_t *
cl_api_clGetKernelInfo CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef clGetKernelArgInfo_t *
cl_api_clGetKernelArgInfo CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clGetKernelArgInfo;

#endif

typedef clGetKernelWorkGroupInfo_t *
cl_api_clGetKernelWorkGroupInfo CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_2_0

typedef clSetKernelArgSVMPointer_t *
cl_api_clSetKernelArgSVMPointer CL_API_SUFFIX__VERSION_2_0;

typedef clSetKernelExecInfo_t *
cl_api_clSetKernelExecInfo CL_API_SUFFIX__VERSION_2_0;

typedef clGetKernelSubGroupInfoKHR_t *
cl_api_clGetKernelSubGroupInfoKHR CL_API_SUFFIX__VERSION_2_0;

#else

typedef void *cl_api_clSetKernelArgSVMPointer;
typedef void *cl_api_clSetKernelExecInfo;
typedef void *cl_api_clGetKernelSubGroupInfoKHR;

#endif

// Event Object APIs
typedef clWaitForEvents_t *
cl_api_clWaitForEvents CL_API_SUFFIX__VERSION_1_0;

typedef clGetEventInfo_t *
cl_api_clGetEventInfo CL_API_SUFFIX__VERSION_1_0;

typedef clRetainEvent_t *
cl_api_clRetainEvent CL_API_SUFFIX__VERSION_1_0;

typedef clReleaseEvent_t *
cl_api_clReleaseEvent CL_API_SUFFIX__VERSION_1_0;

// Profiling APIs
typedef clGetEventProfilingInfo_t *
cl_api_clGetEventProfilingInfo CL_API_SUFFIX__VERSION_1_0;

// Flush and Finish APIs
typedef clFlush_t *
cl_api_clFlush CL_API_SUFFIX__VERSION_1_0;

typedef clFinish_t *
cl_api_clFinish CL_API_SUFFIX__VERSION_1_0;

// Enqueued Commands APIs
typedef clEnqueueReadBuffer_t *
cl_api_clEnqueueReadBuffer CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

typedef clEnqueueReadBufferRect_t *
cl_api_clEnqueueReadBufferRect CL_API_SUFFIX__VERSION_1_1;

#else

typedef void *cl_api_clEnqueueReadBufferRect;

#endif

typedef clEnqueueWriteBuffer_t *
cl_api_clEnqueueWriteBuffer CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

typedef clEnqueueWriteBufferRect_t *
cl_api_clEnqueueWriteBufferRect CL_API_SUFFIX__VERSION_1_1;

#else

typedef void *cl_api_clEnqueueWriteBufferRect;

#endif

#ifdef CL_VERSION_1_2

typedef clEnqueueFillBuffer_t *
cl_api_clEnqueueFillBuffer CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clEnqueueFillBuffer;

#endif

typedef clEnqueueCopyBuffer_t *
cl_api_clEnqueueCopyBuffer CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_1

typedef clEnqueueCopyBufferRect_t *
cl_api_clEnqueueCopyBufferRect CL_API_SUFFIX__VERSION_1_1;

#else

typedef void *cl_api_clEnqueueCopyBufferRect;

#endif

typedef clEnqueueReadImage_t *
cl_api_clEnqueueReadImage CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueWriteImage_t *
cl_api_clEnqueueWriteImage CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef clEnqueueFillImage_t *
cl_api_clEnqueueFillImage CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clEnqueueFillImage;

#endif

typedef clEnqueueCopyImage_t *
cl_api_clEnqueueCopyImage CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueCopyImageToBuffer_t *
cl_api_clEnqueueCopyImageToBuffer CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueCopyBufferToImage_t *
cl_api_clEnqueueCopyBufferToImage CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueMapBuffer_t *
cl_api_clEnqueueMapBuffer CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueMapImage_t *
cl_api_clEnqueueMapImage CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueUnmapMemObject_t *
cl_api_clEnqueueUnmapMemObject CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef clEnqueueMigrateMemObjects_t *
cl_api_clEnqueueMigrateMemObjects CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clEnqueueMigrateMemObjects;

#endif

typedef clEnqueueNDRangeKernel_t *
cl_api_clEnqueueNDRangeKernel CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueTask_t *
cl_api_clEnqueueTask CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueNativeKernel_t *
cl_api_clEnqueueNativeKernel CL_API_SUFFIX__VERSION_1_0;

#ifdef CL_VERSION_1_2

typedef clEnqueueMarkerWithWaitList_t *
cl_api_clEnqueueMarkerWithWaitList CL_API_SUFFIX__VERSION_1_2;

typedef clEnqueueBarrierWithWaitList_t *
cl_api_clEnqueueBarrierWithWaitList CL_API_SUFFIX__VERSION_1_2;

typedef clGetExtensionFunctionAddressForPlatform_t *
cl_api_clGetExtensionFunctionAddressForPlatform CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clEnqueueMarkerWithWaitList;
typedef void *cl_api_clEnqueueBarrierWithWaitList;
typedef void *cl_api_clGetExtensionFunctionAddressForPlatform;

#endif

// Shared Virtual Memory APIs

#ifdef CL_VERSION_2_0

typedef clEnqueueSVMFree_t *
cl_api_clEnqueueSVMFree CL_API_SUFFIX__VERSION_2_0;

typedef clEnqueueSVMMemcpy_t *
cl_api_clEnqueueSVMMemcpy CL_API_SUFFIX__VERSION_2_0;

typedef clEnqueueSVMMemFill_t *
cl_api_clEnqueueSVMMemFill CL_API_SUFFIX__VERSION_2_0;

typedef clEnqueueSVMMap_t *
cl_api_clEnqueueSVMMap CL_API_SUFFIX__VERSION_2_0;

typedef clEnqueueSVMUnmap_t *
cl_api_clEnqueueSVMUnmap CL_API_SUFFIX__VERSION_2_0;

#else

typedef void *cl_api_clEnqueueSVMFree;
typedef void *cl_api_clEnqueueSVMMemcpy;
typedef void *cl_api_clEnqueueSVMMemFill;
typedef void *cl_api_clEnqueueSVMMap;
typedef void *cl_api_clEnqueueSVMUnmap;

#endif

// Deprecated APIs
typedef clSetCommandQueueProperty_t *
cl_api_clSetCommandQueueProperty CL_API_SUFFIX__VERSION_1_0_DEPRECATED;

typedef clCreateImage2D_t *
cl_api_clCreateImage2D CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef clCreateImage3D_t *
cl_api_clCreateImage3D CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef clUnloadCompiler_t *
cl_api_clUnloadCompiler CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef clEnqueueMarker_t *
cl_api_clEnqueueMarker CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef clEnqueueWaitForEvents_t *
cl_api_clEnqueueWaitForEvents CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef clEnqueueBarrier_t *
cl_api_clEnqueueBarrier CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

typedef clGetExtensionFunctionAddress_t *
cl_api_clGetExtensionFunctionAddress CL_API_SUFFIX__VERSION_1_1_DEPRECATED;

// GL and other APIs
typedef clCreateFromGLBuffer_t *
cl_api_clCreateFromGLBuffer CL_API_SUFFIX__VERSION_1_0;

#if defined(CL_VERSION_1_2)

typedef clCreateFromGLTexture_t *
cl_api_clCreateFromGLTexture CL_API_SUFFIX__VERSION_1_2;

#else

typedef void *cl_api_clCreateFromGLTexture;

#endif

typedef clCreateFromGLTexture2D_t *
cl_api_clCreateFromGLTexture2D CL_API_SUFFIX__VERSION_1_0;

typedef clCreateFromGLTexture3D_t *
cl_api_clCreateFromGLTexture3D CL_API_SUFFIX__VERSION_1_0;

typedef clCreateFromGLRenderbuffer_t *
cl_api_clCreateFromGLRenderbuffer CL_API_SUFFIX__VERSION_1_0;

typedef clGetGLObjectInfo_t *
cl_api_clGetGLObjectInfo CL_API_SUFFIX__VERSION_1_0;

typedef clGetGLTextureInfo_t *
cl_api_clGetGLTextureInfo CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueAcquireGLObjects_t *
cl_api_clEnqueueAcquireGLObjects CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueReleaseGLObjects_t *
cl_api_clEnqueueReleaseGLObjects CL_API_SUFFIX__VERSION_1_0;

/* cl_khr_gl_sharing */
typedef clGetGLContextInfoKHR_t *
cl_api_clGetGLContextInfoKHR;

/* cl_khr_gl_event */
typedef clCreateEventFromGLsyncKHR_t *
cl_api_clCreateEventFromGLsyncKHR;

#if defined(_WIN32)

/* cl_khr_d3d10_sharing */

typedef clGetDeviceIDsFromD3D10KHR_t *
cl_api_clGetDeviceIDsFromD3D10KHR CL_API_SUFFIX__VERSION_1_0;

typedef clCreateFromD3D10BufferKHR_t *
cl_api_clCreateFromD3D10BufferKHR CL_API_SUFFIX__VERSION_1_0;

typedef clCreateFromD3D10Texture2DKHR_t *
cl_api_clCreateFromD3D10Texture2DKHR CL_API_SUFFIX__VERSION_1_0;

typedef clCreateFromD3D10Texture3DKHR_t *
cl_api_clCreateFromD3D10Texture3DKHR CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueAcquireD3D10ObjectsKHR_t *
cl_api_clEnqueueAcquireD3D10ObjectsKHR CL_API_SUFFIX__VERSION_1_0;

typedef clEnqueueReleaseD3D10ObjectsKHR_t *
cl_api_clEnqueueReleaseD3D10ObjectsKHR CL_API_SUFFIX__VERSION_1_0;

/* cl_khr_d3d11_sharing */
typedef clGetDeviceIDsFromD3D11KHR_t *
cl_api_clGetDeviceIDsFromD3D11KHR CL_API_SUFFIX__VERSION_1_2;

typedef clCreateFromD3D11BufferKHR_t *
cl_api_clCreateFromD3D11BufferKHR CL_API_SUFFIX__VERSION_1_2;

typedef clCreateFromD3D11Texture2DKHR_t *
cl_api_clCreateFromD3D11Texture2DKHR CL_API_SUFFIX__VERSION_1_2;

typedef clCreateFromD3D11Texture3DKHR_t *
cl_api_clCreateFromD3D11Texture3DKHR CL_API_SUFFIX__VERSION_1_2;

typedef clEnqueueAcquireD3D11ObjectsKHR_t *
cl_api_clEnqueueAcquireD3D11ObjectsKHR CL_API_SUFFIX__VERSION_1_2;

typedef clEnqueueReleaseD3D11ObjectsKHR_t *
cl_api_clEnqueueReleaseD3D11ObjectsKHR CL_API_SUFFIX__VERSION_1_2;

/* cl_khr_dx9_media_sharing */
typedef clGetDeviceIDsFromDX9MediaAdapterKHR_t *
cl_api_clGetDeviceIDsFromDX9MediaAdapterKHR CL_API_SUFFIX__VERSION_1_2;

typedef clCreateFromDX9MediaSurfaceKHR_t *
cl_api_clCreateFromDX9MediaSurfaceKHR CL_API_SUFFIX__VERSION_1_2;

typedef clEnqueueAcquireDX9MediaSurfacesKHR_t *
cl_api_clEnqueueAcquireDX9MediaSurfacesKHR CL_API_SUFFIX__VERSION_1_2;

typedef clEnqueueReleaseDX9MediaSurfacesKHR_t *
cl_api_clEnqueueReleaseDX9MediaSurfacesKHR CL_API_SUFFIX__VERSION_1_2;

#else

/* cl_khr_d3d10_sharing */
typedef void *cl_api_clGetDeviceIDsFromD3D10KHR;
typedef void *cl_api_clCreateFromD3D10BufferKHR;
typedef void *cl_api_clCreateFromD3D10Texture2DKHR;
typedef void *cl_api_clCreateFromD3D10Texture3DKHR;
typedef void *cl_api_clEnqueueAcquireD3D10ObjectsKHR;
typedef void *cl_api_clEnqueueReleaseD3D10ObjectsKHR;

/* cl_khr_d3d11_sharing */
typedef void *cl_api_clGetDeviceIDsFromD3D11KHR;
typedef void *cl_api_clCreateFromD3D11BufferKHR;
typedef void *cl_api_clCreateFromD3D11Texture2DKHR;
typedef void *cl_api_clCreateFromD3D11Texture3DKHR;
typedef void *cl_api_clEnqueueAcquireD3D11ObjectsKHR;
typedef void *cl_api_clEnqueueReleaseD3D11ObjectsKHR;

/* cl_khr_dx9_media_sharing */
typedef void *cl_api_clCreateFromDX9MediaSurfaceKHR;
typedef void *cl_api_clEnqueueAcquireDX9MediaSurfacesKHR;
typedef void *cl_api_clEnqueueReleaseDX9MediaSurfacesKHR;
typedef void *cl_api_clGetDeviceIDsFromDX9MediaAdapterKHR;

#endif

/* OpenCL 1.1 */

#ifdef CL_VERSION_1_1

typedef clSetEventCallback_t *
cl_api_clSetEventCallback CL_API_SUFFIX__VERSION_1_1;

typedef clCreateSubBuffer_t *
cl_api_clCreateSubBuffer CL_API_SUFFIX__VERSION_1_1;

typedef clSetMemObjectDestructorCallback_t *
cl_api_clSetMemObjectDestructorCallback CL_API_SUFFIX__VERSION_1_1;

typedef clCreateUserEvent_t *
cl_api_clCreateUserEvent CL_API_SUFFIX__VERSION_1_1;

typedef clSetUserEventStatus_t *
cl_api_clSetUserEventStatus CL_API_SUFFIX__VERSION_1_1;

#else

typedef void *cl_api_clSetEventCallback;
typedef void *cl_api_clCreateSubBuffer;
typedef void *cl_api_clSetMemObjectDestructorCallback;
typedef void *cl_api_clCreateUserEvent;
typedef void *cl_api_clSetUserEventStatus;

#endif

typedef clCreateSubDevicesEXT_t *
cl_api_clCreateSubDevicesEXT;

typedef clRetainDeviceEXT_t *
cl_api_clRetainDeviceEXT CL_API_SUFFIX__VERSION_1_0;

typedef clReleaseDeviceEXT_t *
cl_api_clReleaseDeviceEXT CL_API_SUFFIX__VERSION_1_0;

/* cl_khr_egl_image */
typedef clCreateFromEGLImageKHR_t *
cl_api_clCreateFromEGLImageKHR;

typedef clEnqueueAcquireEGLObjectsKHR_t *
cl_api_clEnqueueAcquireEGLObjectsKHR;

typedef clEnqueueReleaseEGLObjectsKHR_t *
cl_api_clEnqueueReleaseEGLObjectsKHR;

/* cl_khr_egl_event */
typedef clCreateEventFromEGLSyncKHR_t *
cl_api_clCreateEventFromEGLSyncKHR;

#ifdef CL_VERSION_2_1

typedef clSetDefaultDeviceCommandQueue_t *
cl_api_clSetDefaultDeviceCommandQueue CL_API_SUFFIX__VERSION_2_1;

typedef clCreateProgramWithIL_t *
cl_api_clCreateProgramWithIL CL_API_SUFFIX__VERSION_2_1;

typedef clGetKernelSubGroupInfo_t *
cl_api_clGetKernelSubGroupInfo CL_API_SUFFIX__VERSION_2_1;

typedef clCloneKernel_t *
cl_api_clCloneKernel CL_API_SUFFIX__VERSION_2_1;

typedef clEnqueueSVMMigrateMem_t *
cl_api_clEnqueueSVMMigrateMem CL_API_SUFFIX__VERSION_2_1;

typedef clGetDeviceAndHostTimer_t *
cl_api_clGetDeviceAndHostTimer CL_API_SUFFIX__VERSION_2_1;

typedef clGetHostTimer_t *
cl_api_clGetHostTimer CL_API_SUFFIX__VERSION_2_1;

#else

typedef void *cl_api_clSetDefaultDeviceCommandQueue;
typedef void *cl_api_clCreateProgramWithIL;
typedef void *cl_api_clGetKernelSubGroupInfo;
typedef void *cl_api_clCloneKernel;
typedef void *cl_api_clEnqueueSVMMigrateMem;
typedef void *cl_api_clGetDeviceAndHostTimer;
typedef void *cl_api_clGetHostTimer;

#endif

/* Vendor dispatch table structure */

typedef struct _cl_icd_dispatch {
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

  /* cl_khr_d3d10_sharing */
  cl_api_clGetDeviceIDsFromD3D10KHR clGetDeviceIDsFromD3D10KHR;
  cl_api_clCreateFromD3D10BufferKHR clCreateFromD3D10BufferKHR;
  cl_api_clCreateFromD3D10Texture2DKHR clCreateFromD3D10Texture2DKHR;
  cl_api_clCreateFromD3D10Texture3DKHR clCreateFromD3D10Texture3DKHR;
  cl_api_clEnqueueAcquireD3D10ObjectsKHR clEnqueueAcquireD3D10ObjectsKHR;
  cl_api_clEnqueueReleaseD3D10ObjectsKHR clEnqueueReleaseD3D10ObjectsKHR;

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

  /* cl_khr_d3d11_sharing */
  cl_api_clGetDeviceIDsFromD3D11KHR clGetDeviceIDsFromD3D11KHR;
  cl_api_clCreateFromD3D11BufferKHR clCreateFromD3D11BufferKHR;
  cl_api_clCreateFromD3D11Texture2DKHR clCreateFromD3D11Texture2DKHR;
  cl_api_clCreateFromD3D11Texture3DKHR clCreateFromD3D11Texture3DKHR;
  cl_api_clCreateFromDX9MediaSurfaceKHR clCreateFromDX9MediaSurfaceKHR;
  cl_api_clEnqueueAcquireD3D11ObjectsKHR clEnqueueAcquireD3D11ObjectsKHR;
  cl_api_clEnqueueReleaseD3D11ObjectsKHR clEnqueueReleaseD3D11ObjectsKHR;

  /* cl_khr_dx9_media_sharing */
  cl_api_clGetDeviceIDsFromDX9MediaAdapterKHR
      clGetDeviceIDsFromDX9MediaAdapterKHR;
  cl_api_clEnqueueAcquireDX9MediaSurfacesKHR
      clEnqueueAcquireDX9MediaSurfacesKHR;
  cl_api_clEnqueueReleaseDX9MediaSurfacesKHR
      clEnqueueReleaseDX9MediaSurfacesKHR;

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

} cl_icd_dispatch;

#ifdef __cplusplus
}
#endif

#endif /* #ifndef OPENCL_CL_ICD_H */

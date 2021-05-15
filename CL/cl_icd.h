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
#include <CL/cl_egl.h>
#include <CL/cl_ext.h>
#include <CL/cl_gl.h>

#if defined(_WIN32)
#include <CL/cl_d3d11.h>
#include <CL/cl_d3d10.h>
#include <CL/cl_dx9_media_sharing.h>
#endif

#include <CL/cl_api_ptrs.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * This file contains pointer type definitions for each of the CL API calls as
 * well as a type definition for the dispatch table used by the Khronos ICD
 * loader (see cl_khr_icd extension specification for background).
 */

/* API function pointer definitions */

#ifdef CL_VERSION_2_0
typedef cl_int(CL_API_CALL *cl_api_clGetKernelSubGroupInfoKHR)(
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

// GL and other APIs
typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLBuffer)(
    cl_context context, cl_mem_flags flags, cl_GLuint bufobj,
    int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLTexture)(
    cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel,
    cl_GLuint texture, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLTexture2D)(
    cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel,
    cl_GLuint texture, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLTexture3D)(
    cl_context context, cl_mem_flags flags, cl_GLenum target, cl_GLint miplevel,
    cl_GLuint texture, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromGLRenderbuffer)(
    cl_context context, cl_mem_flags flags, cl_GLuint renderbuffer,
    cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int(CL_API_CALL *cl_api_clGetGLObjectInfo)(
    cl_mem memobj, cl_gl_object_type *gl_object_type,
    cl_GLuint *gl_object_name) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int(CL_API_CALL *cl_api_clGetGLTextureInfo)(
    cl_mem memobj, cl_gl_texture_info param_name, size_t param_value_size,
    void *param_value, size_t *param_value_size_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int(CL_API_CALL *cl_api_clEnqueueAcquireGLObjects)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event *event) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int(CL_API_CALL *cl_api_clEnqueueReleaseGLObjects)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event *event) CL_API_SUFFIX__VERSION_1_0;

/* cl_khr_gl_sharing */
typedef cl_int(CL_API_CALL *cl_api_clGetGLContextInfoKHR)(
    const cl_context_properties *properties, cl_gl_context_info param_name,
    size_t param_value_size, void *param_value, size_t *param_value_size_ret);

/* cl_khr_gl_event */
typedef cl_event(CL_API_CALL *cl_api_clCreateEventFromGLsyncKHR)(
    cl_context context, cl_GLsync sync, cl_int *errcode_ret);

#if defined(_WIN32)

/* cl_khr_d3d10_sharing */

typedef cl_int(CL_API_CALL *cl_api_clGetDeviceIDsFromD3D10KHR)(
    cl_platform_id platform, cl_d3d10_device_source_khr d3d_device_source,
    void *d3d_object, cl_d3d10_device_set_khr d3d_device_set,
    cl_uint num_entries, cl_device_id *devices,
    cl_uint *num_devices) CL_API_SUFFIX__VERSION_1_0;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D10BufferKHR)(
    cl_context context, cl_mem_flags flags, ID3D10Buffer *resource,
    cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D10Texture2DKHR)(
    cl_context context, cl_mem_flags flags, ID3D10Texture2D *resource,
    UINT subresource, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D10Texture3DKHR)(
    cl_context context, cl_mem_flags flags, ID3D10Texture3D *resource,
    UINT subresource, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_0;

typedef
cl_int(CL_API_CALL *cl_api_clEnqueueAcquireD3D10ObjectsKHR)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event *event) CL_API_SUFFIX__VERSION_1_0;

typedef
cl_int(CL_API_CALL *cl_api_clEnqueueReleaseD3D10ObjectsKHR)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event *event) CL_API_SUFFIX__VERSION_1_0;

extern CL_API_ENTRY cl_int CL_API_CALL clGetDeviceIDsFromD3D10KHR(
    cl_platform_id platform, cl_d3d10_device_source_khr d3d_device_source,
    void *d3d_object, cl_d3d10_device_set_khr d3d_device_set,
    cl_uint num_entries, cl_device_id *devices, cl_uint *num_devices);

extern CL_API_ENTRY cl_mem CL_API_CALL
clCreateFromD3D10BufferKHR(cl_context context, cl_mem_flags flags,
                           ID3D10Buffer *resource, cl_int *errcode_ret);

extern CL_API_ENTRY cl_mem CL_API_CALL clCreateFromD3D10Texture2DKHR(
    cl_context context, cl_mem_flags flags, ID3D10Texture2D *resource,
    UINT subresource, cl_int *errcode_ret);

extern CL_API_ENTRY cl_mem CL_API_CALL clCreateFromD3D10Texture3DKHR(
    cl_context context, cl_mem_flags flags, ID3D10Texture3D *resource,
    UINT subresource, cl_int *errcode_ret);

extern CL_API_ENTRY cl_int CL_API_CALL clEnqueueAcquireD3D10ObjectsKHR(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list, cl_event *event);

extern CL_API_ENTRY cl_int CL_API_CALL clEnqueueReleaseD3D10ObjectsKHR(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list, cl_event *event);

/* cl_khr_d3d11_sharing */
typedef cl_int(CL_API_CALL *cl_api_clGetDeviceIDsFromD3D11KHR)(
    cl_platform_id platform, cl_d3d11_device_source_khr d3d_device_source,
    void *d3d_object, cl_d3d11_device_set_khr d3d_device_set,
    cl_uint num_entries, cl_device_id *devices,
    cl_uint *num_devices) CL_API_SUFFIX__VERSION_1_2;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D11BufferKHR)(
    cl_context context, cl_mem_flags flags, ID3D11Buffer *resource,
    cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D11Texture2DKHR)(
    cl_context context, cl_mem_flags flags, ID3D11Texture2D *resource,
    UINT subresource, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromD3D11Texture3DKHR)(
    cl_context context, cl_mem_flags flags, ID3D11Texture3D *resource,
    UINT subresource, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;

typedef
cl_int(CL_API_CALL *cl_api_clEnqueueAcquireD3D11ObjectsKHR)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event *event) CL_API_SUFFIX__VERSION_1_2;

typedef
cl_int(CL_API_CALL *cl_api_clEnqueueReleaseD3D11ObjectsKHR)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event *event) CL_API_SUFFIX__VERSION_1_2;

/* cl_khr_dx9_media_sharing */
typedef
cl_int(CL_API_CALL *cl_api_clGetDeviceIDsFromDX9MediaAdapterKHR)(
    cl_platform_id platform, cl_uint num_media_adapters,
    cl_dx9_media_adapter_type_khr *media_adapters_type, void *media_adapters,
    cl_dx9_media_adapter_set_khr media_adapter_set, cl_uint num_entries,
    cl_device_id *devices, cl_uint *num_devices) CL_API_SUFFIX__VERSION_1_2;

typedef cl_mem(CL_API_CALL *cl_api_clCreateFromDX9MediaSurfaceKHR)(
    cl_context context, cl_mem_flags flags,
    cl_dx9_media_adapter_type_khr adapter_type, void *surface_info,
    cl_uint plane, cl_int *errcode_ret) CL_API_SUFFIX__VERSION_1_2;

typedef
cl_int(CL_API_CALL *cl_api_clEnqueueAcquireDX9MediaSurfacesKHR)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event *event) CL_API_SUFFIX__VERSION_1_2;

typedef
cl_int(CL_API_CALL *cl_api_clEnqueueReleaseDX9MediaSurfacesKHR)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list,
    cl_event *event) CL_API_SUFFIX__VERSION_1_2;

/* cl_khr_d3d11_sharing */
extern CL_API_ENTRY cl_int CL_API_CALL clGetDeviceIDsFromD3D11KHR(
    cl_platform_id platform, cl_d3d11_device_source_khr d3d_device_source,
    void *d3d_object, cl_d3d11_device_set_khr d3d_device_set,
    cl_uint num_entries, cl_device_id *devices, cl_uint *num_devices);

extern CL_API_ENTRY cl_mem CL_API_CALL
clCreateFromD3D11BufferKHR(cl_context context, cl_mem_flags flags,
                           ID3D11Buffer *resource, cl_int *errcode_ret);

extern CL_API_ENTRY cl_mem CL_API_CALL clCreateFromD3D11Texture2DKHR(
    cl_context context, cl_mem_flags flags, ID3D11Texture2D *resource,
    UINT subresource, cl_int *errcode_ret);

extern CL_API_ENTRY cl_mem CL_API_CALL clCreateFromD3D11Texture3DKHR(
    cl_context context, cl_mem_flags flags, ID3D11Texture3D *resource,
    UINT subresource, cl_int *errcode_ret);

extern CL_API_ENTRY cl_int CL_API_CALL clEnqueueAcquireD3D11ObjectsKHR(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list, cl_event *event);

extern CL_API_ENTRY cl_int CL_API_CALL clEnqueueReleaseD3D11ObjectsKHR(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list, cl_event *event);

/* cl_khr_dx9_media_sharing */
extern CL_API_ENTRY cl_int CL_API_CALL clGetDeviceIDsFromDX9MediaAdapterKHR(
    cl_platform_id platform, cl_uint num_media_adapters,
    cl_dx9_media_adapter_type_khr *media_adapter_type, void *media_adapters,
    cl_dx9_media_adapter_set_khr media_adapter_set, cl_uint num_entries,
    cl_device_id *devices, cl_uint *num_devices);

extern CL_API_ENTRY cl_mem CL_API_CALL clCreateFromDX9MediaSurfaceKHR(
    cl_context context, cl_mem_flags flags,
    cl_dx9_media_adapter_type_khr adapter_type, void *surface_info,
    cl_uint plane, cl_int *errcode_ret);

extern CL_API_ENTRY cl_int CL_API_CALL clEnqueueAcquireDX9MediaSurfacesKHR(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list, cl_event *event);

extern CL_API_ENTRY cl_int CL_API_CALL clEnqueueReleaseDX9MediaSurfacesKHR(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list, cl_event *event);

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

typedef cl_int(CL_API_CALL *cl_api_clCreateSubDevicesEXT)(
    cl_device_id in_device,
    const cl_device_partition_property_ext *partition_properties,
    cl_uint num_entries, cl_device_id *out_devices, cl_uint *num_devices);

typedef cl_int(CL_API_CALL *cl_api_clRetainDeviceEXT)(
    cl_device_id device) CL_API_SUFFIX__VERSION_1_0;

typedef cl_int(CL_API_CALL *cl_api_clReleaseDeviceEXT)(
    cl_device_id device) CL_API_SUFFIX__VERSION_1_0;

/* cl_khr_egl_image */
typedef cl_mem(CL_API_CALL *cl_api_clCreateFromEGLImageKHR)(
    cl_context context, CLeglDisplayKHR display, CLeglImageKHR image,
    cl_mem_flags flags, const cl_egl_image_properties_khr *properties,
    cl_int *errcode_ret);

typedef cl_int(CL_API_CALL *cl_api_clEnqueueAcquireEGLObjectsKHR)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list, cl_event *event);

typedef cl_int(CL_API_CALL *cl_api_clEnqueueReleaseEGLObjectsKHR)(
    cl_command_queue command_queue, cl_uint num_objects,
    const cl_mem *mem_objects, cl_uint num_events_in_wait_list,
    const cl_event *event_wait_list, cl_event *event);

/* cl_khr_egl_event */
typedef cl_event(CL_API_CALL *cl_api_clCreateEventFromEGLSyncKHR)(
    cl_context context, CLeglSyncKHR sync, CLeglDisplayKHR display,
    cl_int *errcode_ret);

/* Vendor dispatch table struture */

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

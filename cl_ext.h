/*******************************************************************************
 * Copyright (c) 2008-2010 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 ******************************************************************************/

/* $Revision: 11702 $ on $Date: 2010-06-11 19:44:29 -0700 (Fri, 11 Jun 2010) $ */

/* cl_ext.h contains OpenCL extensions which don't have external */
/* (OpenGL, D3D) dependencies.                                   */

#ifndef __CL_EXT_H
#define __CL_EXT_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __APPLE__
	#include <OpenCL/cl.h>
#else
	#include <CL/cl.h>
#endif

/* cl_khr_fp64 extension - no extension #define since it has no functions  */
#define CL_DEVICE_DOUBLE_FP_CONFIG                  0x1032


/* cl_khr_fp16 extension - no extension #define since it has no functions  */
#define CL_DEVICE_HALF_FP_CONFIG                    0x1033


/* cl_khr_icd extension                                                    */
#define cl_khr_icd 1

/* cl_platform_info                                                        */
#define CL_PLATFORM_ICD_SUFFIX_KHR                  0x0920

/* Additional Error Codes                                                  */
#define CL_PLATFORM_NOT_FOUND_KHR                   -1001

extern CL_API_ENTRY cl_int CL_API_CALL
clIcdGetPlatformIDsKHR(cl_uint          /* num_entries */,
                       cl_platform_id * /* platforms */,
                       cl_uint *        /* num_platforms */);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clIcdGetPlatformIDsKHR_fn)(
    cl_uint          num_entries,
    cl_platform_id * platforms,
    cl_uint *        num_platforms);

/* cl_amd_device_attribute_query - no extension #define since it has no functions */
#define CL_DEVICE_PROFILING_TIMER_OFFSET_AMD        0x4036

/***********************************
 * cl_ext_device_fission extension *
 ***********************************/
#ifndef cl_ext_device_fission
#define cl_ext_device_fission   1
        
extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseDeviceEXT( cl_device_id /*device*/ ) CL_EXTENSION_WEAK_LINK; 
        
typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseDeviceEXT_fn)( 
    cl_device_id /*device*/ ) CL_EXTENSION_WEAK_LINK;

extern CL_API_ENTRY cl_int CL_API_CALL
clRetainDeviceEXT( cl_device_id /*device*/ ) CL_EXTENSION_WEAK_LINK; 
        
typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainDeviceEXT_fn)( 
    cl_device_id /*device*/ ) CL_EXTENSION_WEAK_LINK;

typedef cl_ulong  cl_device_partition_property_ext;

extern CL_API_ENTRY cl_int CL_API_CALL 
clCreateSubDevicesEXT(  
    cl_device_id /*in_device*/,
    const cl_device_partition_property_ext * /* properties */,
    cl_uint /*num_entries*/,
    cl_device_id * /*out_devices*/,
    cl_uint * /*num_devices*/ ) CL_EXTENSION_WEAK_LINK;

typedef CL_API_ENTRY cl_int (CL_API_CALL * clCreateSubDevicesEXT_fn)(  
    cl_device_id /*in_device*/,
    const cl_device_partition_property_ext * /* properties */,
    cl_uint /*num_entries*/,
    cl_device_id * /*out_devices*/,
    cl_uint * /*num_devices*/ ) CL_EXTENSION_WEAK_LINK;

 /* cl_device_partition_property_ext */
#define CL_DEVICE_PARTITION_EQUALLY_EXT             0x4050
#define CL_DEVICE_PARTITION_BY_COUNTS_EXT           0x4051
#define CL_DEVICE_PARTITION_BY_NAMES_EXT            0x4052
#define CL_DEVICE_PARTITION_BY_AFFINITY_DOMAIN_EXT  0x4053
        
/* clDeviceGetInfo selectors */
#define CL_DEVICE_PARENT_DEVICE_EXT                 0x4054
#define CL_DEVICE_PARTITION_TYPES_EXT               0x4055
#define CL_DEVICE_AFFINITY_DOMAINS_EXT              0x4056
#define CL_DEVICE_REFERENCE_COUNT_EXT               0x4057
#define CL_DEVICE_PARTITION_STYLE_EXT               0x4058
        
/* error codes */
#define CL_DEVICE_PARTITION_FAILED_EXT              -1057
#define CL_INVALID_PARTITION_COUNT_EXT              -1058
#define CL_INVALID_PARTITION_NAME_EXT               -1059
        
/* CL_AFFINITY_DOMAINs */
#define CL_AFFINITY_DOMAIN_L1_CACHE_EXT             0x1
#define CL_AFFINITY_DOMAIN_L2_CACHE_EXT             0x2
#define CL_AFFINITY_DOMAIN_L3_CACHE_EXT             0x3
#define CL_AFFINITY_DOMAIN_L4_CACHE_EXT             0x4
#define CL_AFFINITY_DOMAIN_NUMA_EXT                 0x10
#define CL_AFFINITY_DOMAIN_NEXT_FISSIONABLE_EXT     0x100
        
/* cl_device_partition_property_ext list terminators */
#define CL_PROPERTIES_LIST_END_EXT                  ((cl_device_partition_property_ext) 0)
#define CL_PARTITION_BY_COUNTS_LIST_END_EXT  ((cl_device_partition_property_ext) 0)
#define CL_PARTITION_BY_NAMES_LIST_END_EXT   ((cl_device_partition_property_ext) 0 - 1)

#endif /* cl_ext_device_fission */

/***********************************
 * cl_ext_migrate_memobject extension definitions
 ***********************************/
#ifndef cl_ext_migrate_memobject
#define cl_ext_migrate_memobject 1

typedef cl_bitfield cl_mem_migration_flags_ext;

#define CL_MIGRATE_MEM_OBJECT_HOST_EXT              0x1

#define CL_COMMAND_MIGRATE_MEM_OBJECT_EXT           0x4040

extern CL_API_ENTRY cl_int CL_API_CALL
clEnqueueMigrateMemObjectEXT( 
    cl_command_queue /* command_queue */,
    cl_uint /* num_mem_objects */,           
    const cl_mem * /* mem_objects */,
    cl_mem_migration_flags_ext /* flags */,
    cl_uint /* num_events_in_wait_list */,
    const cl_event * /* event_wait_list */,
    cl_event * /* event */);

typedef CL_API_ENTRY cl_int (CL_API_CALL *clEnqueueMigrateMemObjectEXT_fn)( 
    cl_command_queue /* command_queue */,
    cl_uint /* num_mem_objects */,           
    const cl_mem * /* mem_objects */,
    cl_mem_migration_flags_ext /* flags */,
    cl_uint /* num_events_in_wait_list */,
    const cl_event * /* event_wait_list */,
    cl_event * /* event */);

#endif /* cl_ext_migrate_memobject */

#ifdef __cplusplus
}
#endif


#endif /* __CL_EXT_H */

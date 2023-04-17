<%
# Extensions to skip by default because they are in dedicated headers:
skipExtensions = {
    'cl_khr_d3d10_sharing',
    'cl_khr_d3d11_sharing',
    'cl_khr_dx9_media_sharing',
    'cl_khr_egl_event',
    'cl_khr_egl_image',
    'cl_khr_gl_depth_images',
    'cl_khr_gl_event',
    'cl_khr_gl_msaa_sharing',
    'cl_khr_gl_sharing',
    'cl_loader_layers',
    'cl_intel_dx9_media_sharing',
    'cl_intel_va_api_media_sharing',
    'cl_intel_sharing_format_query_d3d10',
    'cl_intel_sharing_format_query_d3d11',
    'cl_intel_sharing_format_query_dx9',
    'cl_intel_sharing_format_query_gl',
    'cl_intel_sharing_format_query_va_api',
    }

# Extensions to include in this header:
def shouldGenerate(extension):
    if extension in genExtensions:
        return True
    elif not genExtensions and not extension in skipExtensions:
        return True
    return False

# XML blocks to include in the headers:
def shouldEmit(block):
    for type in block.findall('type'):
        if type.get('name') in typedefs:
            return True
        elif type.get('name') in macros:
            return True
        elif type.get('name') in structs:
            return True
    for enum in block.findall('enum'):
        #if enum.get('name') in enums:
            return True
    for func in block.findall('command'):
        return True
    return False

# Initially, keep the same extension order as the original headers:
orderedExtensions = [
    # cl_ext.h:
    'cl_khr_command_buffer',
    'cl_khr_command_buffer_multi_device',
    'cl_khr_command_buffer_mutable_dispatch',
    'cl_khr_fp64',
    'cl_khr_fp16',
    'cl_APPLE_SetMemObjectDestructor',
    'cl_APPLE_ContextLoggingFunctions',
    'cl_khr_icd',
    'cl_khr_il_program',
    'cl_khr_image2D_from_buffer',   # incorrect name
    'cl_khr_image2d_from_buffer',
    'cl_khr_initialize_memory',
    'cl_khr_terminate_context',
    'cl_khr_spir',
    'cl_khr_create_command_queue',
    'cl_nv_device_attribute_query',
    'cl_amd_device_attribute_query',
    'cl_arm_printf',
    'cl_ext_device_fission',
    'cl_ext_migrate_memobject',
    'cl_ext_cxx_for_opencl',
    'cl_qcom_ext_host_ptr',
    'cl_qcom_ext_host_ptr_iocoherent',
    'cl_qcom_ion_host_ptr',
    'cl_qcom_android_native_buffer_host_ptr',
    'cl_img_yuv_image',
    'cl_img_cached_allocations',
    'cl_img_use_gralloc_ptr',
    'cl_img_generate_mipmap',
    'cl_img_mem_properties',
    'cl_khr_subgroups',
    'cl_khr_mipmap_image',
    'cl_khr_priority_hints',
    'cl_khr_throttle_hints',
    'cl_khr_subgroup_named_barrier',
    'cl_khr_extended_versioning',
    'cl_khr_device_uuid',
    'cl_khr_pci_bus_info',
    'cl_khr_suggested_local_work_size',
    'cl_khr_integer_dot_product',
    'cl_khr_external_memory',
    'cl_khr_external_memory_dma_buf',
    'cl_khr_external_memory_dx',
    'cl_khr_external_memory_opaque_fd',
    'cl_khr_external_memory_win32',
    'cl_khr_external_semaphore',
    'cl_khr_external_semaphore_dx_fence',
    'cl_khr_external_semaphore_opaque_fd',
    'cl_khr_external_semaphore_sync_fd',
    'cl_khr_external_semaphore_win32',
    'cl_khr_semaphore',
    'cl_arm_import_memory',
    'cl_arm_shared_virtual_memory',
    'cl_arm_get_core_id',
    'cl_arm_job_slot_selection',
    'cl_arm_scheduling_controls',
    'cl_arm_controlled_kernel_termination',
    'cl_arm_protected_memory_allocation',
    'cl_intel_exec_by_local_thread',
    'cl_intel_device_attribute_query',
    'cl_intel_device_partition_by_names',
    'cl_intel_accelerator',
    'cl_intel_motion_estimation',
    'cl_intel_advanced_motion_estimation',
    'cl_intel_simultaneous_sharing',
    'cl_intel_egl_image_yuv',
    'cl_intel_packed_yuv',
    'cl_intel_required_subgroup_size',
    'cl_intel_driver_diagnostics',
    'cl_intel_planar_yuv',
    'cl_intel_device_side_avc_motion_estimation',
    'cl_intel_unified_shared_memory',
    'cl_intel_mem_alloc_buffer_location',
    'cl_intel_create_buffer_with_properties',
    'cl_intel_program_scope_host_pipe',
    'cl_intel_mem_channel_property',
    'cl_intel_mem_force_host_memory',
    'cl_intel_command_queue_families',
    'cl_intel_queue_no_sync_operations',
    'cl_intel_sharing_format_query',
    'cl_ext_image_requirements_info',
    'cl_ext_image_from_buffer',
    'cl_loader_info',
    'cl_khr_depth_images',
    'cl_ext_float_atomics',
    'cl_intel_create_mem_object_properties',
    'cl_pocl_content_size',
    # cl_d3d10.h
    'cl_khr_d3d10_sharing',
    'cl_intel_sharing_format_query_d3d10',
    # cl_d3d11.h
    'cl_khr_d3d11_sharing',
    'cl_intel_sharing_format_query_d3d11',
    # cl_dx9_media_sharing.h
    'cl_khr_dx9_media_sharing',
    'cl_intel_dx9_media_sharing',
    'cl_intel_sharing_format_query_dx9',
    # cl_egl.h
    'cl_khr_egl_image',
    'cl_khr_egl_event',
    # cl_gl.h
    'cl_khr_gl_sharing',
    'cl_khr_gl_event',
    'cl_khr_gl_depth_images',
    'cl_khr_gl_msaa_sharing',
    'cl_intel_sharing_format_query_gl',
    # cl_layer.h
    'cl_loader_layers',
    # cl_va_api_media_sharing_intel.h
    'cl_intel_sharing_format_query_va_api',
    'cl_intel_va_api_media_sharing',
    ]

def getExtensionSortKey(item):
    name = item.get('name')
    return orderedExtensions.index(name)

# Order the extensions should be emitted in the headers.
# KHR -> EXT -> Vendor Extensions
def getExtensionSortKey_ideal(item):
    name = item.get('name')
    if name.startswith('cl_khr'):
        return 0, name
    if name.startswith('cl_ext'):
        return 1, name
    return 99, name

# Order enums should be emitted in the headers.
# Enums Without Bits -> Ordered Bit Enums
def getEnumSortKey(item):
    name = item.get('name')
    if name in enums:
        if enums[name].Value:
            return -1
        if enums[name].Bitpos:
            return int(enums[name].Bitpos)
    return 99

# Gets C function parameter strings for the specified API params:
def getCParameterStrings(params):
    strings = []
    if len(params) == 0:
        strings.append("void")
    else:
        for param in params:
            paramstr = param.Type + ' ' + param.Name + param.TypeEnd
            strings.append(paramstr)
    return strings

# Gets a bit string for the specified bit position:
def getBitPosString(bitpos):
    ret = '('
    ret += '(cl_bitfield)' if int(bitpos) >= 31 else ''
    ret += '1 << '
    ret += bitpos
    ret += ')'
    return ret

# Extensions that are included in the ICD dispatch table for historical reasons.
# This should not be required for new extensions!
loaderExtensions = {
    'cl_ext_device_fission',
    'cl_khr_d3d10_sharing',
    'cl_khr_d3d11_sharing',
    'cl_khr_dx9_media_sharing',
    'cl_khr_egl_event',
    'cl_khr_egl_image',
    'cl_khr_gl_event',
    'cl_khr_gl_sharing',
    'cl_khr_subgroups'
    }

# Gets the preprocessor guard for the given extension:
def getPrototypeIfGuard(name):
    if name in loaderExtensions:
        guard = '!defined(CL_NO_ICD_DISPATCH_EXTENSION_PROTOTYPES)'
    else:
        guard = '!defined(CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES)'
    return guard

# Names that have been generated already, since some may be shared by multiple
# extensions:
generatedNames = set()

def isDuplicateName(name):
    if name in generatedNames:
        return True
    generatedNames.add(name)
    return False

%>/*******************************************************************************
 * Copyright (c) 2008-2023 The Khronos Group Inc.
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

#ifndef ${guard}
#define ${guard}

/*
** This header is generated from the Khronos OpenCL XML API Registry.
*/

%if includes:
${includes}

%endif
#include <CL/cl.h>

/* CL_NO_PROTOTYPES implies CL_NO_EXTENSION_PROTOTYPES: */
#if defined(CL_NO_PROTOTYPES) && !defined(CL_NO_EXTENSION_PROTOTYPES)
#define CL_NO_EXTENSION_PROTOTYPES
#endif

/* CL_NO_EXTENSION_PROTOTYPES implies
   CL_NO_ICD_DISPATCH_EXTENSION_PROTOTYPES and
   CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES: */
#if defined(CL_NO_EXTENSION_PROTOTYPES) && ${"\\"}
    !defined(CL_NO_ICD_DISPATCH_EXTENSION_PROTOTYPES)
#define CL_NO_ICD_DISPATCH_EXTENSION_PROTOTYPES
#endif
#if defined(CL_NO_EXTENSION_PROTOTYPES) && ${"\\"}
    !defined(CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES)
#define CL_NO_NON_ICD_DISPATCH_EXTENSION_PROTOTYPES
#endif

#ifdef __cplusplus
extern "C" {
#endif

%for extension in sorted(spec.findall('extensions/extension'), key=getExtensionSortKey):
%  if shouldGenerate(extension.get('name')):
<%
    name = extension.get('name')
%>/***************************************************************
* ${name}
***************************************************************/
%if extension.get('condition'):
#if ${extension.get('condition')}

%endif
#define ${name} 1
#define ${name.upper()}_EXTENSION_NAME ${"\\"}
    "${name}"

%for block in extension.findall('require'):
%  if shouldEmit(block):
%    if block.get('condition'):
#if ${block.get('condition')}
%    endif
%    if block.get('comment'):
/* ${block.get('comment')} */
%    endif
%    for type in block.findall('type'):
%      if isDuplicateName(type.get('name')):
/* type ${type.get('name')} */
%      else:
%        if type.get('name') in typedefs:
${typedefs[type.get('name')].Typedef.ljust(27)} ${type.get('name')};
%        elif type.get('name') in macros:
#define ${type.get('name')}${macros[type.get('name')].Macro}
%        elif type.get('name') in structs:
<%
    struct = structs[type.get('name')]
%>typedef struct _${struct.Name} {
%          for i, member in enumerate(struct.Members):
    ${member.Type} ${member.Name}${member.TypeEnd};
%          endfor
} ${struct.Name};
%        else:
// type ${type.get('name')} not found!
%        endif
%      endif
%    endfor
%    for enum in sorted(block.findall('enum'), key=getEnumSortKey):
%      if isDuplicateName(enum.get('name')):
/* enum ${enum.get('name')} */
%      else:
%        if enum.get('name') in enums:
%          if enums[enum.get('name')].Value:
#define ${enum.get('name').ljust(51)} ${enums[enum.get('name')].Value}
%          elif enums[enum.get('name')].Bitpos:
#define ${enum.get('name').ljust(51)} ${getBitPosString(enums[enum.get('name')].Bitpos)}
%          else:
// enum ${enum.get('name')} is unassigned!
%          endif
%        else:
// enum ${enum.get('name')} not found!
%        endif
%      endif
%    endfor
%    if block.findall('command'):
%      for func in block.findall('command'):
<%
    api = apisigs[func.get('name')]
%>
typedef ${api.RetType} (CL_API_CALL *
${api.Name}_fn)(
%        for i, paramStr in enumerate(getCParameterStrings(api.Params)):
%          if i < len(api.Params)-1:
    ${paramStr},
%          else:
    ${paramStr}) ${api.Suffix};
%          endif
%        endfor
%      endfor
%      if generate_pfn_typedefs:

/*
** The function pointer typedefs prefixed with "pfn_" are provided for
** compatibility with earlier versions of the headers.  New code is
** encouraged to use the function pointer typedefs that are suffixed with
** "_fn" instead, for consistency.
*/
%        for func in block.findall('command'):
<%
    api = apisigs[func.get('name')]
%>
typedef ${api.RetType} (CL_API_CALL *
pfn_${api.Name})(
%          for i, paramStr in enumerate(getCParameterStrings(api.Params)):
%            if i < len(api.Params)-1:
    ${paramStr},
%            else:
    ${paramStr}) ${api.Suffix};
%            endif
%          endfor
%        endfor
%      endif

#if ${getPrototypeIfGuard(name)}
%      for func in block.findall('command'):
<%
    api = apisigs[func.get('name')]
%>
extern CL_API_ENTRY ${api.RetType} CL_API_CALL
${api.Name}(
%        for i, paramStr in enumerate(getCParameterStrings(api.Params)):
%          if i < len(api.Params)-1:
    ${paramStr},
%          else:
    ${paramStr}) ${api.Suffix};
%          endif
%        endfor
%      endfor

#endif /* ${getPrototypeIfGuard(name)} */
%    endif
%    if block.get('condition'):

#endif /* ${block.get('condition')} */
%    endif

%  endif
%endfor
%if extension.get('condition'):
#endif /* ${extension.get('condition')} */

%endif
%  endif
%endfor
#ifdef __cplusplus
}
#endif

#endif /* ${guard} */

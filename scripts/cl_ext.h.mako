<%
# Extensions to skip - they are in dedicated headers.
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

# Order the extensions should be emitted in the headers.
# KHR -> EXT -> Vendor Extensions
def getExtensionSortKey(item):
    name = item.get('name')
    if name.startswith('cl_khr'):
        return 0, name
    if name.startswith('cl_ext'):
        return 1, name
    return 99, name

# Order enums should be emitted in the haders.
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
    ret = '(1'
    ret += 'ULL' if int(bitpos) > 31 else ''
    ret += ' << '
    ret += bitpos
    ret += ')'
    return ret

# Names that have been generated already, since some may be shared by multiple
# extensions:
generatedNames = set()

def isDuplicateName(name):
    if name in generatedNames:
        return True
    generatedNames.add(name)
    return False

%>/*******************************************************************************
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

#ifndef ${guard}
#define ${guard}

/*
** This header is generated from the Khronos OpenCL XML API Registry.
*/

%if includes:
${includes}
%endif
#include <CL/cl.h>

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

#ifndef CL_NO_PROTOTYPES
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

#endif /* CL_NO_PROTOTYPES */
%    endif
%    if block.get('condition'):

#endif /* ${block.get('condition')} */
%    endif

%  endif
%endfor
%  endif
%endfor
#ifdef __cplusplus
}
#endif

#endif /* ${guard} */

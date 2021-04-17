#!/usr/bin/python3

# Copyright (c) 2021 The Khronos Group Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from mako.template import Template
from mako.exceptions import RichTraceback

from collections import OrderedDict
from collections import namedtuple

import argparse
import sys
import urllib
import xml.etree.ElementTree as etree
import urllib.request

# parse_xml - Helper function to parse the XML file from a URL or local file.
def parse_xml(path):
    file = urllib.request.urlopen(path) if path.startswith("http") else open(path, 'r')
    with file:
        tree = etree.parse(file)
        return tree

# noneStr - returns string argument, or "" if argument is None.
def noneStr(s):
    if s:
        return s
    return ""

def getDisableWarningIncludeString(include):
    warningPush = """#if defined(_MSC_VER)
#if _MSC_VER >=1500
#pragma warning( push )
#pragma warning( disable : 4201 )
#endif
#endif
"""
    warningPop = """
#if defined(_MSC_VER)
#if _MSC_VER >=1500
#pragma warning( pop )
#endif
#endif
"""
    return warningPush + include + warningPop

def getWin32OnlyIncludeString(include):
    return """#if defined(_WIN32)
""" + include + """
#endif
"""



if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    # To pull the latest registry file from GitHub, pass:
    # -registry "https://raw.githubusercontent.com/KhronosGroup/OpenCL-Registry/master/xml/cl.xml"

    parser.add_argument('-registry', action='store',
                        default='cl.xml',
                        help='Use specified registry file instead of cl.xml')
    parser.add_argument('-o', action='store', dest='directory',
                        default='.',
                        help='Create target and related files in specified directory')

    args = parser.parse_args()

    specpath = args.registry

    print('Parsing XML file from: ' + specpath)
    spec = parse_xml(specpath)

    # Generate the API typedef and struct dictionaries:
    typedefs = OrderedDict()
    Typedef = namedtuple('Typedef', 'Typedef Name')
    macros = OrderedDict()
    Macro = namedtuple('Macro', 'Define Name Macro')
    structs = OrderedDict()
    Struct = namedtuple('Struct', 'Name Members')
    StructMember = namedtuple('StructMember', 'Type TypeEnd Name')
    print('Generating API typedef dictionary...')
    for type in spec.findall('types/type'):
        if type.get('category') == 'define':
            if noneStr(type.text).startswith("typedef"):
                typedef = noneStr(type.text)
                name = ""
                for elem in type:
                    if elem.tag == 'name':
                        name = noneStr(elem.text)
                    else:
                        typedef = typedef + noneStr(elem.text) + noneStr(elem.tail)
                typedef = typedef.strip()
                name = name.strip()
                typedefs[name] = Typedef(typedef, name)
            if noneStr(type.text).startswith("#define"):
                define = noneStr(type.text)
                name = ""
                macro = ""
                for elem in type:
                    if elem.tag == 'name':
                        name = noneStr(elem.text)
                        macro = macro + noneStr(elem.tail)
                define = define.strip()
                name = name.strip()
                macro = macro.rstrip() # keep spaces on the left!
                macros[name] = Macro(define, name, macro)
        if type.get('category') == 'struct':
            name = type.get('name')
            mlist = []
            for member in type.findall('member'):
                mtype = noneStr(member.text)
                mtypeend = ""
                mname = ""
                for elem in member:
                    if elem.tag == 'name':
                        mname = noneStr(elem.text)
                        mtypeend = noneStr(elem.tail)
                    elif elem.tag == 'enum':
                        # Assumes any additional enums are for array limits, e.g.:
                        # <member><type>char</type><name>name</name>[<enum>CL_NAME_VERSION_MAX_NAME_SIZE</enum>]</member>
                        mtypeend = mtypeend + noneStr(elem.text) + noneStr(elem.tail)
                    else:
                        mtype = mtype + noneStr(elem.text) + noneStr(elem.tail)
                mtype = mtype.strip()
                mtypeend = mtypeend.strip()
                mname = mname.strip()
                mlist.append(StructMember(mtype, mtypeend, mname))
            structs[name] = Struct(name, mlist)

    # Generate the API enum dictionary:
    enums = OrderedDict()
    Enum = namedtuple('Enum', 'Value Bitpos Name')
    print('Generating API enum dictionary...')
    for enum in spec.findall('enums/enum'):
        value = enum.get('value')
        bitpos = enum.get('bitpos')
        name = enum.get('name')
        enums[name] = Enum(value, bitpos, name)

    # Generate the API function signatures dictionary:
    apisigs = OrderedDict()
    ApiSignature = namedtuple('ApiSignature', 'Name RetType Params Suffix')
    ApiParam = namedtuple('ApiParam', 'Type TypeEnd Name')
    print('Generating API function signatures dictionary...')
    for command in spec.findall('commands/command'):
        suffix = noneStr(command.get('suffix'))
        proto = command.find('proto')
        ret = noneStr(proto.text)
        name = ""
        params = ""
        for elem in proto:
            if elem.tag == 'name':
                name = noneStr(elem.text) + noneStr(elem.tail)
            else:
                ret = ret + noneStr(elem.text) + noneStr(elem.tail)
        ret = ret.strip()
        name = name.strip()

        plist = []
        for param in command.findall('param'):
            ptype = noneStr(param.text)
            ptypeend = ""
            pname = ""
            for elem in param:
                if elem.tag == 'name':
                    pname = noneStr(elem.text)
                    ptypeend = noneStr(elem.tail)
                else:
                    ptype = ptype + noneStr(elem.text) + noneStr(elem.tail)
            ptype = ptype.strip()
            ptypeend = ptypeend.strip()
            pname = pname.strip()
            plist.append(ApiParam(ptype, ptypeend, pname))
        apisigs[name] = ApiSignature(name, ret, plist, suffix)

    # Generate the core API dictionary:
    coreapis = OrderedDict()
    coretypes = OrderedDict()
    coreenums = OrderedDict()
    print('Generating core API dictionary...')
    for feature in spec.findall('feature'):
        version = noneStr(feature.get('name'))

        alist = []
        for function in feature.findall('require/command'):
            name = function.get('name')
            alist.append(apisigs[name])
        coreapis[version] = alist

        tlist = []
        for type in feature.findall('require/type'):
            name = type.get('name')
            if name in typedefs:
                tlist.append(typedefs[name])
            else:
                print('Type %s was not found.' % name)
        coretypes[version] = tlist

        elist = []
        for enum in feature.findall('require/enum'):
            name = enum.get('name')
            if name in enums:
                elist.append(enums[name])
            else:
                print('Enum %s was not found.' % name)
        coreenums[version] = elist

    # Generate the extension API function dictionary:
    extapis = OrderedDict()
    print('Generating API extensions dictionary...')
    for feature in spec.findall('extensions/extension'):
        extension = noneStr(feature.get('name'))

        alist = []
        for function in feature.findall('require/command'):
            name = function.get('name')
            alist.append(apisigs[name])
        extapis[extension] = alist

    try:
        cl_ext_h_template = Template(filename='cl_ext.h.mako')

        gen = open(args.directory + '/cl_dx9_media_sharing.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={'cl_khr_dx9_media_sharing', 'cl_intel_dx9_media_sharing'},
              guard="OPENCL_CL_DX9_MEDIA_SHARING_H_",
              includes=getWin32OnlyIncludeString("#include <d3d9.h>"),
              spec=spec,
              typedefs=typedefs,
              macros=macros,
              structs=structs,
              enums=enums,
              apisigs=apisigs,
              coreapis=coreapis,
              extapis=extapis).
          encode('utf-8', 'replace'))

        gen = open(args.directory + '/cl_d3d10.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={'cl_khr_d3d10_sharing'},
              guard="OPENCL_CL_D3D10_H_",
              includes=getDisableWarningIncludeString("#include <d3d10.h>"),
              spec=spec,
              typedefs=typedefs,
              macros=macros,
              structs=structs,
              enums=enums,
              apisigs=apisigs,
              coreapis=coreapis,
              extapis=extapis).
          encode('utf-8', 'replace'))

        gen = open(args.directory + '/cl_d3d11.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={'cl_khr_d3d11_sharing'},
              guard="OPENCL_CL_D3D11_H_",
              includes=getDisableWarningIncludeString("#include <d3d11.h>"),
              spec=spec,
              typedefs=typedefs,
              macros=macros,
              structs=structs,
              enums=enums,
              apisigs=apisigs,
              coreapis=coreapis,
              extapis=extapis).
          encode('utf-8', 'replace'))

        gen = open(args.directory + '/cl_egl.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={'cl_khr_egl_event', 'cl_khr_egl_image'},
              guard="OPENCL_CL_EGL_H_",
              spec=spec,
              typedefs=typedefs,
              macros=macros,
              structs=structs,
              enums=enums,
              apisigs=apisigs,
              coreapis=coreapis,
              extapis=extapis).
          encode('utf-8', 'replace'))

        gen = open(args.directory + '/cl_gl.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={
                  'cl_khr_gl_depth_images',
                  'cl_khr_gl_event',
                  'cl_khr_gl_msaa_sharing',
                  'cl_khr_gl_sharing',
              },
              guard="OPENCL_CL_GL_H_",
              spec=spec,
              typedefs=typedefs,
              macros=macros,
              structs=structs,
              enums=enums,
              apisigs=apisigs,
              coreapis=coreapis,
              extapis=extapis).
          encode('utf-8', 'replace'))

        gen = open(args.directory + '/cl_layer.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={'cl_loader_layers'},
              guard="OPENCL_CL_LAYER_H_",
              includes='#include <CL/cl_icd.h>',
              spec=spec,
              typedefs=typedefs,
              macros=macros,
              structs=structs,
              enums=enums,
              apisigs=apisigs,
              coreapis=coreapis,
              extapis=extapis).
          encode('utf-8', 'replace'))

        gen = open(args.directory + '/cl_va_api_media_sharing_intel.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={'cl_intel_va_api_media_sharing'},
              guard="OPENCL_CL_VA_API_MEDIA_SHARING_INTEL_H_",
              includes='#include <va/va.h>',
              spec=spec,
              typedefs=typedefs,
              macros=macros,
              structs=structs,
              enums=enums,
              apisigs=apisigs,
              coreapis=coreapis,
              extapis=extapis).
          encode('utf-8', 'replace'))

        gen = open(args.directory + '/cl_ext.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={},
              guard="OPENCL_CL_EXT_H_",
              spec=spec,
              typedefs=typedefs,
              macros=macros,
              structs=structs,
              enums=enums,
              apisigs=apisigs,
              coreapis=coreapis,
              extapis=extapis).
          encode('utf-8', 'replace'))
    except:
        traceback = RichTraceback()
        for (filename, lineno, function, line) in traceback.traceback:
            print('%s(%s) : error in %s' % (filename, lineno, function))
            print('    ', line)
        print('%s: %s' % (str(traceback.error.__class__.__name__), traceback.error))

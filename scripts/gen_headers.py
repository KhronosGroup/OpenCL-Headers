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

import gen

from mako.template import Template
from mako.exceptions import RichTraceback

from collections import OrderedDict
from collections import namedtuple

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
    args = gen.parse_args()
    spec = gen.load_spec(args)

    typedefs = gen.get_apitypedefs(spec)
    macros = gen.get_apimacros(spec)
    structs = gen.get_apistructs(spec)
    enums = gen.get_apienums(spec)
    apisigs = gen.get_apisigs(spec)

    coreapis = gen.get_coreapis(spec, apisigs)
    extapis = gen.get_extapis(spec, apisigs)

    try:
        cl_ext_h_template = Template(filename='cl_ext.h.mako')

        print('Generating cl_dx9_media_sharing.h...')
        gen = open(args.directory + '/cl_dx9_media_sharing.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={
                  'cl_khr_dx9_media_sharing',
                  'cl_intel_dx9_media_sharing',
                  'cl_intel_sharing_format_query_dx9',
              },
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

        print('Generating cl_d3d10.h...')
        gen = open(args.directory + '/cl_d3d10.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={
                  'cl_khr_d3d10_sharing',
                  'cl_intel_sharing_format_query_d3d10',
              },
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

        print('Generating cl_d3d11.h...')
        gen = open(args.directory + '/cl_d3d11.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={
                  'cl_khr_d3d11_sharing',
                  'cl_intel_sharing_format_query_d3d11'
              },
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

        print('Generating cl_egl.h...')
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

        print('Generating cl_gl.h...')
        gen = open(args.directory + '/cl_gl.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={
                  'cl_khr_gl_depth_images',
                  'cl_khr_gl_event',
                  'cl_khr_gl_msaa_sharing',
                  'cl_khr_gl_sharing',
                  'cl_intel_sharing_format_query_gl',
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

        # cl_layer.h is currently generated but unused because the ICD loader
        # uses a different naming convention for function pointers.
        print('Generating cl_layer.h (note: unused)...')
        gen = open(args.directory + '/cl_layer-unused.h', 'wb')
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

        print('Generating cl_va_api_media_sharing_intel.h...')
        gen = open(args.directory + '/cl_va_api_media_sharing_intel.h', 'wb')
        gen.write(
          cl_ext_h_template.render_unicode(
              genExtensions={
                  'cl_intel_va_api_media_sharing',
                  'cl_intel_sharing_format_query_va_api',
              },
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

        print('Generating cl_ext.h...')
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

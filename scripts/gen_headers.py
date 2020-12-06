#!/usr/bin/python3

# Copyright (c) 2020 Ben Ashbaugh
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

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
    structs = OrderedDict()
    Struct = namedtuple('Struct', 'Name Members')
    StructMember = namedtuple('StructMember', 'Type TypeEnd Name')
    print('Generating API typedef dictionary...')
    for type in spec.findall('types/type'):
        if type.get('category') == 'define':
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
        # Create the loader cpp file from the API dictionary:
        test = open(args.directory + '/cl_ext.h', 'wb')
        cl_ext_h_template = Template(filename='cl_ext.h.mako')
        test.write(
          cl_ext_h_template.render_unicode(
              spec=spec,
              typedefs=typedefs,
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

# OpenCL Header Code Generation

## Introduction

In order to ease maintenance and enable faster development in the OpenCL headers, the OpenCL headers for extensions are generated from the OpenCL XML machine readable grammar.
Currently, header generation is only enabled for the OpenCL headers for extensions, and the OpenCL headers for core APIs are still authored manually.

## Dependencies

The OpenCL headers are generated using Python [Mako Templates](https://www.makotemplates.org/).

In most cases, after installing Python for your platform, Mako may be installed using:

```sh
$ pip install Mako
```

## Making Changes

Most changes only require modifications to the Mako templates.
Small changes modifying syntax or layout are simple and straightforward.
Occasionally, more complicated changes will be required, say when a new API is added that is unlike any previous API or when a new extension header file is needed, but this should be rare.

The Python script should only need to be modified if additional information needs to be propagated from the XML file into the Mako template itself.

## Generating Headers

The script to generate headers requires the `cl.xml` machine readable grammar.
The latest version of `cl.xml` may be found in the Khronos OpenCL-Docs repo [here](https://github.com/KhronosGroup/OpenCL-Docs/blob/main/xml/cl.xml).

The easiest way to generate new headers is by using the `headers_generate` target.
For example, from a directory used to build the headers, simply execute:

```sh
$ cmake --build . --target headers_generate
```

The `cl.xml` file used to generate headers with the header generation target may be provided by setting the CMake variable `OPENCL_HEADERS_XML_PATH` to the full path to `cl.xml`.

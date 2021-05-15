/*******************************************************************************
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

#ifndef OPENCL_DLOPEN_H
#define OPENCL_DLOPEN_H

#ifdef OPENCL_LOAD

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#include <pthread.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

extern
#ifdef _WIN32
HMODULE
#else
void *
#endif
opencl_lib_handle;

cl_int extOpenOpenCL();

inline cl_int
extFindOpenCLSymbol(void **pVar, const char *symbolName) {
  if(!opencl_lib_handle) {
    cl_int err = extOpenOpenCL();
    if(err != CL_SUCCESS)
      return err;
  }
  *pVar = dlsym(opencl_lib_handle, symbolName);
  if (!*pVar)
    return CL_INVALID_OPERATION;
  else
    return CL_SUCCESS;
}

#define CLLD_PTR_NAME(name) name ## _ptr

#define CLLD_PTR CLLD_PTR_NAME

#define CLLD_DECL(name) \
extern cl_api_ ## name CLLD_PTR_NAME(name)

#define CLLD_DEF(name) \
cl_api_ ## name CLLD_PTR_NAME(name)

#define CLLD_FETCH_SYMBOL(name) \
extFindOpenCLSymbol((void**)&CLLD_PTR_NAME(name), #name)

#define CLLD_FETCH_RET(name, ret) \
do { \
    if (!CLLD_PTR_NAME(name)) { \
        cl_int _err = CLLD_FETCH_SYMBOL(name); \
        if (_err != CL_SUCCESS) return ret; \
    } \
} while(0)

#define CLLD_FETCH(name) CLLD_FETCH_RET(name, _err)
#define CLLD_FETCH_NULL(name) CLLD_FETCH_RET(name, NULL)
#define CLLD_FETCH_NOERR(name) CLLD_FETCH_RET(name, )

#define CLLD_FETCH_ERR(name, errcode_ret) \
do { \
    if (!CLLD_PTR(name)) { \
        cl_int _err = CLLD_FETCH_SYMBOL(name); \
        if (_err != CL_SUCCESS) { \
            if (errcode_ret) \
              *errcode_ret = _err; \
            return NULL; \
        } \
    } \
} while(0)

#ifdef __cplusplus
}
#endif

#endif /* OPENCL_LOAD */

#endif /* OPENCL_DLOPEN_H */

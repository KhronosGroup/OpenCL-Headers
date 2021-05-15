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

#ifndef OPENCL_DLOPEN_LIB_H
#define OPENCL_DLOPEN_LIB_H

#ifdef OPENCL_LOAD

#ifdef _WIN32
#include <windows.h>
#else
#include <dlfcn.h>
#include <pthread.h>
#endif

#include <CL/opencl.h>

#ifdef _WIN32
static INIT_ONCE initialized = INIT_ONCE_STATIC_INIT;
HMODULE opencl_lib_handle = (HMODULE)NULL;
#else
static pthread_once_t initialized = PTHREAD_ONCE_INIT;
void *opencl_lib_handle = NULL;
#endif
opencl_load_dispatch opencl_lib_dispatch;

#ifdef _WIN32
static void extOpenOpenCL_impl(PINIT_ONCE InitOnce, PVOID Parameter, PVOID *lpContext) {
    (void)InitOnce; (void)Parameter; (void)lpContext;
    opencl_lib_handle = LoadLibraryExA(libraryName, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
    if (!opencl_lib_handle && GetLastError() == ERROR_INVALID_PARAMETER)
    {
        opencl_lib_handle = LoadLibraryExA("OpencL", NULL, 0);
    }
}
#else
static void extOpenOpenCL_impl() {
    opencl_lib_handle = dlopen("libOpenCL.so", RTLD_LAZY | RTLD_LOCAL | RTLD_DEEPBIND);
}
#endif

cl_int extOpenOpenCL() {
#ifdef _WIN32
    InitOnceExecuteOnce(&initialized, extOpenOpenCL_impl, NULL, NULL);
#else
    pthread_once(&initialized, extOpenOpenCL_impl);
#endif
    if (!opencl_lib_handle) {
        return CL_PLATFORM_NOT_FOUND_KHR;
    } else {
        return CL_SUCCESS;
    }
}

#endif /* OPENCL_LOAD */

#endif /* OPENCL_DLOPEN_lib_H */

//
// Copyright (c) 2024 The Khronos Group Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "CL/cl_ext.h"
#include <inttypes.h>
#include <stdio.h>

int extVersionMacro(void)
{
    // Test a non-provisional extension with non-placeholder semantic version.
    printf("Checking version macro for the cl_khr_integer_dot_product "
           "extension\n");

    cl_version ExtVersion = CL_KHR_INTEGER_DOT_PRODUCT_EXTENSION_VERSION;
    cl_version ExtMajorVersion = CL_VERSION_MAJOR(ExtVersion);
    cl_version ExtMinorVersion = CL_VERSION_MINOR(ExtVersion);
    cl_version ExtPatchVersion = CL_VERSION_PATCH(ExtVersion);

    printf("cl_khr_integer_dot_product version value %" PRIu32
           " which is semantic version %" PRIu32 ".%" PRIu32 ".%" PRIu32 "\n",
           ExtVersion, ExtMajorVersion, ExtMinorVersion, ExtPatchVersion);

    // Test vendor extension which uses default semantic version.
    printf("Checking version macro for the cl_APPLE_SetMemObjectDestructor\n");

    ExtVersion = CL_APPLE_SETMEMOBJECTDESTRUCTOR_EXTENSION_VERSION;
    ExtMajorVersion = CL_VERSION_MAJOR(ExtVersion);
    ExtMinorVersion = CL_VERSION_MINOR(ExtVersion);
    ExtPatchVersion = CL_VERSION_PATCH(ExtVersion);

    printf("cl_APPLE_SetMemObjectDestructor version value %" PRIu32
           " which is semantic version %" PRIu32 ".%" PRIu32 ".%" PRIu32 "\n",
           ExtVersion, ExtMajorVersion, ExtMinorVersion, ExtPatchVersion);

    return 0;
}

int main(void)
{
    int Result = extVersionMacro();

    return Result;
}

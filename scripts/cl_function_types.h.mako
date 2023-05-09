<%
# Gets C function parameter strings for the specified API params:
import sys
import json
def getCParameterStrings(params):
    strings = []
    if len(params) == 0:
        strings.append("void")
    else:
        for param in params:
            paramstr = param.Type + ' ' + param.Name + param.TypeEnd
            strings.append(paramstr)
    return strings

%>/*
 * Copyright (c) 2023 The Khronos Group Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * OpenCL is a trademark of Apple Inc. used under license by Khronos.
 */

#ifndef OPENCL_CL_FUNCTION_TYPES_H_
#define OPENCL_CL_FUNCTION_TYPES_H_

#include <CL/cl.h>

%for version, apis in coreapis.items():
%  if version != "CL_VERSION_1_0":
#ifdef ${version}

%  endif
%  for api in apis:
typedef ${api.RetType} CL_API_CALL ${api.Name}_t(
%    for i, paramStr in enumerate(getCParameterStrings(api.Params)):
%      if i < len(api.Params)-1:
    ${paramStr},
%      else:
    ${paramStr});
%      endif
%    endfor

typedef ${api.Name}_t *
${api.Name}_fn ${api.Suffix};

%  endfor
%  if version != "CL_VERSION_1_0":
#endif /* ${version} */

%  endif
%endfor
#endif /* OPENCL_CL_FUNCTION_TYPES_H_ */

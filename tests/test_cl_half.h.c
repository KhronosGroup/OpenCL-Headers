//
// Copyright (c) 2020 The Khronos Group Inc.
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

#include <math.h>
#include <stdio.h>

#include "CL/cl_half.h"

union FI {
  float f;
  uint32_t i;
};

int test_half_to_float(cl_half h, cl_float ref)
{
  cl_float f = cl_half_to_float(h);
  if (f != ref) {
    union FI f_i, ref_i;
    f_i.f = f;
    ref_i.f = ref;
    printf("\nERROR: converting 0x%04x to float: expected 0x%08x, got 0x%08x\n",
           h, ref_i.i, f_i.i);
    return 0;
  }
  return 1;
}

int test_half_from_float(cl_float f, cl_half ref,
                         cl_half_rounding_mode mode, const char *mode_str)
{
  cl_half h = cl_half_from_float(f, mode);
  if (h != ref) {
    union FI f_i;
    f_i.f = f;
    printf(
      "\nERROR: converting 0x%08x to half (%s): expected 0x%04x, got 0x%04x\n",
      f_i.i, mode_str, ref, h);
    return 0;
  }
  return 1;
}

int main(void)
{
  printf("\nChecking conversion routines in cl_half.h\n");

#define CHECK_TO_FLOAT(h, ref)                     \
  if (!test_half_to_float(h, ref)) {               \
    printf("Test failed on line %d.\n", __LINE__); \
    return 1;                                      \
  }

  // Check a handful of values
  CHECK_TO_FLOAT(0x0000, 0.f);
  CHECK_TO_FLOAT(0x3c00, 1.f);
  CHECK_TO_FLOAT(0xbc00, -1.f);
  CHECK_TO_FLOAT(0x7c00, INFINITY);
  CHECK_TO_FLOAT(0xfc00, -INFINITY);


#define CHECK_FROM_FLOAT(f, ref, mode)                         \
  if (!test_half_from_float(f, ref, CL_HALF_##mode, #mode)) {  \
    printf("Test failed on line %d.\n", __LINE__);             \
    return 1;                                                  \
  }

  // Check a handful of normal values
  CHECK_FROM_FLOAT(0.f, 0x0000, RTE);
  CHECK_FROM_FLOAT(1.f, 0x3c00, RTE);
  CHECK_FROM_FLOAT(-1.f, 0xbc00, RTE);
  CHECK_FROM_FLOAT(CL_HALF_MAX, 0x7bff, RTE);
  CHECK_FROM_FLOAT(CL_HALF_MIN, 0x0400, RTE);

  // Check huge positive (non-inf) values round properly
  CHECK_FROM_FLOAT(CL_HALF_MAX + 1000.f, 0x7c00, RTE);
  CHECK_FROM_FLOAT(CL_HALF_MAX + 1000.f, 0x7c00, RTP);
  CHECK_FROM_FLOAT(CL_HALF_MAX + 1000.f, 0x7bff, RTN);
  CHECK_FROM_FLOAT(CL_HALF_MAX + 1000.f, 0x7bff, RTZ);

  // Check huge negative (non-inf) values round properly
  CHECK_FROM_FLOAT(-(CL_HALF_MAX + 1000.f), 0xfc00, RTE);
  CHECK_FROM_FLOAT(-(CL_HALF_MAX + 1000.f), 0xfbff, RTP);
  CHECK_FROM_FLOAT(-(CL_HALF_MAX + 1000.f), 0xfc00, RTN);
  CHECK_FROM_FLOAT(-(CL_HALF_MAX + 1000.f), 0xfbff, RTZ);
#if 0 // Hexadecimal float constant is C++17
  // Check tiny positive values round properly
  CHECK_FROM_FLOAT(0x1.000000p-25, 0x0000, RTE);
  CHECK_FROM_FLOAT(0x1.000000p-25, 0x0001, RTP);
  CHECK_FROM_FLOAT(0x1.000000p-25, 0x0000, RTN);
  CHECK_FROM_FLOAT(0x1.000000p-25, 0x0000, RTZ);

  // Check tiny negative values round properly
  CHECK_FROM_FLOAT(-0x1.000000p-25, 0x8000, RTE);
  CHECK_FROM_FLOAT(-0x1.000000p-25, 0x8000, RTP);
  CHECK_FROM_FLOAT(-0x1.000000p-25, 0x8001, RTN);
  CHECK_FROM_FLOAT(-0x1.000000p-25, 0x8000, RTZ);
#else
  // Check tiny positive values round properly
  CHECK_FROM_FLOAT(2.98023223876953125e-08, 0x0000, RTE);
  CHECK_FROM_FLOAT(2.98023223876953125e-08, 0x0001, RTP);
  CHECK_FROM_FLOAT(2.98023223876953125e-08, 0x0000, RTN);
  CHECK_FROM_FLOAT(2.98023223876953125e-08, 0x0000, RTZ);

  // Check tiny negative values round properly
  CHECK_FROM_FLOAT(-2.98023223876953125e-08, 0x8000, RTE);
  CHECK_FROM_FLOAT(-2.98023223876953125e-08, 0x8000, RTP);
  CHECK_FROM_FLOAT(-2.98023223876953125e-08, 0x8001, RTN);
  CHECK_FROM_FLOAT(-2.98023223876953125e-08, 0x8000, RTZ);
#endif
  printf("\nAll tests passed!\n");

  return 0;
}

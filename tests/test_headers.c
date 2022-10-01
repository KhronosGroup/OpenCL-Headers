//
// Copyright (c) 2020-2022 The Khronos Group Inc.
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

/*
Some versions of inttypes.h required defining the macro __STDC_FORMAT_MACROS to
use the format macros for C++ compiles, but not all.  To improve robustness we
will use inttypes.h for C compiles and cinttypes for C++ compiles.
*/
#if defined(__cplusplus)
#include <cinttypes>
#else
#include <inttypes.h>
#endif

#include <stdio.h>

#include "CL/cl.h"

int test_char()
{
/* char */
    /* Constructor */
    cl_char a = 0;
    cl_char2 a2 = {{ 0, 1 }};
    cl_char4 a4 = {{ 0, 1, 2, 3 }};
    cl_char8 a8 = {{ 0, 1, 2, 3, 4, 5, 6, 7 }};
    cl_char16 a16 = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};

    /* assignment */
    cl_char    b = a;
    cl_char2   b2 = a2;
    cl_char4   b4 = a4;
    cl_char8   b8 = a8;
    cl_char16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %d\n", b );
    printf("b2:  %d %d \n", b2.s[0], b2.s[1] );
    printf("b4:  %d %d %d %d\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %d %d %d %d %d %d %d %d\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_CHAR2__ )
    __cl_char2 v2 = b2.v2;
    printf("__cl_char2:  %d %d \n", ((cl_char*)&v2)[0], ((cl_char*)&v2)[1] );
#else
    printf( "__cl_char2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_CHAR4__ )
    __cl_char4 v4 = b4.v4;
    printf("__cl_char4:  %d %d %d %d \n", ((cl_char*)&v4)[0], ((cl_char*)&v4)[1], ((cl_char*)&v4)[2], ((cl_char*)&v4)[3] );
#else
    printf( "__cl_char4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_CHAR8__ )
    __cl_char8 v8 = b8.v8;
    printf("__cl_char8:  %d %d %d %d %d %d %d %d \n", ((cl_char*)&v8)[0], ((cl_char*)&v8)[1], ((cl_char*)&v8)[2], ((cl_char*)&v8)[3], ((cl_char*)&v8)[4], ((cl_char*)&v8)[5], ((cl_char*)&v8)[6], ((cl_char*)&v8)[7] );
#else
    printf( "__cl_char8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_CHAR16__ )
    __cl_char16 v16 = b16.v16;
    printf("__cl_char16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", ((cl_char*)&v16)[0], ((cl_char*)&v16)[1], ((cl_char*)&v16)[2], ((cl_char*)&v16)[3], ((cl_char*)&v16)[4], ((cl_char*)&v16)[5], ((cl_char*)&v16)[6], ((cl_char*)&v16)[7],
                                                                      ((cl_char*)&v16)[8], ((cl_char*)&v16)[9], ((cl_char*)&v16)[10], ((cl_char*)&v16)[11], ((cl_char*)&v16)[12], ((cl_char*)&v16)[13], ((cl_char*)&v16)[14], ((cl_char*)&v16)[15]);
#else
    printf( "__cl_char16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int test_uchar()
{
/* uchar */
    /* Constructor */
    cl_uchar a = 0;
    cl_uchar2 a2 = {{ 0, 1 }};
    cl_uchar4 a4 = {{ 0, 1, 2, 3 }};
    cl_uchar8 a8 = {{ 0, 1, 2, 3, 4, 5, 6, 7 }};
    cl_uchar16 a16 = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};

    /* assignment */
    cl_uchar    b = a;
    cl_uchar2   b2 = a2;
    cl_uchar4   b4 = a4;
    cl_uchar8   b8 = a8;
    cl_uchar16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %d\n", b );
    printf("b2:  %d %d \n", b2.s[0], b2.s[1] );
    printf("b4:  %d %d %d %d\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %d %d %d %d %d %d %d %d\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_UCHAR2__ )
    __cl_uchar2 v2 = b2.v2;
    printf("__cl_uchar2:  %d %d \n", ((uchar*)&v2)[0], ((cl_uchar*)&v2)[1] );
#else
    printf( "__cl_uchar2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_UCHAR4__ )
    __cl_uchar4 v4 = b4.v4;
    printf("__cl_uchar4:  %d %d %d %d \n", ((uchar*)&v4)[0], ((cl_uchar*)&v4)[1], ((cl_uchar*)&v4)[2], ((cl_uchar*)&v4)[3] );
#else
    printf( "__cl_uchar4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_UCHAR8__ )
    __cl_uchar8 v8 = b8.v8;
    printf("__cl_uchar8:  %d %d %d %d %d %d %d %d \n", ((cl_uchar*)&v8)[0], ((cl_uchar*)&v8)[1], ((cl_uchar*)&v8)[2], ((cl_uchar*)&v8)[3], ((cl_uchar*)&v8)[4], ((cl_uchar*)&v8)[5], ((cl_uchar*)&v8)[6], ((cl_uchar*)&v8)[7] );
#else
    printf( "__cl_uchar8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_UCHAR16__ )
    __cl_uchar16 v16 = b16.v16;
    printf("__cl_uchar16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", ((cl_uchar*)&v16)[0], ((cl_uchar*)&v16)[1], ((cl_uchar*)&v16)[2], ((cl_uchar*)&v16)[3], ((cl_uchar*)&v16)[4], ((cl_uchar*)&v16)[5], ((cl_uchar*)&v16)[6], ((cl_uchar*)&v16)[7],
                                                                      ((cl_uchar*)&v16)[8], ((cl_uchar*)&v16)[9], ((cl_uchar*)&v16)[10], ((cl_uchar*)&v16)[11], ((cl_uchar*)&v16)[12], ((cl_uchar*)&v16)[13], ((cl_uchar*)&v16)[14], ((cl_uchar*)&v16)[15]);
#else
    printf( "__cl_uchar16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int test_short()
{
/* short */
    /* Constructor */
    cl_short a = 0;
    cl_short2 a2 = {{ 0, 1 }};
    cl_short4 a4 = {{ 0, 1, 2, 3 }};
    cl_short8 a8 = {{ 0, 1, 2, 3, 4, 5, 6, 7 }};
    cl_short16 a16 = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};

    /* assignment */
    cl_short    b = a;
    cl_short2   b2 = a2;
    cl_short4   b4 = a4;
    cl_short8   b8 = a8;
    cl_short16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %d\n", b );
    printf("b2:  %d %d \n", b2.s[0], b2.s[1] );
    printf("b4:  %d %d %d %d\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %d %d %d %d %d %d %d %d\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_SHORT2__ )
    __cl_short2 v2 = b2.v2;
    printf("__cl_short2:  %d %d \n", ((cl_short*)&v2)[0], ((cl_short*)&v2)[1] );
#else
    printf( "__cl_short2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_SHORT4__ )
    __cl_short4 v4 = b4.v4;
    printf("__cl_short4:  %d %d %d %d \n", ((cl_short*)&v4)[0], ((cl_short*)&v4)[1], ((cl_short*)&v4)[2], ((cl_short*)&v4)[3] );
#else
    printf( "__cl_short4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_SHORT8__ )
    __cl_short8 v8 = b8.v8;
    printf("__cl_short8:  %d %d %d %d %d %d %d %d \n", ((cl_short*)&v8)[0], ((cl_short*)&v8)[1], ((cl_short*)&v8)[2], ((cl_short*)&v8)[3], ((cl_short*)&v8)[4], ((cl_short*)&v8)[5], ((cl_short*)&v8)[6], ((cl_short*)&v8)[7] );
#else
    printf( "__cl_short8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_SHORT16__ )
    __cl_short16 v16 = b16.v16;
    printf("__cl_short16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", ((cl_short*)&v16)[0], ((cl_short*)&v16)[1], ((cl_short*)&v16)[2], ((cl_short*)&v16)[3], ((cl_short*)&v16)[4], ((cl_short*)&v16)[5], ((cl_short*)&v16)[6], ((cl_short*)&v16)[7],
                                                                      ((cl_short*)&v16)[8], ((cl_short*)&v16)[9], ((cl_short*)&v16)[10], ((cl_short*)&v16)[11], ((cl_short*)&v16)[12], ((cl_short*)&v16)[13], ((cl_short*)&v16)[14], ((cl_short*)&v16)[15]);
#else
    printf( "__cl_short16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int test_ushort()
{
/* ushort */
    /* Constructor */
    cl_ushort a = 0;
    cl_ushort2 a2 = {{ 0, 1 }};
    cl_ushort4 a4 = {{ 0, 1, 2, 3 }};
    cl_ushort8 a8 = {{ 0, 1, 2, 3, 4, 5, 6, 7 }};
    cl_ushort16 a16 = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};

    /* assignment */
    cl_ushort    b = a;
    cl_ushort2   b2 = a2;
    cl_ushort4   b4 = a4;
    cl_ushort8   b8 = a8;
    cl_ushort16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %d\n", b );
    printf("b2:  %d %d \n", b2.s[0], b2.s[1] );
    printf("b4:  %d %d %d %d\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %d %d %d %d %d %d %d %d\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_USHORT2__ )
    __cl_ushort2 v2 = b2.v2;
    printf("__cl_ushort2:  %d %d \n", ((unsigned short*)&v2)[0], ((unsigned short*)&v2)[1] );
#else
    printf( "__cl_ushort2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_USHORT4__ )
    __cl_ushort4 v4 = b4.v4;
    printf("__cl_ushort4:  %d %d %d %d \n", ((unsigned short*)&v4)[0], ((unsigned short*)&v4)[1], ((unsigned short*)&v4)[2], ((unsigned short*)&v4)[3] );
#else
    printf( "__cl_ushort4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_USHORT8__ )
    __cl_ushort8 v8 = b8.v8;
    printf("__cl_ushort8:  %d %d %d %d %d %d %d %d \n", ((unsigned short*)&v8)[0], ((unsigned short*)&v8)[1], ((unsigned short*)&v8)[2], ((unsigned short*)&v8)[3], ((unsigned short*)&v8)[4], ((unsigned short*)&v8)[5], ((unsigned short*)&v8)[6], ((unsigned short*)&v8)[7] );
#else
    printf( "__cl_ushort8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_USHORT16__ )
    __cl_ushort16 v16 = b16.v16;
    printf("__cl_ushort16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", ((unsigned short*)&v16)[0], ((unsigned short*)&v16)[1], ((unsigned short*)&v16)[2], ((unsigned short*)&v16)[3], ((unsigned short*)&v16)[4], ((unsigned short*)&v16)[5], ((unsigned short*)&v16)[6], ((unsigned short*)&v16)[7],
                                                                      ((unsigned short*)&v16)[8], ((unsigned short*)&v16)[9], ((unsigned short*)&v16)[10], ((unsigned short*)&v16)[11], ((unsigned short*)&v16)[12], ((unsigned short*)&v16)[13], ((unsigned short*)&v16)[14], ((unsigned short*)&v16)[15]);
#else
    printf( "__cl_ushort16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int test_int()
{
/* int */
    /* Constructor */
    cl_int a = 0;
    cl_int2 a2 = {{ 0, 1 }};
    cl_int4 a4 = {{ 0, 1, 2, 3 }};
    cl_int8 a8 = {{ 0, 1, 2, 3, 4, 5, 6, 7 }};
    cl_int16 a16 = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};

    /* assignment */
    cl_int    b = a;
    cl_int2   b2 = a2;
    cl_int4   b4 = a4;
    cl_int8   b8 = a8;
    cl_int16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %d\n", b );
    printf("b2:  %d %d \n", b2.s[0], b2.s[1] );
    printf("b4:  %d %d %d %d\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %d %d %d %d %d %d %d %d\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_INT2__ )
    __cl_int2 v2 = b2.v2;
    printf("__cl_int2:  %d %d \n", ((cl_int*)&v2)[0], ((cl_int*)&v2)[1] );
#else
    printf( "__cl_int2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_INT4__ )
    __cl_int4 v4 = b4.v4;
    printf("__cl_int4:  %d %d %d %d \n", ((cl_int*)&v4)[0], ((cl_int*)&v4)[1], ((cl_int*)&v4)[2], ((cl_int*)&v4)[3] );
#else
    printf( "__cl_int4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_INT8__ )
    __cl_int8 v8 = b8.v8;
    printf("__cl_int8:  %d %d %d %d %d %d %d %d \n", ((cl_int*)&v8)[0], ((cl_int*)&v8)[1], ((cl_int*)&v8)[2], ((cl_int*)&v8)[3], ((cl_int*)&v8)[4], ((cl_int*)&v8)[5], ((cl_int*)&v8)[6], ((cl_int*)&v8)[7] );
#else
    printf( "__cl_int8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_INT16__ )
    __cl_int16 v16 = b16.v16;
    printf("__cl_int16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", ((cl_int*)&v16)[0], ((cl_int*)&v16)[1], ((cl_int*)&v16)[2], ((cl_int*)&v16)[3], ((cl_int*)&v16)[4], ((cl_int*)&v16)[5], ((cl_int*)&v16)[6], ((cl_int*)&v16)[7],
                                                                      ((cl_int*)&v16)[8], ((cl_int*)&v16)[9], ((cl_int*)&v16)[10], ((cl_int*)&v16)[11], ((cl_int*)&v16)[12], ((cl_int*)&v16)[13], ((cl_int*)&v16)[14], ((cl_int*)&v16)[15]);
#else
    printf( "__cl_int16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int test_uint()
{
/* uint */
    /* Constructor */
    cl_uint a = 0;
    cl_uint2 a2 = {{ 0, 1 }};
    cl_uint4 a4 = {{ 0, 1, 2, 3 }};
    cl_uint8 a8 = {{ 0, 1, 2, 3, 4, 5, 6, 7 }};
    cl_uint16 a16 = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};

    /* assignment */
    cl_uint    b = a;
    cl_uint2   b2 = a2;
    cl_uint4   b4 = a4;
    cl_uint8   b8 = a8;
    cl_uint16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %d\n", b );
    printf("b2:  %d %d \n", b2.s[0], b2.s[1] );
    printf("b4:  %d %d %d %d\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %d %d %d %d %d %d %d %d\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_UINT2__ )
    __cl_uint2 v2 = b2.v2;
    printf("__cl_uint2:  %d %d \n", ((cl_uint*)&v2)[0], ((cl_uint*)&v2)[1] );
#else
    printf( "__cl_uint2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_UINT4__ )
    __cl_uint4 v4 = b4.v4;
    printf("__cl_uint4:  %d %d %d %d \n", ((cl_uint*)&v4)[0], ((cl_uint*)&v4)[1], ((cl_uint*)&v4)[2], ((cl_uint*)&v4)[3] );
#else
    printf( "__cl_uint4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_UINT8__ )
    __cl_uint8 v8 = b8.v8;
    printf("__cl_uint8:  %d %d %d %d %d %d %d %d \n", ((cl_uint*)&v8)[0], ((cl_uint*)&v8)[1], ((cl_uint*)&v8)[2], ((cl_uint*)&v8)[3], ((cl_uint*)&v8)[4], ((cl_uint*)&v8)[5], ((cl_uint*)&v8)[6], ((cl_uint*)&v8)[7] );
#else
    printf( "__cl_uint8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_UINT16__ )
    __cl_uint16 v16 = b16.v16;
    printf("__cl_uint16: %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", ((cl_uint*)&v16)[0], ((cl_uint*)&v16)[1], ((cl_uint*)&v16)[2], ((cl_uint*)&v16)[3], ((cl_uint*)&v16)[4], ((cl_uint*)&v16)[5], ((cl_uint*)&v16)[6], ((cl_uint*)&v16)[7],
                                                                      ((cl_uint*)&v16)[8], ((cl_uint*)&v16)[9], ((cl_uint*)&v16)[10], ((cl_uint*)&v16)[11], ((cl_uint*)&v16)[12], ((cl_uint*)&v16)[13], ((cl_uint*)&v16)[14], ((cl_uint*)&v16)[15]);
#else
    printf( "__cl_uint16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int test_long()
{
/* long */
    /* Constructor */
    cl_long a = 0;
    cl_long2 a2 = {{ 0, 1 }};
    cl_long4 a4 = {{ 0, 1, 2, 3 }};
    cl_long8 a8 = {{ 0, 1, 2, 3, 4, 5, 6, 7 }};
    cl_long16 a16 = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};

    /* assignment */
    cl_long    b = a;
    cl_long2   b2 = a2;
    cl_long4   b4 = a4;
    cl_long8   b8 = a8;
    cl_long16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %" PRId64 "\n", b );
    printf("b2:  %" PRId64 " %" PRId64 " \n", b2.s[0], b2.s[1] );
    printf("b4:  %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 "\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 "\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 "\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_LONG2__ )
    __cl_long2 v2 = b2.v2;
    printf("__cl_long2:  %" PRId64 " %" PRId64 " \n", ((cl_long*)&v2)[0], ((cl_long*)&v2)[1] );
#else
    printf( "__cl_long2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_LONG4__ )
    __cl_long4 v4 = b4.v4;
    printf("__cl_long4:  %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " \n", ((cl_long*)&v4)[0], ((cl_long*)&v4)[1], ((cl_long*)&v4)[2], ((cl_long*)&v4)[3] );
#else
    printf( "__cl_long4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_LONG8__ )
    __cl_long8 v8 = b8.v8;
    printf("__cl_long8:  %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " \n", ((cl_long*)&v8)[0], ((cl_long*)&v8)[1], ((cl_long*)&v8)[2], ((cl_long*)&v8)[3], ((cl_long*)&v8)[4], ((cl_long*)&v8)[5], ((cl_long*)&v8)[6], ((cl_long*)&v8)[7] );
#else
    printf( "__cl_long8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_LONG16__ )
    __cl_long16 v16 = b16.v16;
    printf("__cl_long16: %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " %" PRId64 " \n", ((cl_long*)&v16)[0], ((cl_long*)&v16)[1], ((cl_long*)&v16)[2], ((cl_long*)&v16)[3], ((cl_long*)&v16)[4], ((cl_long*)&v16)[5], ((cl_long*)&v16)[6], ((cl_long*)&v16)[7],
                                                                      ((cl_long*)&v16)[8], ((cl_long*)&v16)[9], ((cl_long*)&v16)[10], ((cl_long*)&v16)[11], ((cl_long*)&v16)[12], ((cl_long*)&v16)[13], ((cl_long*)&v16)[14], ((cl_long*)&v16)[15]);
#else
    printf( "__cl_long16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int test_ulong()
{
/* ulong */
    /* Constructor */
    cl_ulong a = 0;
    cl_ulong2 a2 = {{ 0, 1 }};
    cl_ulong4 a4 = {{ 0, 1, 2, 3 }};
    cl_ulong8 a8 = {{ 0, 1, 2, 3, 4, 5, 6, 7 }};
    cl_ulong16 a16 = {{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }};

    /* assignment */
    cl_ulong    b = a;
    cl_ulong2   b2 = a2;
    cl_ulong4   b4 = a4;
    cl_ulong8   b8 = a8;
    cl_ulong16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %" PRIu64 "\n", b );
    printf("b2:  %" PRIu64 " %" PRIu64 " \n", b2.s[0], b2.s[1] );
    printf("b4:  %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 "\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 "\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 "\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_ULONG2__ )
    __cl_ulong2 v2 = b2.v2;
    printf("__cl_ulong2:  %" PRIu64 " %" PRIu64 " \n", ((cl_ulong*)&v2)[0], ((cl_ulong*)&v2)[1] );
#else
    printf( "__cl_ulong2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_ULONG4__ )
    __cl_ulong4 v4 = b4.v4;
    printf("__cl_ulong4:  %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " \n", ((cl_ulong*)&v4)[0], ((cl_ulong*)&v4)[1], ((cl_ulong*)&v4)[2], ((cl_ulong*)&v4)[3] );
#else
    printf( "__cl_ulong4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_ULONG8__ )
    __cl_ulong8 v8 = b8.v8;
    printf("__cl_ulong8:  %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " \n", ((cl_ulong*)&v8)[0], ((cl_ulong*)&v8)[1], ((cl_ulong*)&v8)[2], ((cl_ulong*)&v8)[3], ((cl_ulong*)&v8)[4], ((cl_ulong*)&v8)[5], ((cl_ulong*)&v8)[6], ((cl_ulong*)&v8)[7] );
#else
    printf( "__cl_ulong8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_ULONG16__ )
    __cl_ulong16 v16 = b16.v16;
    printf("__cl_ulong16: %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " %" PRIu64 " \n", ((cl_ulong*)&v16)[0], ((cl_ulong*)&v16)[1], ((cl_ulong*)&v16)[2], ((cl_ulong*)&v16)[3], ((cl_ulong*)&v16)[4], ((cl_ulong*)&v16)[5], ((cl_ulong*)&v16)[6], ((cl_ulong*)&v16)[7],
                                                                      ((cl_ulong*)&v16)[8], ((cl_ulong*)&v16)[9], ((cl_ulong*)&v16)[10], ((cl_ulong*)&v16)[11], ((cl_ulong*)&v16)[12], ((cl_ulong*)&v16)[13], ((cl_ulong*)&v16)[14], ((cl_ulong*)&v16)[15]);
#else
    printf( "__cl_ulong16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int test_float()
{
/* float */
    /* Constructor */
    cl_float a = 0.0f;
    cl_float2 a2 = {{ 0.0f, 1.0f }};
    cl_float4 a4 = {{ 0.0f, 1.0f, 2.0f, 3.0f }};
    cl_float8 a8 = {{ 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f }};
    cl_float16 a16 = {{ 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f }};

    /* assignment */
    cl_float    b = a;
    cl_float2   b2 = a2;
    cl_float4   b4 = a4;
    cl_float8   b8 = a8;
    cl_float16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %f\n", b );
    printf("b2:  %f %f \n", b2.s[0], b2.s[1] );
    printf("b4:  %f %f %f %f\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %f %f %f %f %f %f %f %f\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_FLOAT2__ )
    __cl_float2 v2 = b2.v2;
    printf("__cl_float2:  %f %f \n", ((cl_float*)&v2)[0], ((cl_float*)&v2)[1] );
#else
    printf( "__cl_float2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_FLOAT4__ )
    {
        __cl_float4 v4 = b4.v4;
        printf("__cl_float4:  %f %f %f %f \n", ((cl_float*)&v4)[0], ((cl_float*)&v4)[1], ((cl_float*)&v4)[2], ((cl_float*)&v4)[3] );
    }
#else
    printf( "__cl_float4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_FLOAT8__ )
    __cl_float8 v8 = b8.v8;
    printf("__cl_float8:  %f %f %f %f %f %f %f %f \n", ((cl_float*)&v8)[0], ((cl_float*)&v8)[1], ((cl_float*)&v8)[2], ((cl_float*)&v8)[3], ((cl_float*)&v8)[4], ((cl_float*)&v8)[5], ((cl_float*)&v8)[6], ((cl_float*)&v8)[7] );
#else
    printf( "__cl_float8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_FLOAT16__ )
    __cl_float16 v16 = b16.v16;
    printf("__cl_float16: %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f \n", ((cl_float*)&v16)[0], ((cl_float*)&v16)[1], ((cl_float*)&v16)[2], ((cl_float*)&v16)[3], ((cl_float*)&v16)[4], ((cl_float*)&v16)[5], ((cl_float*)&v16)[6], ((cl_float*)&v16)[7],
                                                                      ((cl_float*)&v16)[8], ((cl_float*)&v16)[9], ((cl_float*)&v16)[10], ((cl_float*)&v16)[11], ((cl_float*)&v16)[12], ((cl_float*)&v16)[13], ((cl_float*)&v16)[14], ((cl_float*)&v16)[15]);
#else
    printf( "__cl_float16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int test_double()
{
/* double */
    /* Constructor */
    cl_double a = 0.0f;
    cl_double2 a2 = {{ 0.0f, 1.0f }};
    cl_double4 a4 = {{ 0.0f, 1.0f, 2.0f, 3.0f }};
    cl_double8 a8 = {{ 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f }};
    cl_double16 a16 = {{ 0.0f, 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f }};

    /* assignment */
    cl_double    b = a;
    cl_double2   b2 = a2;
    cl_double4   b4 = a4;
    cl_double8   b8 = a8;
    cl_double16  b16 = a16;

    printf("\nVerifying assignment:\n" );
    printf("b:   %f\n", b );
    printf("b2:  %f %f \n", b2.s[0], b2.s[1] );
    printf("b4:  %f %f %f %f\n", b4.s[0], b4.s[1], b4.s[2], b4.s[3] );
    printf("b8:  %f %f %f %f %f %f %f %f\n", b8.s[0], b8.s[1], b8.s[2], b8.s[3], b8.s[4], b8.s[5], b8.s[6], b8.s[7] );
    printf("b16: %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f\n", b16.s[0], b16.s[1], b16.s[2], b16.s[3], b16.s[4], b16.s[5], b16.s[6], b16.s[7],
                                                                     b16.s[8], b16.s[9], b16.s[10], b16.s[11], b16.s[12], b16.s[13], b16.s[14], b16.s[15]);

    /* vector access */
    printf("\nVerifying vector access:\n" );
#if defined( __CL_DOUBLE2__ )
    __cl_double2 v2 = b2.v2;
    printf("__cl_double2:  %f %f \n", ((cl_double*)&v2)[0], ((cl_double*)&v2)[1] );
#else
    printf( "__cl_double2 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_DOUBLE4__ )
    __cl_double4 v4 = b4.v4;
    printf("__cl_double4:  %f %f %f %f \n", ((cl_double*)&v4)[0], ((cl_double*)&v4)[1], ((cl_double*)&v4)[2], ((cl_double*)&v4)[3] );
#else
    printf( "__cl_double4 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_DOUBLE8__ )
    __cl_double8 v8 = b8.v8;
    printf("__cl_double8:  %f %f %f %f %f %f %f %f \n", ((cl_double*)&v8)[0], ((cl_double*)&v8)[1], ((cl_double*)&v8)[2], ((cl_double*)&v8)[3], ((cl_double*)&v8)[4], ((cl_double*)&v8)[5], ((cl_double*)&v8)[6], ((cl_double*)&v8)[7] );
#else
    printf( "__cl_double8 SIMD vectors not supported on this architecture.\n" );
#endif

#if defined( __CL_DOUBLE16__ )
    __cl_double16 v16 = b16.v16;
    printf("__cl_double16: %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f %f \n", ((cl_double*)&v16)[0], ((cl_double*)&v16)[1], ((cl_double*)&v16)[2], ((cl_double*)&v16)[3], ((cl_double*)&v16)[4], ((cl_double*)&v16)[5], ((cl_double*)&v16)[6], ((cl_double*)&v16)[7],
                                                                      ((cl_double*)&v16)[8], ((cl_double*)&v16)[9], ((cl_double*)&v16)[10], ((cl_double*)&v16)[11], ((cl_double*)&v16)[12], ((cl_double*)&v16)[13], ((cl_double*)&v16)[14], ((cl_double*)&v16)[15]);
#else
    printf( "__cl_double16 SIMD vectors not supported on this architecture.\n" );
#endif

    printf( "\n" );
    return 0;
}

int main(void)
{
  printf( "\nChecking operations on cl_types.\nNumbers, where presented, should walk upward from 0, with step of 1:\n" );

  test_char();
  test_uchar();
  test_short();
  test_ushort();
  test_long();
  test_ulong();
  test_float();
  test_double();

  return 0;
}

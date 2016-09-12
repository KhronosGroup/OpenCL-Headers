/*******************************************************************************
 * Copyright (c) 2008-2016 The Khronos Group Inc.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and/or associated documentation files (the
 * "Materials"), to deal in the Materials without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Materials, and to
 * permit persons to whom the Materials are furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Materials.
 *
 * MODIFICATIONS TO THIS FILE MAY MEAN IT NO LONGER ACCURATELY REFLECTS
 * KHRONOS STANDARDS. THE UNMODIFIED, NORMATIVE VERSIONS OF KHRONOS
 * SPECIFICATIONS AND HEADER INFORMATION ARE LOCATED AT
 *    https://www.khronos.org/registry/
 *
 * THE MATERIALS ARE PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * MATERIALS OR THE USE OR OTHER DEALINGS IN THE MATERIALS.
 ******************************************************************************/
/*****************************************************************************\

Copyright (c) 2013-2016 Intel Corporation All Rights Reserved.

THESE MATERIALS ARE PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL INTEL OR ITS
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THESE
MATERIALS, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

File Name: cl_ext_intel.h

Abstract:

Notes:

\*****************************************************************************/

#ifndef __CL_EXT_INTEL_H
#define __CL_EXT_INTEL_H

#ifdef __APPLE__
    #include <OpenCL/cl.h>
    #include <OpenCL/cl_platform.h>
#else
    #include <CL/cl.h>
    #include <CL/cl_platform.h>
#endif

#ifdef __cplusplus
extern "C" {
#endif

/***************************************
* cl_intel_thread_local_exec extension *
****************************************/

#define cl_intel_thread_local_exec 1

#define CL_QUEUE_THREAD_LOCAL_EXEC_ENABLE_INTEL      (((cl_bitfield)1) << 31)

/***********************************************
* cl_intel_device_partition_by_names extension *
************************************************/

#define cl_intel_device_partition_by_names 1

#define CL_DEVICE_PARTITION_BY_NAMES_INTEL          0x4052
#define CL_PARTITION_BY_NAMES_LIST_END_INTEL        -1

/************************************************
* cl_intel_accelerator extension                *
* cl_intel_motion_estimation extension          *
* cl_intel_advanced_motion_estimation extension *
*************************************************/

#define cl_intel_accelerator 1
#define cl_intel_motion_estimation 1
#define cl_intel_advanced_motion_estimation 1

typedef struct _cl_accelerator_intel* cl_accelerator_intel;
typedef cl_uint cl_accelerator_type_intel;
typedef cl_uint cl_accelerator_info_intel;

typedef struct _cl_motion_estimation_desc_intel {
    cl_uint mb_block_type;
    cl_uint subpixel_mode;
    cl_uint sad_adjust_mode;
    cl_uint search_path_type;
} cl_motion_estimation_desc_intel;

/* error codes */
#define CL_INVALID_ACCELERATOR_INTEL                              -1094
#define CL_INVALID_ACCELERATOR_TYPE_INTEL                         -1095
#define CL_INVALID_ACCELERATOR_DESCRIPTOR_INTEL                   -1096
#define CL_ACCELERATOR_TYPE_NOT_SUPPORTED_INTEL                   -1097

/* cl_accelerator_type_intel */
#define CL_ACCELERATOR_TYPE_MOTION_ESTIMATION_INTEL               0x0

/* cl_accelerator_info_intel */
#define CL_ACCELERATOR_DESCRIPTOR_INTEL                           0x4090
#define CL_ACCELERATOR_REFERENCE_COUNT_INTEL                      0x4091
#define CL_ACCELERATOR_CONTEXT_INTEL                              0x4092
#define CL_ACCELERATOR_TYPE_INTEL                                 0x4093

/* cl_motion_detect_desc_intel flags */
#define CL_ME_MB_TYPE_16x16_INTEL                                 0x0
#define CL_ME_MB_TYPE_8x8_INTEL                                   0x1
#define CL_ME_MB_TYPE_4x4_INTEL                                   0x2

#define CL_ME_SUBPIXEL_MODE_INTEGER_INTEL                         0x0
#define CL_ME_SUBPIXEL_MODE_HPEL_INTEL                            0x1
#define CL_ME_SUBPIXEL_MODE_QPEL_INTEL                            0x2

#define CL_ME_SAD_ADJUST_MODE_NONE_INTEL                          0x0
#define CL_ME_SAD_ADJUST_MODE_HAAR_INTEL                          0x1

#define CL_ME_SEARCH_PATH_RADIUS_2_2_INTEL                        0x0
#define CL_ME_SEARCH_PATH_RADIUS_4_4_INTEL                        0x1
#define CL_ME_SEARCH_PATH_RADIUS_16_12_INTEL                      0x5

#define CL_ME_SKIP_BLOCK_TYPE_16x16_INTEL                         0x0
#define CL_ME_CHROMA_INTRA_PREDICT_ENABLED_INTEL                  0x1
#define CL_ME_LUMA_INTRA_PREDICT_ENABLED_INTEL                    0x2
#define CL_ME_SKIP_BLOCK_TYPE_8x8_INTEL                           0x4

#define CL_ME_FORWARD_INPUT_MODE_INTEL                            0x1
#define CL_ME_BACKWARD_INPUT_MODE_INTEL                           0x2
#define CL_ME_BIDIRECTION_INPUT_MODE_INTEL                        0x3

#define CL_ME_BIDIR_WEIGHT_QUARTER_INTEL                          16
#define CL_ME_BIDIR_WEIGHT_THIRD_INTEL                            21
#define CL_ME_BIDIR_WEIGHT_HALF_INTEL                             32
#define CL_ME_BIDIR_WEIGHT_TWO_THIRD_INTEL                        43
#define CL_ME_BIDIR_WEIGHT_THREE_QUARTER_INTEL                    48

#define CL_ME_COST_PENALTY_NONE_INTEL                             0x0
#define CL_ME_COST_PENALTY_LOW_INTEL                              0x1
#define CL_ME_COST_PENALTY_NORMAL_INTEL                           0x2
#define CL_ME_COST_PENALTY_HIGH_INTEL                             0x3

#define CL_ME_COST_PRECISION_QPEL_INTEL                           0x0
#define CL_ME_COST_PRECISION_HPEL_INTEL                           0x1
#define CL_ME_COST_PRECISION_PEL_INTEL                            0x2
#define CL_ME_COST_PRECISION_DPEL_INTEL                           0x3

#define CL_ME_LUMA_PREDICTOR_MODE_VERTICAL_INTEL                  0x0
#define CL_ME_LUMA_PREDICTOR_MODE_HORIZONTAL_INTEL                0x1
#define CL_ME_LUMA_PREDICTOR_MODE_DC_INTEL                        0x2
#define CL_ME_LUMA_PREDICTOR_MODE_DIAGONAL_DOWN_LEFT_INTEL        0x3

#define CL_ME_LUMA_PREDICTOR_MODE_DIAGONAL_DOWN_RIGHT_INTEL       0x4
#define CL_ME_LUMA_PREDICTOR_MODE_PLANE_INTEL                     0x4
#define CL_ME_LUMA_PREDICTOR_MODE_VERTICAL_RIGHT_INTEL            0x5
#define CL_ME_LUMA_PREDICTOR_MODE_HORIZONTAL_DOWN_INTEL           0x6
#define CL_ME_LUMA_PREDICTOR_MODE_VERTICAL_LEFT_INTEL             0x7
#define CL_ME_LUMA_PREDICTOR_MODE_HORIZONTAL_UP_INTEL             0x8

#define CL_ME_CHROMA_PREDICTOR_MODE_DC_INTEL                      0x0
#define CL_ME_CHROMA_PREDICTOR_MODE_HORIZONTAL_INTEL              0x1
#define CL_ME_CHROMA_PREDICTOR_MODE_VERTICAL_INTEL                0x2
#define CL_ME_CHROMA_PREDICTOR_MODE_PLANE_INTEL                   0x3

/* cl_device_info */
#define CL_DEVICE_ME_VERSION_INTEL                                0x407E

#define CL_ME_VERSION_LEGACY_INTEL                                0x0
#define CL_ME_VERSION_ADVANCED_VER_1_INTEL                        0x1
#define CL_ME_VERSION_ADVANCED_VER_2_INTEL                        0x2

extern CL_API_ENTRY cl_accelerator_intel CL_API_CALL
clCreateAcceleratorINTEL(
    cl_context                  /* context */,
    cl_accelerator_type_intel   /* accelerator_type */,
    size_t                      /* descriptor_size */,
    const void*                 /* descriptor */,
    cl_int*                     /* errcode_ret */) CL_EXT_SUFFIX__VERSION_1_2;

typedef CL_API_ENTRY cl_accelerator_intel (CL_API_CALL *clCreateAcceleratorINTEL_fn)(
    cl_context                  /* context */,
    cl_accelerator_type_intel   /* accelerator_type */,
    size_t                      /* descriptor_size */,
    const void*                 /* descriptor */,
    cl_int*                     /* errcode_ret */) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clGetAcceleratorInfoINTEL(
    cl_accelerator_intel        /* accelerator */,
    cl_accelerator_info_intel   /* param_name */,
    size_t                      /* param_value_size */,
    void*                       /* param_value */,
    size_t*                     /* param_value_size_ret */) CL_EXT_SUFFIX__VERSION_1_2;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clGetAcceleratorInfoINTEL_fn)(
    cl_accelerator_intel        /* accelerator */,
    cl_accelerator_info_intel   /* param_name */,
    size_t                      /* param_value_size */,
    void*                       /* param_value */,
    size_t*                     /* param_value_size_ret */) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clRetainAcceleratorINTEL(
    cl_accelerator_intel        /* accelerator */) CL_EXT_SUFFIX__VERSION_1_2;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clRetainAcceleratorINTEL_fn)(
    cl_accelerator_intel        /* accelerator */) CL_EXT_SUFFIX__VERSION_1_2;

extern CL_API_ENTRY cl_int CL_API_CALL
clReleaseAcceleratorINTEL(
    cl_accelerator_intel        /* accelerator */) CL_EXT_SUFFIX__VERSION_1_2;

typedef CL_API_ENTRY cl_int (CL_API_CALL *clReleaseAcceleratorINTEL_fn)(
    cl_accelerator_intel        /* accelerator */) CL_EXT_SUFFIX__VERSION_1_2;

/******************************************
* cl_intel_simultaneous_sharing extension *
*******************************************/

#define cl_intel_simultaneous_sharing 1

#define CL_DEVICE_SIMULTANEOUS_INTEROPS_INTEL            0x4104
#define CL_DEVICE_NUM_SIMULTANEOUS_INTEROPS_INTEL        0x4105

/***********************************
* cl_intel_egl_image_yuv extension *
************************************/

#define cl_intel_egl_image_yuv 1

#define CL_EGL_YUV_PLANE_INTEL                           0x4107

/********************************
* cl_intel_packed_yuv extension *
*********************************/

#define cl_intel_packed_yuv 1

#define CL_YUYV_INTEL                                    0x4076
#define CL_UYVY_INTEL                                    0x4077
#define CL_YVYU_INTEL                                    0x4078
#define CL_VYUY_INTEL                                    0x4079

/********************************************
* cl_intel_required_subgroup_size extension *
*********************************************/

#define cl_intel_required_subgroup_size 1

#define CL_DEVICE_SUB_GROUP_SIZES_INTEL                  0x4108
#define CL_KERNEL_SPILL_MEM_SIZE_INTEL                   0x4109
#define CL_KERNEL_COMPILE_SUB_GROUP_SIZE_INTEL           0x410A

/****************************************
* cl_intel_driver_diagnostics extension *
*****************************************/

#define cl_intel_driver_diagnostics 1

typedef cl_uint cl_diagnostics_verbose_level;

#define CL_CONTEXT_SHOW_DIAGNOSTICS_INTEL                0x4106

#define CL_CONTEXT_DIAGNOSTICS_LEVEL_ALL_INTEL           ( 0xff )
#define CL_CONTEXT_DIAGNOSTICS_LEVEL_GOOD_INTEL          ( 1 )
#define CL_CONTEXT_DIAGNOSTICS_LEVEL_BAD_INTEL           ( 1 << 1 )
#define CL_CONTEXT_DIAGNOSTICS_LEVEL_NEUTRAL_INTEL       ( 1 << 2 )

#ifdef __cplusplus
}
#endif

#endif /* __CL_EXT_INTEL_H */

/*******************************************************************************
 * Copyright (c) 2019 The Khronos Group Inc.
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

/**
 * This is a header-only utility library that provides OpenCL host code with
 * routines for converting to/from cl_half values.
 *
 * Example usage:
 *
 *    #include <CL/cl_half.h>
 *    ...
 *    cl_half h = cl_float_to_half(0.5f, CL_HALF_RTE);
 *    cl_float f = cl_half_to_float(h);
 */

#ifndef __CL_HALF_H
#define __CL_HALF_H

#include <CL/cl_platform.h>

#ifdef __cplusplus
extern "C" {
#endif


/**
 * Rounding mode used when converting to cl_half.
 */
typedef enum
{
  CL_HALF_RTE, // round to nearest even
  CL_HALF_RTZ, // round towards zero
  CL_HALF_RTP, // round towards positive infinity
  CL_HALF_RTN, // round towards negative infinity
} cl_half_rounding_mode;

/**
 * Convert a cl_float to a cl_half.
 */
static inline cl_half cl_float_to_half(cl_float f, cl_half_rounding_mode rounding_mode)
{
  // Type-punning to get direct access to underlying bits
  union
  {
    cl_float f;
    uint32_t i;
  } f32;
  f32.f = f;

  // Extract sign bit
  uint16_t sign = f32.i >> 31;

  // Extract FP32 exponent and mantissa
  uint32_t f_exp = (f32.i >> (CL_FLT_MANT_DIG - 1)) & 0xFF;
  uint32_t f_mant = f32.i & ((1 << (CL_FLT_MANT_DIG - 1)) - 1);

  // Remove FP32 exponent bias
  int32_t exp = f_exp - CL_FLT_MAX_EXP + 1;

  // Add FP16 exponent bias
  uint16_t h_exp = exp + CL_HALF_MAX_EXP - 1;

  // Check for NaN / infinity
  if (f_exp == 0xFF)
  {
    if (f_mant)
    {
      // NaN -> propagate mantissa and silence it
      uint16_t h_mant = f_mant >> (CL_FLT_MANT_DIG - CL_HALF_MANT_DIG);
      h_mant |= 0x200;
      return (sign << 15) | 0x7C00 | h_mant;
    }
    else
    {
      // Infinity -> zero mantissa
      return (sign << 15) | 0x7C00;
    }
  }

  // Check for overflow
  if (exp >= CL_HALF_MAX_EXP)
  {
    if (rounding_mode == CL_HALF_RTZ)
    {
      // Round overflow towards zero -> largest positive value
      return (sign << 15) | 0x7BFF;
    }
    else if (rounding_mode == CL_HALF_RTP && sign)
    {
      // Round overflow towards positive infinity -> largest positive value
      return (sign << 15) | 0x7BFF;
    }
    else if (rounding_mode == CL_HALF_RTN && !sign)
    {
      // Round overflow towards negative infinity -> smallest negative value
      return (sign << 15) | 0x7BFF;
    }
    else
    {
      // Overflow to infinity
      return (sign << 15) | 0x7C00;
    }
  }

  // Check for underflow
  if (exp < (CL_HALF_MIN_EXP - CL_HALF_MANT_DIG - 1))
  {
    if (rounding_mode == CL_HALF_RTP && !sign && (f_exp || f_mant))
    {
      // Round underflow towards positive infinity -> smallest positive value
      return (sign << 15) | 1;
    }
    else if (rounding_mode == CL_HALF_RTN && sign && (f_exp || f_mant))
    {
      // Round underflow towards negative infinity -> largest negative value
      return (sign << 15) | 1;
    }
    else
    {
      // Flush to zero
      return (sign << 15);
    }
  }

  // Position of the bit that will become the FP16 mantissa LSB
  uint32_t lsb_pos;

  if (exp < -14)
  {
    // Denormal -> include the implicit 1 from the FP32 mantissa
    h_exp = 0;
    f_mant |= 1 << (CL_FLT_MANT_DIG - 1);

    // Mantissa shift amount depends on exponent
    lsb_pos = -exp + (CL_FLT_MANT_DIG - 25);
  }
  else
  {
    // Normal -> just truncate mantissa
    lsb_pos = CL_FLT_MANT_DIG - CL_HALF_MANT_DIG;
  }

  // Generate FP16 mantissa by shifting FP32 mantissa
  uint16_t h_mant = f_mant >> lsb_pos;

  // Check whether we need to round
  uint32_t halfway = 1 << (lsb_pos - 1);
  uint32_t mask = (halfway << 1) - 1;
  switch (rounding_mode)
  {
    case CL_HALF_RTE:
      if ((f_mant & mask) > halfway)
      {
        // More than halfway -> round up
        h_mant += 1;
      }
      else if ((f_mant & mask) == halfway)
      {
        // Exactly halfway -> round to nearest even
        if (h_mant & 0x1)
          h_mant += 1;
      }
      break;
    case CL_HALF_RTZ:
      // Mantissa has already been truncated -> do nothing
      break;
    case CL_HALF_RTP:
      if ((f_mant & mask) && !sign)
      {
        // Round positive numbers up
        h_mant += 1;
      }
      break;
    case CL_HALF_RTN:
      if ((f_mant & mask) && sign)
      {
        // Round negative numbers down
        h_mant += 1;
      }
      break;
  }

  // Check for mantissa overflow
  if (h_mant & 0x400)
  {
    h_exp += 1;
    h_mant = 0;
  }

  return (sign << 15) | (h_exp << 10) | h_mant;
}


/**
 * Convert a cl_double to a cl_half.
 */
static inline cl_half cl_double_to_half(cl_double d, cl_half_rounding_mode rounding_mode)
{
  // Type-punning to get direct access to underlying bits
  union
  {
    cl_double d;
    uint64_t i;
  } f64;
  f64.d = d;

  // Extract sign bit
  uint16_t sign = f64.i >> 63;

  // Extract FP64 exponent and mantissa
  uint64_t d_exp = (f64.i >> (CL_DBL_MANT_DIG - 1)) & 0x7FF;
  uint64_t d_mant = f64.i & ((1ul << (CL_DBL_MANT_DIG - 1)) - 1);

  // Remove FP64 exponent bias
  int64_t exp = d_exp - CL_DBL_MAX_EXP + 1;

  // Add FP16 exponent bias
  uint16_t h_exp = exp + CL_HALF_MAX_EXP - 1;

  // Check for NaN / infinity
  if (d_exp == 0x7FF)
  {
    if (d_mant)
    {
      // NaN -> propagate mantissa and silence it
      uint16_t h_mant = d_mant >> (CL_DBL_MANT_DIG - CL_HALF_MANT_DIG);
      h_mant |= 0x200;
      return (sign << 15) | 0x7C00 | h_mant;
    }
    else
    {
      // Infinity -> zero mantissa
      return (sign << 15) | 0x7C00;
    }
  }

  // Check for overflow
  if (exp >= CL_HALF_MAX_EXP)
  {
    if (rounding_mode == CL_HALF_RTZ)
    {
      // Round overflow towards zero -> largest positive value
      return (sign << 15) | 0x7BFF;
    }
    else if (rounding_mode == CL_HALF_RTP && sign)
    {
      // Round overflow towards positive infinity -> largest positive value
      return (sign << 15) | 0x7BFF;
    }
    else if (rounding_mode == CL_HALF_RTN && !sign)
    {
      // Round overflow towards negative infinity -> smallest negative value
      return (sign << 15) | 0x7BFF;
    }
    else
    {
      // Overflow to infinity
      return (sign << 15) | 0x7C00;
    }
  }

  // Check for underflow
  if (exp < (CL_HALF_MIN_EXP - CL_HALF_MANT_DIG - 1))
  {
    if (rounding_mode == CL_HALF_RTP && !sign && (d_exp || d_mant))
    {
      // Round underflow towards positive infinity -> smallest positive value
      return (sign << 15) | 1;
    }
    else if (rounding_mode == CL_HALF_RTN && sign && (d_exp || d_mant))
    {
      // Round underflow towards negative infinity -> largest negative value
      return (sign << 15) | 1;
    }
    else
    {
      // Flush to zero
      return (sign << 15);
    }
  }

  // Position of the bit that will become the FP16 mantissa LSB
  uint32_t lsb_pos;

  if (exp < -14)
  {
    // Denormal -> include the implicit 1 from the FP64 mantissa
    h_exp = 0;
    d_mant |= 1ul << (CL_DBL_MANT_DIG - 1);

    // Mantissa shift amount depends on exponent
    lsb_pos = -exp + (CL_DBL_MANT_DIG - 25);
  }
  else
  {
    // Normal -> just truncate mantissa
    lsb_pos = CL_DBL_MANT_DIG - CL_HALF_MANT_DIG;
  }

  // Generate FP16 mantissa by shifting FP64 mantissa
  uint16_t h_mant = d_mant >> lsb_pos;

  // Check whether we need to round
  uint64_t halfway = 1ul << (lsb_pos - 1);
  uint64_t mask = (halfway << 1) - 1;
  switch (rounding_mode)
  {
    case CL_HALF_RTE:
      if ((d_mant & mask) > halfway)
      {
        // More than halfway -> round up
        h_mant += 1;
      }
      else if ((d_mant & mask) == halfway)
      {
        // Exactly halfway -> round to nearest even
        if (h_mant & 0x1)
          h_mant += 1;
      }
      break;
    case CL_HALF_RTZ:
      // Mantissa has already been truncated -> do nothing
      break;
    case CL_HALF_RTP:
      if ((d_mant & mask) && !sign)
      {
        // Round positive numbers up
        h_mant += 1;
      }
      break;
    case CL_HALF_RTN:
      if ((d_mant & mask) && sign)
      {
        // Round negative numbers down
        h_mant += 1;
      }
      break;
  }

  // Check for mantissa overflow
  if (h_mant & 0x400)
  {
    h_exp += 1;
    h_mant = 0;
  }

  return (sign << 15) | (h_exp << 10) | h_mant;
}


/**
 * Convert a cl_half to a cl_float.
 */
static inline cl_float cl_half_to_float(cl_half h)
{
  // Type-punning to get direct access to underlying bits
  union
  {
    cl_float f;
    uint32_t i;
  } f32;

  // Extract sign bit
  uint16_t sign = h >> 15;

  // Extract FP16 exponent and mantissa
  uint16_t h_exp = (h >> (CL_HALF_MANT_DIG - 1)) & 0x1F;
  uint16_t h_mant = h & 0x3FF;

  // Remove FP16 exponent bias
  int32_t exp = h_exp - CL_HALF_MAX_EXP + 1;

  // Add FP32 exponent bias
  uint32_t f_exp = exp + CL_FLT_MAX_EXP - 1;

  // Check for NaN / infinity
  if (h_exp == 0x1F)
  {
    if (h_mant)
    {
      // NaN -> propagate mantissa and silence it
      uint32_t f_mant = h_mant << (CL_FLT_MANT_DIG - CL_HALF_MANT_DIG);
      f_mant |= 0x400000;
      f32.i = (sign << 31) | 0x7F800000 | f_mant;
      return f32.f;
    }
    else
    {
      // Infinity -> zero mantissa
      f32.i = (sign << 31) | 0x7F800000;
      return f32.f;
    }
  }

  // Check for zero / denormal
  if (h_exp == 0)
  {
    if (h_mant == 0)
    {
      // Zero -> zero exponent
      f_exp = 0;
    }
    else
    {
      // Denormal -> normalize it
      // - Shift mantissa to make most-significant 1 implicit
      // - Adjust exponent accordingly
      uint32_t shift = 0;
      while ((h_mant & 0x400) == 0)
      {
        h_mant <<= 1;
        shift++;
      }
      h_mant &= 0x3FF;
      f_exp -= shift - 1;
    }
  }

  f32.i = (sign << 31) | (f_exp << 23) | (h_mant << 13);
  return f32.f;
}


#ifdef __cplusplus
}
#endif


#endif  /* __CL_HALF_H */

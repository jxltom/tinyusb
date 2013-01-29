/*
 * common.h
 *
 *  Created on: Nov 26, 2012
 *      Author: hathach
 */

/*
 * Software License Agreement (BSD License)
 * Copyright (c) 2013, hathach (tinyusb.net)
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 *
 * This file is part of the tinyUSB stack.
 */

/** \file
 *  \brief Common Header File
 *
 *  \note TBD
 */

/** \defgroup Group_Common Common Files
 * @{
 *
 *  \defgroup Group_CommonH common.h
 *
 *  @{
 */

#ifndef _TUSB_COMMON_H_
#define _TUSB_COMMON_H_

#ifdef __cplusplus
 extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>

#include "compiler/compiler.h"
#include "tusb_option.h"
#include "errors.h"
#include "assertion.h"
#include "binary.h"

#include "hal/hal.h"
#include "core/tusb_types.h"
#include "core/std_descriptors.h"
#include "osal/osal.h"

// TODO try to manipulate gcc cmd option instead
#ifndef _TEST_
  #define STATIC_ static
#else
  #define STATIC_
#endif


/// form an uint32_t from 4 x uint8_t
static inline uint32_t u32_from_u8(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4) ATTR_ALWAYS_INLINE ATTR_CONST;
static inline uint32_t u32_from_u8(uint8_t b1, uint8_t b2, uint8_t b3, uint8_t b4)
{
  return (b1 << 24) + (b2 << 16) + (b3 << 8) + b4;
}

/// min value
static inline uint32_t min_of(uint32_t x, uint32_t y) ATTR_ALWAYS_INLINE ATTR_CONST;
static inline uint32_t min_of(uint32_t x, uint32_t y)
{
  return (x < y) ? x : y;
}

/// max value
static inline uint32_t max_of(uint32_t x, uint32_t y) ATTR_ALWAYS_INLINE ATTR_CONST;
static inline uint32_t max_of(uint32_t x, uint32_t y)
{
  return (x > y) ? x : y;
}

#ifdef __cplusplus
 }
#endif

#endif /* _TUSB_COMMON_H_ */

/**  @} */
/**  @} */
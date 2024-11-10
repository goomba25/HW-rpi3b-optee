/*
 * Copyright (c) 2016-2017, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * The name of this file must not be modified
 */

#ifndef USER_TA_HEADER_DEFINES_H
#define USER_TA_HEADER_DEFINES_H

/* To get the TA UUID definition */
#include <hello_world_ta.h>

#define HELLO_RPI_OPTEE_UUID                                 \
  {                                                          \
    0xCFF75836U, 0x9787U, 0x4FDBU,                           \
    {                                                        \
      0xA0U, 0xA9U, 0xD1U, 0x2CU, 0x76U, 0xFDU, 0xCCU, 0x3DU \
    }                                                        \
  }

#define TA_HELLO_WORLD_UUID                          \
  {                                                  \
    0x8aaaf200, 0x2450, 0x11e4,                      \
    {                                                \
      0xab, 0xe2, 0x00, 0x02, 0xa5, 0xd5, 0xc5, 0x1b \
    }                                                \
  }

#define TA_UUID HELLO_RPI_OPTEE_UUID

/*
 * TA properties: multi-instance TA, no specific attribute
 * TA_FLAG_EXEC_DDR is meaningless but mandated.
 */
#define TA_FLAGS TA_FLAG_EXEC_DDR

/* Provisioned stack size */
#define TA_STACK_SIZE (2 * 1024)

/* Provisioned heap size for TEE_Malloc() and friends */
#define TA_DATA_SIZE (32 * 1024)

/* The gpd.ta.version property */
#define TA_VERSION "1.0"

/* The gpd.ta.description property */
#define TA_DESCRIPTION "Example of OP-TEE Hello World Trusted Application"

/* Extra properties */
#define TA_CURRENT_TA_EXT_PROPERTIES                        \
  {"org.linaro.optee.examples.hello_world.property1",       \
   USER_TA_PROP_TYPE_STRING,                                \
   "Some string"},                                          \
  {                                                         \
    "org.linaro.optee.examples.hello_world.property2",      \
        USER_TA_PROP_TYPE_U32, &(const uint32_t) { 0x0010 } \
  }

#endif /* USER_TA_HEADER_DEFINES_H */

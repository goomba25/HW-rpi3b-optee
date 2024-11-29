#ifndef _REE_INVOKE_H_
#define _REE_INVOKE_H_

#include <stdint.h>

#define TA_UUID                                                                                   \
    {                                                                                             \
        0xCFF75836U, 0x9787U, 0x4FDBU, { 0xA0U, 0xA9U, 0xD1U, 0x2CU, 0x76U, 0xFDU, 0xCCU, 0x3DU } \
    }

uint32_t ivk_OpenTa(void);
void ivk_CloseTa(void);
uint32_t ivk_RunOperationTa(uint32_t cmdId,
                            void *src1,
                            uint32_t srcLength1,
                            void *src2,
                            uint32_t srcLength2,
                            void *src3,
                            uint32_t srcLength3,
                            void *src4,
                            uint32_t srcLength4);

#endif /* _REE_INVOKE_H_ */
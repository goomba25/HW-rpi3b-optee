#ifndef _HELLO_COMMAND_H_
#define _HELLO_COMMAND_H_

#define HELLO_CMD_NONE          0x00000000U

#define HELLO_CMD_HASH_INIT     0x21001000U
#define HELLO_CMD_BLOCK_INIT    0x31001000U
#define HELLO_CMD_STREAM_INIT   0x32001000U
#define HELLO_CMD_AEAD_INIT     0x33001000U
#define HELLO_CMD_RSASSA_INIT   0x41001000U
#define HELLO_CMD_ECDSA_INIT    0x42001000U
#define HELLO_CMD_CMAC_INIT     0x51001000U
#define HELLO_CMD_HMAC_INIT     0x52001000U
#define HELLO_CMD_ECDH_INIT     0x61001000U
#define HELLO_CMD_PBKDF2_INIT   0x62001000U

#define HELLO_CMD_HASH_UPDATE   0x21002000U
#define HELLO_CMD_BLOCK_UPDATE  0x31002000U
#define HELLO_CMD_STREAM_UPDATE 0x32002000U
#define HELLO_CMD_AEAD_UPDATE   0x33002000U
#define HELLO_CMD_CMAC_UPDATE   0x51002000U
#define HELLO_CMD_HMAC_UPDATE   0x52002000U

#define HELLO_CMD_RNG_FINAL     0x10003000U
#define HELLO_CMD_HASH_FINAL    0x21003000U
#define HELLO_CMD_BLOCK_FINAL   0x31003000U
#define HELLO_CMD_STREAM_FINAL  0x32003000U
#define HELLO_CMD_AEAD_FINAL    0x33003000U
#define HELLO_CMD_ECDH_INIT     0x61003000U
#define HELLO_CMD_PBKDF2_INIT   0x62003000U

#define HELLO_CMD_RSASSA_SIGN   0x41004000U
#define HELLO_CMD_RSASSA_SIGN   0x42004000U

#define HELLO_CMD_RSASSA_VERIFY 0x41006000U
#define HELLO_CMD_RSASSA_VERIFY 0x42006000U

#define HELLO_CMD_CMAC_COMPUTE  0x51005000U
#define HELLO_CMD_HMAC_COMPUTE  0x52005000U

#define HELLO_CMD_CMAC_COMPARE  0x51006000U
#define HELLO_CMD_HMAC_COMPARE  0x52006000U

#endif /* _HELLO_COMMAND_H_ */
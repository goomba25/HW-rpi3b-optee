#ifndef _TEE_LOG_H_
#define _TEE_LOG_H_

#include <trace.h>

#define FucntionEnter()    DMSG("Enter\n");
#define FucntionLevae()    DMSG("Leave\n");
#define LogDebug(fmt, ...) DMSG(fmt "\n", ##__VA_ARGS__);
#define LogError(fmt, ...) EMSG(fmt "\n", ##__VA_ARGS__);

#endif /* _TEE_LOG_H_ */
#ifndef _REE_LOG_H_
#define _REE_LOG_H_

#include <stdio.h>

#define COLOR_RED       "\033[38;2;255;0;0m"
#define COLOR_BLUE      "\033[38;2;0;0;255m"
#define COLOR_GREEN     "\033[38;2;0;255;0m"
#define COLOR_RESET     "\033[0m"

#define FunctionEnter() printf("%s[Enter]%s %s\n", COLOR_BLUE, COLOR_RESET, __FUNCTION__)
#define FunctionLeave() printf("%s[Leave]%s %s\n", COLOR_BLUE, COLOR_RESET, __FUNCTION__)
#define LogDebug(fmt, ...) \
    printf("%s[DEBUG:%s:%d]%s " fmt "\n", COLOR_GREEN, __FUNCTION__, __LINE__, ##__VA_ARGS__, COLOR_RESET)
#define LogError(fmt, ...) \
    printf("%s[Error:%s:%d]%s" fmt "\n", COLOR_RED, __FUNCTION__, __LINE__, ##__VA_ARGS__, COLOR_RESET)

#endif /* _REE_LOG_H_ */
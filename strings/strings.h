#pragma once
#ifndef STRLEN_H_
#define STRLEN_H_

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

size_t my_strlen(const char *str);

char* my_strcpy(char *to, const char *from);

char *my_strstr1(const char *haystack, const char *needle);

int my_atoi(const char *str);

char *revert_string(char *str);

#ifdef __cplusplus
}
#endif

#endif


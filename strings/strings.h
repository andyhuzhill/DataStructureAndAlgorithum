#pragma once
#ifndef STRLEN_H_
#define STRLEN_H_

#include <stddef.h>

size_t my_strlen(const char *str);

char *my_strcpy(char *to, const char *from);

char *my_strstr1(const char *haystack, const char *needle);

int my_atoi(const char *str);

bool has_all_unique_char(const char *str);

char *revert_string(char *str);

char *remove_duplicate_char(char *str);

bool is_anagram_string(const char *str1, const char *str2);

#endif



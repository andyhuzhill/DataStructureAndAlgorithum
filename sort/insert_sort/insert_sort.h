#pragma once
#ifndef INSERT_SORT_H_
#define INSERT_SORT_H_

#ifdef __cplusplus
extern "C" {
#endif

int insert_sort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2));

#ifdef __cplusplus
}
#endif

#endif


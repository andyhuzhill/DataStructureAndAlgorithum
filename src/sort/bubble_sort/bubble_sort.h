#pragma once
#ifndef BUBBLE_SORT_H_
#define BUBBLE_SORT_H_

#ifdef __cplusplus
extern "C" {
#endif

int bubble_sort(void *data, int size, int elem_size, int (*compare)(const void *key1, const void *key2));

#ifdef __cplusplus
}
#endif

#endif


#include "bubble_sort.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

int bubble_sort(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2))
{
    assert(data != NULL);
    assert(compare != NULL);

    int i = 0;
    int j = 0;

    char *a = data;
    char *elem_temp = NULL;

    if ((elem_temp = (char *)malloc(esize)) == NULL) {
        return -1;
    }

    for (i = 0; i < size - 1; ++i) {
        for (j = 0; j < size - i - 1; ++j) {
            if (compare(&a[j * esize], &a[(j + 1) * esize])) {
                memcpy(elem_temp, &a[j * esize], esize);
                memcpy(&a[j * esize], &a[(j + 1) * esize], esize);
                memcpy(&a[(j + 1) * esize], elem_temp, esize);
            }
        }
    }

    free(elem_temp);
    return 0;
}


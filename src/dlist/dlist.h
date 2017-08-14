#pragma once
#ifndef DLIST_H_
#define DLIST_H_

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct DListItem_ {
    struct DListItem_ *prev;
    void *data;
    struct DListItem_ *next;
} DListItem;

typedef struct {
    int size;
    DListItem *head;
    DListItem *tail;
    void (*destroy)(void *data);
} DList;


/* Public Interface */
void dlist_init(DList *list, void (*destroy)(void *data));

void dlist_destroy(DList *list);

int dlist_insert_next(DList *list, DListItem *element, const void *data);

int dlist_insert_prev(DList *list, DListItem *element, const void *data);

int dlist_remove(DList *list, DListItem *element, void **data);

#define dlist_size(list) ((list)->size)
#define dlist_head(list) ((list)->head)
#define dlist_tail(list) ((list)->tail)
#define dlist_data(item) ((item)->data)
#define dlist_is_head(item) ((item)->prev == NULL ? 1 : 0)
#define dlist_is_tail(item) ((item)->next == NULL ? 1 : 0)
#define dlist_next(item) ((item)->next)
#define dlist_prev(item) ((item)->prev)

#ifdef __cplusplus
}
#endif

#endif

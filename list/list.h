#pragma once
#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ListItem_ {
    void *data;                  /* Data field */
    struct ListItem_ *next;      /* Pointer to next item */
} ListItem;

typedef struct {
    int size;                    /* Item count in list */
    ListItem *head;              /* Head pointer */
    ListItem *tail;              /* Tail pointer */
    void (*destroy)(void *data); /* Destroy function */
} List;

/* Public Interface */
void list_init(List *list, void (*destroy)(void *data));
void list_destroy(List *list);

int list_insert_next(List *list, ListItem *element, const void *data);
int list_remove_next(List *list, ListItem *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_is_head(list, element) ((element) == (list)->head ? 1 : 0)
#define list_is_tail(list, element) ((element)->next == NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element)  ((element)->next)

#ifdef __cplusplus
}
#endif

#endif


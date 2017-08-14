#include "dlist.h"
#include <assert.h>
#include <string.h>

void dlist_init(DList *list, void (*destroy)(void *data))
{
    assert(list != NULL);

    list->size = 0;
    list->head = list->tail = NULL;
    list->destroy = destroy;
}

void dlist_destroy(DList *list)
{
    assert(list != NULL);

    void *item_data = NULL;

    while (dlist_size(list)) {
        if ((dlist_remove(list, NULL, &item_data) == 0) &&
                (list->destroy != NULL)) {
            list->destroy(item_data);
        }
    }

    memset(list, 0, sizeof(list));
}

int dlist_insert_next(DList *list, DListItem *element, const void *data)
{
    assert(list != NULL);

    if ((element == NULL) && (dlist_size(list) != 0)) {
        return -1;
    }

    DListItem *new_item = (DListItem *)malloc(sizeof(DListItem));
    if (!new_item) {
        return -1;
    }
    new_item->data = (void *)data;

    if (dlist_size(list) == 0) {
        list->head = new_item;
        new_item->prev = NULL;
        new_item->next = NULL;
        list->tail = new_item;
    } else {
        new_item->next = element->next;
        new_item->prev = element;

        if (new_item->next == NULL) {
            list->tail = new_item;
        } else {
            element->next->prev = new_item;
        }
        element->next = new_item;
    }
    list->size ++;
    return 0;
}

int dlist_insert_prev(DList *list, DListItem *element, const void *data)
{
    assert(list != NULL);
    if ((element == NULL) && (dlist_size(list) != 0)) {
        return -1;
    }

    DListItem *new_item = (DListItem *)malloc(sizeof(DListItem));
    if (!new_item) {
        return - 1;
    }
    new_item->data = (void *)data;

    if (dlist_size(list) == 0) {
        list->head = new_item;
        new_item->prev = NULL;
        new_item->next = NULL;
        list->tail = new_item;
    } else {
        new_item->next = element;
        new_item->prev = element->prev;

        if (new_item->prev == NULL) {
            list->head = new_item;
        } else {
            element->prev->next = new_item;
        }

        element->prev = new_item;
    }

    list->size ++;
    return 0;
}

int dlist_remove(DList *list, DListItem *element, void **data)
{
    assert(list != NULL);

    if ((element == NULL) || dlist_size(list) == 0) {
        return -1;
    }

    *data = element->data;

    if (element == dlist_head(list)) {
        list->head = element->next;
        if (list->head == NULL) {
            list->tail = NULL;
        } else {
            element->next->prev = NULL;
        }
    } else {
        element->prev->next = element->next;
        if (element->next == NULL) {
            list->tail = element->prev;
        } else {
            element->next->prev = element->prev;
        }

    }
    free(element);

    list->size --;
    return 0;
}


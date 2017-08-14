#include "list.h"
#include <assert.h>
#include <string.h>

void list_init(List *list, void (*destroy)(void *data))
{
    assert(list != NULL);

    list->size = 0;
    list->head = list->tail = NULL;
    list->destroy = destroy;
}

void list_destroy(List *list)
{
    assert(list != NULL);

    ListItem *pItem = list->head;

    while (pItem) {
        list->head = list->head->next;
        if (pItem->data && list->destroy) {
            list->destroy(pItem->data);
        }
        free(pItem);
        pItem = list->head;
    }

    memset(list, 0, sizeof(List));
}

int list_insert_next(List *list, ListItem *element, const void *data)
{
    assert(list != NULL);

    ListItem *pItem = (ListItem *)malloc(sizeof(ListItem));
    if (!pItem) {
        return -1;
    }

    pItem->data = (void *)data;

    if (element == NULL) { // Insert into list at the head
        pItem->next = list->head;
        list->head = pItem;
        if (list_size(list) == 0) {
            list->tail = pItem;
        }
    } else {
        pItem->next = element->next;
        element->next = pItem;
        if (pItem->next == NULL) {
            list->tail = pItem;
        }
    }
    list->size++;
    return 0;
}

int list_remove_next(List *list, ListItem *element, void **data)
{
    assert(list != NULL);

    if (list_size(list) == 0) {
        return -1;
    }

    ListItem *pItem = NULL;
    if (element == NULL) {
        *data = list->head->data;
        pItem = list->head;
        list->head = list->head->next;

        if (list_size(list) == 1) {
            list->tail = NULL;
        }
    } else {
        if (element->next == NULL) {
            return -1;
        }
        *data = element->next->data;
        pItem = element;
        element->next = element->next->next;

        if (element->next == NULL) {
            list->tail = element;
        }
    }
    free(pItem);

    list->size--;
    return 0;
}


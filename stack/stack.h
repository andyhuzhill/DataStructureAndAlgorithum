#pragma once
#ifndef STACK_H_
#define STACK_H_

#ifdef __cplusplus
extern "C" {
#endif


#include "list.h"

typedef List Stack;

#define stack_init list_init
#define stack_destroy list_destroy
#define stack_size list_size
#define stack_peek(stack) ((stack)->head == NULL ? NULL : (stack)->head->data)

int stack_push(Stack *stack, const void *data);

int stack_pop(Stack *stack, void **data);

#ifdef __cplusplus
}
#endif

#endif


#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>

typedef struct {
  size_t size;
  size_t capacity;
  void * arr;
} stack;

stack * create_stack(void *, size_t);
int push(stack *, void *);
void * pop(stack *);
void * top(stack *);
stack * increase_cap(stack *);

#endif

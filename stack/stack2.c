#include <stdio.h>
#include <stdlib.h>
#include "stack2.h"

#define empty_top (-1)

ptrstackrecord create_stack(int max_elem)
{
  ptrstackrecord stack;

  stack = (ptrstackrecord)malloc(sizeof(ptrstackrecord));
  if (!stack)
    printf("fatal error\n");

  stack->top = empty_top;
  stack->array = (elemtype *)malloc(max_elem * sizeof(elemtype));
  if (!stack->array)
    return NULL;
  stack->capacity = max_elem - 1; // use capacity as index, from 0

  return stack;
}

int is_full(ptrstackrecord stack)
{
  return stack->top == stack->capacity;
}

int is_empty(ptrstackrecord stack)
{
  return stack->top == empty_top; // one less than 0
}

void push(ptrstackrecord stack, elemtype x)
{
  if (is_full(stack))
    printf("is full\n");
  else
    stack->array[++stack->top] = x;
}

int stack_size(ptrstackrecord stack)
{
  return stack->top + 1;
}

elemtype pop(ptrstackrecord stack)
{
  if (is_empty(stack))
  {
    printf("is empty\n");
    return -1;
  }
  else
  {
    return stack->array[stack->top--];
  }
}

elemtype top(ptrstackrecord stack)
{
  if (is_empty(stack))
  {
    printf("is empty\n");
    return -1;
  }
  else
  {
    return stack->array[stack->top];
  }
}

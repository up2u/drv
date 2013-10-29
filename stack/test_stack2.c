#include <stdio.h>
#include "stack2.h"

#define MAX_STACK_SIZE 1

int main()
{
  ptrstackrecord s = NULL;
  int top_elem = 0;
  int pop_elem = 0;

  s = create_stack(MAX_STACK_SIZE);
  printf("size is %d\n", stack_size(s));

  push(s, 123);
  printf("size is %d\n", stack_size(s));

  top_elem = top(s);
  printf("the top elem is %d\n", top_elem);

  push(s, 456);
  printf("size is %d\n", stack_size(s));

  pop_elem = pop(s);
  printf("the poped elem is %d\n", pop_elem);
  pop_elem = pop(s);
  printf("the poped elem is %d\n", pop_elem);

  push(s, 789);
  printf("size is %d\n", stack_size(s));
  top_elem = top(s);
  printf("the top elem is %d\n", top_elem);

  return 0;
}

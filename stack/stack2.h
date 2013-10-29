#ifndef _STACH2_H_
#define _STACH2_H_

typedef int elemtype;

typedef struct
{
  elemtype *array;
  int top;
  int capacity;
} stackrecord;

typedef stackrecord * ptrstackrecord;

ptrstackrecord create_stack(int max_elem);
int is_full(ptrstackrecord stack);
int is_empty(ptrstackrecord stack);
void push(ptrstackrecord stack, elemtype x);
elemtype pop(ptrstackrecord stack);
elemtype top(ptrstackrecord stack);
int stack_size(ptrstackrecord stack);


#endif // _STACH2_H_

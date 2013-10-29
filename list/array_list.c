#include <stdio.h>
#include "list.h"

#define NUM 5

sqlist * init(sqlist * sl, int *array, int n)
{
  sl->elem   = array;
  sl->size   = n;
}

int main()
{
  int a = 0;
  int array[NUM] = {0};
  sqlist sl;

  init(&sl, array, NUM);

  printf("the size is %d\n", sl.size);
  printf("it is %d\n", a);

  return 0;
}

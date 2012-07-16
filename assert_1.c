#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main(int argc, char *argv[])
{
  int t1 =atoi(argv[1]);

  printf("argv[1] = %d\n", t1);
  assert(t1 < 2);
  printf("after assert\n");
  return 0;
}

#include <stdio.h>

// test gdb

void fun(int a)
{
  printf("input is %d\n", a);
  if(a > 0){
    printf("will return \n");
    return;  // if fun return type is not void, use gdb will go through this line
             // else gdb will jump to 12(mean the end of function)
  }
  return;
}

int main()
{
  int a = 3;

  fun(a);
}

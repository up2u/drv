#include <stdio.h>

// array name is lvalue !
// will error when assign to
int main(int argc, char *argv[])
{
  int array[2] = {1, 2};
  int *p_arr = array;
  int sum = 0;
  int i;

  // array is lvalue
  for (i = 0; i < 2; ++i)
  {
    sum += array[i];
    array++;    // !! error
  }

  sum = 0;
  for (i = 0; i < 2; ++i)
  {
    sum += *p_arr;
    p_arr++;
  }

  return 1;
}

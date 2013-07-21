// ----------------------------------------------------------------------------
// file t1.16.c
//
// ----------------------------------------------------------------------------

#include <stdio.h>

// descend order
void print_descending(int a, int b, int c)
{
  int tmp;

  scanf("%d, %d, %d", &a, &b, &c);
  //  printf("they are: a, b, c : %d %d %d\n", a, b, c);

  if (a < b)
  {
    tmp = a;
    a   = b;
    b   = tmp;
  }
  if (a < c)
  {
    tmp = c;
    c   = a;
    a   = tmp;
  }
  if (b < c)
  {
    tmp = b;
    b   = c;
    c   = tmp;
  }

  printf("descend order is %d, %d, %d \n", a, b, c);
}

// main
int main()
{
  int i1, i2, i3;

  print_descending(i1, i2, i3);

  return 1;
}

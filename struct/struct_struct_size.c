#include <stdio.h>

struct st1
{
  long long ll1;
  char  c1;
};

struct st2
{
  int i2;
};


struct st3
{
  struct st1 a;
  struct st2 b;
  char c;
};


int main()
{
  struct st3 t1;
  printf("size of struct st3 = %d\n", sizeof(t1));

  return 0;
}

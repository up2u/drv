#include <stdio.h>

// 欧几里得算法
unsigned int gcd(unsigned int m, unsigned int n)
{
  unsigned int rem;

  while (0 != n)
  {
    rem = m % n;
    m   = n;
    n   = rem;
  }

  return m;
}

int main()
{
  int a = 50;
  int b = 15;
  int c = gcd(a, b);

  printf("the gcd is %d\n", c);

  return 0;
}

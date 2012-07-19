#include <stdio.h>

typedef struct ext_addr_s
{
  int lo;
  int hi;
}ext_addr_t;


int main()
{
  ext_addr_t ib;
  ib.lo = 0x12345678;
  ib.hi = 0xabc00def;

  printf("It is use llX %016llX\n", *(unsigned long long *)&ib);

  return 0;
}


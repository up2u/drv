#include <stdio.h>

// NOTE: if string is out of range,
// then will truncate it ?!
int main(int argc, char *argv[])
{
  // input 0x1ffff ffff  --> will out put 0x1ffff fff
  int t1 = strtol(argv[1], NULL, 16);
  printf("it is %d[0x%x]\n", t1, t1);

  return 0;
}

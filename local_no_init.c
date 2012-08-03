#include <stdio.h>

typedef struct stu_s
{
  int id;
  int high;
}stu_t;

int main()
{
  stu_t s1;
  // in this case there are not zero in this structure !?
  printf("s1.id=0x%08x, s1.high=0x%08x\n", s1.id, s1.high);

  return 0;
}

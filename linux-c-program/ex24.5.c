#include <stdio.h>
#include <string.h>

static const char *msg[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

char *get_a_day(int idx)
{
  static char buf[20];
  strcpy(buf, msg[idx]);

  return buf;
}

//
int main(int argc, char *argv[])
{
  // NOTE: After test on CentOS6.4
  // It execute from right to left : means: [1] then [0] ,
  // it's Monday then Sunday
  // so the result will be all Sunday Sunday
  printf("%s %s\n", get_a_day(0), get_a_day(1));

  // the result will be Sunday and Monday
  printf("%s\n", get_a_day(0));
  printf("another one\n");
  printf("%s\n", get_a_day(1));
  return 0;
}

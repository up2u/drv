#include <stdio.h>

void repeat_three_times(void (*f)(void *), void *p)
{
  f(p);
  f(p);
  f(p);
}

// NOTE: parameter should be void * type:
void say_hello(void *str)
{ // then convert to char *
  printf("the string is %s\n", (const char *)str);
}

// NOTE: parameter should be void * type:
void count_num(void *num)
{
  int i;
  // then convert to int
  for (i = 0; i < (int)num; ++i)
  {
    printf("%d ", i);
  }
  putchar('\n');
}

int main(int argc, char *argv[])
{
  repeat_three_times(say_hello, "Guys"); // "Guys" is void * ??
  repeat_three_times(count_num, (void *)4); // should input void * type.

  return 0;
}

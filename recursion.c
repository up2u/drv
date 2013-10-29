#include <stdio.h>

// out put the digital num from high bit
void printout(int i)
{
  if (i >= 10)
    printout(i / 10);

  printf ("%d\n", i % 10);
}

int main(int argc, char *argv[])
{
  int i = 1234;

  printout(i);
  return 0;
}

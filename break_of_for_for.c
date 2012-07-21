#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, j;

  for (i = 0; i < 2; i++)
  {
    for (j = 0; j < 3; j++)
    {
      if (j < strtol(argv[1], NULL, 10))
        break;
      printf("2dn for\n");
    }
    printf("1st for\n");
  }

  return 0;
}


#include <stdio.h>
#include <string.h>

int duff_device(char *to, char *from, int count)
{
  register n = (count + 7) / 8;

  switch (count % 8)
  {
    case 0:  do { *to = *from++;   // to without ++; !!
    case 7:       *to = *from++;
    case 6:       *to = *from++;
    case 5:       *to = *from++;
    case 4:       *to = *from++;
    case 3:       *to = *from++;
    case 2:       *to = *from++;
    case 1:       *to = *from++;
             } while (--n > 0);
  }
}

int main()
{
  char to, from[15] = "abcdefghijklmno";

  duff_device(&to, from, 15);

  //  printf("length is %d\n", strlen(from));
  //  printf("the last one is %d\n", from[15]);
  putchar(to);
  putchar('\n');

  return 1;
}

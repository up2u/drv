#include <stdio.h>

// output diamond
// NOTE : num must even num
//   *
//  ***
// *****
//  ***
//   *

void diamond(int n, char c)
{
  int half_h = n/2;
  int i = 0;
  int j = 0;
  int star_count = 0;
  int space_count = 0;

  // please input even num !
  if (0 == n % 2)
  {
    return;
  }

  for (i = 0; i < n; ++i)
  {
    if (i < half_h)
    {
      space_count = half_h - i;
      star_count = 2 * i + 1;
    } else
    {
      space_count = i - half_h;
      star_count = 2 * (n - i) - 1;
    }

    // space
    for (j = 0; j < space_count; ++j)
    {
      printf (" ");
    }

    // star
    for (j = 0; j < star_count; ++j)
    {
      putchar(c);
    }
    printf ("\n");
  }
}

int main(int argc, char *argv[])
{
  int n = 0;
  char c = '*';

  printf("input the num of diamond to n: \n");
  scanf("%d", &n);

  printf("now the diamond is as below : \n");
  diamond(n, c);

  return 0;
}

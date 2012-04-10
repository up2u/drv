#include <stdio.h>

// an example from CU, show the difference between
// array and point

extern int *a;
extern int b[];

int main(int argc, char *argv[])
{
    int x = 0, y = 0;
    x = a[3];
    y = b[3];
    printf("x = %d\n", x);// segment fault !!
    printf("y = %d\n", y);//

    return 0;
}

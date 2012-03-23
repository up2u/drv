#include <stdio.h>

int main(int argc, char *argv)
{
    int i = 2;
    int clz = 0;

    __asm__ __volatile__ ("clz\t%0, %1\n"
                          :"=r"(clz)
                          :"r"(i)
        );
    printf("the clz of i[%08x] is %d\n", i, clz);
}

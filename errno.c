#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

//usage: ./a.out 99999999999999 to see the errno

int main(int argc, char **argv)
{
    printf("test errno\n");
    printf("1: errno = %d\n", errno);

    long int num = strtol(argv[1], NULL, 10);
    printf("2: errno = %d\n", errno);
    printf("num is %d\n", num);

    return 0;
}

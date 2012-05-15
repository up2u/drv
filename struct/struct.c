#include <stdio.h>

struct class
{
    int num;
    int group;
};

int main()
{
    struct class aa = {10, 20};

    struct class bb = {30, 40};

    bb = aa;

    printf("struct bb.num=%d, bb.group=%d \n", bb.num ,bb.group);

    return 0;
}

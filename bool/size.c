#include <stdio.h>
//#include <stdbool.h>

typedef enum level
{
    true=1,
    false=0
}bool;

int main(void)
{
    bool t1;
    printf("sizeof bool is %d\n", sizeof(t1));
    return 0;
}


#include <stdio.h>

// can use constant string !
// use of strchr !!
int main()
{
    char *msg ="a b\n";
    char *p1 = strchr(msg, '\n');
    printf("offset is %d\n", p1 - msg);

    return 0;
}

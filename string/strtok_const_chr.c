#include <stdio.h>

// will segment fault !!
// use of strtok !!
// from the man BUGS
// * These functions cannot be used on constant strings.
int main()
{
    char *msg ="a b\n";
    char *p1 = strtok(msg, " ");
    printf("1st is %s\n", p1);

    return 0;
}

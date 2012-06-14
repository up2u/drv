#include <stdio.h>

// use array instead of const string !
// use of strtok !!
// from the man BUGS
// * These functions cannot be used on constant strings.
int main()
{
    char msg[10] = "a b\n";
    char *p1 = strtok(msg, " ");
    printf("1st is %s\n", p1);


    return 0;
}

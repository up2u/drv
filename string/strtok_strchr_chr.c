#include <stdio.h>

// use of strtok + strchr !!

// why can't find in strchr  ???
int main()
{
    char msg[10] ="a b\n";
    char *p1 = strtok(msg, " ");
    char *p2 = strchr(msg, '\n');

    printf("1st part is %s\n", p1);
    printf("start addr = %d\n", msg);
    printf("find addr = %d\n", p2); // why return 0 ???
    printf("offset of is %d\n", p2-msg);

    return 0;
}

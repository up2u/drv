#include <stdio.h>

// use of strtok + strchr !!
// bug ? the order of strtok and strchr !
int main()
{
    char msg[10] ="a b\n";
    char *p2 = strchr(msg, '\n');  // strchr before strtok !!
    char *p1 = strtok(msg, " ");

    printf("1st part is %s\n", p1);
    printf("start addr = %d\n", msg);
    printf("find addr = %d\n", p2); // when strtok used after strchr it return right !!
    printf("offset of is %d\n", p2-msg);

    return 0;
}

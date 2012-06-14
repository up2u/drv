#include <stdio.h>

// Delimiter characters  at  the  start  or  end  of the string are ignored
int main()
{
    char msg[10] = " a b\n";
    char *p1 = strtok(msg, " ");

    printf("1 start addr = %p\n", msg);
    printf("p1 = %p\n", p1);
    printf("p1 string=%s\n", p1);

    char msg2[10] = "3 ";
    char *p2 = strtok(msg2, " ");
    printf("2 start addr = %p\n", msg2);
    printf("p2 = %p\n", p2);

    return 0;
}

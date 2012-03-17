#include <stdio.h>



#define PRINT(n)  printf("the "#n" string is : %s\n", str##n)

int main(int argc, char *argv)
{
    char *str7 = "hello \n";
    PRINT(7);

    return 0;
}

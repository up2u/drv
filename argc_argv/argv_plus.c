#include <stdio.h>


// compare argv[] with up layer function!
int pf(int argc, char *argv[])
{
    int i = 0;
    printf("in another function argc is %d\n", argc);
    for(; i < argc; i++)
        printf("argv[%d] = %s\n",i, argv[i]);


}

int main(int argc, char *argv[])
{
    int i = 0;
    printf("in main function, argc = %d\n", argc);
    for(; i < argc; i++)
        printf("argv[%d] = %s\n", i, argv[i]);

    printf("now call another function \n");
    pf(argc-1, argv+1);

    return 0;
}

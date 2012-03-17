#include <stdio.h>
#include <stdlib.h>

#define num 31
typedef int (*pmonth)[num];

int main(char argc, char *argv)
{
    pmonth pm1;
    pmonth pm2;

    pm1 = (pmonth)malloc(sizeof(int)*num);;
    pm2 = (int (*)[num])malloc(sizeof(int)*num);


    printf("sizeof(pm1) is %d\n", sizeof(pm1));
    printf("sizoef(pm2) is %d\n", sizeof(pm2));

    return 0;
}

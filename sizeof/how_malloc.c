#include <stdio.h>
#include <stdlib.h>

typedef int (*pmonth)[31];

int main(char argc, char *argv)
{
    pmonth pm1;
    pmonth pm2;

    pm1 = (pmonth)malloc(31);;
    pm2 = (int (*)[31])malloc(31);


    printf("sizeof(pm1) is %d\n", sizeof(pm1));
    printf("sizoef(pm2) is %d\n", sizeof(pm2));

    return 0;
}

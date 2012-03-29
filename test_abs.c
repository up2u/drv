#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int negate = 0x80000000;
    int positive = abs(negate);
    int a = -3;
    int b = abs(a);
    int c = -2147483648;
    int d = abs(c);
    printf("the negate is %d[0x%08x], abs value of it is %d[0x%08x]\n", negate,negate,positive,positive);
    printf("the negate is %d[0x%08x], abs value of it is %d[0x%08x]\n", a,a,b,b);
    printf("the negate is %d[0x%08x], abs value of it is %d[0x%08x]\n", c,c,d,d);

    return 0;
}

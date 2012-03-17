#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[30];
    char *b = (char *)malloc(20 * sizeof(char));
    char *p;
    char *q[20];
    char *m[20][20];
    int (*n)[10];
    struct mystruct
    {
        char dda;
        double dda1;
        int type;
    };
    struct mystruct k;

    printf("sizeof(a)=%d\n",sizeof(a));  // 30
    printf("sizeof(b)=%d\n",sizeof(b));  // 4
    printf("sizeof(a[3])=%d\n",sizeof(a[3]));  //1
    printf("sizeof(b+3)=%d\n",sizeof(b+3));  // 4 !!
    printf("sizeof(*(b+4))=%d\n",sizeof(*(b+4)));  //1

    printf("sizeof(p)=%d\n",sizeof(p)); // 4
    printf("sizeof(q)=%d\n",sizeof(q)); // 80  !!
    printf("sizeof(m)=%d\n",sizeof(m)); // 1600
    printf("sizeof(n)=%d\n",sizeof(n)); // 4 !!
    printf("sizeof(k)=%d\n",sizeof(k)); // 16 on x86, because it is not 8 bytes alignment when double

    return 0;
}

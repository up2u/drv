#include <stdio.h>

int main(int argc, char *argv)
{
    // test gcc or nds whether they change between MIN_32 to MAX_32

    int n_min = -0x80000000;    
    int p_max = -n_min;

    int p_max1 = 0x7fffffff;
    int n_min1 = -p_max;
    
    int n1 = -0x40000000L;
    int p1 = -n1;
    
// it seems that the max negate -2147483648 cat't be to max int 2147483647
    printf("the negate is %d[0x%x]\n", n_min, n_min); //
    printf("the positive is %d[0x%x]\n", p_max, p_max); //

// this can 2147483647 -> -2147483648
    printf("the positive is %d[0x%x]\n", p_max1, p_max1);//
    printf("the negate is %d[0x%x]\n", n_min1, n_min1); //

    printf("the negate is %d[0x%x]\n", n1, n1); // 
    printf("the positive is %d[0x%x]\n", p1, p1); //

    return 0;
}

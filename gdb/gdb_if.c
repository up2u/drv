#include <stdio.h>

int main(int argc, char *argv[])
{
    int i = 0;
    int j = 0;
    int k = 0;
    for(i=0; i<4; i++){
        for(j=0; j<3; j++){
            printf("now i = %d, j = %d\n", i, j);
        }
        putchar('\n');
    }
    return 0;
}

#include <stdio.h>


// in sim
// when use fprintf, %02x will put ffffffff ??
// why ?? just to check how the print !
int main(void)
{
    FILE *fp = NULL;
    fp = fopen("./fp.log", "w");
    unsigned char buf[2] = {
        255, 238
    };
    int i = 0;

    for(; i < 2; i++){
        printf("%02x", buf[i]);
        fprintf(fp, "%02x ", buf[i]);
    }
    putchar('\n');

    return 0;
}

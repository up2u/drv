#include <stdio.h>

#define BUF_SIZE 50

void *mymemset(void *s, int c, size_t n)
{
    char *src = (char *)s;
    const char chr = (unsigned char)c;
    while(n--){
        *src++ = chr;
    }
}


int main(int argc, char *argv[])
{
    char buf[BUF_SIZE] = {0};
    int i = 0;

    mymemset(buf, '\x52', BUF_SIZE); // oct '\052' = *, hex '\x52' = R
    while(i++<BUF_SIZE){
        printf("%c", buf[i-1]); // NOTICE: the i is start from 1
        fflush(NULL);
        if(0 == (i&7)){ // NOTICE: the priority of == and &
            putchar('\n');
            fflush(NULL);
        }
    }
    putchar('\n');
    fflush(NULL);
    return 0;
}

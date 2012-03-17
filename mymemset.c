#include <stdio.h>

void *mymemset(void *s, int c, size_t n)
{
    char *src = (char *)s;
    while(n--){
        *src++ = c;
    }
}


int main(int argc, char *argv[])
{
    char buf[100] = {0};
    int i = 0;

    mymemset(buf, 'a', 100);
    while(i++<100){
        printf("%c", buf[i]);
        if(0 == (i&7)){ // NOTICE: the priority of == and &
            putchar('\n');
        }
    }
    putchar('\n');
    return 0;
}

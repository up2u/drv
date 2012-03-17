#include <stdio.h>

void reverse_str1(char *buf, int n) // with temporary value
{
    char swap = '\0';

    int i = 0;
    for(; i<n/2; i++){
        swap = buf[i];
        buf[i] = buf[n-1-i];
        buf[n-1-i] = swap;
    }
}

void reverse_str2(char *buf, int n)  // without temporary value
{
    int i = 0;
    for(; i<n/2; i++){  // bit xor operation
        buf[i] = buf[i]^buf[n-1-i];
        buf[n-1-i] = buf[i]^buf[n-1-i];
        buf[i] = buf[i]^buf[n-1-i];
    }
}

int main(int argc, char *argv[])
{
    char buf[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', '\n'};

//    reverse_str1(buf, 8);
    reverse_str2(buf, 8);

    char *p_buf = buf;
    int len = sizeof(buf);
    for(; p_buf<buf+len; p_buf++){
        putchar(*p_buf);
    }
    putchar('\n');
}

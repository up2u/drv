#include <stdio.h>

#define errmsg(s) printf("file:%s, function: %s, line: %d, my string: %s", __FILE__, __FUNCTION__, __LINE__, s)

int main(int argc, char *argv[])
{
    printf("this is me\n");
    errmsg("hello\n");

    return 0;
}

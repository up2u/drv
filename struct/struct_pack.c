#include <stdio.h>

struct addr_t
{
    union
    {
        unsigned long long long_addr;
        unsigned int short_addr;
    }addr;
    char index;
};

int main(int argc, char *argv[])
{
    struct addr_t t1;

    printf("sizeof struct addr_t is %d\n", sizeof(t1));

    return 0;
}

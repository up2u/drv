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
    // how to index element in union !
    printf("sizeof union element %d\n", sizeof(t1.addr.long_addr));

    return 0;
}

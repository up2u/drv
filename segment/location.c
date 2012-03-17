#include <stdio.h>
#include <stdlib.h>

/*define array, let it located in heap, stack, global data area*/

static int global_BSS[6];
int global_DATA[3] = {12, 30, 56};

int main(int argc, char *argv[])
{
    // heap
    char *p_heap = (char *)malloc(sizeof(char) * 10);

    // stack
    char p_stakc[12];

    static int local_bss[4];
    static local_data = 3;


    return 0;
}

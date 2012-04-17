#include <stdio.h>
#include <stdlib.h>

void bye(void)
{
    printf("just say goodbye \n");
}

int main(int argc, char **argv)
{
    atexit(bye);
    int i = 0;
    while(i < 3){
        sleep(1);
        printf("i = %d\n", i);
        i++;
    }

    return 0;
}

#include <stdio.h>
#include <unistd.h>

// the switch case used in contiki-os
// used to return from event interupt
//

int main(int argc, char *argv[])
{
    char c1 = 'a';
    int i = strtol(argv[1], NULL, 10);

    {
        char c1 = 'b';
        switch(i)
        {
        case 1:
            ;
            printf("within 1 bracket {}\n");
            while(1)
            {
            case 2:
                printf("within 2 bracket {}\n");
                do
                {
                case 3:
                    printf("within 3 bracket {}\n");

                }while(0);
                sleep(2);
            }
        }
    };  // can use ;
    return 0;
}

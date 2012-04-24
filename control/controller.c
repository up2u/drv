#include <stdio.h>
#include "command.h"

// This file is just a toplevel controller


void usage();

int main(int argc, char *argv[])
{
    if(argc < 2){
        usage();
        return -1;
    }
    if(parse_command(argv[1])){ // argv[2] argv[3] ... list need to process.. !!
        printf("command found\n");
    }

    return 0;
}


void usage()
{
    printf("---------usage begin-------------\n");
    printf("* ./controller.exe\n");
    printf("*\n");
    printf("*\n");
    printf("*\n");
    printf("*\n");
    printf("---------usage end---------------");
    putchar('\n');
}


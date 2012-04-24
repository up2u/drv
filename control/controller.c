#include <stdio.h>
#include "command.h"

// This file is just a toplevel controller

#define MAX_ARG_BUF 512
#define MAX_ARG_LENGTH 30

void usage();


char arg_buf[MAX_ARG_BUF] = {'0'};

int main(int argc, char *argv[])
{
    char *string[MAX_ARG_LENGTH] = {NULL};
    int i;
    char *p_buf = arg_buf;

    if(argc < 2){
        usage();
        return -1;
    }
    for(i=0; i<argc-1; i++){
        strcpy(p_buf, argv[i+1]);
        p_buf = p_buf + strlen(p_buf) + 1;
        p_buf[-1] = ' ';
    }
    p_buf[-1] = '\n';

    parse_command(arg_buf);

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


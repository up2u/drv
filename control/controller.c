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

    parse(argc, argv);

    return 0;
}


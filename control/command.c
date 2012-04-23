#include <stdio.h>
#include "command.h"

int do_echo(void *arg);
int do_list(void *arg);

struct cmd cmd_tbl[] =
{
    {"echo", do_echo},
    {"list", do_list}
};

int do_echo(void *arg)
{
    printf("the command is do_echo\n");

    return 0;
}

int do_list(void *arg)
{
    printf("the command is do_list\n");

    return 0;
}

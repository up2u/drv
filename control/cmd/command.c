#include <stdio.h>
#include <string.h>
#include "command.h"

static int do_echo(void *arg); // prototype
static int do_list(void *arg);
int parse_command(char *string);

//======================================================
//
//
//======================================================
static struct cmd cmd_tbl[] =
{
    {"echo", do_echo},  // ,
    {"list", do_list}
};

//------------------------------------------------------
//
//
//------------------------------------------------------
static int do_echo(void *arg)
{
    printf("the command is do_echo\n");

    return 0;
}

//------------------------------------------------------
//
//
//------------------------------------------------------

static int do_list(void *arg)
{
    printf("the command is do_list\n");

    return 0;
}

int parse_command(char *string)
{
    int i;
    for(i=0; i<COMMAND_TABLE_SIZE; i++){
        if(strcmp(string, cmd_tbl[i].name) == 0){
            printf("the command is %s\n", cmd_tbl[i].name);
            return 1;
        }
    }
    if(i == COMMAND_TABLE_SIZE){
        printf("-----------NOTICE begin------------\n");
        putchar('\n');
        printf("bad command or not implemented yes\n");
        putchar('\n');
        printf("-----------NOTICE end--------------\n");
        return 0;
    }

    return 1;
}

#include <stdio.h>
#include <string.h>
#include "command.h"
#include "defines.h"

static int do_echo(char *string); // prototype
static int do_list(char *string);
static int do_add(char *string);

int parse_command(char *string);

//#define printf(...) MYPRINT(...)


//======================================================
//
//
//======================================================
static struct cmd cmd_tbl[] =
{
    {"echo", do_echo},  // ,
    {"list", do_list},
    {"add",  do_add}
};

//------------------------------------------------------
//
//
//------------------------------------------------------
static int do_echo(char *string)
{
    printf("the command is do_echo\n");

    return 0;
}

//------------------------------------------------------
//
//
//------------------------------------------------------

static int do_list(char *string)
{
    printf("the command is do_list\n");

    return 0;
}

//------------------------------------------------------
//
//
//------------------------------------------------------
static int do_send(char *string)
{

    return 0;
}

//------------------------------------------------------
// add node
// this will fork a process ??
// use toplogy: or use default net-list ??
//
//------------------------------------------------------
static int do_add(char *string)
{
    int id = 0;
    char *elf_file = NULL;
    char *str1 = strtok(string, " ");
    if(str1 != NULL){
        id = strtol(str1, NULL, 10);
        printf("the id num is %d\n", id);
    }
    elf_file = strtok(NULL, " ");
    if(elf_file){
        printf("the elf_file is %s\n", elf_file);
    }

    return 0;
}

int parse_command(char *string)
{
    int i;
    for(i=0; i<COMMAND_TABLE_SIZE; i++){
        if(strcmp(string, cmd_tbl[i].name) == 0){
            printf("the command is %s\n", cmd_tbl[i].name);
            MYPRINT("run handler");
            cmd_tbl[i].handler(string);
            return 1;
        }
    }
    if(i == COMMAND_TABLE_SIZE){
        printf("-----------NOTICE begin------------\n");
        putchar('\n');
        printf("bad command or not implemented yes\n");
        putchar('\n');
        printf("-----------NOTICE end--------------\n");
        MYPRINT("Test MYPRINT");
        return 0;
    }

    return 1;
}

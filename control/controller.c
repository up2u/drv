#include <stdio.h>
#include <string.h>
#include "command.h"

void usage();
int parse_command();

int main(int argc, char *argv[])
{
    if(argc < 2){
        usage();
        return -1;
    }
    if(parse_command(argv[1])){
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
        printf("bad command or not implemented yes\n");
        return 0;
    }

    return 1;
}

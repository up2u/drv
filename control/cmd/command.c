#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "command.h"
#include "defines.h"
#include "node.h"


static int do_echo(char *string); // prototype
static int do_list(char *string);
static int do_add(char *string);
void do_script(char *string);
void do_node_num(char *string);
int NNODE = 0;


int parse_command(int argc, char **argv);
typedef struct
{
    const char *name;
    void (*func_arg)(const char *);
//    int flags;
    char *help;
    char *argname;
}optiondef;

static const optiondef options[] = {
    {"f", do_script, "input script file", "filename"},
    {"n", do_node_num, "node num", "num 2-20"} // node num ??
};

// find_option

static const optiondef * find_option(const optiondef *po, const char *name)
{
    while(po->name != NULL){
        if(!strcmp(po->name, name))
            break;
        po++;
    }
    return po;
}


// script
void do_script(char *string)
{
    printf("the is option for run script\n");
}
// do_node_num
void do_node_num(char *string)
{
    NNODE = strtol(string, NULL, 10);
    printf("this is option for node num \n");
}

//------------------------------------------------------
// init the node struct
// give him some name
//------------------------------------------------------

static int init_pipe(node_t *node,u32 index, u32 pid)
{
    node->index = index;
    node->pid = pid;
    sprintf(node->cmd_in.name, "/tmp/fifo/pp_cmd_in_%d", index);
    sprintf(node->cmd_out.name, "/tmp/fifo/pp_cmd_out_%d", index);
    sprintf(node->data_in.name, "/tmp/fifo/pp_data_in_%d", index);
    sprintf(node->data_out.name, "/tmp/fifo/pp_data_out_%d", index);
    if((node->cmd_in.pipe = open(node->cmd_in.name, O_RDONLY)) == -1) {
        MYPRINT("open");
        return -1;
    }
    if((node->cmd_out.pipe = open(node->cmd_out.name, O_WRONLY)) == -1) {
        MYPRINT("open");
        return -1;
    }
    if((node->data_in.pipe = open(node->data_in.name, O_RDONLY)) == -1) {
        MYPRINT("open");
        return -1;
    }
    if((node->data_out.pipe = open(node->cmd_in.name, O_WRONLY)) == -1) {
        MYPRINT("open");
        return -1;
    }
    return 1;
}

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
    pid_t pid;
    node_t nd;
    if(str1 != NULL){
        id = strtol(str1, NULL, 10);
        printf("the id num is %d\n", id);
    }else{
        MYPRINT("add node");
        printf("usage: ./a.out add id node_elf\n");
        return -1;
    }

    memset(&nd, '\0', sizeof(nd));
    pid = fork();

    switch(pid){
    case -1:
        MYPRINT("fork error");
        break;
    case 0:
        MYPRINT("child process");
        elf_file = strtok(NULL, " ");
        if(elf_file){
            printf("the elf_file is %s\n", elf_file);
            system(elf_file); // node execute elf file
        }
        break;
    default:
        MYPRINT("parent process");
        printf("child pid = %d\n", pid);
        init_pipe(&nd, id, pid);
    }
}

int parse_command(int argc, char **argv)
{
//    int i;
//    char *cmd = strtok(string, " ");
//
//    for(i=0; i<COMMAND_TABLE_SIZE; i++){
//        if(strcmp(cmd, cmd_tbl[i].name) == 0){
//            printf("the command is %s\n", cmd_tbl[i].name);
//            MYPRINT("run handler");
//            cmd_tbl[i].handler(cmd + strlen(cmd) + 1);
//            return 1;
//        }
//    }
//    if(i == COMMAND_TABLE_SIZE){
//        printf("-----------NOTICE begin------------\n");
//        putchar('\n');
//        printf("bad command or not implemented yes\n");
//        putchar('\n');
//        printf("-----------NOTICE end--------------\n");
//        MYPRINT("Test MYPRINT");
//        return 0;
//    }
//
    int optindex = 1; // 1
    const char *opt;
    int handleoption = 1; // !
    const optiondef *po;

    while(optindex < argc){
        opt = argv[optindex++];
        if(opt[0] == '-' && opt[1] != '\n'){
            opt++;
            po = find_option(options, opt);
           //   if(!strcmp(po->name, "f")){ // run from script
                po->func_arg(argv[optindex]);
           //}
        }
    }
    return 1;
}

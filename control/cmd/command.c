#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "command.h"
#include "defines.h"
#include "node.h"

#define MAX_ARG_BUF 512

static int do_echo(char *string); // prototype
static int do_list(char *string);
static int do_add(char *string);
void do_script(char *string);
void do_node_num(char *string);
void parse(int argc, char **argv);
int parse_option(int argc, char **argv);
void parse_command(char *string);
void cli(void);

static struct cmd cmd_tbl[] =
{
    {"echo", do_echo},  // ,
    {"list", do_list},
    {"add",  do_add}
};


int NNODE = 0;

void cli()
{
    char msg[MAX_ARG_BUF];
    char *msg_ptr = NULL;

    while(1){
        printf("sim >> ");
        fflush(stdout);
        fgets(msg, sizeof(msg), stdin);
        if((msg_ptr = strchr(msg, '\n')) != NULL){
            *msg_ptr = '\0';
        }
        if(strcmp(msg, "\0")){ // an error when use '\0' ??
            parse_command(msg);
        }
    }
}

void parse_command(char *string)
{
    char *cmd;
    int i;

    cmd = strtok(string, " ");
    for(i=0; i<COMMAND_TABLE_SIZE; i++){
        if(!strcmp(cmd_tbl[i].name, cmd)){
            //find cmd
            cmd_tbl[i].handler(string + strlen(cmd) + 1);
        }
    }
}



typedef struct
{
    const char *name;
    int flags;
#define HAS_ARG    0x0001
#define OPT_INT    0x0002

    union{
        void (*func_arg)(const char *);
        int *int_arg;
    }u;
    char *help;
    char *argname;
}optiondef;

static const optiondef options[] = {
    {"f", HAS_ARG, {(void *)do_script}, "input script file", "filename"},
    {"n", OPT_INT, {(void *)&NNODE}, "node num", "num 2-20"} // node num ??
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

int parse_option(int argc, char **argv)
{
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
            if(po->flags & HAS_ARG){ // function
                po->u.func_arg(argv[optindex]);
            }else if(po->flags & OPT_INT){ // int arg
                *(po->u.int_arg) = strtol(argv[optindex], NULL, 10);
                printf("now NNODE = %d\n", NNODE);
            }
            // get other command from command line.
        }
    }


}

void parse(int argc, char **argv)
{

    parse_option(argc, argv);
    cli();
}

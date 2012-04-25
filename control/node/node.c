#include <stdio.h>
//for open()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
// pthread
#include <pthread.h>

#include "node.h"
#include "defines.h"

//void *(*start_routine)(void*)
void *data_in_thread(void *);
void *cmd_in_thread(void *);

// fix me
#define MAX_PIPE_SIZE 128

void *data_in_thread(void *node)
{
    static char msg[MAX_PIPE_SIZE];
    node_t  *pnode = (node_t *)node;

    while(1){
        if(read(pnode->data_in.pipe, msg, MAX_PIPE_SIZE) == -1){
            MYPRINT("data_in_thread");
            // drv related
            printf("the msg recived from data_in_thread is %s\n", msg);
        }
    }
}

void *cmd_in_thread(void *node)
{
    node_t *pnode = (node_t *)node;

    while(1){
//        if(read(pnode->cmd_in.pipe, ))
        ;
    }
}


//------------------------------------------------------
// init the node struct
// give him some name
//------------------------------------------------------
int init_node(node_t *node,u32 index, u32 pid)
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
    if(pthread_create(node->data_in.thread, NULL, data_in_thread, (void *)node) != 0){
        MYPRINT("data in thread");
    }
//    if(pthread_create(node->cmd_in.thread, NULL, cmd_in_thread, (void *)node) != 0){
//        MYPRINT("cmd in thread");
//    }
    return 1;
}



//void commands

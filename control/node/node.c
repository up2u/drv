#include <stdio.h>
//for open()
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
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
        if(read(pnode->data_in.pipe, msg, 5) == -1){
            MYPRINT("data_in_thread");

        }
        // drv related, recive data from simulated drv
        printf("the msg recived from data_in_thread is %s\n", msg);
    }
}

//void *cmd_in_thread(void *node)
//{
//    node_t *pnode = (node_t *)node;
//
//    while(1){
////        if(read(pnode->cmd_in.pipe, ))
//        ;
//    }
//}


//------------------------------------------------------
// init the node struct
// give him some name
//------------------------------------------------------
int init_node(node_t *node,u32 index, u32 pid)
{ // fix me mknod and mkfifo
  // can't use /tmp/fifo/pp.. because can't mkdir. fifo
  // tempolary use /tmp/pp..
  // and must remove the exist fifo in /tmp/pp..

    node->index = index;
    node->pid = pid;

    sprintf(node->cmd_in.name, "/tmp/pp_cmd_in_%d", index);
//
//    printf("the node->cmd_in.name = %s\n", node->cmd_in.name);
//    if(mknod(node->cmd_in.name, S_IFIFO | 0666, 0) < 0){
//        MYPRINT("mknod 1");
//        return -1;
//    }
//    sprintf(node->cmd_out.name, "/tmp/pp_cmd_out_%d", index);
//    if(mknod(node->cmd_out.name, S_IFIFO | 0666, 0) < 0){
//        MYPRINT("mknod 2");
//        return -1;
//    }
//    sprintf(node->data_out.name, "/tmp/pp_data_out_%d", index);
//    if(mknod(node->data_out.name, S_IFIFO | 0666, 0) < 0){
//        MYPRINT("mknod 4");
//        return -1;
//    }
//
    sprintf(node->data_in.name, "/tmp/pp_data_in_%d", index);
    if(mknod(node->data_in.name, S_IFIFO | 0666, 0) < 0){
        MYPRINT("mknod 3");
        return -1;
    }


//    if((node->cmd_in.pipe = open(node->cmd_in.name, O_RDONLY)) == -1) {
//        MYPRINT("open 1");
//        return -1;
//    }
//    if((node->cmd_out.pipe = open(node->cmd_out.name, O_WRONLY)) == -1) {
//        MYPRINT("open 2");
//        return -1;
//    }
//    if((node->data_out.pipe = open(node->cmd_in.name, O_WRONLY)) == -1) {
//        MYPRINT("open 4");
//        return -1;
//    }

//    if((node->data_in.pipe = open(node->data_in.name, O_RDONLY)) == -1) {

    node->data_in.pipe = open(node->data_in.name, O_RDONLY);
        MYPRINT("open 3");
//        return -1;
//    }
    static char msg[MAX_PIPE_SIZE];
    printf("the node->data_in.name = %s\n", node->data_in.name);
//    while(1){
        if(read(node->data_in.pipe, msg, 5) == -1){
            MYPRINT("data_in_thread");
        }
        // drv related, recive data from simulated drv
        printf("the msg recived from data_in_thread is %s\n", msg);
//    }

//    if(pthread_create(node->data_in.thread, NULL, data_in_thread, (void *)node) != 0){
//        MYPRINT("data in thread");
//    }
//    if(pthread_create(node->cmd_in.thread, NULL, cmd_in_thread, (void *)node) != 0){
//        MYPRINT("cmd in thread");
//    }
    return 1;
}



//void commands

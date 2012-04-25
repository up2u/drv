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
void *sim_data_thread(void *);
void *sim_cmd_thread(void *);

// fix me
#define MAX_PIPE_SIZE 128

void *sim_data_thread(void *node)
{// data from node to simulator
    static char msg[MAX_PIPE_SIZE];
    node_t  *pnode = (node_t *)node;
    int read_num = 0;

    while(1){
        if((read_num = read(pnode->sim_data.pipe, msg, MAX_PIPE_SIZE)) == -1){
            MYPRINT("sim_data_thread");
        }
        usleep(5);
        printf("the msg recived from sim_data_thread is %c\n", msg[0]);
    }
}

//void *sim_cmd_thread(void *node)
//{
//    node_t *pnode = (node_t *)node;
//
//    while(1){
////        if(read(pnode->sim_cmd.pipe, ))
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

//    sprintf(node->sim_cmd.name, "/tmp/pp_cmd_in_%d", index);
//    printf("the node->sim_cmd.name = %s\n", node->sim_cmd.name);
//    if(mknod(node->sim_cmd.name, S_IFIFO | 0666, 0) < 0){
//        MYPRINT("mknod sim_cmd");
//        return -1;
//    }
//
//    if((node->sim_cmd.pipe = open(node->sim_cmd.name, O_RDONLY)) == -1) {
//        MYPRINT("open sim_cmd");
//        return -1;
//    }
//    if(pthread_create(&(node->sim_cmd.thread), NULL, sim_cmd_thread, (void *)node) != 0){
//        MYPRINT("sim_cmd");
//    }


    sprintf(node->sim_data.name, "/tmp/pp_data_in_%d", index);
    if(mknod(node->sim_data.name, S_IFIFO | 0666, 0) < 0){
        MYPRINT("mknod sim_data");
        return -1;
    }
    if((node->sim_data.pipe = open(node->sim_data.name, O_RDONLY)) == -1) {
        MYPRINT("open sim_data");
        return -1;
    }
    if(pthread_create(&(node->sim_data.thread), NULL, sim_data_thread, (void *)node) != 0){
        MYPRINT("pthread_create");
    }
    return 1;
}


#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "node.h"
#include "defines.h"

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
//    if(pthead_create(node->data_in.pthread, NULL, data_in_thread, NULL) != 0){
//        MYPRINT("data in thread");
//    }
//    if(pthead_create(node->cmd_in.pthread, NULL, cmd_in_thread, NULL) != 0){
//        MYPRINT("cmd in thread");
//    }
    return 1;
}



//void commands

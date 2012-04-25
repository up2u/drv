#ifndef _NODE_H_
#define _NODE_H_

#include <pthread.h>
#include "types.h"

#define MAX_PIPE_NAME 20

typedef struct pipe
{
    char name[MAX_PIPE_NAME];
    int pipe;
    pthread_t thread;
    //other
}pipe_t;

typedef struct node
{
    u32 index;
    u32 pid;
    pipe_t cmd_in;
    pipe_t cmd_out;
    pipe_t data_in;
    pipe_t data_out;

    //other
}node_t;

int init_node(node_t *node,u32 index, u32 pid);

#endif // _NODE_H_

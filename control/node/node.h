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
    pipe_t sim_cmd;
    pipe_t sim_data;
    pipe_t node_cmd;
    pipe_t node_data;

    //other
}node_t;

int init_node(node_t *node,u32 index, u32 pid);

#endif // _NODE_H_

#ifndef _NODE_H_
#define _NODE_H_

#include "types.h"

#define MAX_PIPE_NAME 20

typedef struct pipe
{
    char name[MAX_PIPE_NAME];
    int pipe;
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


#endif // _NODE_H_

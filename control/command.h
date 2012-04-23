#ifndef _COMMAND_H_
#define _COMMAND_H_

int do_echo(void *arg);
int do_list(void *arg);

#define COMMAND_TABLE_SIZE (sizeof(cmd_tbl)/sizeof(struct cmd))

typedef int(* handler)(void *);

typedef struct cmd
{
    char *name;
    handler do_something;
}cmt_t;

extern struct cmd cmd_tbl[2];

#endif

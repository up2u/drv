#ifndef _COMMAND_H_
#define _COMMAND_H_

static int do_echo(void *arg); // prototype
static int do_list(void *arg);
int parse_command(char *string);

#define COMMAND_TABLE_SIZE (sizeof(cmd_tbl)/sizeof(struct cmd))

// NOTICE : retrun type
typedef int(* handler)(void *);

typedef struct cmd
{
    char *name;
    handler do_something;
}cmt_t;

#endif  // _COMMAND_H_

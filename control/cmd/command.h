#ifndef _COMMAND_H_
#define _COMMAND_H_

void parse(int argc, char **argv);

#define COMMAND_TABLE_SIZE (sizeof(cmd_tbl)/sizeof(struct cmd))

// NOTICE : retrun type
typedef int(* handler_t)(char *string);

typedef struct cmd
{
    char *name;
    handler_t handler;
}cmt_t;

#endif  // _COMMAND_H_

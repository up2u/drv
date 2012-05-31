#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = 0;
    pid = fork();

    switch(pid)
    {
    case -1:
        perror("fork failed");
    case 0:
        sleep(5);
        printf("it is child process\n");
    default :
        printf("it is parent process\n");
        return 0;
    }
}

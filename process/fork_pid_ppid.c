#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

// show the relation between pid & ppid
//

void main(void)
{
    pid_t pid;
    int i = 0;

    printf("main process pid=%d\n", getpid());
    for(; i<3; i++){
        pid = fork();
        if(-1 == pid || 0 == pid){
            break;
        }
    }
    if(-1 == pid){
        perror("fork failed");
        exit(1);
    }
    if(0 == pid){
        printf("child pid=%d, ppid=%d\n", getpid(), getppid());
        exit(0);
    }else{
        printf("parent pid=%d\n", getpid());
        sleep(2); // if not wait some seconds its child process will be got by pid 1 (init)
    }
}

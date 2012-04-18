#include <stdio.h>
#include <sys/select.h>

int main(int argc, char *argv[])
{
    fd_set rfds;
    struct timeval tv;
    int retval;

    /*watch stdio (fd 0) to see when it has input*/
    FD_ZERO(&rfds);
    FD_SET(0,&rfds);

    /*wait for 5 seconds*/
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    retval = select(1, &rfds, NULL, NULL, &tv); // fds + 1
    /*don't rely on the value of tv now !*/

    if(retval == -1)
        perror("select()");
    else if(retval){  // FD_ISSET(0, &rfds) will be true
        printf("the retval = %d\n");
        printf("data is available now. \n");
    }
    else
        printf("NO data within 5 seconds. \n");

    return 0;
}

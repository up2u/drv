#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

// usage: ./a.out this will wait for data from pipe
// then open another terminal and echo "1234567890abcedf" > ./p1
// the will end, and show the data from pipe.

int main(int artc,char *argv[])
{
    char msg[10];
    int fd;
    int rd;

    mknod("./p1", S_IFIFO | 0666, 0);
    fd = open("./p1", O_RDONLY);
    printf("fd = %d\n", fd);
    rd = read(fd, msg, 10);
    printf("rd num = %d\n", rd);

    printf("msg is %s\n", msg);
    return 0;
}

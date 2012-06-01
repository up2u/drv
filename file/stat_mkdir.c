#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

// use stat to check whether a directory exists
// else mkdir it
int main(void)
{
    struct stat st;

    if(stat("./mydir", &st) != 0){
        printf("directory not exist, now mkdir it\n");
        if(mkdir("./mydir", 0755) != 0){
            printf("mkdir directory failed\n");
        }
    }
    printf("the end\n");
}

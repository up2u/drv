#include <stdio.h>

int main()
{
    int nw = 0;
    int nr = 0;
    int i = 0;
    FILE *fd = NULL;
    char buf_write[5] = {
        1, 'b', '\000', 2, 'e' // put '\0' to file and read it again to check whether it can be ending by this '\0'
    };
    char buf_read[5] = {0};

    char *p_buf = buf_write;

    fd = fopen("./1.log", "r+");
    nw = fwrite(p_buf, 1, 5, fd); // check file size use du -b
    fseek(fd, 0, SEEK_SET);
    nr = fread(buf_read, 1, 5, fd);

    printf("nw=%d, nr=%d\n", nw, nr);

    i = 0;
    while(i<5){
        printf("buf_read[%d]=%d\n", i, buf_read[i]);
        i++;
    }
    return 0;
}

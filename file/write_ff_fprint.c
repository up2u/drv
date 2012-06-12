#include <stdio.h>

int main()
{
    unsigned char c = 255;
    FILE *fd = fopen("./1.log", "w");

    fprintf(fd, "%02x", c);

    fclose(fd);
    return 0;
}

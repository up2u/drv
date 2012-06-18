#include <stdio.h>

int main()
{
    unsigned char c = 255;
    unsigned char c2; // 1st use unsigned, then use signed char !
    FILE *fd = fopen("./1.log", "r+");
    FILE *fd2 = fopen("./2.log", "w");
    fwrite(&c, 1, 1, fd);
    fseek(fd, 0, SEEK_SET);

    fread(&c2, 1, 1, fd);
    fprintf(fd2, "%02x", c2);

    fclose(fd);
    fclose(fd2);
    return 0;
}

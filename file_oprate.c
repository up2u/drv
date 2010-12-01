#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main()
{
	int fd = 0;
	ssize_t write_num = 0;
    char *str = "Hello, software weekly";
	size_t count = strlen(str);

	if ((fd = open("./tmp.txt", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR)) < 0) {
		printf("open file hello.txt fail, errno=%d\n",fd);
		return -1;
	}
	if((write_num = write(fd, (void *)str, count)) < 0){
		printf("write string error:%d\n",write_num);
		return -1;
	}
    return 0;
}


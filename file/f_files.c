#include <stdio.h>

int main(int argc, char *argv[])
{
//	char buf_w[] = {"hello to"};
//	char buf_r[10] = {'\0'};
	short buf_w[] = {100, 101, 102};
	short buf_r[10] = {'\0'};
	FILE *fp_1 = NULL;
	int ret_write = 0;
	int ret_read = 0;
 	int ret_tell = 0;
	printf("size of buf_w is %d\n", sizeof(buf_w));
	if((fp_1 = fopen("/tmp/f1.txt", "w+")) == NULL){
		printf("fopen error \n");
		return -1;
	}
	/*write and read return value is member count*/
	if((ret_write = fwrite(buf_w, 2, 5, fp_1)) < 5){
		printf("fwrite error \n");
		return -1;
	}
	printf("write num is %d\n", ret_write);
	ret_tell = ftell(fp_1);
	/*now the fp indicator is at end*/
	printf("before seek,the fp is %d\n", ret_tell);
	/*now set the fp indicator to head*/
	fseek(fp_1, 0L, SEEK_SET);
	ret_tell = ftell(fp_1);
	/*now the fp indicator is at head*/
	printf("after seek the fp is %d\n", ret_tell);
	if((ret_read = fread(buf_r, 2, 5, fp_1)) < 5){
		printf("fread error \n");
		return -1;
	}
	printf("read num is %d\n", ret_read);
//	printf("the contents read from fp_1 is: %s\n", buf_r);
	printf("the contents read from fp_1:use short is: %d\n", *buf_r); //is 100
	printf("the contents read from fp_1:use interger is: %d\n", *(int *)buf_r); // the content from 100 to 101 = 6619236

	return 0;
}

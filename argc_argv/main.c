#include <stdio.h>
#include <string.h>

//usage: ./a.out 10 "20 30" 40

//and cacluate the sum of input string
//NOTICE: how pass arguments !!!
//

int add(char *string);

int main(int argc, char *argv[])
{
    int i = 0;
    char *string[30] = {NULL};
    char buf[40] = {'0'};
    char *p_buf = buf;

    // init zero
    memset(buf, '\0', 40);

    if(argc < 2){
        printf("input some args\n");
        return 0;
    }
    // output args
    for(;i<argc; i++)
    printf("the input string is %s\n", argv[i]);

    // copy args address
    for(i=0; i<argc; i++){
        string[i] = argv[i+1];
    }
//    add(string[1]); // when string quoted "", they be treated a total element, like : 1 2 "2 3" 4, that "2 3" is on element.

    // copy args contents
    for(i=0; i<argc-1; i++){
        strcpy(p_buf,argv[i+1]);
        p_buf = p_buf + strlen(p_buf) + 1; // pading whitespace
        p_buf[-1] = ' ';
    }
    p_buf[-1] = '\0';

    printf("buf is %s\n", buf);
    return 0;
}

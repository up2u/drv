#include <stdio.h>

int main()
{
    //      space   |2 | 3 |
    char msg[10] = "a  b   c";
    printf("original string is %s\n", msg);

    char *ptr = strtok(msg, " ");
    int i = 0;

    while(ptr != NULL){
        // go through
        ptr = strtok(NULL, " ");
    }
// we can see strtok will not change only change the 1st matched
    printf("now msg is :");
    while(i<10){
        printf("%02x", msg[i]);
        i++;
    }

    return 0;
}

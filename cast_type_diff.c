#include <stdio.h>

#define SIZE 5
short s_buf[SIZE] = 
{
    0x0000, // +0
    0x0001, 0xffff,  // 1, -1
    0x1000, 0x7fff //-32768, 32767
};


int main(int argc ,char *argv[])
{
    int i = 0,j = 0;
    int i1 = 0;
    short s1 = 0;
    short s2 = 0;
    
    for(i=0; i<SIZE; i++){
        s1 = s_buf[i];
        for(j=0; j<SIZE; j++){
            s2 = s_buf[j];
            i1 = (int)s1 + s2;
            printf("(int)%d[0x%x] + %d[0x%x] = %d[0x%x]\n",(int)s1,(int)s1, s2, s2, i1);
        }
    }
    return 0;
}

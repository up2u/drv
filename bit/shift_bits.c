#include <stdio.h>

int main(int argc, char *argv[])
{
    int negate1 = -1;
    int negate2 = -4;
    int negate3 = 0x80000000L;

    int shift_n1 = negate1 << 34;
    int shift_n2 = negate2 << 34;
    int shift_n3 = negate3 << 34;

    unsigned int pos1 = 7;
    unsigned int pos2 = 15;
    unsigned int pos3 = 0x80000000L;

    unsigned int s_pos1 = pos1 << 34;
    unsigned int s_pos2 = pos2 << 34;
    unsigned int s_pos3 = pos3 << 34;
    
    
    printf("negate1=%d[0x%08x], shift_n1=%d[0x%08x]\n", negate1,negate1, shift_n1,shift_n1);
    printf("negate2=%d[0x%08x], shift_n2=%d[0x%08x]\n", negate2,negate2, shift_n2,shift_n2);
    printf("negate3=%d[0x%08x], shift_n3=%d[0x%08x]\n", negate3,negate3, shift_n3,shift_n3);

    printf("snegate1=%d[0x%08x], shift_sn1=%d[0x%08x]\n", pos1,pos1, s_pos1, s_pos1);
    printf("snegate2=%d[0x%08x], shift_sn2=%d[0x%08x]\n", pos2,pos2, s_pos2, s_pos2);
    printf("snegate3=%d[0x%08x], shift_sn3=%d[0x%08x]\n", pos3,pos3, s_pos3, s_pos3);

    return 0;
}

#include <stdio.h>

int main()
{
  putchar('T');
  putchar('H');
  putchar('I');
  putchar('S');
  putchar('\b');
  putchar('N');
  //./a.out <-- not see 'S'
  //THIN[name@neptune cli]$

  // input file and use command: od to check
  FILE *fp = fopen("./backspace_log", "w");
  fputc('T',  fp);
  fputc('H',  fp);
  fputc('I',  fp);
  fputc('S',  fp);
  fputc('\b', fp);
  fputc('N',  fp);
  fputc('\b', fp); // check what is in file (last char)
  //1:
  // this is the result of file : backspace_log
  // NOTE: they still have 'S', and 'N'
  //od -a backspace_log
  //0000000   T   H   I   S  bs   N  bs
  //0000007
  // and size of byte is :
  // du -b backspace_log
  // 7 backspace_log

  //2 : cat backspace_log
  // THI[name@neptune cli]$

  fclose(fp);
  return 0;
}

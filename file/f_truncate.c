#include <stdio.h>
#include <stdlib.h>

#define BUF_SISE 200

int main(int argc, char *argv[])
{
	 FILE *flength = NULL;
	 FILE *fdata = NULL;
	 FILE *fintg = NULL;
	 int frame_num = 0;
	 int length = 0;
	 int value = 0;
	 int i = 0, j = 0;
	 int in_buf[BUF_SISE] = {'\0'};

	 fintg = fopen("/tmp/fintg.file", "r");
	 flength = fopen("/tmp/trflength.file", "w+");
	 fdata = fopen("/tmp/trfdata.file","w+");
	 
	 if(fread(&frame_num, 4, 1, fintg) != 1){
		  printf("fread frame_num failed \n");
		  exit(0);
	 }
	 for(i=0; i<frame_num; i++){
		  if(fread(&length, 4, 1, fintg) != 1){  // get the current frame length 
			   printf("fread length failed \n");
			   exit(0);
		  }
		  if(fwrite(&length, 4, 1, flength) != 1){ // restore to length file
			   printf("fwrite length to flength failed \n");
			   exit(0);
		  }
		  if(fread(in_buf, 4, length, fintg) != length){ // read lengths data to in_buf
			   printf("fread cont failed \n");
			   exit(0);
		  }
		  if(fwrite(in_buf, 4, length, fdata) != length){ // restore to data file
			   printf("fwrite in_buf data to failed \n");
			   exit(0);
		  }
	 }

	 fclose(flength);
	 fclose(fdata);
	 fclose(fintg);
	 return 0;
}

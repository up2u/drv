#include <stdio.h>
#include <stdlib.h>

#define FRAME_NUM 20
#define MAX_FRAME_LENGTH 10
#define FLAG_BIT   1

int main(int argc, char *argv[])
{
	 FILE *flength = NULL;
	 FILE *fdata = NULL;
	 FILE *fintg = NULL;
	 int value = 0;
	 int length = 0;
	 int frame_num = FRAME_NUM;
	 int i = 0, j = 0;

	 flength = fopen("/tmp/flength.file", "w+");
	 if(flength == NULL){
		  printf("fopen flength failed \n");
		  exit(0);
	 }
	 fdata = fopen("/tmp/fdata.file", "w+");
	 if(fdata == NULL){
		  printf("fopen fdata failed \n");
		  exit(0);
	 }
	 fintg = fopen("/tmp/fintg.file", "w+");
	 if(fintg == NULL){
		  printf("fopen fintg failed \n");
		  exit(0);
	 }
	 // firstly store frame_num to integrate file
	 if(fwrite(&frame_num, 4, 1, fintg) != 1){
		  printf("fwrite total frame_num to integrate file failed \n");
		  exit(0);
	 }
	 for(i=0; i<FRAME_NUM; i++){
		  length = rand()%MAX_FRAME_LENGTH;  // get this frame length
		  if(fwrite(&length, 4, 1, flength) != 1){  // store length to a single file
			   printf("fwrite length to single file failed\n");
			   exit(0);
		  }
		  if(fwrite(&length, 4, 1, fintg) != 1){  // store length to a integrate file 
			   printf("fwrite length to integrate file failed\n");
			   exit(0);
		  }

		  for(j=0; j<length; j++){
			   value = rand();               // get this frame data
			   if(fwrite(&value, 4, 1, fdata) != 1) { // store data to single file
					printf("fwrite value to single file failed \n");
					exit(0);
			   }
			   if(fwrite(&value, 4, 1, fintg) != 1){ // store data to integrate file
					printf("fwrite value to integrate file failed \n");
					exit(0);
			   }
		  }
	 }

	 fclose(flength);
	 fclose(fdata);
	 fclose(fintg);
	 return 0;
}

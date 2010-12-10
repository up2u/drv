#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void thread1(void)
{
	int j = 0;
	for(j=0; j<3; j++){
		printf("this is pthread. 1\n");	
		usleep(1000);
	}	
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
void thread2(void)
{
	int k = 0;
	for(k=0; k<4; k++){
		printf("this is pthread. 2\n");	
		usleep(10000);
	}	
}

/*-----------------------------------------------------------------------------
* Function: 
* Purpose: 
*         
* Parameters:
*         
* Return: 
*-----------------------------------------------------------------------------*/
int main()
{
	pthread_t id1;
	pthread_t id2;
	int i = 0;
	int ret = 0;
	ret = pthread_create(&id1, NULL, (void *)thread1, NULL);
	if(ret != 0){
		printf("create pthread error !\n");
		return -1;
	}
	ret = pthread_create(&id2, NULL, (void *)thread2, NULL);
	if(ret != 0){
		printf("create pthread error !\n");
		return -1;
	}
	for(i=0; i<2; i++){
		printf("time %d: this is the main process.\n", i);
	}
	pthread_join(id1, NULL);
	pthread_join(id2, NULL);

	return 0;	
}


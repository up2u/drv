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
void thread(void)
{
	int i = 0;
	for(i=0; i<3; i++){
		printf("this is a pthread.\n");	
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
int main()
{
	pthread_t id;
	int i = 0;
	int ret = 0;
	ret = pthread_create(&id, NULL, (void *)thread, NULL);
	if(ret != 0){
		printf("create pthread error !\n");
		return -1;
	}
	for(i=0; i<3; i++){
		printf("this is the main process.\n");
		pthread_join(id, NULL);
		return 0;	
	}
	return 0;	
}


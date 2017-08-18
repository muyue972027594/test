/***************************************************
文件名：zuoye1.c
功  能：一个线程读，一个线程写
版本号：0.0.1
***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>

int num[5] = {0};
sem_t sem_rd,sem_wr;


void *myread(void *arg)
{
	
	while(num[0] < 200)	
	{
		sem_wait(&sem_rd);
		printf("num[0] = %d,num[1] = %d\n",num[0],num[1]);
		sem_post(&sem_wr);
	}
	
	pthread_exit(NULL);

}


void *mywrite(void *arg)
{
	while(num[0] < 200)	
	{
		if(num[0] % 3 == 0)
		{
			sem_wait(&sem_wr);
			num[1]++;
			sem_post(&sem_rd);
		}
		num[0]++;
	}
	
	pthread_exit(NULL);
}


int main()
{
	pthread_t thread[2] = {0};
	int ret = 0;

	sem_init(&sem_rd,0,0);
	sem_init(&sem_wr,0,1);
	
	ret = pthread_create(&thread[0],NULL,myread,NULL);
	if(ret != 0)
	{
		printf("create myread error!\n");
		exit(-1);
	}

	
	ret = pthread_create(&thread[1],NULL,mywrite,NULL);
	if(ret != 0)
	{
		printf("create myread error!\n");
		exit(-1);
	}


	pthread_join(thread[0],NULL);
	pthread_join(thread[1],NULL);


	return 0;
}
















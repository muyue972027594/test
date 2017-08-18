/***************************************************
文件名：test3.c
功  能：一个线程读，一个线程写
版本号：0.0.1
***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int num[5] = {0};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void *myread(void *arg)
{
	
	while(num[0] < 200)	
	{
		if(num[2] == 1)
		{
	//		pthread_mutex_lock(&mutex);

			num[2] = 0;
			printf("num[0] = %d,num[1] = %d\n",num[0],num[1]);

	//		pthread_mutex_unlock(&mutex);
		}
	}
	
	pthread_exit(NULL);

}


void *mywrite(void *arg)
{
	while(num[0] < 200)	
	{
		if(num[2] == 0)
		{
	//		pthread_mutex_lock(&mutex);

			num[0]++;
			if(num[0] % 3 == 0)
			{
				num[1]++;num[2] = 1;
			}

	//		pthread_mutex_unlock(&mutex);
		}
	}
	
	pthread_exit(NULL);
}


int main()
{
	pthread_t thread[2] = {0};
	int ret = 0;

	
	
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

	pthread_mutex_destroy(&mutex);

	return 0;
}
















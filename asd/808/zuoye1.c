/*********************************************
文件名：zuoye1.c
功  能：两个线程对一全局变量实现加一操作
版本号：0.0.1
***********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int count = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void * add_one(void * arg)
{
	for(int i = 0;i < 15;i++)
	{
		pthread_mutex_lock(&mutex);
		count += 1;
		printf("子线程 - count = %d\n",count);
		pthread_mutex_unlock(&mutex);
		
//		sleep(1);
	}
}

int main()
{
	pthread_t thread = 0;
	int ret = 0;

	ret = pthread_create(&thread,NULL,add_one,NULL);
	if(ret != 0)
	{
		printf("thread create error!\n");
		exit(-1);
	}

	for(int i = 0;i < 15;i++)
	{
		pthread_mutex_lock(&mutex);
		count += 1;
		printf("主线程 - count = %d\n",count);
		pthread_mutex_unlock(&mutex);
//		sleep(1);
	}


	pthread_join(thread,NULL);

	pthread_mutex_destory(&mutex);

	return 0;
}









/***************************************************
文件名：zuoye3.c
功  能：一个线程读，一个线程写
版本号：0.0.1
***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int num[5] = {0};
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond1 = PTHREAD_COND_INITIALIZER;
pthread_cond_t cond2 = PTHREAD_COND_INITIALIZER;


void *myread(void *arg)
{
	
	while(num[0] < 200)	
	{
		pthread_mutex_lock(&mutex);

		if(num[2] == 0)
			pthread_cond_wait(&cond1,&mutex);
		
		num[2] = 0;
		printf("num[0] = %d,num[1] = %d\n",num[0],num[1]);
		
		pthread_cond_signal(&cond2);
		pthread_mutex_unlock(&mutex);
		sleep(0.5);
	}
	
	pthread_exit(NULL);

}


void *mywrite(void *arg)
{
	while(num[0] < 200)	
	{
		pthread_mutex_lock(&mutex);
		if(num[2] == 1)
			pthread_cond_wait(&cond2,&mutex);

		num[0]++;
		if(num[0] % 3 == 0)
		{
			num[1]++;num[2] = 1;
			if(pthread_cond_signal(&cond1) != 0)
				printf("cond signal error!\n");
		}

		pthread_mutex_unlock(&mutex);
//		sleep(1);
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
	pthread_cond_destroy(&cond1);
	pthread_cond_destroy(&cond2);

	return 0;
}
















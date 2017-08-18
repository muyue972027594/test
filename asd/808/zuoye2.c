/*********************************************
文件名：zuoye2.c
功  能：四个窗口卖100张票
版本号：0.0.1
***********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int count = 100;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;


void * sell(void * arg)
{
	char *ch = (char *)arg;
	while(count > 0)
	{
		pthread_mutex_lock(&mutex);
		if(count > 0)
		{
			printf("%s  票号%d\n",ch,count);
			count -= 1;
		}
		pthread_mutex_unlock(&mutex);
		
		sleep(0.5);
	}
}

int main()
{
	pthread_t thread[4] = {0};
	int ret = 0;
	char * ch[4] = {"窗口1出票","窗口2出票","窗口3出票","窗口4出票"};

	for(int i = 0;i < 4;i++)
	{
		ret = pthread_create(&thread[i],NULL,sell,ch[i]);
		if(ret != 0)
		{
			printf("thread create error!\n");
			exit(-1);
		}
	}


	for(int i = 0;i < 4;i++)
		pthread_join(thread[i],NULL);

	return 0;
}









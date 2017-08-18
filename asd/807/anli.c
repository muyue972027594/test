/************************************************************
文件名：anli.c
功  能：产生子线程，传参,取返回值
版本号：0.0.1
*************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>

int count = 0;

void *fun(void *data)
{
	int *num = &count; 
	*num = strlen(data);

	printf("count = %d\n",count);
	return (void *)num;
}

int main()
{
	pthread_t thread = 0;
	int ret = 0;
	int count = 0;
	char ch[10] = "123456789";	
	int * num = &count;
	
	ret = pthread_create(&thread,NULL,fun,ch);

	if(ret != 0)
	{
		printf("thread create error!\n");
		exit(-1);
	}
	
	pthread_join(thread,(void **)&num);

	printf("num = %d\n",*num);

	return 0;
}






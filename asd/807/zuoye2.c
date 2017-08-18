/*******************************************************
文件名：zuoye2.c
功  能：多线程操作一个文件，分别统计字数
版本号：0.0.1
********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>

typedef struct filecount
{
	int file1;
	int count;
}STFC;


void *count1(void *data)
{
	char buf[100] = {0};
	int count = 0,i = 0;
	FILE * fd ;
	STFC *data1 = (STFC *)data;
	
	fd = fopen("./test.txt","r");

    if(fd < 0)
    {
        perror("file open error");
        pthread_exit(NULL);
    }

	while(fread(buf,1,99,fd))
	{
		i = 0;
		while(buf[i] != 0)
		{
			if((buf[i] >= 'a' && buf[i] <= 'z') 
				|| (buf[i] >= 'A' && buf[i] <= 'Z'))
			{
				count++;
			}
			i++;
		}
		memset(buf,0,100);
	}

	data1->count = count;

	fclose(fd);
}


void *count2(void *data)
{
	char buf[100] = {0};
	int count = 0,i = 0;
	FILE * fd = 0;
	STFC *data1 = (STFC *)data;
	
	fd = fopen("./test.txt","r");

    if(fd < 0)
    {
        perror("file open error");
        pthread_exit(NULL);
    }

	while(fread(buf,1,99,fd))
	{
		i = 0;
		while(buf[i] != 0)
		{
			if((buf[i] >= 33 && buf[i] <= 47) 
				|| (buf[i] >= 58 && buf[i] <= 64)
				|| (buf[i] >= 91 && buf[i] <= 96)
				|| (buf[i] >= 123 && buf[i] <= 127))
			{
				count++;
			}
			i++;
		}
		memset(buf,0,100);
	}

	data1->count = count;
	
	fclose(fd);
	
}


void *count3(void *data)
{
	
	char buf[100] = {0};
	int count = 0,i = 0;
	FILE * fd = 0;
	STFC *data1 = (STFC *)data;
	
	fd = fopen("./test.txt","r");

    if(fd < 0)
    {
        perror("file open error");
        pthread_exit(NULL);
    }

	while(fread(buf,1,99,fd))
	{
		i = 0;
		while(buf[i] != 0)
		{
			if(buf[i] < 0)
			{
				count++;
			}
			i++;
		}
		memset(buf,0,100);
	}

	data1->count = count/3;

	fclose(fd);

}


int main()
{
	STFC num[3];
	pthread_t thread[3] = {0};
	int ret = 0;

	memset(num,0,3 * sizeof(STFC));


	ret = pthread_create(&thread[0],NULL,count1,&num[0]);
	if(ret != 0)
	{
		printf("thread create 1 error!\n");
		exit(-1);
	}
	

	ret = pthread_create(&thread[1],NULL,count2,&num[1]);
	if(ret != 0)
	{
		printf("thread create 2 error!\n");
		exit(-1);
	}
	

	ret = pthread_create(&thread[2],NULL,count3,&num[2]);
	if(ret != 0)
	{
		printf("thread create 3 error!\n");
		exit(-1);
	}
	
	for(int i = 0;i < 3;i++)
		pthread_join(thread[i],NULL);


	printf("字母个数为  %d  \n",num[0].count);
	printf("标点个数为  %d  \n",num[1].count);
	printf("汉字个数为  %d  \n",num[2].count);










}









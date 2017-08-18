/******************************************************
文件名：zuoye2_.c
功  能：父子进程写入一个文件
版本号：0.0.1
******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<time.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main()
{
	pid_t pid;
	int fd,wr_d,status;
	time_t timep;

	if(fd < 0)
	{
		perror("open error");
		exit (-1) ;
	}	

	pid = fork();
	if(pid > 0)
	{
	fd = open("time1.txt",O_WRONLY|O_CREAT,0644);
		for(int i = 0;i < 5;i++)
		{
			time(&timep);
			wr_d = write(fd,ctime(&timep),strlen(ctime(&timep)));
			sleep(3);
		}
	close(fd);

		if(WIFEXITED(status))
		{
			printf("nomal exit!\n");
		}
	}
	else if(pid == 0)
	{
	fd = open("time.txt",O_WRONLY|O_CREAT,0644);
		for(int j = 0;j < 5;j++)
		{
			time(&timep);
        	wr_d = write(fd,ctime(&timep),strlen(ctime(&timep)));
        	sleep(2);
		}
	close(fd);
		
		exit (0);
	}
	else 
	{
		perror("Fork error");
		exit (-1);
	}

	exit (0);
}





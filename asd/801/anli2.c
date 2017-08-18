#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	pid_t data1,data2;
	
	data1 = fork();
	if(data1 > 0)
	{
		data2 = fork();
		if(data2 > 0)
		{
			printf("父进程号  %d \n",getpid());
		}
		else if(data2 == 0)
		{
			printf("子进程号2  %d \n",getpid());
		}
		else
			perror("fork 2 error");
	}
	else if(data1 == 0)
	{
		printf("子进程号1  %d \n",getpid());
	}
	else
	{
		perror("fork error");
	}
}

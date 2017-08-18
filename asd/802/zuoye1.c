/******************************************************
文件名：zuoye1.c
功  能：父子进程同时复制文件（头文件、调用copyfile.c文件）
版本号：0.0.1
******************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include"wenjian.h"

int main()
{
	pid_t pid;
	int status;

	pid = fork();
	if(pid > 0)
	{
		printf("Father PID  %d\n",getpid());
		copyfile("file.txt","newfile.txt");
	}
	else if(pid == 0)
	{
		printf("Child PID  %d\n",getpid());
		copyfile("cpfile.txt","newcpfile.txt");
		exit(20);
	}
	else
	{
		perror("fork error");
		exit(0);
	}
}

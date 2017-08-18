/****************************************
文件名：anli1.c
功  能：父进程等待子进程结束，规定时间内没有结束则强制杀死子进程
版本号：0.0.1
***************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<signal.h>


void jieshu(int x)
{
	kill(0,9);
}

int main()
{
	pid_t pid,buf;
	int fd[2];

	if(pipe(fd) < 0)
	{
		perror("pipe error");
		exit(-1);
	}

	pid = fork();
	if(pid > 0)
	{
		close(fd[1]);

//		signal(14,jieshu);
		alarm(15);

		if(read(fd[0],&buf,20) < 0)
		{
			perror("read error");
			exit(-1);
		}
		printf("子进程编号为%d\n",buf);
		close(fd[0]);
		pause();
		kill(pid,9);

	}else if(pid == 0)
	{

		close(fd[0]);
		buf = getpid();

		sleep(20);

		if(write(fd[1],&buf,20) < 0)
		{
			perror("write error");
			exit(-1);
		}
		close(fd[1]);

	}else 
	{
		perror("fork error");
		exit(-1);
	}

	return 0;
}




















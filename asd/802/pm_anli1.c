/********************************************88
文件名：pm_anli1.c
功  能：无名管道，父子进程通信
版本号：0.0.1
***********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	int fd[2] = {0};
	char buf[20] = {0};

	if(pipe(fd) < 0)
	{
		perror("pipe error");
		exit(-1);
	}

	pid = fork();
	if(pid > 0)
	{
		write(fd[1],"Father write",15);
		sleep(2);
		read(fd[0],buf,20);
		printf("%s\n",buf);
		close(fd[0]);
		close(fd[1]);
	}
	else if(pid == 0)
    {
        read(fd[0],buf,20);
        sleep(2);
        write(fd[1],"Child write",15);
		printf("%s\n",buf);
        close(fd[0]);
        close(fd[1]);
    }
	else
	{
		perror("Fork error");
		exit(-1);
	}
}




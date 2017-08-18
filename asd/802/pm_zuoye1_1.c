/********************************************88
文件名：pm_zuoye1_1.c
功  能：无名管道，父子进程聊天
版本号：0.0.1
***********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main()
{
	pid_t pid;
	int fd1[2] = {0};
	int fd2[2] = {0};
	char buf[20] = {0};

	if(pipe(fd1) < 0)
	{
		perror("pipe1 error");
		exit(-1);
	}
	if(pipe(fd2) < 0)
	{
		perror("pipe2 error");
		exit(-1);
	}

	pid = fork();
	if(pid > 0)
	{
		close(fd1[0]);
		close(fd2[1]);
		for(int i = 0;i < 5;i++)
		{	
			printf("Father>>");
			fgets(buf,20,stdin);
			write(fd1[1],buf,strlen(buf));
			memset(buf,0,sizeof(buf));
			sleep(1);
			read(fd2[0],buf,20);
			printf("\n\n父  端\nChild:%s\n",buf);
			memset(buf,0,sizeof(buf));
		}
		close(fd1[1]);
		close(fd2[0]);
	}
	else if(pid == 0)
    {
		close(fd1[1]);
        close(fd2[0]);
        for(int j = 0;j < 5;j++)
        {   
			read(fd1[0],buf,20);
            printf("\n\n子  端\nFather:%s\n",buf);
            memset(buf,0,sizeof(buf));
            sleep(1);
			printf("Child>>");
			fgets(buf,20,stdin);
            write(fd2[1],buf,strlen(buf));
            memset(buf,0,sizeof(buf));
        }
        close(fd1[0]);
        close(fd2[1]);
    }
	else
	{
		perror("Fork error");
		exit(-1);
	}
}




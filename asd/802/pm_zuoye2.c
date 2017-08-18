/*****************************************************
文件名：pm_zuoye2.c
功  能：通过有名管道文件复制文件(pm_zuoye2.c 与 pm_zuoye2_2.c配合)
版本号：0.0.1
&***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd1,fd2;
	char buf[32] = {0};

	fd1 = open("./path",O_WRONLY);
	if(fd1 < 0)
	{
		perror("open1 error");
		exit(-1);
	}
	
	fd2 = open("./file.txt",O_RDONLY);
	if(fd2 < 0)
	{
        perror("open2 error");
        exit(-1);
    }

	while(read(fd2,buf,32))
	{
		if(write(fd1,buf,strlen(buf)) < 0)
		{
			perror("write error");
			exit(-1);
		}
		memset(buf,0,32);
	}	

	close(fd1);
	close(fd2);

	return 0;
}

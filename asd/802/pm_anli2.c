/*********************************************
文件名：pm_anli2.c
功  能：有名管道实现两个进程通信(pm_anli2.c 与 pm_anli2_2.c配合)
版本号：0.0.1
***********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd;

/*	if(mkfifo("./path",0644) < 0)
	{
		perror("mkfifo error");
		exit(-1);
	}
*/
	fd = open("./path",O_WRONLY);
	if(fd < 0)
	{
		perror("open error");
		exit(-1);
	}

	if(write(fd,"ni hao",10) < 0)
	{
		perror("write error");
		exit(-1);
	}

	close(fd);

	return 0;
}











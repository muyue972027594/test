/**************************************************
文件名：anli1.c
功  能：显示指定文件最后修改时间
版本号：0.0.1
***************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<time.h>
int main(int argc,char *argv[])
{
	int data=0,i;
	char time[50]={0},*time1;
	struct stat buf;
	time1=time;

/*拿到时间并转换*/
	data=stat(argv[1],&buf);
	if(data<0)
	{
		perror("stat");
		return -1;
	}
	time1=ctime(&buf.st_mtime);

/*输出时间*/
	printf("%s最后修改时间为",argv[1]);
	for(i=4;i<20;i++)
		printf("%c",time1[i]);
//	printf("%d",strlen(time));
	printf("\n");
}

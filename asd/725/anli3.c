/**************************************
文件名：anli3.c
功  能：将文件file.txt复制到cpfile.txt
版本号：0.0.1
**************************************/
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int fd1=0,fd2=0,rd_data=0,wr_data=0;
	char buf[20]={0};
	
	/*打开两个文件*/
	fd1=open("file.txt",O_RDONLY);	
	if(fd1<0)
	{
		perror("file.txt open error");
		return -1;
	}	
	fd2=open("cpfile.txt",O_WRONLY);	
	if(fd2<0)
	{
		perror("cpfile.txt open error");
		return -1;
	}	

	/*循环读取并写入*/
	while(1)
    {
        rd_data=read(fd1,buf,20);
		if(rd_data<0)
		{
			perror("file.txt read error");
			return -1;
		}
		if(rd_data==0) break;
		wr_data=write(fd2,buf,20);
		if(wr_data<0)
		{
			perror("cpfile.txt read error");
			return -1;
		}
//		buf[20]={0};
		memset(buf,0,strlen(buf));
    }

	/*关闭文件*/
	close(fd1);
	close(fd2);
	return 0;
}

/**************************************
文件名：copyfile.c
功  能：将一个文件的内容复制到另一个新建文件中
版本号：0.0.1
**************************************/
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int copyfile(char argv1[20],char argv2[20])
{
    int fd1=0,fd2=0,rd_data=0,wr_data=0;
    char buf[20]={0};

    /*打开两个文件*/
    fd1=open(argv1,O_RDONLY);
    if(fd1<0)
    {
        perror("old file open error");
        return -1;
    }
    fd2=open(argv2,O_WRONLY|O_CREAT,0644);
    if(fd2<0)
    {
        perror("new file open error");
        return -1;
    }

    /*循环读取并写入*/
    while(1)
    {
        rd_data=read(fd1,buf,20);
        if(rd_data<0)
        {
            perror("old file read error");
            return -1;
        }
        if(rd_data==0) break;
        wr_data=write(fd2,buf,20);
        if(wr_data<0)
        {
            perror("new file write error");
            return -1;
        }
        memset(buf,0,strlen(buf));
    }

    /*关闭文件*/
    close(fd1);
    close(fd2);
    return 0;
}


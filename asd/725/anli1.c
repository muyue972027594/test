/*************************************************
文件名：anli1.c
功  能：判断文件是否存在
版本号：0.0.1
************************************************/
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
	if(access("/home/ubuntu/test/file.txt",0)<0)
		printf("Can not find this file!\n");
	else
		printf("This file can be found!\n");
}

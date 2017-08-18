/************************************************
文件名：filesend.c
功  能：网络传输（发送文件），与filerecv.c相互传输
版本号：0.0.1
***********************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<fcntl.h>

#define PORT 6660


int main()
{
	struct sockaddr_in my_addr,to_addr;
	char buf1[64] = {0};
	char buf2[70] = {0};
	int sock = 0,ret = 0;
	int size = sizeof(to_addr);
	int fd = 0,count = 0,count1 = 0;

	memset(&my_addr,0,sizeof(my_addr));
	memset(&to_addr,0,sizeof(to_addr));

	to_addr.sin_family = AF_INET;
	to_addr.sin_port = PORT;
	to_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


	sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock < 0)
	{
		perror("socket error");
		exit(-1);
	}
	
	fd = open("./Aash Clsr .mp3",O_RDONLY);
	if(fd < 0)
	{
		perror("open error");
		exit(-1);
	}
	
	while(1)
	{
		memset(buf1,0,sizeof(buf1));
		memset(buf2,0,sizeof(buf2));

		ret = read(fd,buf1,sizeof(buf1) - 1);
		if(ret < 0)
		{
			perror("read error");
			exit(-1);
		}
		
		count += ret;

		if(ret == sizeof(buf1) - 1) 
			buf2[0] = '1';
		else
			buf2[0] = '2';
		strcat(buf2,buf1);

		ret = sendto(sock,buf2,sizeof(buf2),0,(struct sockaddr*)&to_addr,size);
		if(ret < 0)
		{
			perror("sendto error");
			exit(-1);
		}
		
		count1 += ret;

		if(buf2[0] == '2') break;
	
	}

	printf("读取%d，发送%d\n",count,count1);

	close(fd);
	close(sock);


	return 0;
}














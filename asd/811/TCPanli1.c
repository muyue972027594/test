/******************************************************
文件名：TCPanli1.c
功  能：
版本号：0.0.1
*********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


#define PORT 6868

int main()
{
	struct sockaddr_in to_addr;
	int sock = 0;
	int ret = 0;
	
	to_addr.sin_family = AF_INET;
	to_addr.sin_port = htons(PORT);
	to_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("socket error");
		exit(-1);
	}

	ret = connect(sock,(struct sockaddr*)&to_addr,sizeof(to_addr));
	if(ret < 0)
	{
		perror("connect error");
		exit(-1);
	}	

	ret = send(sock,"hello",10,0);
	if(ret < 0)
	{
		perror("send error");
		exit(-1);
	}

	close(sock);
}





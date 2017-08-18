/************************************************
文件名：anli1.c
功  能：网络传输（先发后收），与anli2.c相互传输
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

#define PORT 6660


int main()
{
	struct sockaddr_in to_addr;
	char buf[30] = {0};
	int sock = 0,ret = 0;

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

	while(1)
	{
	
		printf("请输入信息>>>");
		fgets(buf,sizeof(buf) - 1,stdin);

		ret = sendto(sock,buf,strlen(buf),0,(struct sockaddr*)&to_addr,sizeof(to_addr));
		if(ret < 0)
		{
			perror("sendto error");
			exit(-1);
		}

		if(strcmp(buf,"0\n") == 0) break;

		memset(buf,0,sizeof(buf));

		ret = recvfrom(sock,buf,sizeof(buf) - 1,0,NULL,NULL);
		if(ret < 0)
		{
			perror("recvfrom error");
			exit(-1);
		}

		puts(buf);
	
		if(strcmp(buf,"0\n") == 0) break;
	}
	close(sock);


	return 0;
}














/************************************************
文件名：anli2.c
功  能：网络传输（先收后发），与anli1.c相互传输
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
	struct sockaddr_in my_addr,from_addr;
	char buf[30] = {0};
	int sock = 0,ret = 0;
	int size = sizeof(from_addr);

	memset(&my_addr,0,sizeof(my_addr));
	memset(&from_addr,0,sizeof(from_addr));

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = PORT;
	my_addr.sin_addr.s_addr = INADDR_ANY;




	sock = socket(AF_INET,SOCK_DGRAM,0);
	if(sock < 0)
	{
		perror("socket error");
		exit(-1);
	}

	ret = bind(sock,(struct sockaddr*)&my_addr,sizeof(my_addr));
	if(ret < 0)
	{
		perror("bind error");
		exit(-1);
	}
	
	while(1)
	{

		ret = recvfrom(sock,buf,sizeof(buf) - 1,0,
							(struct sockaddr*)&from_addr,&size);
		if(ret < 0)
		{
			perror("recvfrom error");
			exit(-1);
		}
	

		puts(buf);
	
		if(strcmp(buf,"0\n") == 0) break;

		memset(buf,0,sizeof(buf));
		printf("请输入信息>>>");
		fgets(buf,sizeof(buf) - 1,stdin);

//		ret = sendto(sock,buf,sizeof(buf),0,(struct sockaddr*)&from_addr,size);
		ret = sendto(sock,buf,sizeof(buf),0,NULL,size);
		if(ret < 0)
		{
			perror("sendto error");
			exit(-1);
		}

		if(strcmp(buf,"0\n") == 0) break;
	}

	close(sock);


	return 0;
}














/******************************************************
文件名：recvTCP.c
功  能：作为客户端登录服务器
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
#include<fcntl.h>

struct shuju
{
	int ret;
	char buf[64];
};

#define PORT 6868

int main()
{
	struct sockaddr_in to_addr;
	int sock = 0;
	int ret = 0;
	char order[80] = {0};
	struct shuju data;
	char name[12] = {0};
	char password[15] = {0};
	int fd = 0;
	
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

	printf("**请输入用户名**\n>>>>>");
	scanf("%s",name);
	printf("**请输入密码**\n>>>>>");
	scanf("%s",password);

	sprintf(order,"$$%s,%s##",name,password);

	ret = send(sock,order,sizeof(order),0);
	if(ret < 0)
	{
		perror("send error");
		exit(-1);
	}

	fd = open("./down.mp3",O_WRONLY|O_CREAT,0777);
	if(fd < 0)
	{
		perror("open error");
		exit(-1);
	}

	while(1)
	{
		memset(&data,0,sizeof(data));
		ret = recv(sock,&data,sizeof(data),0);
		if(ret < 0)
		{
			perror("recv error");
			exit(-1);
		}

		if(data.ret == 0) 
		{
			puts(data.buf);
			break;
		}
		ret = write(fd,data.buf,data.ret);
		if(ret < 0)
		{
			perror("write error");
			exit(-1);
		}

		
	}

	close(sock);
	close(fd);
}

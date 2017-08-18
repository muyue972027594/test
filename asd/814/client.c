/******************************************************
文件名：client.c
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


#define TOPORT htons(6660)
#define TOIP inet_addr("127.0.0.1")


int main()
{
	struct sockaddr_in to_addr;
	int sock = 0;
	int ret = 0;
	char order[80] = {0};
	char data[80] = {0};
	char name[12] = {0};
	char password[15] = {0};
	
	to_addr.sin_family = AF_INET;
	to_addr.sin_port = TOPORT;
	to_addr.sin_addr.s_addr = TOIP;

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
//while(1)
{


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

	ret = recv(sock,data,sizeof(data),0);
	if(ret < 0)
	{
		perror("recv error");
		exit(-1);
	}

	puts(data);

	if((data[0] == '$' && data[1] =='$') 
		&& (data[strlen(data) - 1] == '#' && data[strlen(data) - 2] == '#'))
	{
		printf("%s\n",strtok(data,"$#,"));
		printf("%s\n",strtok(NULL,"#$,"));
	}
	else
		printf("data lost!\n");




}



	close(sock);
}





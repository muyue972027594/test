/****************************************************8
文件名：anli1.c
功  能：
版本号：0.0.1
*****************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<pthread.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


#define MYPORT htons(6660)
#define MYIP inet_addr("127.0.0.1")

void *fun(void *arg)
{
	int ret = 0;
	int cl_sock = *(int *)arg;
	char buf[64] = {0};
	char name[20] = {0},password[20] = {0};


	memset(buf,0,sizeof(buf));
	ret = recv(cl_sock,buf,sizeof(buf),0);
	if(ret < 0)
	{
		perror("recv error");
		exit(-1);
	}

	if((buf[0] == '$' && buf[1] =='$') 
		&& (buf[strlen(buf) - 1] == '#' && buf[strlen(buf) - 2] == '#'))
	{
		sprintf(name,"%s",strtok(buf,"#$,"));
		sprintf(password,"%s",strtok(NULL,"#$,"));

		printf("用户名：%s\n密码：%s\n",name,password);
	}
	else
		printf("data lost!\n");

	memset(buf,0,sizeof(buf));

	if(strcmp(password,"123456") == 0)
		sprintf(buf,"$$普通用户,登录成功！##");
	else
		sprintf(buf,"$$ERROR,用户名密码错误##");

	ret = send(cl_sock,buf,sizeof(buf),0);
	if(ret < 0)
	{
		perror("send error");
		exit(-1);
	}

	close(cl_sock);

}

int main(int argc,char* argv[])
{
	struct sockaddr_in my_addr,cl_addr[5];
	int ret = 0;
	int sock = 0,cl_sock[5] = {0};
	int size = sizeof(cl_addr[0]);

	fd_set recv_set;


	memset(&my_addr,0,sizeof(my_addr));
	for(int i = 0;i < 5;i++)
		memset(&cl_addr[i],0,sizeof(cl_addr[i]));

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = MYPORT;
	my_addr.sin_addr.s_addr = MYIP;

	sock = socket(AF_INET,SOCK_STREAM,0);
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

	ret = listen(sock,5);
	if(ret < 0)
	{
		perror("listen error");
		exit(-1);
	}

	while(1)
	{
		cl_sock[0] = accept(sock,(struct sockaddr *)&cl_addr[0],&size);
		if(cl_sock[0] < 0)
		{
			perror("accept error");
			exit(-1);
		}

		fun(&cl_sock[0]);

	}

	close(sock);

}
















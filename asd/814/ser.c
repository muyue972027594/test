/****************************************************8
文件名：ser.c
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
	int *cl_sock = (int *)arg;
	char buf[64] = {0};
	char name[20] = {0},password[20] = {0};


	memset(buf,0,sizeof(buf));
	ret = recv(*cl_sock,buf,sizeof(buf),0);
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

	ret = send(*cl_sock,buf,sizeof(buf),0);
	if(ret < 0)
	{
		perror("send error");
		exit(-1);
	}

	close(*cl_sock);
	*cl_sock = 0;

}

int main(int argc,char* argv[])
{
	struct sockaddr_in my_addr,cl_addr[5];
	int ret = 0;
	int sock = 0,cl_sock[5] = {0};
	int size = sizeof(cl_addr[0]);
	int i = 0,j = 0;

	fd_set recv_set;
	int maxfd = 0;


	memset(&my_addr,0,sizeof(my_addr));
	for(i = 0;i < 5;i++)
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

		maxfd = sock;
	while(1)
	{
		FD_ZERO(&recv_set);		
		FD_SET(sock,&recv_set);

		for(i = 0;i < 5;i++)
			if(cl_sock[i] != 0)
				FD_SET(cl_sock[i],&recv_set);

		ret = select(maxfd + 1,&recv_set,NULL,NULL,NULL);
		if(ret < 0)
		{
			perror("select error");
			exit(-1);
		}
 

		if(FD_ISSET(sock,&recv_set))
		{
			cl_sock[j] = accept(sock,(struct sockaddr *)&cl_addr[j],&size);
			if(cl_sock[j] < 0)
			{
				perror("accept error");
				exit(-1);
			}
			if(maxfd < cl_sock[j])
				maxfd = cl_sock[j];
			j++;
		}

		for(i = 0;i < 5;i++)
		{
			if(FD_ISSET(cl_sock[i],&recv_set))
			{
				fun(&cl_sock[i]);
				FD_CLR(cl_sock[i],&recv_set);
			}
		}
	}

	close(sock);

}
















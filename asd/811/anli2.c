/************************************************
文件名：anli2.c
功  能：网络传输（先发后收），与anli1.c相互传输
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
#include<pthread.h>

typedef struct mynet
{
	struct sockaddr_in addr;
	int sock;
}MYNET;

#define MYPORT 6660
#define FMPORT 6060

void *mysend(void *arg)
{

	MYNET *send_p = (MYNET *)arg;
	char buf[32] = {0};
	int ret = 0;

	while(1)
	{
		memset(&buf,0,sizeof(buf));

		printf("\n请输入>>>");
		fgets(buf,sizeof(buf) - 1,stdin);

		ret = sendto(send_p->sock,buf,strlen(buf),0,
					(struct sockaddr*)&send_p->addr,sizeof(send_p->addr));
		if(ret < 0)
		{
			perror("sendto error");
			pthread_exit(NULL);
		}

		if(strcmp(buf,"0\n") == 0)
		{
			printf("\n结束输入，只可获取！\n");
			break;
		}
	}

	pthread_exit(NULL);
}


void *myrecv(void *arg)
{

	MYNET *recv_p = (MYNET *)arg;
	char buf[32] = {0};
	int ret = 0;
	int size = sizeof(recv_p->addr);

	while(1)
	{
		memset(buf,0,sizeof(buf));

		ret = recvfrom(recv_p->sock,buf,sizeof(buf) - 1,0,
						(struct sockaddr*)&recv_p->addr,&size);
		if(ret < 0)
		{
			perror("recvfrom error");
			pthread_exit(NULL);
		}
	
		printf("\n获取到:::");
		puts(buf);
	
		if(strcmp(buf,"0\n") == 0)
		{
			printf("\n对方已结束输入，不可获取！\n");
			break;
		}
	}

	pthread_exit(NULL);
}


int main()
{

	MYNET data;
	int ret = 0;
	pthread_t thread[2] = {0};
	struct sockaddr_in myaddr;

	memset(&data,0,sizeof(data));

	data.addr.sin_family = AF_INET;
	data.addr.sin_port = htons(FMPORT);
	data.addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	memset(&myaddr,0,sizeof(myaddr));

	myaddr.sin_family = AF_INET;
	myaddr.sin_port = htons(MYPORT);
	myaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	data.sock = socket(AF_INET,SOCK_DGRAM,0);
	if(data.sock < 0)
	{
		perror("socket error");
		exit(-1);
	}

	ret = bind(data.sock,(struct sockaddr*)&myaddr,sizeof(myaddr));
	if(ret < 0)
	{
		perror("bind error");
		exit(-1);
	}

	ret = pthread_create(&thread[0],NULL,mysend,&data);
	if(ret != 0)
	{
		printf("pthread create error!");
		exit(-1);
	}

	ret = pthread_create(&thread[1],NULL,myrecv,&data);
	if(ret != 0)
	{
		printf("pthread create error!");
		exit(-1);
	}

	pthread_join(thread[0],NULL);	
	pthread_join(thread[1],NULL);	


	close(data.sock);


	return 0;
}














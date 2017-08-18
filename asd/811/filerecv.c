/************************************************
文件名：filerecv.c
功  能：网络传输（接收文件），与filesend.c相互传输
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
	struct sockaddr_in my_addr;
	char buf1[64] = {0};
	char buf2[70] = {0};
	int sock = 0,ret = 0;
	int fd = 0,count = 0,count1 = 0;

	memset(&my_addr,0,sizeof(my_addr));
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = PORT;
	my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");


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

	fd = open("./down.mp3",O_WRONLY|O_CREAT,0777);
	if(fd < 0)
	{
		perror("open error");
		exit(-1);
	}

	while(1)
	{
		memset(buf1,0,sizeof(buf1));
		memset(buf2,0,sizeof(buf2));

		ret = recvfrom(sock,buf2,sizeof(buf2),0,NULL,NULL);
		if(ret < 0)
		{
			perror("recvfrom error");
			exit(-1);
		}

		count1 += ret;

		if(buf2[0] == '1') 
		{

//			ret = write(fd,buf2 + 1,strlen(buf2) - 1);
			ret = write(fd,buf2 + 1,sizeof(buf1) - 1);
			if(ret < 0)
			{
				perror("write error");
				exit(-1);
			}
			count += ret;
		}
		if(buf2[0] == '2') 
		{

			ret = write(fd,buf2 + 1,strlen(buf2) - 1);
			if(ret < 0)
			{
				perror("write error");
				exit(-1);
			}
			count += ret;
			break;
		}
		
		

		
	}

	printf("接收%d,写入%d\n",count1,count);

	close(fd);
	close(sock);


	return 0;
}














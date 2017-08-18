/******************************************************
文件名：sendTCP.c
功  能：作为服务器接收数据并作出应答
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

#define PORT 6868

struct shuju
{
	int ret;
	char buf[64];
};

int main()
{
	struct sockaddr_in from_addr,my_addr;
	int sock = 0,TOsock = 0;
	int ret = 0;
	char buf[64] = {0};
	struct shuju data;
	char name[12] = {0};
	char password[15] = {0};
	int i = 0,j = 0;
	int fd = 0;

	int size = sizeof(from_addr);
	
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(PORT);
	my_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

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

	TOsock = accept(sock,(struct sockaddr*)&from_addr,&size);
	if(TOsock < 0)
	{
		perror("accept error");
		exit(-1);
	}


	
	ret = recv(TOsock,buf,sizeof(buf),0);
	if(ret < 0)
	{
		perror("recv error");
		exit(-1);
	}
	
	if((buf[0] == '$' && buf[1] =='$')
        && (buf[strlen(buf) - 1] == '#' && buf[strlen(buf) - 2] == '#'))
    {
		sprintf(name,"%s",strtok(buf,"$#,")); 
		sprintf(password,"%s",strtok(NULL,"$#,"));
    }

	if(strcmp(password,"123456") == 0)
	{
		fd = open("./1122.mp3",O_RDONLY);

		while(1)
		{
			memset(&data,0,sizeof(data));
			
			ret = read(fd,data.buf,sizeof(data.buf) - 1);
			
			data.ret = ret;
			if(data.ret == 0)
			{
				sprintf(data.buf,"文件已下载完成！");	
				break;
			}
			ret = send(TOsock,&data,sizeof(data),0);
		
		}
		
		close(fd);
	}	
	else
		sprintf(data.buf,"用户名密码错误！");


		data.ret = 0;

		ret = send(TOsock,&data,sizeof(data),0);

	sleep(2);

	close(TOsock);
}





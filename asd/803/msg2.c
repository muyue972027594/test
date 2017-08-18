/**************************************************************
文件名：msg2.c
功  能：利用消息队列聊天（msg1.c 与 msg2.c 配合）
版本号：0.0.1
**************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

typedef struct msgbuf
{
	long type;
	char msg[50];
}MSG;

int main()
{
	key_t key = 0;
	MSG mess;

	key = ftok("/home/zhang/asd/803",25);
	key = msgget(key,IPC_CREAT | 0660);
	if(key < 0)
	{
		perror("msgget error");
		exit(-1);
	}

	for(int i = 0;i < 5;i++)
	{
		memset(&mess,0,sizeof(MSG));
		if(msgrcv(key,&mess,50,1,0) < 0)
		{
			perror("msgrcv error");
			exit(-1);
		}	
		printf("\n\n\n\nPC 1 :%s",mess.msg);

		sleep(1);

		memset(&mess,0,sizeof(MSG));
		printf("\nPC 2 >>");
		fgets(mess.msg,50,stdin);
		mess.type = 2;
		if(msgsnd(key,&mess,50,0) < 0)
		{
			perror("msgsnd error");
			exit(-1);
		}

		sleep(1);
		
	}

/*	sleep(5);

	if(msgctl(key,IPC_RMID,NULL))
	{
		perror("msgctl error");
		exit(-1);
	}
*/
	return 0;
}



















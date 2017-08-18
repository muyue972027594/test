/**************************************************
文件名：anli1.c
功  能：两个进程通过共享内存通信(anli1.c 与 anli1_1.c 配合)
版本号：0.0.1
**************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
	key_t key;
	char *buf = NULL;
	char data[20] = "ni hao!";

	key = ftok("/home/zhang/asd/803",803);
	key = shmget(key,1024,IPC_CREAT | 0666);
	printf("%d\n",key);
	if(key < 0)
	{
		perror("shmget error");
		exit(-1);
	}

	buf = shmat(key,NULL,0);
	if(buf < 0)
	{
		perror("shmat error");
		exit(-1);
	}
	
	strcpy(buf,data);
	
	if(shmdt(buf) < 0)
	{
		perror("shmdt error");
		exit(-1);
	}

/*	if(shmctl(key,IPC_RMID,NULL) < 0)
	{
		perror("shmctl error ");
		exit(-1);
	}
*/
	return 0;
}

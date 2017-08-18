/******************************************************
文件名：anli2.c
功  能：间隔五秒输出一次
版本号：0.0.1
*********************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void print1(int x)
{
	printf("loading...\n");
}

void print2(int x)
{
	
}

int main()
{

/*	while(1)
	{
		signal(14,print1);
		alarm(5);
		sleep(5);
	}
*/


/*	while(1)
	{
		sleep(5);
		print1(1);
	}
*/


	while(1)
	{
		signal(14,print2);
		alarm(5);
		pause();
		print1(1);
	}


	return 0;
}

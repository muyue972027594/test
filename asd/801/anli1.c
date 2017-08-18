#include<unistd.h>
#include<stdio.h>

int main()
{
	pid_t data;
	
	data = getpid();
	printf("进程号  %d \n",data);
}

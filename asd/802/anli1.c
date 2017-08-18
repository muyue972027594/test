#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	pid_t data;
	int status;

	data = fork();
	if(data > 0)
	{
		printf("Father PID  %d\n",getpid());
		waitpid(data,&status,0);
		if(WIFEXITED(status))
		{
			printf("nomal exit!  return %d\n",WEXITSTATUS(status));
		}
	}
	else if(data == 0)
	{
		printf("Child PID  %d\n",getpid());
		exit(20);
	}
}

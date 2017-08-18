#include<stdio.h>
#include<mysql/mysql.h>
#include<string.h>

int main()
{
	MYSQL mysql;
	
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,"localhost","root","123","company",0,NULL,0) ==NULL)
	{
		printf("connect error:%s\n",mysql_error(&mysql));
		return -1;
	}
	else
		printf("connect ok!\n");
	
	mysql_close(&mysql);
	return 0;
}

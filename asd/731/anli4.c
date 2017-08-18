/**********************************************************
文件名：anli4.c
功  能：键盘输操作数据库
版本号：0.0.1
********************************************************/
#include<stdio.h>
#include<mysql/mysql.h>
#include<string.h>

int main()
{
	char sql[100] = {0},name[20] = {0},addr[40] = {0};
	int id=0;
	MYSQL mysql;
	
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,"localhost","root","123","ex1",0,NULL,0) == NULL)
	{
		printf("connect error:%s\n",mysql_error(&mysql));
		return -1;
	}
	else
		printf("\nconnect ok!\n");

	while(1)
	{
		printf("\nmysql>>");
		memset(sql,0,sizeof(sql));
		fgets(sql,100,stdin);
		sql[strlen(sql)-1]='\0';
		if(strlen(sql) <= 2) break;
	

		if(mysql_real_query(&mysql,sql,strlen(sql)) != 0)
		{
			printf("query error:%s\n",mysql_error(&mysql));
        	return -1;
		}
		else
        	printf("\nquery ok!\n");
	}
	
	mysql_close(&mysql);
	return 0;
}

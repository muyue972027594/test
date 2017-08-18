/**********************************************************
文件名：anli3.c
功  能：键盘输入数据存入数据库
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
		printf("\n请依次输入id，name，addr（id为0时结束）\n");
		printf("\n例：10001 zhang aaaaaaaaaa\n");
		scanf("%d",&id);
		if(id == 0) break;
		scanf("%s%s",name,addr);
		sprintf(sql,"insert into exam values(%d,'%s','%s');",id,name,addr);
	

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

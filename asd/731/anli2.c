#include<stdio.h>
#include<mysql/mysql.h>
#include<string.h>

int main()
{
	char *sql="insert into exam values(10001,'zhang','dddddddddddd');";
	MYSQL mysql;
	
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,"localhost","root","123","ex1",0,NULL,0) == NULL)
	{
		printf("connect error:%s\n",mysql_error(&mysql));
		return -1;
	}
	else
		printf("connect ok!\n");

	if(mysql_real_query(&mysql,sql,strlen(sql)) != 0)
	{
		 printf("query error:%s\n",mysql_error(&mysql));
        return -1;
	}
	else
        printf("query ok!\n");
	
	mysql_close(&mysql);
	return 0;
}

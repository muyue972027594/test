/**********************************************************
文件名：anli5.c
功  能：显示数据库中指定表数据
版本号：0.0.1
********************************************************/
#include<stdio.h>
#include<mysql/mysql.h>
#include<string.h>

int main()
{
	char sql[150] = {0};
	char tab_name[10]={0};
	MYSQL mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	
	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,"localhost","root","123","ex1",0,NULL,0) == NULL)
	{
		printf("connect error:%s\n",mysql_error(&mysql));
		return -1;
	}
	else
		printf("\nconnect ok!\n");

	printf("\n请输入要显示的表名\n");
	scanf("%s",tab_name);
	memset(sql,0,sizeof(sql));
	strcpy(sql,"select * from ");
	strcat(sql,tab_name);
//	puts(sql);

	if(mysql_real_query(&mysql,sql,strlen(sql)) != 0)
	{
		printf("query error:%s\n",mysql_error(&mysql));
      	return -1;
	}
	else
	{
       	printf("\nquery ok!\n");
			
		res = mysql_use_result(&mysql);	
//		printf("%llu,%d\n",mysql_num_rows(res),mysql_num_fields(res));		
//		for(int i = 0;i < mysql_num_rows(res);i++)
//		for(int i = 0;i < mysql_field_count(&mysql);i++)
		while(1)
		{
			row = mysql_fetch_row(res);
			if(row <= 0) break;
			for(int j = 0;j < mysql_num_fields(res);j++)
				printf(" %s ",row[j]);
			printf("\n");
		}
			
		mysql_free_result(res);
	}
	
	mysql_close(&mysql);
	return 0;
}

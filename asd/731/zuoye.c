/***************************************************
文件名：zuoye.c
功  能：数据库中  增、删、查、改
版本号：0.0.1
*****************************************************/
#include<stdio.h>
#include<mysql/mysql.h>
#include<string.h>

typedef struct student 
{
	int num; 
	char name[20];
	float score;
	struct student *next;
} STU;

MYSQL mysql;

int myinsert();
int mydelete();
int myupdate();
int myselect(STU *head);
int myfree(STU *head);

int main()
{
	int menu = 1;
	STU *head = NULL;
	head = malloc(sizeof(STU));
	mysql_init(&mysql);

	/*建立连接*/
    if(mysql_real_connect(&mysql,"localhost","root","123","ex1",0,NULL,0) == NULL)
    {
        printf("connect error : %s\n",mysql_error(&mysql));
        return -1;
    }
    else
        printf("\nconnect ok!\n");

	while(menu != 0)
	{
		printf("\n*************************************************\n");
		printf("\n增加---1  删除---2  查询---3  修改---4  退出---0 \n");
		printf("\n*************************************************\n");
		
		scanf("%d",&menu);

		switch(menu)
		{
			case 1:myinsert();break;
			case 2:mydelete();break;
			case 3:myselect(head);break;
			case 4:myupdate();break;
			case 0:myfree(head);break;
			default:
				printf("输入错误！");
		}
	}

	/*关闭连接*/
	mysql_close(&mysql);
	return 0;
}

/*往表里增加记录*/
int myinsert()
{
	char sql[100] = {0};
	char name[20] = {0};
	float score = 0;
    int num = 0;

    while(1)
    {
		memset(sql,0,sizeof(sql));
        printf("\n请依次输入num,name,score（num为0时结束）\n");
        printf("\n例：10001 zhang 80.5\n");
        scanf("%d",&num);
        if(num == 0) break;
        scanf("%s%f",name,&score);
        sprintf(sql,"insert into test values(%d,'%s','%f')",num,name,score);

        if(mysql_real_query(&mysql,sql,strlen(sql)) != 0)
        {
            printf("\nquery error:%s\n",mysql_error(&mysql));
            return -1;
        }
        else
            printf("\nquery ok!\n");
    }
	
}

/*通过编号删除记录*/
int mydelete()
{
    char sql[100] = {0};
    int num = 0;

    while(1)
    {
        memset(sql,0,sizeof(sql));
        printf("\n请输入要删除的num（num为0时结束）\n");
        printf("\n例：10001\n");
        scanf("%d",&num);
        if(num == 0) break;

        sprintf(sql,"delete from test where num = %d",num);

        if(mysql_real_query(&mysql,sql,strlen(sql)) != 0)
        {
            printf("\nquery error:%s\n",mysql_error(&mysql));
            return -1;
        }
        else
            printf("\nquery ok!\n");
    }
	
} 

/*通过编号修改记录中姓名或成绩（自动识别）*/
int myupdate()
{
    char sql[100] = {0};
	char buf[20] = {0};
    int num = 0;

    while(1)
    {
        memset(sql,0,sizeof(sql));
        memset(buf,0,sizeof(buf));
        printf("\n请输入要修改的num（num为0时结束）\n");
        printf("\n例：10001\n");
        scanf("%d",&num);
        if(num == 0) break;
		printf("\n请输入正确信息\n");
        scanf("%s",buf);
		if(buf[0] > '9')
        	sprintf(sql,"update test set name='%s' where num = %d",buf,num);
		else
        	sprintf(sql,"update test set scroe= %s where num = %d",buf,num);

        if(mysql_real_query(&mysql,sql,strlen(sql)) != 0)
        {
            printf("\nquery error:%s\n",mysql_error(&mysql));
            return -1;
        }
        else
            printf("\nquery ok!\n");
    }

}

/*将查询的记录放入链表并显示*/
int myselect(STU *head)
{
	MYSQL_RES *res;
	MYSQL_ROW row;
	STU *p1,*p2;
	char *sql = "select * from test";

	if(mysql_real_query(&mysql,sql,strlen(sql)) != 0)
    {
        printf("\nquery error:%s\n",mysql_error(&mysql));
        return -1;
    }
    else
        printf("\nquery ok!\n");

	/*查询记录存入链表*/
	res = mysql_store_result(&mysql);
	for(int i = 0;i < mysql_num_rows(res);i++)
	{
		row = mysql_fetch_row(res);

//		printf("%s %s %s\n",row[0],row[1],row[2]);
		p2 = malloc(sizeof(STU));
		if(i == 0)
			head->next = p1 = p2;
		else
		{
			p1->next = p2;
			p1 = p2;
		}

		p2->num = atoi(row[0]);
		strcpy(p2->name,row[1]);
		p2->score = atof(row[2]);
		p2->next = NULL;
	}
	
	/*链表显示*/
	p1 = head->next;
	printf("\n\n");
	while(p1 != NULL)
	{
		printf("%d %-5s %g\n",p1->num,p1->name,p1->score);
		p1 = p1->next;
	}
	printf("\n");
}

/*释放空间*/
int myfree(STU *head)
{
	STU *p1,*p2;
	p1 = head;
	while(p1 != NULL)
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
}





























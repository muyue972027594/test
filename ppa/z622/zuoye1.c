#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student
	{
		char name[10];
		int num;
	}stu;
int main()
{
	char a[10];int b,coun=0,coun1=0;
	stu *p;FILE *fp;
	fp=fopen("student.txt","a+");
	while(1)
	{
		printf("请输入学生信息(按0 0结束)\n");
		scanf("%s%d",a,&b);
		if(a[0]=='0'&&b==0) break;
		else
		{
			p=malloc(sizeof(stu));
			strcpy(p->name,a);
			p->num=b;
			coun+=fwrite(p,sizeof(stu),1,fp);
			free(p);
		}
		coun1++;
	}
	if(coun!=coun1) 
		printf("print error\n");
	else
	{
		rewind(fp);
		printf("请输入要查找的学生名字\n");
		scanf("%s",a);
		coun=0;
		while(1)
		{
			coun+=fread(p,sizeof(stu),1,fp);
			if(strcmp(p->name,a)==0)
			{
				printf("%s %d\n",p->name,p->num);
				break;
			}
		}
		if(coun<1) printf("find error\n");
	}
	fclose(fp);
}

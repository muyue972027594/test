#include"xitong.h"
void chaxun(stu *x)
{
	stu *p;
	int m=0;
	char a[10],*p1={"学号 %d 姓名 %-10s 性别 %s 年龄 %d 生日 %-18s 地址 %s\n"};
	printf("\n请输入要查询的学生姓名\n");
	scanf("%s",a);
	p=x;
	while(p!=NULL)
    {
        if(strcmp(p->name,a)==0)
		{
			printf(p1,p->num,p->name,p->sex,p->age,p->bthd,p->adrs);
			m=1;
			break;
		}
        p=p->next;
    }
	if(m==0) printf("查无此人\n");
}


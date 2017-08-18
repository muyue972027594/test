#include"xitong.h"
stu *luru(stu *x,int *y)
{
	stu *p,*p1,*p2;
	p=x;
	char a[10];int m=0;
	while(1)
	{
		printf("\n请录入一位学生的姓名_例:张三_(输入0结束)\n");
		scanf("%s",a);
		if(a[0]=='0') break;
		else
		{
			p2=malloc(sizeof(stu));
			(*y)++;
			strcpy(p2->name,a);
			printf("\n请依次录入学生的学号，性别，年龄，生日，地址\n");
			printf("例：2017001 男 15 2002年6月1日 山西省太原市小店区\n");
			scanf("%d%s%d%s%s",&p2->num,p2->sex,&p2->age,p2->bthd,p2->adrs);
			if(p==NULL)
			{
				if(m==0) x=p1=p2,m++;
				else p1->next=p2,p1=p2;
			}
			else
			{
				while(p->next!=NULL)
					p=p->next;
				if(m==0) p->next=p1=p2,m++;
				else p1->next=p2,p1=p2; 
			}
			p2->next=NULL;
		}
	}
	return x;
}

#include"xitong.h"
void liulan(stu*x)
{
	stu*p;
	p=x;
	char *p1={"学号 %d 姓名 %-10s 性别 %s 年龄 %d 生日 %-18s 地址 %s\n"};
	while(p!=NULL)
	{
		printf(p1,p->num,p->name,p->sex,p->age,p->bthd,p->adrs);
		p=p->next;
	}
}
stu * fr(stu *x,int y)
{
    int i;
    stu *z;
    for(i=0;i<y;i++)
    {
        z=x->next;
        free(x);
        x=z;
    }
	return x;
}


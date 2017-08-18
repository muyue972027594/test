#include"xitong.h"
stu *xiugai(stu*x)
{
    stu *p;
    char a[10];
	int m=0,menu;
    p=x;
    printf("\n请输入要修改的学生姓名\n");
    scanf("%s",a);
    while(p!=NULL)
    {   
		if(strcmp(p->name,a)==0)
        {
            m=1;
			printf("\n请输入要修改的项目\n");
			printf("\n1.学号\t2.姓名\t3.性别\n4.年龄\t5.生日\t6.地址\n");
			scanf("%d",&menu);
			switch(menu)
			{
				case 1:
				{
					printf("请输入正确的学号\n");
					scanf("%d",&p->num);
				} break;
				case 2:
				{
					printf("请输入正确的姓名\n");
					scanf("%s",p->name);
				} break;
				case 3:
				{
					printf("请输入正确的性别\n");
					scanf("%s",p->sex);
				} break;
				case 4:
				{
					printf("请输入正确的年龄\n");
					scanf("%d",&p->age);
				} break;
				case 5:
				{
					printf("请输入正确的生日\n");
					scanf("%s",p->bthd);
				} break;
				case 6:
				{
					printf("请输入正确的地址\n");
					scanf("%s",p->adrs);
				} 
			}
            break;
        }
        p=p->next;
    }
	if(m==0) printf("查无此人");
    return(x);
}

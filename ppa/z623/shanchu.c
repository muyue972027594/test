#include"xitong.h"
stu*shanchu(stu *x,int *y)
{
    stu *p1,*p2;
	char a[10];
    p1=p2=x;
    printf("请输入要删除的学生姓名\n");
    scanf("%s",a);
    while(p2!=NULL)
    {
		
        if(strcmp(p2->name,a)==0)
        {
            if(p2==x) x=x->next;
            else p1->next=p2->next;
            free(p2);(*y)--;
            break;
        }
		p1=p2;p2=p2->next;
    }
    return(x);
}


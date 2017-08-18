#include"lianbiao.h"
str_lb *cre(int a)
{
    str_lb *head,*p1,*p2;
    int i,m=0;
    printf("请输入%d个整数\n",a);
    for(i=0;i<a;i++)
    {
        p2=malloc(sizeof(str_lb));
        m++;
        scanf("%d",&p2->a);
        if(i==0)
            head=p1=p2;
        else
            {p1->p=p2;p1=p2;}
    }
    p1->p=NULL;
	return(head);
}

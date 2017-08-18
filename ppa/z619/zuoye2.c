/***链表指定删除***/
#include<stdio.h>
#include<stdlib.h>
    typedef struct lianbiao
    {
        int a; 
        struct lianbiao *p;
    } str_lb;
str_lb * del(str_lb *x,int a);
void print(str_lb *x);
void fre(str_lb *x,int y);
int main()
{   
    str_lb *head,*p1,*p2;
    int i,a,b,m=0;
	printf("请输入十个整数\n");
    for(i=0;i<10;i++)//创建列表
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
	do
	{
		printf("请选择删除(0)或全部输出(1)\n");
		scanf("%d",&b);
		switch(b)
		{
			case 0:
			{
				printf("请输入要删除的整数\n");
				scanf("%d",&a);
				head=del(head,a);m--;
			}
			break;
			case 1:print(head);break;
		}
	} while(b!=1);
	fre(head,m);
}
str_lb * del(str_lb *x,int a)
{
	str_lb *y,*z;
	int m=0;
	y=z=x;
	 do
    {
        if(m==0)  m++;
        else z=y,y=y->p;
        if(a==y->a) 
		{
			z->p=y->p;
			if(y==x) x=x->p;
			free(y);
		}
    }
    while(y->p!=NULL);
	return(x);
}
void print(str_lb *x)
{
	str_lb *y;
	int m=0;
	y=x;
	printf("\n");
    do
    {
        if(m==0) m++;
        else y=y->p;
        printf("%d\n",y->a);
    }
    while(y->p!=NULL);
}
void fre(str_lb *x,int y)
{
	int i;
	str_lb *z;
    for(i=0;i<y;i++)
    {
        z=x->p;
        free(x);
        x=z;
    }
}


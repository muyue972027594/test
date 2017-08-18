/***建一链表***/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	typedef struct lianbiao
	{
		int a;
		struct lianbiao *p;
	} str_lb;
	str_lb *head,*p1,*p2;
	int i,n=0,m=0;
	for(i=0;i<10;i++)//创建列表
	{
		p2=malloc(sizeof(str_lb));
		p2->a=n++;
		if(i==0)
			head=p1=p2;
		else
			{p1->p=p2;p1=p2;}
	}
	p1->p=NULL;p1=p2=head;
	do//输出链表
	{
		if(m==0) p1=p1,m++;
		else p1=p1->p;
		printf("%d\n",p1->a);
	}
	while(p1->p!=NULL);
	for(i=0;i<10;i++)//释放空间
	{
		p2=head->p;
		free(head);
		head=p2;
	}
}

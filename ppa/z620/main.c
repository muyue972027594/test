#include"lianbiao.h"
int main()
{
	str_lb *head;
	int a,b;
	printf("**请先创建一个链表**\n请输入链表结点的个数\n");
	scanf("%d",&a);
	head=cre(a);
	do
	{
		printf("请选择增加(2)、删除(1)或结束(0)\n");	
		scanf("%d",&b);
        switch(b)
        {
            case 2:head=add(head,&a);break;
            case 1:head=del(head,&a);break;
        }
    } while(b);
	print(head);
    fre(head,a);
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


#include"lianbiao.h"
str_lb *add(str_lb *x,int *f)
{
	str_lb *y,*z,*p;
	int a,m=0;
	y=z=x;
	p=malloc(sizeof(str_lb));
	printf("请输入要增加的数\n");
	scanf("%d",&p->a);
    do
    {
        if(m==0) m++;
        else z=y,y=y->p;
        if(p->a<=y->a)
		{
			if(y==x) 
			{
				p->p=x;x=p;
				(*f)++;
				break;
			}
			else
			{
				p->p=z->p;
				z->p=p;(*f)++;
				break;
			}
		}
		else if(y->p==NULL)
		{
			p->p=y->p;
			y->p=p;
			y=p;(*f)++;
			break;
		}
    }
    while(y->p!=NULL);
	return(x);
}

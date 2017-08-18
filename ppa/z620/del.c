#include"lianbiao.h"
str_lb * del(str_lb *x,int *f)
{
    str_lb *y,*z;
    int a,m=0;
    y=z=x;
	printf("请输入要删除的数\n");
	scanf("%d",&a);
     do
    {
        if(m==0)  m++;
        else z=y,y=y->p;
        if(a==y->a)
        {
            z->p=y->p;
            if(y==x) x=x->p;
            free(y);(*f)--;
			break;
        }
    }
    while(y->p!=NULL);
    return(x);
}


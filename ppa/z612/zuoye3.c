/***第三题：乘法口诀表***/
#include<stdio.h>
void biao(int *x,int *y);
int main()
{
	int i=1,j=1,*p1=&i,*p2=&j;
	biao(p1,p2);
}
void biao(int*x,int*y)
{
	for(*x;*x<10;*x+=1)
	{
		for(*y=1;*y<=*x;*y+=1)
			printf("%d×%d=%d\t",*y,*x,*x**y);
		printf("\n");
	}
}


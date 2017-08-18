/***交换两个变量的值***/
#include<stdio.h>
void jiaohuan1(int x,int y);
void jiaohuan2(int*x,int*y);
void jiaohuan3(int*x,int*y);
int main()
{
	int a,b,*p1,*p2;
	printf("请输入两个整数\n");
	scanf("%d%d",&a,&b);
	p1=&a;p2=&b;
	printf("交换前a=%d,b=%d\n",a,b);
//	jiaohuan1(a,b);
//	jiaohuan2(p1,p2);printf("交换后a=%d,b=%d\n",a,b);
	jiaohuan3(p1,p2);
}
void jiaohuan1(int x,int y)
{
	int z;
	z=x;x=y;y=z;
	printf("交换后a=%d,b=%d\n",x,y);
}
void jiaohuan2(int*x,int*y)
{
	int z;
	z=*x;*x=*y;*y=z;
}
void jiaohuan3(int*x,int*y)
{
	int *z=NULL;
	z=x;x=y;y=z;
	printf("交换后a=%d,b=%d\n",*x,*y);
}

#include<stdio.h>
int main()
{
	int a,b,c,d,e;
	printf("请输入一个三位数：\n");
	scanf("%d",&a);
	b=a/100;c=a/10;d=c-10*b;e=a-100*b-10*d;
	printf("原数为%d逆数为%d\n",a,100*e+10*d+b);
}

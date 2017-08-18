/*****************************************

				计算器

****************************************/
#include<stdio.h>
float sum(float x,float y);
float sub(float x,float y);
float mul(float x2,float y2);
float div(float x3,float y3);
int main()
{
	float b,c;int a;
	printf("请选择运算\n加法运算——1   减法运算——2\n乘法运算——3   除法运算——4\n");
	scanf("%10d",&a);
	if(a==1||a==2||a==3||a==4)
	{
		printf("请输入要求解的两个数\n");
		scanf("%f%f",&b,&c);
		switch(a)
		{
			case 1:printf("和为%g\n",sum(b,c));break;
			case 2:printf("差为%g\n",sub(b,c));break;
			case 3:printf("积为%g\n",mul(b,c));break;
			case 4:printf("商为%g\n",div(b,c));break;
		}
	}
	else printf("输入错误\n");
}
float sum(float x,float y)
{
	return(x+y);
}
float sub(float x,float y)
{
	return(x-y);
}
float mul(float x2,float y2)
{
	return(x2*y2);
}
float div(float x3,float y3)
{
	return(x3/y3);
}

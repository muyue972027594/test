/********************************************************
				长l，宽w，求长方形面积s
				
********************************************************/
#include<stdio.h>
int main()
{
	float l,w,s;
	printf("请依次输入长方形的长和宽，用空格键隔开\n");
	scanf("%f%f",&l,&w);
	s=l*w;
	printf("长方形的长为%6.2f，长方形的宽为%6.2f，长方形的面积为%10.2f\n",l,w,s);
}

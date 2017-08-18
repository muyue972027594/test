/*******************************************************************

					边长a、b、c，求三角形面积

*******************************************************************/
#include<math.h>
#include<stdio.h>
int main()
{
	float a,b,c,s,sq,area;
	printf("请输入三角形的三个边长\n");
	scanf("%f%f%f",&a,&b,&c);
	s=(a+b+c)/2;sq=s*(s-a)*(s-b)*(s-c);area=sqrt(sq);
	printf("三角形面积为%.2f\n",area);
}

/**************************************************************************

								计算运费

**************************************************************************/
#include<stdio.h>
#define P 30
float f(float x,float y);
int main()
{
	float s,w;
	printf("请输入运送货物重量和运送距离(吨,KM)\n");
	scanf("%f%f",&w,&s);
	printf("运费为%.2f元\n",f(s,w));
}
float f(float x,float y)
{
	float d;
	if(x<250) d=0;
	if(x>=250&&x<500) d=0.02;
	if(x>=500&&x<1000) d=0.05;
	if(x>=1000&&x<2000) d=0.08;
	if(x>=2000&&x<3000) d=0.1;
	if(x>=3000) d=0.15;
	return (P*x*y*(1-d));
}


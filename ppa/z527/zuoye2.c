/***************************************************************

					解一元二次方程

***************************************************************/
#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,x1,x2;
	printf("请按标准方式输入一元二次方程的三个参数\n");
	scanf("%f%f%f",&a,&b,&c);
	x1=(-b+sqrt(b*b-4*a*c))/(2*a);
	x2=(-b-sqrt(b*b-4*a*c))/(2*a);
	if(b*b>=4*a*c)
	{
		if(x1==x2)
			printf("方程的解x1=x2=%g\n",x1);
		else
			printf("方程的解x1=%g,x2=%g\n",x1,x2);
	}
	else
		printf("此方程在实数范围内无解\n");	
}

/**********************************************************
			将小数点后第四位四舍五入

***********************************************************/
#include<stdio.h>
int main()
{
	float a,e,f;int b,c,d;
	printf("请输入一个实数，小数点后多于四位\n");
	scanf("%f",&a);
	f=a*10000;b=f;c=b%10;
	if(c>=5)
	{	
		d=b/10+1;e=d;printf("四舍五入后为%.3f\n",e/1000);
	}
	else
	{
		d=b/10;e=d;printf("四舍五入后为%.3f\n",e/1000);
	}
}



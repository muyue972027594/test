/***平均值，方差，标准差***/
#include<stdio.h>
#include<math.h>
int main()
{
	float s[6],sum=0,d=0;
	int i;
	printf("输入六个温度值\n");
	for(i=0;i<6;i++)
	{
		scanf("%f",&s[i]);
		sum+=s[i];
	}
	for(i=0;i<6;i++)
	{
		d+=(s[i]-sum/6)*(s[i]-sum/6)/6;
	}
	printf("平均值为%f\n",sum/6);
	printf("方差为%f\n",d);
	printf("标准差为%f\n",sqrt(d));
}

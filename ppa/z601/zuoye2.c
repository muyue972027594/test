/*********************************************

				判断整数的位数

**********************************************/
#include<stdio.h>
int main()
{
	int shu,a=1,b=1;
	printf("请输入一个整数\n");
	scanf("%d",&shu);
	while(1)
	{
		a*=10;
		if(shu/a!=0)
			b++;
		else
		{
			printf("此数为%d位数\n",b);
			break;
		}
	}
}

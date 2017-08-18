/***1+(1+2)...+(1+2+...+n)求和***/
#include<stdio.h>
int main()
{
	int i,n,sum=0,sum1=0;
	printf("请输入一个正整数\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		sum+=i;
		sum1+=sum;
	}
	printf("和为%d\n",sum1);
}

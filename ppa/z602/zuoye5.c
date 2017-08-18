/***1-n的和***/
#include<stdio.h>
int main()
{
	int n,i,sum=0;
	printf("请输入一个正整数\n");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
		sum+=i;
	printf("总和为%d\n",sum);
}

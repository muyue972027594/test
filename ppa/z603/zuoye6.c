/***n!末尾零的个数***/
#include<stdio.h>
int main()
{
	int n,i,m=1,m1;
	printf("请输入一个正整数(必须小于13)\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		m*=i;
	m1=m;i=0;
	while(m1%10==0)
	{
		i++;m1/=10;
	}
	printf("%d!=%d,末尾有%d个零\n",n,m,i);
}

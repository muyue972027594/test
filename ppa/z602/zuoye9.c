/***最大公约数、最小公倍数***/
#include<stdio.h>
int main()
{
	int i,j,m,n;
	printf("请输入两个正整数\n");
	scanf("%d%d",&m,&n);
	for(i=m;i>0;i--)
	{
		if(m%i==0&&n%i==0) break;
	}
	for(j=1;1;j++)
		if(j%m==0&&j%n==0)
			break;
	printf("最大公约数为%d\t最小公倍数为%d\n",i,j);
}

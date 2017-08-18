/***取出数字每个数位的奇数***/
#include<stdio.h>
int main()
{
	int shu,a,b=1,c=0,new=0;
	printf("请输入一个整数\n");
	scanf("%d",&shu);
	a=shu;
	while(1)
	{
		if(a%10%2==1)
		{
			c=a%10;
			c*=b;new+=c;b*=10;
		}
		if(a/10==0) break;
		a/=10;
	}
	printf("新数为%d\n",new);
}

/***一组数，查找位置***/
#include<stdio.h>
int main()
{
	int s[6],i,k,shu;
	printf("请输入六个整数\n");
	for(i=0;i<6;i++)
		scanf("%d",&s[i]);
	printf("请输入要查找的数\n");
	scanf("%d",&shu);
	for(i=0;i<6;i++)
	{
		if(shu==s[i]) 
		{
			k=i;
			printf("第%d个数 ",k+1);
		}
	}
	printf("\n");
}

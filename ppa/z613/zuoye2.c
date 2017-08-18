/***第二题：一组数，查找位置***/
#include<stdio.h>
void chazhao(int*x,int y);
int main()
{
	int s[6],i,shu;
	printf("请输入六个整数\n");
	for(i=0;i<6;i++)
		scanf("%d",&s[i]);
	printf("请输入要查找的数\n");
	scanf("%d",&shu);
	chazhao(s,shu);
}
void chazhao(int*x,int y)
{
	int i;
	for(i=0;i<6;i++)
		if(y==*(x+i))
			printf("第%d个数 ",i+1);
	printf("\n");
}

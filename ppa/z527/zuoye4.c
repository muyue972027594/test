/*************************************************

			 		是润年吗？

************************************************/
#include<stdio.h>
int main()
{
	int year;
	printf("请输入要查询的年份\n");
	scanf("%d",&year);
	if((year%4==0&&year%100!=0)||year%400==0)
		printf("%d是润年\n",year);
	else
		printf("%d不是润年\n",year);
		
}

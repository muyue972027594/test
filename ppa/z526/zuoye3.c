/**********************************************************************

							实现四则运算

***********************************************************************/
#include<stdio.h>
int main()
{
	int a,b;
	printf("请输入两个整数\n");
	scanf("%d%d",&a,&b);
	printf("前数与后数之和为%d\n",a+b);
	printf("前数与后数之差为%d\n",a-b);
	printf("前数与后数之积为%d\n",a*b);
	printf("前数与后数之商为%d\n",a/b);
	printf("前数与后数之余为%d\n",a%b);
}
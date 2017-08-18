/***第七题：输出数组元素***/
#include<stdio.h>
void shuchu1(int *x);
void shuchu2(int *x);
void shuchu3(int *x);
int main()
{
	int a[6],i;
	printf("请输入六个整数\n");
	for(i=0;i<6;i++)
		scanf("%d",&a[i]);
	printf("i++,a[i]方式输出:\n");
	for(i=0;i<6;i++)
		printf("%d ",a[i]);
	printf("\n");
	printf("i++,*(a+i)方式输出:\n");
	for(i=0;i<6;i++)
		printf("%d ",*(a+i));
	printf("\n");
	shuchu1(a);
	shuchu2(a);
	shuchu3(a);
}
void shuchu1(int*x)
{
	int i;
	printf("i++,x[i]方式输出:\n");
	for(i=0;i<6;i++)
		printf("%d ",x[i]);
	printf("\n");
}
void shuchu2(int*x)
{
	int i;
	printf("i++,*(x+i)方式输出:\n");
	for(i=0;i<6;i++)
		printf("%d ",*(x+i));
	printf("\n");
}
void shuchu3(int*x)
{
	int *p;
	printf("x++,*x方式输出:\n");
	for(p=x;x<p+6;x++)
		printf("%d ",*x);
	printf("\n");
}

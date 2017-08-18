/***输出指定大小的菱形***/
#include<stdio.h>
int main()
{
	int h,l,i,j,k,a,b;
	printf("请输入菱形的行和列\n");
	scanf("%d%d",&h,&l);
	b=(l/2)%(h/2);
	if(b!=0||h>l) printf("此行和列无法生成菱形\n");
	else
	{
		a=(l/2)/(h/2);
		for(i=0;i<=h/2;i++)
		{
			for(j=0;j<l/2-a*i;j++)
				printf(" ");
			for(k=0;k<1+2*a*i;k++)
				printf("*");
			printf("\n");
		}
		for(i=1;i<=h/2;i++)
		{
			for(j=1;j<1+a*i;j++)
				printf(" ");
			for(k=0;k<l-2*a*i;k++)
				printf("*");
			printf("\n");
		}
	}
}

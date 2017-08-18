/***1/2,2/3,3/5,5/8...的和***/
#include<stdio.h>
int main()
{
	int i,n,a=1,b=2,c=0;float sum=0;
	printf("请输入求和的项的数目\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		sum+=(float)a/b;
		c=b;b=a+b;a=c;
	}	
	printf("和为%f\n",sum);
}

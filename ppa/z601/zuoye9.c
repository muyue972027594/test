/*****************************************************************

						小于n且和7相关的数

*****************************************************************/
#include<stdio.h>
int main()
{
	int n,i,j=0,a[6000];
	printf("请输入一个四位数一下的整数\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		if(i%7==0||i%10==7||i/10%10==7||i/100%10==7||i/1000%10==7)
		{
			j++;
			a[j]=i;
		}
	}
	printf("%d个(",j);
	for(i=1;j>=i;i++)
	{
		printf("%d",a[i]);
		if(j!=i) printf("、");
		else printf(")\n");
	}
}
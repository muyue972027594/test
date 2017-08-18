#include<stdio.h>
int main()
{
	int a[10],i,j,k,min;
	printf("请输入十个数\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	for(i=0;i<9;i++)
	{
		min=a[i];k=i;
		for(j=i;j<10;j++)
		{
			if(min>=a[j])
			{
				min=a[j];k=j;
			}
		}
		a[k]=a[i];a[i]=min;
	}
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
}

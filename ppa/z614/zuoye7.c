/***第七题：动态存入，交换最大值、最小值***/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,m,n,*p,max,min;
	p=malloc(sizeof(int)*10);
	printf("请输入十个整数\n");
	for(i=0;i<10;i++)
	{
		scanf("%d",p+i);
		if(i==0)
		{
			max=min=*p;
			m=n=0;
		}
		if(max<*(p+i))
		{
			max=*(p+i);
			m=i;
		}
		if(min>*(p+i))
		{
			min=*(p+i);
			n=i;
		}
	}
	*(p+m)=min;*(p+n)=max;
	for(i=0;i<10;i++)
		printf("%d ",*(p+i));
	printf("\n");
}

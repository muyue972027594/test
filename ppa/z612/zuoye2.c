/***第二题：利用指针排序***/
#include<stdio.h>
void paixu(int *x);
void main()
{
	int a[10],i;
	printf("请输入十个整数\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);
	paixu(a);
	printf("从大到小排序后为\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);
	printf("\n");
}
void paixu(int *x)
{
	int i,j,n;
	for(i=0;i<10;i++)
		for(j=i+1;j<10;j++)
			if(*(x+i)<*(x+j))
			{
				n=*(x+i);
				*(x+i)=*(x+j);
				*(x+j)=n;
			}
}

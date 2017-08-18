/***第三题：最大值的位置***/
#include<stdio.h>
void max(int (*x)[4]);
int m,n;
int main()
{
	int a[3][4],i,j;
	printf("请输入3×4个整数\n");
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			scanf("%d",&a[i][j]);
	max(a);
	printf("最大值在第%d行第%d列\n",m+1,n+1);
}
void max(int (*x)[4])
{
	int i,j,max1;
	max1=**x;m=n=0;
	for(i=0;i<3;i++)
		for(j=0;j<4;j++)
			if(max1<*(*(x+i)+j))
			{
				max1=*(*(x+i)+j);
				m=i;n=j;
			}
}

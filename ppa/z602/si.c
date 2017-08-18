/***飞机***/
#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,k,N;
	printf("请指定飞机的大小\n");
	scanf("%d",&N);
	for(i=0;i<=N;i++)
	{
		for(j=0;j<sqrt(((N/2+1)-i)*((N/2+1)-i))*3;j++)
			printf(" ");
		for(k=0;k<N-sqrt(((N/2+1)-i)*((N/2+1)-i))*2;k++)
			printf("*");
		printf("\n");
	}
}

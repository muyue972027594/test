/***杨辉三角***/
#include<stdio.h>
#define N 10
int main()
{
	int s[N][N],i,j;
	for(i=0;i<N;i++)
	{
		s[i][0]=1;
		for(j=1;j<N;j++)
			s[i][j]=0;
	}
	for(i=1;i<N;i++)
		for(j=1;j<=i;j++)
			s[i][j]=s[i-1][j-1]+s[i-1][j];
	for(i=0;i<N;i++)
	{
		for(j=0;j<=i;j++)
			printf("%-3d ",s[i][j]);
		printf("\n");
	}
}

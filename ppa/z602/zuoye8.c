/***3-1000的素数***/
#include<stdio.h>
int main()
{
	int i,j,k=0;
	for(i=3;i<=1000;i++)
	{
		for(j=2;j<i;j++)
		{
			if(i%j==0) break;
		}
		if(j==i)
		{
			printf("%d\t",i);
			k++;
			if(k%5==0) 
				printf("\n");
		}
	}
	printf("\n");
}

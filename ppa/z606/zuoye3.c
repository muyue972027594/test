/***完数***/
#include<stdio.h>
int main()
{
    int i=0,j,n,sum=0;
	for(n=3;n<1000;n++)
	{
        for(j=2;j<n;j++)
           	if(n%j==0)
               	sum+=j;
		if(sum==n-1)
		{
			printf("%d ",n);
			i++;
			if(i%5==0) printf("\n");
		}
		sum=0;
	}
	if(i%5!=0) printf("\n");
}

/***3整除，含有5***/
#include<stdio.h>
int main()
{
	int n,i,j=0,m;
	printf("请输入一个数\n");
	scanf("%d",&n);
	for(i=1;i<n;i++)
	{
		if(i%3==0)
		{
			m=i;
			while(m!=0)
			{
				if(m%10==5)
				{
					printf("%d\t",i);
					j++;
					if(j%5==0) printf("\n");
					break;
				}
				m/=10;
			}
		}
	}
	if(j==0) printf("没有这样的数\n");
	if(j%5!=0) printf("\n");
}

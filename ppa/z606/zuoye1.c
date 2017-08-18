/***二位数组的鞍点***/
#include<stdio.h>
int main()
{
	int s[5][5],i,j,max,min,b[5],c[5],count=0;
	printf("请输入一个5×5的数组\n");
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			scanf("%d",&s[i][j]);
	for(i=0;i<5;i++)
	{
		max=s[i][0];
		min=s[0][i];
		for(j=1;j<5;j++)
		{
			if(max<s[i][j])
				max=s[i][j];
			if(min>s[j][i])
				min=s[j][i];
		}
		b[i]=max;c[i]=min;
	}
	for(i=0;i<5;i++)
		for(j=0;j<5;j++)
			if(b[i]==c[j])
			{
				printf("鞍点为%d\n",b[i]);
				count++;
			}
	if(count==0) printf("没有鞍点\n");
}

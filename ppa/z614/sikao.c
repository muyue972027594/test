/***报号，输出报号顺序***/
#include<stdio.h>
int main()
{
	int i,j,r,s,m,out,men;
	printf("请输入共有的人数，从第几个人开始，报数到第几人出圈\n");
	scanf("%d%d%d",&r,&s,&m);
	int a[r];
	men=r;out=0;j=s-1;
	for(i=0;i<r;i++)
		a[i]=i+1;
	while(men!=0)
	{
		printf("%-4d",a[j++]);out++;
		if(out%m==0)
		{
			printf("\n");
			if(out/m>1)
				for(i=j-m;i<j-1;i++)
				{
					a[i-out/m+1]=a[i];
//					printf("000000000000000000\n");
				}
		}
		if(j==men)
		{
			if(out%m!=0)
				for(i=j-out%m;i<j;i++)
					a[i-out/m]=a[i];
			else
				for(i=j-out%m;i<j-1;i++)
					a[i-out/m]=a[i];	
			j=0;
			men-=out/m;
			out%=m;
			
		}
	}
}

/***按0结束输入，保留较大的五个数***/
#include<stdio.h>
int main()
{
	int s[6],i=0,j,k,min;
	printf("请输入几个整数\n");
	do
	{
		scanf("%d",&s[i]);
		if(i<5) i++;
		else
		{
			min=s[0];k=0;
			for(j=0;j<5;j++)
				if(min>s[j])
				{
					min=s[j];k=j;
				}
			if(s[k]<s[5])
				s[k]=s[5];
		}
	} while(s[5]!=0);
    for(j=0;j<5;j++)
        printf("%d ",s[j]);
    printf("\n");
}

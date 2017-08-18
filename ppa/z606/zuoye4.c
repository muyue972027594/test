/***对角线之和***/
#include<stdio.h>
int main()
{
    int s[3][3],i,j,sum=0,sum1=0;
    printf("请输入一个3×3的数组\n");
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&s[i][j]);
    for(i=0;i<3;i++)
    {
		sum+=s[i][i];
        for(j=0;j<3;j++)
    		if(i+j==2)
        		sum1+=s[i][j];
    }
    printf("主对角线的和为%d，副对角线的和为%d\n",sum,sum1);
}


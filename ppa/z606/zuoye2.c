/***找最大值***/
#include<stdio.h>
int main()
{
    int s[3][4],i,j,m,n,max;
    printf("请输入一个3×4的数组\n");
    for(i=0;i<3;i++)
        for(j=0;j<4;j++)
            scanf("%d",&s[i][j]);
	max=s[0][0];m=0;n=0;
    for(i=0;i<3;i++)
    {
        for(j=1;j<4;j++)
        {
            if(max<s[i][j])
			{
                max=s[i][j];
				m=i;n=j;
			}
        }
    }
    printf("最大值为%d，在第%d行第%d列\n",max,m+1,n+1);
}


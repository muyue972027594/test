/***从小到大排序***/
#include<stdio.h>
int main()
{
    float a[10],min;int i,j,k;
    printf("请输入十个数\n");
    for(i=0;i<10;i++)
        scanf("%f",&a[i]);
    for(i=0;i<9;i++)
    {
        min=a[i];k=i;
        for(j=i;j<10;j++)
        {
            if(min>=a[j])
            {
                min=a[j];k=j;
            }
        }
        a[k]=a[i];a[i]=min;
    }
    for(i=0;i<10;i++)
        printf("%g ",a[i]);
    printf("\n");
}


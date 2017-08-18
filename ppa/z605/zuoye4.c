/***最小值放到最后***/
#include<stdio.h>
int main()
{
    int a[10],i,k,min;
    printf("请输入十个数\n");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
	min=a[0];k=0;
    for(i=0;i<10;i++)
    {
        if(min>a[i])
        {
             min=a[i];k=i;
        }
    }
    a[k]=a[9];a[9]=min;
    for(i=0;i<10;i++)
        printf("%d ",a[i]);	
    printf("\n");
}

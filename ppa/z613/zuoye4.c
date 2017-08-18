/***第四题：最小值放到最后***/
#include<stdio.h>
void min(int*x);
int main()
{
    int a[10],i;
    printf("请输入十个数\n");
    for(i=0;i<10;i++)
        scanf("%d",&a[i]);
	min(a);
	printf("交换后为：\n");
    for(i=0;i<10;i++)
        printf("%d ",a[i]);	
    printf("\n");
}
void min(int *x)
{
	int m,k,i;
	m=*x;k=0;
    for(i=0;i<10;i++)
    {
        if(m>x[i])
        {
             m=x[i];k=i;
        }
    }
    x[k]=x[9];x[9]=m;
}

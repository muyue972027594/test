/***查找比某数大的最小值***/
#include<stdio.h>
int main()
{
    float a[10],min,shu;int i,j,k;
    printf("请输入十个数\n");
    for(i=0;i<10;i++)
        scanf("%f",&a[i]);
	printf("请输入要比较的数\n");
	scanf("%f",&shu);
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
        if(a[i]>shu)
		{
			printf("比%g大的最小值为%g\n",shu,a[i]);break;
		}
}


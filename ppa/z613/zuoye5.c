/***第五题：查找比某数大的最小值***/
#include<stdio.h>
void chazhao(float*x,float*y,float z);
int main()
{
    float a[10],min,shu,*p;int i;
    printf("请输入十个数\n");
    for(i=0;i<10;i++)
        scanf("%f",&a[i]);
	printf("请输入要查找的数\n");
	scanf("%f",&shu);
	p=&min;
	chazhao(a,p,shu);
	printf("比%g大的最小值为%g\n",shu,min);
}
void chazhao(float*x,float*y,float z)
{
	int i,j;float m;
    for(i=0;i<9;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(*(x+i)>=*(x+j))
            {
                m=*(x+i);*(x+i)=*(x+j);*(x+j)=m;
            }
        }
    }
    for(i=0;i<10;i++)
        if(x[i]>z)
		{
			*y=x[i];break;
		}
}

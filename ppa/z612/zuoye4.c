/***第四题：浮点数计算平均值***/
#include<stdio.h>
float pingjun(float *x);
int main()
{
	float a[10];
	int i;
	printf("请输入十个数\n");
	for(i=0;i<10;i++)
		scanf("%f",&a[i]);
	printf("平均值为%g\n",pingjun(a));
}
float pingjun(float *x)
{
	int i;
	float sum=0;
	for(i=0;i<10;i++)
		sum+=*(x+i);
	return(sum/10);
}


/*********************************************

					平均值

*********************************************/
#include<stdio.h>
int main()
{
	float a,sum=0;int i;
	printf("请输入五个温度数据\n");
	for(i=0;i<5;i++)
	{
		scanf("%f",&a);
		sum+=a;
	}
	printf("平均值为%.3f\n",sum/5);
}
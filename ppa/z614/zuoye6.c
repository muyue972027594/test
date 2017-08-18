/***第六题：动态存储，计算平均值***/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j; float *p,*p1;
	p=malloc(sizeof(float));
	*p=0;
	printf("请输入几个整数，输入-1结束\n");
	for(i=0;1;i++)
	{
		p1=malloc(sizeof(float));
		scanf("%f",p1);
		if(*p1==-1)
		{
			free(p1);
			break;
		}
		else
		{
			*p+=*p1;
			free(p1);
		}
	}
	printf("平均值为：%g\n",*p/i);
	free(p);
}


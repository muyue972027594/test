/***第一题：找最大值***/
#include<stdio.h>
void max(float *x,float*y);
int main()
{
	float s[5],m,*p;
	int i;
	p=&m;
	printf("请输入五个浮点数\n");
	for(i=0;i<5;i++)
		scanf("%f",&s[i]);
	max(s,p);
	printf("最大值为%g\n",m);
}
void max(float*x,float*y)
{
	int i;
	*y=*x;
	for(i=0;i<5;i++)
		if(*y<*(x+i))
			*y=*(x+i);
}


/***第一题：将部分数放到另一数组***/
#include<stdio.h>
void fun(float *x,float *y);
int j=0;
int main()
{
	float score1[10],score2[10];
	int i;
	printf("请输入十个成绩\n");
	for(i=0;i<10;i++)
		scanf("%f",&score1[i]);
	fun(score1,score2);
	for(i=0;i<j;i++)
		printf("%g ",*(score2+i));
	printf("\n");
}
void fun(float *x,float *y)
{
	int i;
	for(i=0;i<10;i++)
		if(*(x+i)<60)
			*(y+j++)=*(x+i);
}

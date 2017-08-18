/***第二题：求总分***/
#include<stdio.h>
void sum1(float (*x)[3],float *y);
void main()
{
	float s[8][3],total[8];
	int i,j;
	printf("请依次输入八位学员的各科成绩\n");
	for(i=0;i<8;i++)
		for(j=0;j<3;j++)
			scanf("%f",&s[i][j]);
	sum1(s,total);
	for(i=0;i<8;i++)
		printf("%g ",*(total+i));
	printf("\n");
}
void sum1(float (*x)[3],float *y)
{
	int i,j;
	for(i=0;i<8;i++)
	{
		*(y+i)=0;
		for(j=0;j<3;j++)
			*(y+i)+=x[i][j];
	}
}

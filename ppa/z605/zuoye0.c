/***10个成绩，平均值，分数段，最大值，最小值，逆序输出***/
#include<stdio.h>
int main()
{
	float s[10],sum=0,max=0,min=100;
	int i,a=0,b=0,c=0;
	printf("请输入十个成绩\n");
	for(i=0;i<10;i++)
	{
		scanf("%f",&s[i]);
		sum+=s[i];
		if(max<s[i]) max=s[i];
		if(min>s[i]) min=s[i];
		if(s[i]<60) a++;
		else if(s[i]<80) b++;
		else c++;
	}
	printf("平均成绩为%g，最高分%g，最低分%g\n",sum/10,max,min);
	printf("优秀(80+)%d人，良好(60-80)%d人，不及格(60)%d人\n",c,b,a);
	for(i=9;i>=0;i--)
		printf("%g ",s[i]);
	printf("\n");
}

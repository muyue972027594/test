/***找最大值***/
#include<stdio.h>
int main()
{
	float s[5],max=0;
	int i;
	printf("请输入五个浮点数\n");
	for(i=0;i<5;i++)
	{
		scanf("%f",&s[i]);
		if(max<s[i]) max=s[i];
	}
	printf("最大值为%g\n",max);
}

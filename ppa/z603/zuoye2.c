/***青蛙爬井***/
#include<stdio.h>
int main()
{
	int i;float h,m,n,s;
	printf("请输入井深，白天怕的距离，夜晚滑的距离(米)\n");
	scanf("%f%f%f",&h,&m,&n);
	s=m;
	for(i=1;1;i++)
	{
		if(s>h)
		{
			printf("爬出井需要%d天\n",i);
			break;
		}
		s+=(m-n);
		if(i>=1000) 
		{
			printf("此青蛙三年之内难以爬出此井\n");
			break;
		}
	}
}

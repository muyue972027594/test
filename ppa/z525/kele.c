/**********************************
		可乐可装多少瓶？
**********************************/	
#include<stdio.h>
int main()
{
	double t2;float v;int b1;
	printf("请输入可乐的体积，单位为ml\n");
	scanf("%f",&v);
    t2=v/600;b1=v/600;
    if(t2>b1)
		printf("可装可乐%d瓶\n",++b1);
	else 
		printf("可装可乐%d瓶\n",b1);	
}


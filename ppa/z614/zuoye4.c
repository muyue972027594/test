/***第四题：长和宽，计算面积***/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	float *p;
	p=malloc(3*sizeof(float));
	printf("请输入长和宽\n");
	scanf("%f%f",p,p+1);
	*(p+2)=*p**(p+1);
	printf("面积为：%g\n",*(p+2));
	free(p);
}

/**************************************************

				比较两个数大小

**************************************************/
#include<stdio.h>
int bijiao(float x,float y);
int main()
{
	float a,b;
	printf("请输入要比较的两个数\n");
	scanf("%f%f",&a,&b);
	printf("比较值为%d\n#比较值为1表示前数大于后数，0表示相等\n",bijiao(a,b));
}
int bijiao(float x,float y)
{
	if(x-y>0) return 1;
	if(x-y==0) return 0;
	if(x-y<0) return -1;
}

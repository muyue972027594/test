/*****************************************

			理想体重是多少？

****************************************/
#include<stdio.h>
int main()
{
	float high,w;int a;
	printf("请选择性别\n男性——1,女性——2\n");
	scanf("%d",&a);
	if(a!=1&&a!=2) printf("输入错误\n");
	else 
	 {
		printf("请输入身高(单位:cm)\n");
		scanf("%f",&high);
		if(a==1) w=(high-80)*0.7;
		if(a==2) w=(high-70)*0.6;
		printf("理想体重为%g公斤\n",w);
		printf("%g——%g为良好\n",0.9*w,1.1*w);  
	 }
}

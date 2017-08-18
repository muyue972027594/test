/***************************************************************

							成绩分级

***************************************************************/
#include<stdio.h>
int main()
{
	float gra;int a;
	printf("请输入成绩\n");
	scanf("%f",&gra);
	if(gra>=0&&gra<60) a=69;
	else if(gra>=60&&gra<70) a=68;
	else if(gra>=70&&gra<80) a=67;
	else if(gra>=80&&gra<90) a=66;
	else if(gra>=90&&gra<=100) a=65;
	else printf("输入错误\n");
	if(a>64&&a<70)	printf("成绩为%c级\n",a);
}

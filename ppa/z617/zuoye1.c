/***第一题：显示信息即平均分***/
#include<stdio.h>
int main()
{
	struct stu 
	{
		int numb;
		char name[10];
		float gra;
	}a[2]={2017001,"张三",78.5,2017002,"李四",88.5};
	char *p={"学号：%d\t姓名：%s\t成绩：%g\n"};
	float ave;
	ave=(a[1].gra+a[0].gra)/2;
	printf(p,a[0].numb,a[0].name,a[0].gra);
	printf(p,a[1].numb,a[1].name,a[1].gra);
	printf("俩人平均分为%g\n",ave);
}

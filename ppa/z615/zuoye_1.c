/***编号增、删成绩***/
#include<stdio.h>
void delt();
void add();
float s[50]={0};
int main()
{
	int i,a;
	do
	{
		printf("请选择增加(1)或删除(2)或输出(0)\n");
		scanf("%d",&a);
		switch(a)
		{
			case 2:delt();break;
			case 1:add();
		}
	}
	while(a!=0);
	for(i=0;i<50;i++)
		printf("%g ",s[i]);
	printf("\n");
}
void delt()
{
	int i,j;	
	printf("请输入要删除的学生编号\n");
	scanf("%d",&i);
	s[i]=0;
	for(j=i;j<50;j++)
	{
		s[j]=s[j+1];
	}
}
void add()
{
	int i,j;float a;
	printf("请输入要增加的学生编号和成绩\n");
	scanf("%d%f",&i,&a);
	if(s[i]!=0)
		for(j=49;j>=i;j--)
			s[j]=s[j-1];
	s[i]=a;
}

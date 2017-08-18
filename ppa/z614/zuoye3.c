/***第三题：字符串反序存放***/
#include<stdio.h>
#include<string.h>
void fun(char *x);
void main()
{
	char a[20];
	printf("请输入几个字符\n");
	fgets(a,20,stdin);
	fun(a);
	puts(a);
}
void fun(char *x)
{
	char ch;
	int i;
	for(i=0;i<(strlen(x)-1)/2;i++)
	{
		ch=*(x+i);
		*(x+i)=*(x+strlen(x)-2-i);
		*(x+strlen(x)-2-i)=ch;
	}	
}

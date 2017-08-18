/***第二题：统计字符串的长度***/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[50];
	printf("请输入一个字符串\n");
	gets(a);
	printf("字符串长度为%d\n",strlen(a));
}

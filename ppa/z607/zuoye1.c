/***第一题：strcat连接功能***/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[20],b[10];
	printf("请输入两个字符串，用空格隔开\n");
	scanf("%s%s",a,b);
	puts(strcat(a,b));
}


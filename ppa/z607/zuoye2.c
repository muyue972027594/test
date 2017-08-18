/***第二题：strcpy字符串拷贝***/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[20],b[10];
	printf("请输入两个字符串，用空格隔开\n");
	scanf("%s%s",a,b);
	puts(strcpy(a,b));
}

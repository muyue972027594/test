/***第一题：判断回文字符串***/
#include<stdio.h>
#include<string.h>
void huiwen();
int main()
{
	char a[50];
	printf("请输入一个字符串(不超过45个字符)\n");
	gets(a);
	huiwen(a);
}
void huiwen(char *x)
{
	char b[50];
	int i;
	for(i=0;i<strlen(x);i++)
		b[i]=x[strlen(x)-i-1];
	b[i]='\0';
	puts(b);
	if(strcmp(x,b)==0)
		printf("是回文字符串\n");
	else
		printf("不是回文字符串\n");
}

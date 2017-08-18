/***第三题：strcmp字符串比较***/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[10],b[10];
    printf("请输入两个字符串，用空格隔开：\n");
	scanf("%s%s",a,b);
	if(strcmp(a,b)>0) printf("结果为1,即a>b\n");	
	else if(strcmp(a,b)==0) printf("结果为0,即a=b\n");	
	else printf("结果为-1,即a<b\n");	
}

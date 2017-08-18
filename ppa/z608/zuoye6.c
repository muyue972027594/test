/***第六题：字符串排序***/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],ch;
	int i,j;
	printf("请输入一串字符\n");
	gets(a);
	for(i=0;i<strlen(a);i++)
		for(j=i+1;j<strlen(a);j++)
			if(a[i]<a[j])
			{
				ch=a[i];a[i]=a[j];a[j]=ch;
			}
	puts(a);
}

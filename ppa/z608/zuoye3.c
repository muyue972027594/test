/***第三题：统计单词个数***/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int word=0,i,count=0;
	printf("请输入一个字符串\n");
	gets(a);
	for(i=0;i<100;i++)
	{
		if(a[i]==' ') word=0;
		else if(word==0&&((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')))
		{
			count++;word=1;
		}
		if(a[i]=='\0') break;
	}
	printf("单词有%d个\n",count);
}

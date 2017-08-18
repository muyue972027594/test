/***找出字符串中的数字***/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[30];
	int i;
	printf("请输入一个字符串\n");
	scanf("%s",a);
	for(i=0;i<30;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
			printf("%c",a[i]);
		if(a[i]=='\0') break;
	}	
	printf("\n");
}

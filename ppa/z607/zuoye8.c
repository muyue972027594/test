/***统计字符数***/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	int i,big=0,small=0,shu=0,kong=0,other=0;
	printf("请输入一个字符串\n");
	gets(a);
	for(i=0;i<100;i++)
	{
		if(a[i]=='\0') break;
		if(a[i]>='A'&&a[i]<='Z') big++;
		else if(a[i]>='a'&&a[i]<='z') small++;
		else if(a[i]>='0'&&a[i]<='9') shu++;
		else if(a[i]==' ') kong++;
		else other++;
	}
	printf("大写字母有%d个，小写字母有%d个，数字有%d个，空格有%d个，其他标点符号有%d个\n",big,small,shu,kong,other);
}

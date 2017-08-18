/***第四题：数字字符转换为数字***/
#include<stdio.h>
#include<string.h>
void zhuan();
int huan(char x);
int main()
{
	char a[100];
	printf("请输入一个字符串\n");
	gets(a);
	zhuan(a);
}
void zhuan(char *x)
{
	int i,shu=0;
	for(i=0;x[i]!='\0';i++)
        if(x[i]>='0'&&x[i]<='9')
        { 
			shu+=huan(x[i]);
			shu*=10;
		}
	printf("数字为%d\n",shu/10);
}
int huan(char x)
{
	switch(x)
	{
		case '0':return 0;break;
		case '1':return 1;break;
		case '2':return 2;break;
		case '3':return 3;break;
		case '4':return 4;break;
		case '5':return 5;break;
		case '6':return 6;break;
		case '7':return 7;break;
		case '8':return 8;break;
		case '9':return 9;break;
	}
}

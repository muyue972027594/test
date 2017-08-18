/***第一题：找出字符串中的数字***/
#include<stdio.h>
#include<string.h>
int main()
{
    char a[40];
	int i,shu=0,n=0;
    printf("请输入一个字符串\n");
    fgets(a,40,stdin);
    for(i=0;i<strlen(a);i++)
    {
		if(a[i]==':') n=1;
        if(a[i]>='0'&&a[i]<='9'&&n)
		{
            shu+=a[i]-48;
			shu*=10;
        }
    }
    printf("取到的数为%d\n",shu/10);
}


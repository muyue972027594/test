/***第四题：函数代替strcat功能***/
#include<stdio.h>
int main()
{
	char a[30],b[10];
	int i,j,n;
	printf("请输入第一个字符串\n");
	for(i=0;i<30;i++)
	{
		scanf("%c",&a[i]);
		if(a[i]=='\n') break;
	}
	printf("请输入第二个字符串\n");
	for(j=0;j<10;j++)
    {
        scanf("%c",&b[j]);
        if(b[j]=='\n') break;
    }
	for(n=0;n<j;n++)
		a[i+n]=b[n];
	for(n=0;n<i+j;n++)
		printf("%c",a[n]);
	printf("\n");
}

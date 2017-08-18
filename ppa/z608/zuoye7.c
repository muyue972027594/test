/***第七题：实现strcat连接功能***/
#include<stdio.h>
#include<string.h>
void lianjie(char *x,char *y);
int main()
{
    char a[100],b[50];
    printf("请输入第一个字符串\n");
    gets(a);
    printf("请输入第二个字符串\n");
    gets(b);
    lianjie(a,b);
}
void lianjie(char *x,char*y)
{
	int i,n=strlen(x);
	for(i=0;i<=strlen(y);i++)
        x[n+i]=y[i];
	puts(x);
}


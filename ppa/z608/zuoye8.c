/***第八题：实现strcpy复制的功能***/
#include<stdio.h>
#include<string.h>
void fuzhi(char *x,char *y);
int main()
{
    char a[100],b[50];
    printf("请输入第一个字符串\n");
    gets(a);
    printf("请输入第二个字符串\n");
    gets(b);
    fuzhi(a,b);
}
void fuzhi(char *x,char*y)
{
    int i;
    for(i=0;i<=strlen(y);i++)
        x[i]=y[i];
    puts(x);
}


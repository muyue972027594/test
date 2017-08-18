/***第九题：实现strcmp比较功能***/
#include<stdio.h>
#include<string.h>
void bijiao(char *x,char *y);
int main()
{
    char a[100],b[50];
    printf("请输入第一个字符串\n");
    gets(a);
    printf("请输入第二个字符串\n");
    gets(b);
    bijiao(a,b);
}
void bijiao(char *x,char*y)
{
    int i,n=strlen(x);
    for(i=0;i<(strlen(x)>strlen(y)?strlen(x):strlen(y));i++)
    {
		if(x[i]>y[i])
        {
            printf("结果为1,即a>b\n");
            break;
        }
        else if(x[i]<y[i])
        {
            printf("结果为-1,即a<b\n");
            break;
        }
        else continue;
    }
    if(i==(strlen(x)>strlen(y)?strlen(x):strlen(y)))
        printf("结果为0,即a=b\n");
}


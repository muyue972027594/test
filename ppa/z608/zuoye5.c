/***第五题：最大公共子串***/
#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100],c[50],d[50];
	int i,j,k,m,n,s,s1;
	printf("请输入第一个字符串\n");
	gets(a);
	printf("请输入第二个字符串\n");
	gets(b);
	if(strlen(a)<strlen(b))
	{
		for(i=strlen(a);i>0;i--)
			for(j=0;j<=strlen(a)-i;j++)
			{
				s=0;
				for(k=j;k<j+i;k++)
					c[s++]=a[k];
				c[s]='\0';
//				puts(c);
				for(m=0;m<strlen(b)-i;m++)
				{
					s1=0;
					for(n=m;n<m+i;n++)
						d[s1++]=b[n];
					d[s1]='\0';
//					puts(d);
					if(strcmp(c,d)==0)
					{
						printf("最大公共子串为");
						puts(c);
						i=0;j=100;
						break;
					}
				}
			}
	}
	else
    {
        for(i=strlen(b);i>0;i--)
            for(j=0;j<=strlen(b)-i;j++)
            {
                s=0;
                for(k=j;k<j+i;k++)
                    c[s++]=b[k];
                c[s]='\0';
//              puts(c);
                for(m=0;m<strlen(a)-i;m++)
                {
                    s1=0;
                    for(n=m;n<m+i;n++)
                        d[s1++]=a[n];
                    d[s1]='\0';
//                  puts(d);
                    if(strcmp(c,d)==0)
                    {
                        printf("最大公共子串为");
                        puts(c);
                        i=0;j=100;
                        break;
                    }
                }
            }
    }
}

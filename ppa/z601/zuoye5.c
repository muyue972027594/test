/*********************************************************

					是不是回文数？

*********************************************************/
#include<stdio.h>
int main()
{
	int shu,a=1,b,c=0,d;
    printf("请输入一个整数\n");
    scanf("%d",&shu);
    while(1)
    {
		b=shu/a%10;
		a*=10;
        c+=b;
		d=shu/a;
		if(d==0) break;
		c*=10;
    }
	if(c==shu)	printf("此数为回文数\n");
	else	printf("此数不是回文数\n");
}

/***abc+cba=1333***/
#include<stdio.h>
int main()
{
	int a,b,c;
	for(a=1;a<=9;a++)
		for(b=0;b<=9;b++)
			for(c=1;c<=9;c++)
				if(100*a+10*b+c+100*c+10*b+a==1333)
					printf("分别为%d  %d  %d\n",a,b,c);
}

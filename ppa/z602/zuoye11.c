/***200-300,三位数和12,积42***/
#include<stdio.h>
int main()
{
	int i,a,b,c;
	for(i=200;i<=300;i++)
	{
		a=i/100;b=i/10%10;c=i%10;
		if(a+b+c==12&&a*b*c==42)
		printf("%d\t",i);
	}
	printf("\n");
}

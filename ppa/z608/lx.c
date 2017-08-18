#include<stdio.h>
#include<string.h>
int main()
{
	char a[50],b[10];
	fgets(a,20,stdin);
	fgets(b,10,stdin);
	puts(strcpy(a,b));
	printf("%c\n",a[8]);
}

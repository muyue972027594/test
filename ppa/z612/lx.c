#include<stdio.h>
#include<string.h>
void main()
{ char a[20]="ab",b[20]="lmnp";
	int i=0;
	strcat(a,b);
	while(a[i++]!='\0')
	{
		printf("%d\n",i);
		 b[i]=a[i];
	}
  puts(b);
}

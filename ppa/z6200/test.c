#include<stdio.h>
#include<string.h>
int main()
{
	char a[5][10]={"任超","二五","光阳","三五","任小超"},b[10];
	int i,j;
	for(i=0;i<5;i++)
		for(j=i+1;j<5;j++)
			if(strcmp(a[i],a[j])>0)
			{
				strcpy(b,a[i]);strcpy(a[i],a[j]);strcpy(a[j],b);
			}			
	for(i=0;i<5;i++)
		printf("%s\n",a[i]);
}

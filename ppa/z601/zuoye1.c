/****************************************************

			1-100之间能被3整除的数

***************************************************/
#include<stdio.h>
int main()
{
	int i=0,b=0;
/*	for(i=1;i<=100;i++)
	{
		while(i%3==0) 
		{
			printf("%d\t",i);
			b++;
			while(b%5==0)
			{
				printf("\n");
				break;
			}
			break;
		}
	}
	printf("\n");
*/	do
	{
		i++;
		if(i%3==0)
		{
			printf("%d\t",i);
			b++;
			if(b%5==0) printf("\n");
		}
	}
	while(i<=100);
	printf("\n");
}

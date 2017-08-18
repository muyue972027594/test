/***第六题：按0结束输入，保留较大的五个数***/
#include<stdio.h>
void fun(int*x);
int main()
{
	int s[6],i=0;
	printf("请输入几个整数\n");
	do
	{
		scanf("%d",&s[i]);
		if(i<5) i++;
		else fun(s);
	} while(s[5]!=0);
    for(i=0;i<5;i++)
        printf("%d ",*(s+i));
    printf("\n");
}
void fun(int *x)
{
	int min,i,k;
	min=*x;k=0;
	for(i=0;i<5;i++)
		if(min>*(x+i))
		{
			min=*(x+i);k=i;
		}
	if(*(x+k)<x[5])
		*(x+k)=x[5];
}

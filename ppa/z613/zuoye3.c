/***第三题：统计某数的次数***/
#include<stdio.h>
void coun(int*x,int*y,int z);
int main()
{
    int s[10],i,k=0,shu,*p;
	p=&k;
    printf("请输入十个整数\n");
    for(i=0;i<10;i++)
        scanf("%d",&s[i]);
    printf("请输入要统计的数\n");
    scanf("%d",&shu);
	coun(s,p,shu);
    printf("%d出现了%d次\n",shu,k);
}
void coun(int*x,int*y,int z)
{
	int i;
    for(i=0;i<10;i++)
    	if(z==x[i]) 
			(*y)++;    
}

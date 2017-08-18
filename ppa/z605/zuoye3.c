/***统计某数的次数***/
#include<stdio.h>
int main()
{
    int s[10],i,k=0,shu;
    printf("请输入十个整数\n");
    for(i=0;i<10;i++)
        scanf("%d",&s[i]);
    printf("请输入要统计的数\n");
    scanf("%d",&shu);
    for(i=0;i<10;i++)
    	if(shu==s[i]) 
			k++;    
    printf("%d出现了%d次\n",shu,k);
}
                       

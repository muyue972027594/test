/**********  7的相关数  ******************/
#include<stdio.h>
int main()
{
    int n,a,b,i,j=0,k,s[6000];
    printf("请输入一个四位数以下的整数\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
		a=i;
        for(k=0;a!=0;)
        {	
			b=a%10;
			if(b==7)
			{
            	j++;s[j]=i;
				break;
			}
			else if(i%7==0)
			{
				j++;s[j]=i;
				break;
			}
			a/=10;
        }
    }
    printf("%d个(",j);
    for(i=1;j>=i;i++)
    {
        printf("%d",s[i]);
        if(j!=i) printf("、");
        else printf(")\n");
    }
}


/********************************************************

				1-100之间所有奇数的和

*********************************************************/
#include<stdio.h>
int main()
{
	int i=0,b=0,sum=0;
	for(i=1;i<=100;i++)
    {
        while(i%2==1) 
        {
			sum+=i;
            printf("%2d\t",i);
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
	printf("和为%d\n",sum);
}

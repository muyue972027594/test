/***************************************************************

					输出指定大小的菱形

**************************************************************/
#include<stdio.h>
int main()
{
	int i,j,k,a;
	printf("请输入菱形的行数(必须为奇数)\n");
	scanf("%d",&a);
	for(i=0;i<=a/2;i++)
	{
		for(j=0;j<a/2-i;j++)
			printf(" ");
		for(k=0;k<1+2*i;k++)
			printf("*");
		printf("\n");
	}
	for(i=a-a/2;i<a;i++)
	{
		for(j=0;j<i-a/2;j++)
			printf(" ");
		for(k=0;k<a-2*(i-a/2);k++)
			printf("*");
		printf("\n");
	}
}
/*
          *          
*                   *
          *
  *  
*   *
  *
     *
    * *
   *   *
  *     *
 *       *
*         *
 *       *
  *     *
   *   *
    * *
     *
     *  
    ***
  *******
***********
  *******
    ***
     *
     *
***********
     *
*/
/****************************************************

					找零多少？
***************************************************/
#include<stdio.h>
int main()
{
	int con,pay,cha;int a1=100,a5=100,a10=100,a20=100,a50=100,b1,b5,b10,b20,b50;
	printf("请依次输入消费金额和付款金额\n");
	scanf("%d%d",&con,&pay);
	cha=pay-con;b50=cha/50;b20=(cha%50)/20;b10=((cha%50)%20)/10;
	b5=(((cha%50)%20)%10)/5;b1=((((cha%50)%20)%10)%5)/1;
	printf("找零%d元\n",cha);
	a50-=b50;a20-=b20;a10-=b20;a5-=b5;a1-=b1;
	printf("#推荐找零");
	if(b50>0)printf("50元%d张,",b50);
	if(b20>0)printf("20元%d张,",b20);
	if(b10>0)printf("10元%d张,",b10);
	if(b5>0)printf("5元%d张,",b5);
	if(b1>0)printf("1元%d张\n",b1);
	printf("#推荐找零50元%d张,20元%d张,10元%d张,5元%d张,1元%d张\n",b50,b20-b20,b10+2*b20,b5,b1);
}
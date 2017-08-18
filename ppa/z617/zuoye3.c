/***第三题：商品信息***/
#include<stdio.h>
#include<string.h>
int main()
{
	struct shop
	{
		char num[10];
		char name[30];
		char day[10];
		float pri;
		int count;
	};
	struct shop a[4]={{"666001001","猴头菇饼干65g","20170406",7.5,100},
						{"666001002","小熊饼干80g","20170503",8.0,80},
						{"666002001","蒙牛优酸乳330ml","20170605",4.0,200},
						{"666002002","美汁源果粒橙500ml","20170528",3.5,150}};
	char *p={"编号:%s 商品名:%-22s 生产日期:%s 单价:%-5g元 数量:%-5d\n"};
	int i;
	for(i=0;i<4;i++)
		printf(p,a[i].num,a[i].name,a[i].day,a[i].pri,a[i].count);
}

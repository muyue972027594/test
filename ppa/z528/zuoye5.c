/**********************************************************************

					 		电费、水费计算

*********************************************************************/
#include<stdio.h>
float ch_e(int x);
float ch_w(float x,int y);
int main()
{
	int a,a1,b;float c;
	printf("请选择功能\n#计算电费——1,计算水费——2\n");
	scanf("%d",&a);
	switch(a)
	{
		case 1:
			{
 				printf("请输入用电量(单位:度)\n");
   				scanf("%d",&b);
    			printf("电费为%g元\n",ch_e(b));

			}
				break;
		case 2:
			{
				printf("请选择用水类别\n");
				printf("#生活用水——1,事业用水——2,工业用水——3,服务用水——4,特种用水——5\n");
				scanf("%d",&a1);
				if(a1>0&&a1<6)
				{
                	printf("请输入用水量(单位:立方米)\n");
                	scanf("%f",&c);
				}
				else printf("输入错误\n");
                printf("水费为%g元\n",ch_w(c,a1));
            }
				break;
		default:printf("输入错误\n");
	}
}
float ch_e(int x)
{
	float num;
    if(x>=0&&x<=170) num=x*0.477;
    else if(x>170&&x<=260) num=170*0.477+(x-170)*0.527;
    else if(x>260) num=170*0.477+90*0.527+(x-260)*0.777;
	return num;
}
float ch_w(float x,int y)
{
	switch(y)
	{
		case 1:return x*2.9;break;
		case 2:return x*3.2;break;
		case 3:return x*4.2;break;
		case 4:return x*5.6;break;
		case 5:return x*49;
	}
}	

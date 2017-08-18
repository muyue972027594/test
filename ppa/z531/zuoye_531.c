/************************************************************************

							输入题号找题

*************************************************************************/
#include<stdio.h>
void zuoye1();
void zuoye2();
void zuoye3();
void zuoye4();
void zuoye5();
void zuoye6();
float max(float x,float y,float z);
float mid(float x,float y,float z);
float min(float x,float y,float z);
float ch_e(int x);
float ch_w(float x,int y);
void xinghao();
void hanzi(int x);
void xun(int x);
void main()
{
	int tihao;
	printf("请输入题号：\n");
	scanf("%d",&tihao);
	switch(tihao)
	{
		case 1:zuoye1();break;
		case 2:zuoye2();break;
		case 3:zuoye3();break;
		case 4:zuoye4();break;
		case 5:zuoye5();break;
		case 6:zuoye6();break;
		default:printf("无此题！\n");
	}
}
void zuoye1()
{
	float a,b,c;
	printf("<第一题:输入三个数，输出**最大值，中间值，最小值**>\n");
	printf("#请输入三个数\n");
	scanf("%f%f%f",&a,&b,&c);
	xinghao();
	printf("               最大值为：%g\n               中间值为：%g\n               最小值为：%g\n",max(a,b,c),mid(a,b,c),min(a,b,c));
	xinghao();
}
void zuoye2()
{
	float a2;
	printf("<第二题：判断正负>\n");
	printf("#请输入要判断的数\n");
	scanf("%f",&a2);
	if(a2>0) printf("判断结果为“+”\n");
	else if(a2<0) printf("判断结果为“-”\n");
	else printf("判断结果为“0”\n");
}
void zuoye3()
{
	float w;
	printf("<第三题：托运收费>\n");
	printf("#请输入托运行李的重量(公斤)\n");
	scanf("%f",&w);
	if(w<=50) printf("托运费为%g元\n",0.15*w);
	else printf("托运费为%g元\n",0.15*50+0.25*(w-50));
}
void zuoye4()
{
	int a4,b4,c4,d4,year1,year2,year3,year4;
	printf("<第四题：月份输出为第几季度第几月>\n");
	printf("#请输入年和月(用逗号隔开)\n");
	scanf("%d,%d",&a4,&b4);
	switch(b4)
	{
		case 1:c4=1;d4=1;break;
		case 2:c4=1;d4=2;break;
		case 3:c4=1;d4=3;break;
		case 4:c4=2;d4=1;break;
		case 5:c4=2;d4=2;break;
		case 6:c4=2;d4=3;break;
		case 7:c4=3;d4=1;break;
		case 8:c4=3;d4=2;break;
		case 9:c4=3;d4=3;break;
		case 10:c4=4;d4=1;break;
		case 11:c4=4;d4=2;break;
		case 12:c4=4;d4=3;
	}
	year1=a4/1000;year2=a4/100%10;year3=a4/10%10;year4=a4%10;
	hanzi(year1);hanzi(year2);hanzi(year3);hanzi(year4);printf("年第");
	hanzi(c4);printf("季度第");
	hanzi(d4);printf("月份\n");
}
void zuoye5()
{
	int a5,b5,c5,d5,year1,year2,year3,year4,day;
	printf("<第五题：日期转换为(上中下)旬第几天>\n");
	printf("#请输入年月日(分别用逗号隔开)\n");
	scanf("%d,%d,%d",&a5,&b5,&c5);
	if(c5<=10) { d5=0;day=c5;}
	else if(c5<=20) { d5=1;day=c5-10;}
	else { d5=2;day=c5-20;}
	year1=a5/1000;year2=a5/100%10;year3=a5/10%10;year4=a5%10;
    hanzi(year1);hanzi(year2);hanzi(year3);hanzi(year4);printf("年第");
	hanzi(b5);printf("月");
	xun(d5);printf("旬第");
	hanzi(day);printf("天\n");
}
void zuoye6()
{
    int a6,a1,b;float c;
	printf("<第六题：常用费用计算(水费、电费)>\n");
    printf("请选择功能\n#计算电费——1,计算水费——2\n");
    scanf("%d",&a6);
    switch(a6)
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
                printf("#生活用水——1,事业用水——2,工业用水——3,服务用水——4,特种用>水——5\n");
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
float max(float x,float y,float z)
{
    float x1;
    x1=(x>y)?x:y;x1=(x1>z)?x1:z;
    return x1;
}
float mid(float x,float y,float z)
{
    float y1;
    if(x<y){ y1=x;x=y;y=y1;}
    if(x<z){ y1=x;x=z;z=y1;}
    if(y<z){ y1=y;y=z;z=y1;}
    return y;
}
float min(float x,float y,float z)
{
    float z1;
    z1=(x>y)?y:x;z1=(z1>z)?z:z1;
    return z1;
}
void xinghao()
{
    int i;
    for(i=0;i<40;i++)  printf("*");
    if(i==40) printf("\n");
}

void hanzi(int x)
{
	switch(x)
	{
		case 0:printf("零");break;
		case 1:printf("一");break;
		case 2:printf("二");break;
		case 3:printf("三");break;
		case 4:printf("四");break;
		case 5:printf("五");break;
		case 6:printf("六");break;
		case 7:printf("七");break;
		case 8:printf("八");break;
		case 9:printf("九");break;
		case 10:printf("十");break;
		case 11:printf("十一");break;
		case 12:printf("十二");break;
	}
}
void xun(int x)
{
	switch(x)
	{
		case 0:printf("上");break;
		case 1:printf("中");break;
		case 2:printf("下");break;
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


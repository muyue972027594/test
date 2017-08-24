/***************************************************************8
文件名：zhixing.c
功  能：执行系统
版本号：0.0.1
***************************************************************/
#include"headfile.h"


/*执行杀虫操作*/
void shachong(short x)
{
	if(x == 1)
		printf("正在杀虫！\n");
	if(x == 2)
		printf("杀虫异常！\n");
}


/*执行施肥操作*/
void shifei(short x)
{
	if(x == 1)
		printf("正在施肥！\n");
	if(x == 2)
		printf("施肥异常！\n");

}


/*执行浇水操作*/
void jiaoshui(short x)
{
	if(x == 1)
		printf("正在浇水！\n");
	if(x == 2)
		printf("浇水异常！\n");
}



/*执行加热操作*/
void jiare(short x)
{
	if(x == 1)
		printf("正在加热！\n");
	if(x == 2)
		printf("加热异常！\n");
}



/*执行通风操作*/
void tongfeng(short x)
{
	if(x == 1)
		printf("正在通风！\n");
	if(x == 2)
		printf("通风异常！\n");
}



/*执行补光操作*/
void buguang(short x)
{
	if(x == 1)
		printf("开启补光！\n");
	if(x == 2)
		printf("补光异常！\n");
}


/*产生CO2操作*/
void makeCO2(short x)
{
	if(x == 1)
		printf("正在产生CO2！\n");
	if(x == 2)
		printf("产生CO2异常！\n");

}

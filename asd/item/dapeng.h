#ifndef DAPENG_H
#define DAPENG_H

#include"headfile.h"

/*检测数据结构体*/
typedef struct shuju
{
	short Airtem;//空气温度
	short Airhum;//空气湿度
	short Soiltem;//土壤温度
	short Soilhum;//土壤湿度
	short pot;//二氧化碳浓度
	short lum;//光照强度（需乘以100）
	short kl_bug;//杀虫
	short sp_manu;//施肥
	short water_bk;//浇水反馈
	short heat_bk;//加热反馈
	short wind_bk;//通风反馈
	short make_bk;//产生CO2反馈
	short light_bk;//补光反馈
} DATA;


/*执行命令结构体*/
typedef struct mingling
{
	short water;
	short heat;
	short wind;
	short light;
	short kill;
	short manur;
	short make;
} CMD;



struct st
{
	int sock;
	CMD cmd1;
};


/*数据检测函数*/
short Airwendu();
short Airshidu();
short Soilwendu();
short Soilshidu();
short CO2();
short guang();

/*执行检测函数*/
short Te_water();
short Te_heat();
short Te_wind();
short Te_light();
short Te_make();

/*执行函数*/
void shachong(short x);
void shifei(short x);
void jiaoshui(short x);
void jiare(short x);
void tongfeng(short x);
void buguang(short x);
void makeCO2(short x);


void* WaitCMD(void *arg);
void sove(int num,struct st *buf,DATA *data);
#endif

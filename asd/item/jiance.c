/****************************************************8
文件名：jiance.c
功  能：监测系统
版本号：0.0.1
********************************************************/
#include"headfile.h"


/*空气温度检测(0 ~ 50度)*/
short Airwendu()
{
    short tem;

    srand((int)time(0));

    tem = 0 + (int)(50.0 * rand() / (RAND_MAX + 1.0));

    return tem;
}


/*空气湿度检测(10% ~ 90%)*/
short  Airshidu()
{
    short hum;

    srand((int)time(0));

    hum = 10 + (int)(80.0 * rand() / (RAND_MAX + 1.0));

    return hum;
}


/*二氧化碳浓度检测(50 ~ 1550 ppm)*/
short CO2()
{
    short pot;

    srand((int)time(0));

    pot = 50 + (int)(1500.0 * rand() / (RAND_MAX + 1.0));

    return pot;
}


/*土壤温度检测(5 ~ 30度)*/
short Soilwendu()
{
    short tem;

    srand((int)time(0));

    tem = 5 + (int)(25.0 * rand() / (RAND_MAX + 1.0));

    return tem;
}


/*土壤湿度检测(5% ~ 85%)*/
short Soilshidu()
{
    short hum;

    srand((int)time(0));

    hum = 5 + (int)(80.0 * rand() / (RAND_MAX + 1.0));

    return hum;
}


/*光照检测(1 ~ 1001)百LX*/
short guang()
{
    short lum;

    srand((int)time(0));

    lum = 1 + (int)(1000.0 * rand() / (RAND_MAX + 1.0));

    return lum;
}

/*浇水系统反馈*/
short Te_water()
{
    short Te_hum;

	srand((int)time(0));
	Te_hum = 29 + (int)(30.0 * rand() / (RAND_MAX + 1.0));

    return Te_hum;
}


/*加热系统反馈*/
short Te_heat()
{
    short Te_tem;

    srand((int)time(0));
	Te_tem = 11 + (int)(10.0 * rand() / (RAND_MAX + 1.0));

    return Te_tem;
}


/*通风系统反馈*/
short Te_wind()
{
    short Te_pot;

    srand((int)time(0));
	Te_pot = 1100 + (int)(150.0 * rand() / (RAND_MAX + 1.0));

    return Te_pot;
}


/*产生CO2反馈*/
short Te_make()
{
    short Te_pot;

    srand((int)time(0));
	Te_pot = 90 + (int)(350.0 * rand() / (RAND_MAX + 1.0));

    return Te_pot;
}


/*补光系统反馈*/
short Te_light()
{
    short Te_lum;

    srand((int)time(0));
	Te_lum = 150 + (int)(300.0 * rand() / (RAND_MAX + 1.0));

    return Te_lum;
}


















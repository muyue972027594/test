#include"headfile.h"
#include"dapeng.h"

int main()
{
	for( int i = 0;1;i++)
	{
		printf("Airwendu(0-50)  = %d\n",Airwendu());
		printf("Airshidu(10-90)  = %d\n",Airshidu());
		printf("Soilwendu(5-30)  = %d\n",Soilwendu());
		printf("Soilshidu(5-85)  = %d\n",Soilshidu());
		printf("CO2(50-1550)  = %d\n",CO2());
		printf("guang(1-1001)  = %d\n",guang());
		printf("Te_water  = %d\n",Te_water());
		printf("Te_heat  = %d\n",Te_heat());
		printf("Te_wind  = %d\n",Te_wind());
		printf("Te_light  = %d\n",Te_light());

		shachong(Te_water());
		shifei(Te_water());
		jiaoshui(Te_water());
		jiare(Te_water());
		tongfeng(Te_water());
		buguang(Te_water());

		printf("\n\n");

		sleep(2);
	}


}

/****************************************************************
文件名：dapeng.c
功  能：大棚内部系统（控制系统，监测系统，执行系统）
版本号：0.0.1

*******************************************************************/
#include "headfile.h"
#include "dapeng.h"



int main(int argc ,char *argv[])
{
	struct sockaddr_in to_addr;
	int ret = 0;
	DATA data1;
	struct st buf1;
	int num = 0;
	pthread_t pth = 0;

	memset(&data1,0,sizeof(data1));
	memset(&buf1,0,sizeof(buf1));
	to_addr.sin_family = AF_INET;
	to_addr.sin_port = TOPORT;
	to_addr.sin_addr.s_addr = TOIP;

	buf1.sock = socket(AF_INET,SOCK_STREAM,0);
	if(buf1.sock < 0)
	{
		perror("socket error");
		exit(-1);
	}

	ret = connect(buf1.sock,(struct sockaddr*)&to_addr,sizeof(to_addr));
	if(ret < 0)
	{
		perror("connect error");
		exit(-1);
	}	

	ret = send(buf1.sock,"dapeng",sizeof("dapeng"),0);
    if(ret < 0)
    {
        perror("send error");
        exit(-1);
    }

	ret = pthread_create(&pth,NULL,WaitCMD,&buf1);
	if(ret != 0)
	{
		printf("pthread error!\n");
		exit(-1);
	}

	while(1)
	{
		num++;

		data1.Airtem = Airwendu();
		data1.Airhum = Airshidu();
		data1.Soiltem = Soilwendu();
		data1.Soilhum = Soilshidu();
		data1.pot = CO2();
		data1.lum = guang();

		sove(num,&buf1,&data1);
		memset(&buf1.cmd1,2,sizeof(buf1.cmd1));

		printf("空气温度 %d，空气湿度 %d \n",data1.Airtem,data1.Airhum);
		printf("土壤温度 %d，土壤湿度 %d \n",data1.Soiltem,data1.Soilhum);
		printf("CO2浓度 %d，光照强度 %d \n",data1.pot,data1.lum);
		shachong(data1.kl_bug);
		shifei(data1.sp_manu);
		jiaoshui(data1.water_bk);
		jiare(data1.heat_bk);
		tongfeng(data1.wind_bk);
		buguang(data1.light_bk);
		makeCO2(data1.make_bk);
		printf("\n\n");

				
		ret = send(buf1.sock,&data1,sizeof(data1),0);
		if(ret < 0)
		{
			perror("send error");
			exit(-1);
		}		

		sleep(5);
	}

}


void sove(int num,struct st *buf,DATA *data)
{
		
		if(num == 20)
		{
			data->kl_bug = 1;
		}
		else
		{
			data->kl_bug = 0;
		}

		if(num % 15 == 0)
		{
			data->sp_manu = 1;
		}
		else
		{
			data->sp_manu = 0;
		}
		
		if(data->Airtem < 15 || (data->Airtem < 30 && buf->cmd1.heat == 1))
		{
			data->heat_bk = 1;
			if(data->Airtem > Te_heat())
				data->heat_bk = 2;
		}
		if(data->Airtem > 30 || (data->Airtem > 15 && buf->cmd1.heat == 0))
		{
			data->heat_bk = 0;
			if(data->Airtem < Te_heat())
				data->heat_bk = 2;
		}
	
		if(data->Soilhum < 30 || (data->Soilhum < 60 && buf->cmd1.water == 1))
		{
			data->water_bk = 1;
			if(data->Soilhum > Te_water())
				data->water_bk = 2;
		}
		if(data->Soilhum > 60 || (data->Soilhum > 30 && buf->cmd1.water == 0))
		{
			data->water_bk = 0;
			if(data->Soilhum < Te_water())
				data->water_bk = 2;
		}

		if(data->pot > 1200 || (data->pot > 800 && buf->cmd1.wind == 1))
		{
			data->wind_bk = 1;
			if(data->pot < Te_wind())
				data->wind_bk = 2;
		}
		if(data->pot < 800 || (data->pot < 1200 && buf->cmd1.wind == 0))
		{
			data->wind_bk = 0;
			if(data->pot > Te_wind())
				data->wind_bk = 2;
		}

		if(data->lum < 100 || (data->lum < 300 && buf->cmd1.light == 1))
		{
			data->light_bk = 1;
			if(data->lum > Te_light())
				data->light_bk = 2;
		}
		if(data->lum > 300 || (data->lum > 100 && buf->cmd1.light == 0))
		{
			data->light_bk = 0;
			if(data->lum < Te_light())
				data->light_bk = 2;
		}

		if(data->pot < 100 || (data->pot < 800 && buf->cmd1.make == 1))
		{
			data->make_bk = 1;
			if(data->pot > Te_make())
				data->make_bk = 2;
		}
		if(data->pot > 800 || (data->pot > 100 && buf->cmd1.make == 0))
		{
			data->make_bk = 0;
			if(data->pot < Te_make())
				data->make_bk = 2;
		}

}



void* WaitCMD(void *arg)
{
	struct st *re_cmd = (struct st *)arg;
	int ret = 0;
	
	while(1)
	{
		ret = recv(re_cmd->sock,&re_cmd->cmd1,sizeof(re_cmd->cmd1),0);
		if(ret < 0)
		{
			perror("recv error");
			pthread_exit(NULL);
		}

		printf("I RECV IT!\n");
	}

	pthread_exit(NULL);
}

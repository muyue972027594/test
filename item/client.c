/*******************************************
文件名：client.c
功  能：客户端(查看数据)
版本号：0.0.1
*******************************************************/
#include"headfile.h"
#include"client.h"


int main(int argc,char *argv[])
{
	struct sockaddr_in to_addr;
    int ret = 0;
    int sock = 0;
	int menu = 0;
    pthread_t pth = 0;


    to_addr.sin_family = AF_INET;
    to_addr.sin_port = TOPORT;
    to_addr.sin_addr.s_addr = TOIP;

    sock = socket(AF_INET,SOCK_STREAM,0);
    if(sock < 0)
    {
        perror("socket error");
        exit(-1);
    }

    ret = connect(sock,(struct sockaddr*)&to_addr,sizeof(to_addr));
    if(ret < 0)
    {
        perror("connect error");
        exit(-1);
    }

	ret = send(sock,"client",sizeof("client"),0);
    if(ret < 0)
    {
        perror("send error");
        exit(-1);
    }


	do
	{

		printf("请选择功能：0.退出；1.查询；2.操控； \n");
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:cli_sel(&sock);break;
			case 2:cli_ctr(&sock);break;
			case 0:cli_end(&sock);

		}

	}
	while(menu);


}


void *cli_sel(void *arg)
{
	int sock = *(int *)arg;

    int ret = 0;
    struct sel_data mydata1;
	char cli_cmd[50] = {0};
	char FRtime[20] = {0};
	char cmd_mon[10] = {0};
	char cmd_day[10] = {0};
	char cmd_time[10] = {0};

	memset(FRtime,0,sizeof(FRtime));	
	memset(cli_cmd,0,sizeof(cli_cmd));	
	
	printf("请输入查询的日期\n");
	printf("例如：8.21.13:50\n");
	scanf("%s",FRtime);
	
	sprintf(cmd_mon,"%s",strtok(FRtime,"."));
	sprintf(cmd_day,"%s",strtok(NULL,"."));
	sprintf(cmd_time,"%s",strtok(NULL,"."));

	sprintf(cli_cmd,"$$%s,%s %s %s##","sel",mon_chge(atoi(cmd_mon)),cmd_day,cmd_time);

	puts(cli_cmd);

	ret = send(sock,cli_cmd,sizeof(cli_cmd),0);
    if(ret < 0)
    {
		perror("send error");
        exit(-1);
    }

	while(1)
	{
		memset(&mydata1,0,sizeof(mydata1));
			
		ret = recv(sock,&mydata1,sizeof(mydata1),0);
    	if(ret < 0)
    	{
    	    perror("recv error");
    	    exit(-1);
    	}
			
		if(strcmp(mydata1.sel_time,"#$") == 0) break;
		printf("%s ",mydata1.sel_time);
		printf("%5d ",mydata1.sel_data.Airtem);
		printf("%5d ",mydata1.sel_data.Airhum);
		printf("%5d ",mydata1.sel_data.Soiltem);
		printf("%5d ",mydata1.sel_data.Soilhum);
		printf("%5d ",mydata1.sel_data.pot);
		printf("%5d ",mydata1.sel_data.lum);
		printf("%5d ",mydata1.sel_data.kl_bug);
		printf("%5d ",mydata1.sel_data.sp_manu);
		printf("%5d ",mydata1.sel_data.water_bk);
		printf("%5d ",mydata1.sel_data.heat_bk);
		printf("%5d ",mydata1.sel_data.wind_bk);
		printf("%5d ",mydata1.sel_data.light_bk);
		printf("%5d ",mydata1.sel_data.make_bk);
		printf("\n");

	}

}




void *cli_ctr(void *arg)
{
	int sock = *(int *)arg;

    int ret = 0;
    struct sel_data mydata1;
	char cli_cmd[50] = {0};
	char FRtime[10] = {0};
	char password[15] = {0};

	memset(FRtime,0,sizeof(FRtime));	
	memset(cli_cmd,0,sizeof(cli_cmd));	

	printf("请输入操作密码\n");
	scanf("%s",password);
	if(strcmp(password,"123456") == 0)
	{	
		printf("请输入操作命令(七位的二进制数)\n");
    	printf("例如：0110011\n");
		printf("依次为杀虫、施肥、浇水、加热、通风、产生CO2、补光\n");
    	scanf("%s",FRtime);

		sprintf(cli_cmd,"$$%s,%s##","ctr",FRtime);

		puts(cli_cmd);

		ret = send(sock,cli_cmd,sizeof(cli_cmd),0);
    	if(ret < 0)
    	{
			perror("send error");
        	exit(-1);
    	}
	}else
		printf("密码错误，不可操作！\n");

}


void *cli_end(void *arg)
{
	int sock = *(int *)arg;

    int ret = 0;
    struct sel_data mydata1;
	char cli_cmd[50] = {0};
	char FRtime[10] = "end";

	sprintf(cli_cmd,"$$%s,%s##","end",FRtime);

	puts(cli_cmd);

	ret = send(sock,cli_cmd,sizeof(cli_cmd),0);
    if(ret < 0)
    {
		perror("send error");
        exit(-1);
    }

}



char *mon_chge(int x)
{
	switch(x)
	{
		case 1:return "Jan";break;
		case 2:return "Feb";break;
		case 3:return "Mar";break;
		case 4:return "Apr";break;
		case 5:return "May";break;
		case 6:return "Jun";break;
		case 7:return "Jul";break;
		case 8:return "Aug";break;
		case 9:return "Sep";break;
		case 10:return "Oct";break;
		case 11:return "Nov";break;
		case 12:return "Dec";break;

	}

}











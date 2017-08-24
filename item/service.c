/*******************************************************8
文件名：service.c
功  能：服务器端：接收检测数据，存储到数据库，与客户端交互
版本号：0.0.1
***********************************************************/
#include"headfile.h"
#include"dapeng.h"
#include"service.h"




int main(int argc,char *argv[])
{
	struct sockaddr_in my_addr;
	struct sockaddr_in from_addr;
	int size = sizeof(from_addr);
	int TOsock = 0,ret = 0;
	int sock = 0;
	int i = 0;
	MYSQL mysql;
	CMD cmd1;
	struct SER1 ser[10];
	pthread_t pth[2] = {0};
	char sel_buf[15] = {0};

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = MYPORT;
	my_addr.sin_addr.s_addr = MYIP;

	sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock < 0)
	{
		perror("socket error");
		exit(-1);
	}

	ret = bind(sock,(struct sockaddr*)&my_addr,sizeof(my_addr));
	if(ret < 0)
	{
		perror("bind error");
		exit(-1);
	}

	ret = listen(sock,5);
	if(ret < 0)
	{
		perror("listen error");
		exit(-1);
	}

	mysql_init(&mysql);
	if(mysql_real_connect(&mysql,"localhost",
							"root","123","dapeng",0,NULL,0) ==NULL)
	{
		printf("connect error:%s\n",mysql_error(&mysql));
		pthread_exit(NULL);
	}
	else
		printf("connect ok!\n");

	while(1)
	{
		TOsock = accept(sock,(struct sockaddr*)&from_addr,&size);
		if(TOsock < 0)
		{
			perror("accept error");
			exit(-1);
		}
		
		memset(sel_buf,0,sizeof(sel_buf));
		memset(&ser[i],0,sizeof(ser[i]));
		
		ret = recv(TOsock,sel_buf,sizeof(sel_buf),0);
        if(ret < 0)
        {
            perror("recv error");
            exit(-1);
        }
	
		ser[i].sock = TOsock;
		ser[i].mysql = mysql;
		ser[i].cmd_p = &cmd1;

		if(strcmp(sel_buf,"dapeng") == 0)
		{
			ret = pthread_create(&pth[0],NULL,ser_dapeng,&ser[i]);
			if(ret != 0)
		    {
        		printf("pthread error!\n");
        		exit(-1);
    		}
			ret = pthread_create(&pth[0],NULL,ser_send,&ser[i]);
			if(ret != 0)
		    {
        		printf("pthread error!\n");
        		exit(-1);
    		}
			i++;
		}

		if(strcmp(sel_buf,"client") == 0)
		{
			ret = pthread_create(&pth[1],NULL,ser_cli,&ser[i]);
            if(ret != 0)
            {
                printf("pthread error!\n");
                exit(-1);
            }
		}
		

	}

	
}


void *ser_dapeng(void *arg)
{

	struct SER1 ser = *(struct SER1 *)arg;

	int TOsock = ser.sock;
	int ret = 0;
	DATA data1;
	MYSQL mysql = ser.mysql;
	char sql[300] = {0};
	time_t timep;
	char ch_time[30] = {0};

	while(1)
	{

		ret = recv(TOsock,&data1,sizeof(data1),0);
		if(ret < 0)
    	{
    	    perror("recv error");
    	    pthread_exit(NULL);
    	}

		memset(&sql,0,sizeof(sql));

		time(&timep);
		sprintf(ch_time,"%s",ctime(&timep));
		ch_time[strlen(ch_time) - 1] = '\0';
		sprintf(sql,"insert into ser_dap_data values('%s',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d)",ch_time,data1.Airtem,data1.Airhum,data1.Soiltem,
					data1.Soilhum,data1.pot,data1.lum,data1.kl_bug,
					data1.sp_manu,data1.water_bk,data1.heat_bk,data1.wind_bk,
					data1.light_bk,data1.make_bk);

		if(mysql_real_query(&mysql,sql,strlen(sql)) != 0)
		{
			printf("DAP query error:%s\n",mysql_error(&mysql));
        	pthread_exit(NULL);
		}
		else
        	printf("DAP query ok!\n");

	}

	close(TOsock);
	mysql_close(&mysql);

	pthread_exit(NULL);

}


void *ser_send(void *arg)
{
	struct SER1 *ser = (struct SER1 *)arg;
	int TOsock = ser->sock;
	int ret = 0;

	while(1)
    {
		if(ser->cmd_p->water < 2 || ser->cmd_p->heat < 2
					|| ser->cmd_p->wind < 2 || ser->cmd_p->light < 2
					|| ser->cmd_p->kill < 2 || ser->cmd_p->manu < 2
					|| ser->cmd_p->make < 2)
		{

        	ret = send(TOsock,ser->cmd_p,sizeof(CMD),0);
        	if(ret < 0)
        	{
        	    perror("recv error");
        	    pthread_exit(NULL);
        	}

			memset(ser->cmd_p,3,sizeof(CMD));
		}
	}
}


void *ser_cli(void *arg)
{

	struct SER1 *ser = (struct SER1 *)arg;

	int TOsock = ser->sock;
	int ret = 0;
	struct sel_data mydata1;
	MYSQL mysql = ser->mysql;
	MYSQL_RES *res;
	MYSQL_ROW row;
	char sql[300] = {0};
	char cmd_c1[20] = {0};
	char cmd_c2[20] = {0};
	char cli_cmd[30] = {0};


	while(1)
	{
		memset(cli_cmd,0,sizeof(cli_cmd));
		ret = recv(TOsock,cli_cmd,sizeof(cli_cmd),0);
		if(ret < 0)
    	{
    	    perror("recv error");
    	    exit(-1);
    	}

		puts(cli_cmd);

		memset(sql,0,sizeof(sql));	
		memset(cmd_c1,0,sizeof(cmd_c1));
		memset(cmd_c2,0,sizeof(cmd_c2));

		if((cli_cmd[0] != '$' && cli_cmd[1] != '$') 
			|| (cli_cmd[strlen(cli_cmd) - 2] !='#' 
			&& cli_cmd[strlen(cli_cmd) - 1] !='#'))
			continue;

		sprintf(cmd_c1,"%s",strtok(cli_cmd,"$,#"));
		sprintf(cmd_c2,"%s",strtok(NULL,"$,#"));

		if(strcmp("end",cmd_c1) == 0) 
			break;			

		if(strcmp("ctr",cmd_c1) == 0)
		{
			ser->cmd_p->kill = atoi(&cmd_c2[0]);
			ser->cmd_p->manu = atoi(&cmd_c2[1]);
			ser->cmd_p->water = atoi(&cmd_c2[2]);
			ser->cmd_p->heat = atoi(&cmd_c2[3]);
			ser->cmd_p->wind = atoi(&cmd_c2[4]);
			ser->cmd_p->make = atoi(&cmd_c2[5]);
			ser->cmd_p->light = atoi(&cmd_c2[6]);
		}

		if(strcmp("sel",cmd_c1) == 0)
		{
			
			sprintf(sql,"select * from ser_dap_data where time like '%%%s%%'",
						cmd_c2);	
			puts(sql);

			if(mysql_real_query(&mysql,sql,strlen(sql)) != 0)
	        {
	            printf("CLI query error:%s\n",mysql_error(&mysql));
	            pthread_exit(NULL);
	        }
	        else
	            printf("CLI query ok!\n");
		
			res = mysql_use_result(&mysql);
			while(1)
			{
				row = mysql_fetch_row(res);
				if(row <= 0) break;
				for(int j = 0;j < mysql_num_fields(res);j++)
				{	
					printf(" %s ",row[j]);

					strcpy(mydata1.sel_time,row[0]);
					mydata1.sel_data.Airtem = atoi(row[1]);
					mydata1.sel_data.Airhum = atoi(row[2]);
					mydata1.sel_data.Soiltem = atoi(row[3]);
					mydata1.sel_data.Soilhum = atoi(row[4]);
					mydata1.sel_data.pot = atoi(row[5]);
					mydata1.sel_data.lum = atoi(row[6]);
					mydata1.sel_data.kl_bug = atoi(row[7]);
					mydata1.sel_data.sp_manu = atoi(row[8]);
					mydata1.sel_data.water_bk = atoi(row[9]);
					mydata1.sel_data.heat_bk = atoi(row[10]);
					mydata1.sel_data.wind_bk = atoi(row[11]);
					mydata1.sel_data.light_bk = atoi(row[12]);
					mydata1.sel_data.make_bk = atoi(row[13]);

				}
				ret = send(TOsock,&mydata1,sizeof(mydata1),0);
		        if(ret < 0)
		        {
		            perror("send error");
		            pthread_exit(NULL);
		        }
				
				sleep(0.5);			

				printf("\n");
			}
			
			ret = send(TOsock,"#$",sizeof("#$"),0);
    	    if(ret < 0)
    	    {
    	        perror("send error");
    	        pthread_exit(NULL);
    	    }
		}

	}
	mysql_free_result(res);

	close(TOsock);

sleep(3);
	pthread_exit(NULL);

}

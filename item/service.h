#ifndef SERVICE_H
#define SERVICE_H

#include"headfile.h"
#include"dapeng.h"

struct sel_data
{
	char sel_time[30];
	DATA sel_data;

};


struct SER1
{
	int sock;
	MYSQL mysql;
	CMD * cmd_p;
};


#define MYPORT htons(6660)
#define MYIP inet_addr("192.168.0.114")
void *ser_dapeng(void *arg);
void *ser_cli(void *arg);
void *ser_send(void *arg);




#endif

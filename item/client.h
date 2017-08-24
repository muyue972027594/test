#ifndef CLIENT_H
#define CLIENT_H


#include"headfile.h"
#include"dapeng.h"
#include"service.h"

#define TOPORT htons(6660)
#define TOIP inet_addr("192.168.0.114")

char *mon_chge(int x);
void *cli_sel(void *arg);
void *cli_ctr(void *arg);
void *cli_end(void *arg);



























#endif

#ifndef _XITONG_H_
#define _XITONG_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct station //站点结构体
{
	unsigned num:6;//站点编号
	char name[25];//站名
	float far;//与始站距离
	struct station *next;//指向下一个结构体的指针
} stst;
typedef struct bus //车次结构体
{
	unsigned num:10;//车次
	char No[25];//车牌
	float price;//价格
	float way;//里程
	stst *stt;//路线
	struct bus *next;//指向下一个结构体
} stbus;


stbus *luru(stbus *x);//录入及添加
void liulan(stbus *x);//显示
void chaxun(stbus *x);//查询
stbus *shanchu(stbus *x);//删除
stbus *xiugai(stbus *x);//修改
void fr(stbus *x);//释放空间
void gengxin(stbus *x);//更新，写入文件
stbus *jiazai();//加载，读取文件

#endif

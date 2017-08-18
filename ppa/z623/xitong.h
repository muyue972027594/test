#ifndef _XITONG_H_
#define _XITONG_H_
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct student
{
	int num;
	char name[10];
	char sex[5];
	int age;
	char bthd[30];
	char adrs[30];
	struct student *next;
} stu;
stu *luru(stu *x,int *y);
void liulan(stu *x);
void chaxun(stu *x);
stu *shanchu(stu *x,int *y);
stu *xiugai(stu *x);
stu *fr(stu *x,int y);
void gengxin(stu *x);
#endif

#ifndef _LIANBIAO_H_
#define _LIANBIAO_H_
#include<stdio.h>
#include<stdlib.h>
    typedef struct lianbiao
    {
        int a;
        struct lianbiao *p;
    } str_lb;
str_lb * cre(int a);
str_lb * del(str_lb *x,int *f);
str_lb * add(str_lb *x,int *f);
void print(str_lb *x);
void fre(str_lb *x,int y);

#endif 

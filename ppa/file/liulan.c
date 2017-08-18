/************************************************

文件名：liulan.c
功  能：按指定项排序并显示数据 // 释放空间
参  数：车次链表头地址
返回值：无

************************************************/
#include"xitong.h"
void liulan(stbus*x)
{
	stbus *p1,*p2,*p3;
	p1=x;
	stst *pp;
	int menu;
	char *p0n={"车次 %u 车牌号 %s 价格 %.1f元 里程 %gKm \n"};
	char *p0p={"价格 %.1f元 车次 %u 车牌号 %s 里程 %gKm \n"};
	char *p0w={"里程 %gKm 车次 %u 车牌号 %s 价格 %.1f元 \n"};
	char *p0={"站点编号 %u 站名 %s 与始站距离 %gKm \n"};
	do
	{
    	printf("\n\n");
    	printf("     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    	printf("     ┃ ******************************************* ┃\n");
    	printf("     ┃ * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ * ┃\n");
    	printf("     ┃ * ┃*************************************┃ * ┃\n");
    	printf("     ┃ * ┃**                                 **┃ * ┃\n");
    	printf("     ┃ * ┃**         1.按车次升序显示        **┃ * ┃\n");
    	printf("     ┃ * ┃****       2.按价格升序显示      ****┃ * ┃\n");
    	printf("     ┃ * ┃****       3.按里程升序显示      ****┃ * ┃\n");
    	printf("     ┃ * ┃****       4.按默认顺序显示      ****┃ * ┃\n");
    	printf("     ┃ * ┃****                             ****┃ * ┃\n");
    	printf("     ┃ * ┃****         公交子系统          ****┃ * ┃\n");
    	printf("     ┃ * ┃****          bus 1.1.1          ****┃ * ┃\n");
    	printf("     ┃ * ┃*************************************┃ * ┃\n");
    	printf("     ┃ * ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ * ┃\n");
    	printf("     ┃ ******************************************* ┃\n");
    	printf("     ┗━━━━━━━━━━━━━━━━━按0返回主菜单━━━━━━━━━━━━━━━┛\n");
    	printf("\n\n");
		scanf("%d",&menu);
		if(menu>4||menu<1) menu=0;
		switch(menu)
		{
			case 1:
			{
				while(p1!=NULL)
				{
					p3=p1;p2=p1->next;
					while(p2!=NULL)
						{
							if(p3->num>p2->num)
								p3=p2;
							p2=p2->next;
						}
					p2=malloc(sizeof(stbus));
					p2->num=p3->num;p2->price=p3->price;p2->way=p3->way;
					strcpy(p2->No,p3->No);p2->stt=p3->stt;
					p3->num=p1->num;p3->price=p1->price;p3->way=p1->way;
					strcpy(p3->No,p1->No);p3->stt=p1->stt;
					p1->num=p2->num;p1->price=p2->price;p1->way=p2->way;
					strcpy(p1->No,p2->No);p1->stt=p2->stt;
					free(p2);
					printf(p0n,p1->num,p1->No,p1->price,p1->way);
					if(p1->stt==NULL){p1=p1->next;continue;}
					pp=p1->stt;
					while(pp->next!=NULL)
					{
						printf(p0,pp->num,pp->name,pp->far);
						pp=pp->next;
					}
					p1=p1->next;
				}
				p1=x;
			} break;
			case 2:
			{
				while(p1!=NULL)
				{
					p3=p1;p2=p1->next;
					while(p2!=NULL)
						{
							if(p3->price>p2->price)
								p3=p2;
							p2=p2->next;
						}
					p2=malloc(sizeof(stbus));
					p2->num=p3->num;p2->price=p3->price;p2->way=p3->way;
					strcpy(p2->No,p3->No);p2->stt=p3->stt;
					p3->num=p1->num;p3->price=p1->price;p3->way=p1->way;
					strcpy(p3->No,p1->No);p3->stt=p1->stt;
					p1->num=p2->num;p1->price=p2->price;p1->way=p2->way;
					strcpy(p1->No,p2->No);p1->stt=p2->stt;
					free(p2);
					printf(p0p,p1->price,p1->num,p1->No,p1->way);
					if(p1->stt==NULL){p1=p1->next;continue;}
					pp=p1->stt;
					while(pp->next!=NULL)
					{
						printf(p0,pp->num,pp->name,pp->far);
						pp=pp->next;
					}
					p1=p1->next;
				}
				p1=x;
			} break;
			case 3:
			{
				while(p1!=NULL)
				{
					p3=p1;p2=p1->next;
					while(p2!=NULL)
						{
							if(p3->way>p2->way)
								p3=p2;
							p2=p2->next;
						}
					p2=malloc(sizeof(stbus));
					p2->num=p3->num;p2->price=p3->price;p2->way=p3->way;
					strcpy(p2->No,p3->No);p2->stt=p3->stt;
					p3->num=p1->num;p3->price=p1->price;p3->way=p1->way;
					strcpy(p3->No,p1->No);p3->stt=p1->stt;
					p1->num=p2->num;p1->price=p2->price;p1->way=p2->way;
					strcpy(p1->No,p2->No);p1->stt=p2->stt;
					free(p2);
					printf(p0w,p1->way,p1->num,p1->No,p1->price);
					if(p1->stt==NULL){p1=p1->next;continue;}
					pp=p1->stt;
					while(pp->next!=NULL)
					{
						printf(p0,pp->num,pp->name,pp->far);
						pp=pp->next;
					}
					p1=p1->next;
				}
				p1=x;
			} break;
			case 4:
			{
				while(p1!=NULL)
				{
					printf(p0n,p1->num,p1->No,p1->price,p1->way);
					if(p1->stt==NULL){p1=p1->next;continue;}
					pp=p1->stt;
					while(pp->next!=NULL)
					{
						printf(p0,pp->num,pp->name,pp->far);
						pp=pp->next;
					}
					p1=p1->next;
				}
			}
		}
	}while(menu);
}
void fr(stbus *x)
{
    stbus *y,*y1;
	stst *z,*z1;
	y=x;
    while(y!=NULL)
    {
		y1=y->next;
		z=y->stt;
		while(z!=NULL)
		{
			z1=z->next;
			free(z);
			z=z1;
		}
		free(y);
		y=y1;
    }
}


/************************************************

文件名：chaxun.c
功  能：查询指定数据
参  数：车次链表头地址 
返回值：无

************************************************/
#include"xitong.h"
void chaxun(stbus *x)
{
	stbus *p;
	stst *p1;
	int m,menu;
	char a[25],*p10={"车次 %u 车牌 %s 价格 %g 里程 %g \n"},
				*p20={"站台编号 %u 站名 %s 与始发站距离 %g \n"};
	do
	{
    	printf("\n\n");
        printf("     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
        printf("     ┃ ******************************************* ┃\n");
        printf("     ┃ * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ * ┃\n");
        printf("     ┃ * ┃*************************************┃ * ┃\n");
        printf("     ┃ * ┃**                                 **┃ * ┃\n");
        printf("     ┃ * ┃**           1.车次查询            **┃ * ┃\n");
        printf("     ┃ * ┃****         2.站点查询          ****┃ * ┃\n");
        printf("     ┃ * ┃****         0.返回上级          ****┃ * ┃\n");
        printf("     ┃ * ┃****                             ****┃ * ┃\n");
        printf("     ┃ * ┃****                             ****┃ * ┃\n");
        printf("     ┃ * ┃****         公交子系统          ****┃ * ┃\n");
        printf("     ┃ * ┃****          bus 1.1.1          ****┃ * ┃\n");
        printf("     ┃ * ┃*************************************┃ * ┃\n");
        printf("     ┃ * ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ * ┃\n");
        printf("     ┃ ******************************************* ┃\n");
        printf("     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
        printf("\n\n");
		scanf("%d",&menu);
		if(menu!=1&&menu!=2) menu=0;
		if(menu==0) break;
		do
		{
			printf("\n请输入要查询的车次(按0结束)\n");
			scanf("%u",&m);
			if(m==0) break;
			switch(menu)
			{
				case 1:
				{
	 				p=x;
					while(p!=NULL)
    				{
    	    			if(p->num==m)
						{
							printf(p10,p->num,p->No,p->price,p->way);
							break;
						}
    				    p=p->next;
    				}
					if(p==NULL) printf("\n无此车次\n");
				} break;
				case 2:
				{
					do
					{
						printf("\n请输入要查询的站名\n");
						scanf("%s",a);
						if(a[0]=='0')
						{
							m=0;break;
						}
                    	p=x;
                    	while(p!=NULL)
                    	{
                    	    if(p->num==m) break;
                    	    p=p->next;
						}
						p1=p->stt;
                    	while(p1->next!=NULL)
                    	{
                        	if(strcmp(p1->name,a)==0)
                        	{
                        	    printf(p20,p1->num,p1->name,p1->far);
                    	        break;
                    	    }
                    	    p1=p1->next;
                    	}
                    	if(p1->next==NULL) printf("\n无此站名\n");
					} while(a[0]=='0');
				}
			}
		} while(m);
	} while(menu);
}


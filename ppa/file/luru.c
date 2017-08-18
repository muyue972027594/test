/************************************************

文件名：luru.c
功  能：添加录入数据
参  数：车次链表头地址
返回值：车次链表头地址

************************************************/
#include"xitong.h"
stbus *luru(stbus *x)
{
	stbus *p,*p1,*p2;
	p=x;
    stst *p3,*p4,*p5,*p6;
    int menu,i,n=0,n1=0;
    char a[25],mima[10]="123456",mima1[10];
    char *p0n={"车次 %u 车牌号 %s 价格 %.1f元 里程 %gKm \n"};
    char *p1n={"改为  车次 %u 车牌号 %s 价格 %.1f元 里程 %gKm \n"};
    char *p0s={"站点编号 %u 站名 %s 与始站距离 %gKm \n"};
    char *p1s={"改为  站点编号 %u 站名 %s 与始站距离 %gKm \n"};
    unsigned m,m1;
    printf("\n\n");
    printf("     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("     ┃ ******************************************* ┃\n");
    printf("     ┃ * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ * ┃\n");
    printf("     ┃ * ┃*************************************┃ * ┃\n");
    printf("     ┃ * ┃**                                 **┃ * ┃\n");
    printf("     ┃ * ┃**                                 **┃ * ┃\n");
    printf("     ┃ * ┃****       请输入操作密码        ****┃ * ┃\n");
    printf("     ┃ * ┃****     **初始密码123456**      ****┃ * ┃\n");
    printf("     ┃ * ┃****                             ****┃ * ┃\n");
    printf("     ┃ * ┃****                             ****┃ * ┃\n");
    printf("     ┃ * ┃****         公交子系统          ****┃ * ┃\n");
    printf("     ┃ * ┃****          bus 1.1.1          ****┃ * ┃\n");
    printf("     ┃ * ┃*************************************┃ * ┃\n");
    printf("     ┃ * ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ * ┃\n");
    printf("     ┃ ******************************************* ┃\n");
    printf("     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    printf("\n\n");
    for(i=0;i<3;i++)
    {
        scanf("%s",mima1);
        if(strcmp(mima1,mima)!=0) continue;
        else
        {
			do
			{
           		printf("\n\n");
            	printf("     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
            	printf("     ┃ ******************************************* ┃\n");
            	printf("     ┃ * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ * ┃\n");
            	printf("     ┃ * ┃*************************************┃ * ┃\n");
            	printf("     ┃ * ┃**                                 **┃ * ┃\n");
            	printf("     ┃ * ┃**           1.添加车次            **┃ * ┃\n");
            	printf("     ┃ * ┃****         2.添加站点          ****┃ * ┃\n");
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
  /*                  while(p!=NULL)
                    {
                        printf(p0n,p->num,p->No,p->price,p->way);
                        p=p->next;
                    }
                    p=x;
	*/				printf("\n请输入要添加的车次(输入0结束)\n");
					scanf("%u",&m1);
					if(m1==0) break;
					else
					{
//								printf("44444444444444444444444444\n");
						switch(menu)
						{
							case 1:
							{
				 				p2=malloc(sizeof(stbus));
								p2->num=m1;
								printf("\n请依次输入车牌号、价格、里程\n");
								printf("例：晋A2017001  1  32.5\n");
								scanf("%s%f%f",p2->No,&p2->price,&p2->way);
								p2->stt=NULL;p2->next=NULL;
								if(p==NULL)
								{
									if(n1==0) x=p1=p2,n1++;
									else p1->next=p2,p1=p2;
								}
								else
								{
									while(p->next!=NULL)
									p=p->next;
									if(n1==0) p->next=p1=p2,n1++;
									else p1->next=p2,p1=p2; 
								}
							} break;
							case 2:
                 	   		{
//								printf("333333333333333333333333\n");
								if(p==NULL)
								{
									 printf("\n请先添加车次！\n");
									 m1=0;
									 break;
								}
								else
								{
                        			while(p!=NULL)
                        			{
                            			if(p->num==m1) break;
                            			p=p->next;
                        			}
                        			if(p==NULL)	
									{
										 printf("\n没有指定的车次,请先添加该车次！\n");
										 m1=0;
										 break;
									}
                        			else
                        			{
                                		p5=p->stt;
/*                                		while(p5->next!=NULL)
                                		{
								printf("22222222222222222222222222\n");
                                		    printf(p0s,p5->num,p5->name,p5->far);
                                	    	p5=p5->next;
                                		}
										p5=p->stt;
*/										do
										{
                            				printf("\n请输入站点编号(按0结束)\n");
                            				scanf("%u",&m);
                                			p4=malloc(sizeof(stst));
											p4->num=m;p4->next=NULL;
		                           			if(p5==NULL)
        		                   			{
//								printf("0000000000000000000\n");
                		           			    if(n==0) p->stt=p3=p4,n++;
                        	        			else p3->next=p4,p3=p4;
                           					}
                           					else
                           					{	
                               					while(p5->next!=NULL)
												{
//								printf("1111111111111111111111\n");
                               						p6=p5;p5=p5->next;
												}
//												free(p5);
                               					if(n==0) {p6->next=p3=p4;n++;}
                               					else {p3->next=p4;p3=p4;}
                           					}
											if(m==0) 
											{
												m1=0;break;
											}
                            				printf("\n请输入站名、与始站距离\n");
                            				scanf("%s%f",p4->name,&p4->far);
										} while(m);
										n=0;
									}
								}
							}
						}
					}
				} while(m1);
				p=x;
			} while(menu);
			break;
		}
	}
	return x;
}

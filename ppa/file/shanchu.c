/************************************************

文件名：shanchu.c
功  能：删除指定数据
参  数：车次链表头地址 
返回值：车次链表头地址

************************************************/
#include"xitong.h"
stbus *shanchu(stbus *x)
{
	
    stbus *p1,*p2;
	stst *p3,*p4;
	int menu,i;
	char a[25],mima[10]="123456",mima1[10];
    char *p0n={"车次 %u 车牌号 %s 价格 %.1f元 里程 %gKm \n"};
    char *p1n={"删除掉了  车次 %u 车牌号 %s 价格 %.1f元 里程 %gKm \n"};
    char *p0s={"站点编号 %u 站名 %s 与始站距离 %gKm \n"};
    char *p1s={"删掉了  站点编号 %u 站名 %s 与始站距离 %gKm \n"};
	unsigned m;
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
    			printf("     ┃ * ┃**           1.删除车次            **┃ * ┃\n");
    			printf("     ┃ * ┃****         2.删除站点          ****┃ * ┃\n");
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
					p1=x;
					while(p1!=NULL)
					{
                        printf(p0n,p1->num,p1->No,p1->price,p1->way);
						p1=p1->next;
					}
					printf("\n请输入要删除的车次(按0结束)\n");
					scanf("%u",&m);
					if(m==0) break;
					switch(menu)
					{
						case 1:
						{
	    					p1=p2=x;
    						while(p2!=NULL)
    						{
    	    					if(p2->num==m)
       	 						{
            						if(p2==x) x=x->next;
            						else p1->next=p2->next;
                    				printf(p1n,p2->num,p2->No,p2->price,p2->way);
            						free(p2);
            						break;
        						}
								p1=p2;p2=p2->next;
    						}
						} break;
						case 2:
						{
	    					p1=p2=x;
    						while(p2!=NULL)
    						{
    	    					if(p2->num==m)
       	 						{
		                            p3=p2->stt;
        		                    while(p3->next!=NULL)
                		            {
                        		        printf(p0s,p3->num,p3->name,p3->far);
                                		p3=p3->next;
                            		}
            						p3=p4=p2->stt;
            						break;
        						}
								p2=p2->next;
    						}
							if(p2==NULL)
							{
								 printf("\n没有指定的车次\n");break;
							}
							else
							{
								do
								{
									printf("\n请输入要删除的站点(按0结束)\n");
									scanf("%s",a);
									if(a[0]=='0') 
									{
										m=0;break;
									}
    								while(p4->next!=NULL)
    								{
    	    							if(strcmp(p4->name,a)==0)
       	 								{
            								if(p4==p2->stt) p2->stt=p4->next;
            								else p3->next=p4->next;
                        					printf(p1s,p4->num,p4->name,p4->far);
            								free(p4);
            								break;
        								}
										p3=p4;p4=p4->next;
    								}
								} while(a[0]=='0');
							}
						}
					}
				}while(m);
			} while(menu);
			break;
		}
	}
    return(x);
}


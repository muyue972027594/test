/************************************************

文件名：xiugai.c
功  能：修改指定数据
参  数：车次链表头地址  
返回值：车次链表头地址

************************************************/
#include"xitong.h"
stbus *xiugai(stbus *x)
{
    stbus *p;
    stst *p1;
    int menu,i,menu1;
    char a[25],mima[10]="123456",mima1[10];
    char *p0n={"车次 %u 车牌号 %s 价格 %.1f元 里程 %gKm \n"};
    char *p1n={"改为  车次 %u 车牌号 %s 价格 %.1f元 里程 %gKm \n"};
    char *p0s={"站点编号 %u 站名 %s 与始站距离 %gKm \n"};
    char *p1s={"改为  站点编号 %u 站名 %s 与始站距离 %gKm \n"};
    unsigned m,n;
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
                printf("     ┃ * ┃**           1.修改车次            **┃ * ┃\n");
                printf("     ┃ * ┃****         2.修改站点          ****┃ * ┃\n");
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
                    p=x;
                    while(p!=NULL)
                    {
                        printf(p0n,p->num,p->No,p->price,p->way);
                        p=p->next;
                    }
    		        printf("\n请输入要修改的车次(按0结束)\n");
    		        scanf("%u",&m);
        		    if(m==0) break;
        		    switch(menu)
        		    {
            		    case 1:
            		    {
            		        p=x;
            		        while(p!=NULL)
            		        {
            		            if(p->num==m) break;
            		            p=p->next;
            		        }
            		        if(p==NULL) printf("\n无此车次\n");
							else
							{
            		                printf("\n\n");
					                printf("     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
                					printf("     ┃ ******************************************* ┃\n");
                					printf("     ┃ * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ * ┃\n");
                					printf("     ┃ * ┃*************************************┃ * ┃\n");
                					printf("     ┃ * ┃**                                 **┃ * ┃\n");
                					printf("     ┃ * ┃**           1.修改车牌            **┃ * ┃\n");
                					printf("     ┃ * ┃****         2.修改价格          ****┃ * ┃\n");
                					printf("     ┃ * ┃****         3.修改里程          ****┃ * ┃\n");
                					printf("     ┃ * ┃****         0.返回上级          ****┃ * ┃\n");
                					printf("     ┃ * ┃****                             ****┃ * ┃\n");
                					printf("     ┃ * ┃****         公交子系统          ****┃ * ┃\n");
                					printf("     ┃ * ┃****          bus 1.1.1          ****┃ * ┃\n");
                					printf("     ┃ * ┃*************************************┃ * ┃\n");
                					printf("     ┃ * ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ * ┃\n");
                					printf("     ┃ ******************************************* ┃\n");
                					printf("     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
                					printf("\n\n");
               						scanf("%d",&menu1);
            						switch(menu1)
            						{
                						case 1:
                						{
                    						printf("请输入正确的车牌\n");
                    						scanf("%s",p->No);
                                    		printf(p1n,p->num,p->No,p->price,p->way);
                						} break;
                						case 2:
                						{
                    						printf("请输入正确的价格\n");
                    						scanf("%f",&p->price);
                                    		printf(p1n,p->num,p->No,p->price,p->way);
                						} break;
                						case 3:
                						{
                    						printf("请输入正确的里程\n");
                    						scanf("%f",&p->way);
                                    		printf(p1n,p->num,p->No,p->price,p->way);
                						} break;
                						case 0: break;
									}       	
							}
            		    } break;
		                case 2:
		                {
		                    do
		                    {
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
                                    printf(p0s,p1->num,p1->name,p1->far);
                                    p1=p1->next;
                                }
		                        printf("\n请输入要修改的站名\n");
		                        scanf("%s",a);
		                        p1=p->stt;
		                        while(p1->next!=NULL)
		                        {
		                            if(strcmp(p1->name,a)==0) break;
                        		    p1=p1->next;
                        		}
                        		if(p1->next==NULL) printf("\n无此站名\n");
								else
								{
                                    	printf("\n\n");
                                    	printf("     ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
                                    	printf("     ┃ ******************************************* ┃\n");
                                    	printf("     ┃ * ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓ * ┃\n");
                                    	printf("     ┃ * ┃*************************************┃ * ┃\n");
                                    	printf("     ┃ * ┃**                                 **┃ * ┃\n");
                                    	printf("     ┃ * ┃**           1.修改编号            **┃ * ┃\n");
                                    	printf("     ┃ * ┃****         2.修改站名          ****┃ * ┃\n");
                                    	printf("     ┃ * ┃****         3.修改距离          ****┃ * ┃\n");
                                    	printf("     ┃ * ┃****         0.返回上级          ****┃ * ┃\n");
                                    	printf("     ┃ * ┃****                             ****┃ * ┃\n");
                                    	printf("     ┃ * ┃****         公交子系统          ****┃ * ┃\n");
                                    	printf("     ┃ * ┃****          bus 1.1.1          ****┃ * ┃\n");
                                    	printf("     ┃ * ┃*************************************┃ * ┃\n");
                                    	printf("     ┃ * ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛ * ┃\n");
                                    	printf("     ┃ ******************************************* ┃\n");
                                    	printf("     ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
                                    	printf("\n\n");
                                    	scanf("%d",&menu1);
                                    	switch(menu1)
                                    	{
                                        	case 1:
                                        	{
                                        	    printf("请输入正确的编号\n");
                                        	    scanf("%u",&n);
												p1->num=n;
                                            	printf(p1s,p1->num,p1->name,p1->far);
                                        	} break;
                                        	case 2:
                                        	{
                                        	    printf("请输入正确的站名\n");
                                        	    scanf("%s",p1->name);
                                            	printf(p1s,p1->num,p1->name,p1->far);
                                        	} break;
                                        	case 3:
                                        	{
                                        	    printf("请输入正确的距离\n");
                                        	    scanf("%f",&p1->far);
                                            	printf(p1s,p1->num,p1->name,p1->far);
                                        	} break;
                                        	case 0: break;
                                    	}
								}
                    		} while(a[0]=='0');
                		}
            		}
        		} while(m);
    		} while(menu);
			break;
		}
 	}
	return x;
}



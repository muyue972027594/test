/************************************************

文件名：jiazai.c
功  能：加载文件内数据
参  数：车次链表头地址
返回值：车次链表头地址

************************************************/
#include"xitong.h"
stbus * jiazai()
{
	FILE *fp1,*fp2;
	stbus *x=NULL,*p,*p1;
	stst *p2,*p3;
	int m=0,n=0,i;
    if((fp1=fopen("bus.txt","r"))==NULL)
        perror("fopen");
    if((fp2=fopen("station.txt","r"))==NULL)
        perror("fopen");
    if(fp1!=NULL&&fp2!=NULL)
        while(1)
        {
			p1=malloc(sizeof(stbus));
            if(fread(p1,sizeof(stbus),1,fp1)!=1)
			{
				free(p1);break;
			}
			p1->stt=NULL;p1->next=NULL;	
//			printf("车次 %u 车牌 %s 价格 %g 里程 %g \n",p->num,p->No,p->price,p->way);
			if(m==0) 
			{
				x=p=p1;m++;
			}
			else
			{
				p->next=p1;p=p1;
			}
            while(1)
            {
				p3=malloc(sizeof(stst));
           		if(fread(p3,sizeof(stst),1,fp2)!=1)
				{
					p3->next=NULL;
					free(p3);break;
				}
				if(n==0)
				{
					p1->stt=p2=p3;n++;
				}
				else
				{
               		p2->next=p3;p2=p3;
				}
				if(p3->num==0) {n=0;break;}
            }
        }
    fclose(fp1);
    fclose(fp2);
	return x;
}

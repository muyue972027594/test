/************************************************

文件名：gengxin.c
功  能：将数据实时写到文件里
参  数：车次链表头地址  
返回值：无

************************************************/
#include"xitong.h"
void gengxin(stbus *x)
{
	FILE *fp1,*fp2;
	stbus *p;
	stst *p1;
	p=x;
	if((fp1=fopen("bus.txt","w"))==NULL)
		perror("fopen");
	if((fp2=fopen("station.txt","w"))==NULL)
		perror("fopen");
	if(fp1!=NULL&&fp2!=NULL)
		while(p!=NULL)
		{
			fwrite(p,sizeof(stbus),1,fp1);
			if(p->stt==NULL){p=p->next; continue;}
			p1=p->stt;
			while(p1!=NULL)
			{
				fwrite(p1,sizeof(stst),1,fp2);
				p1=p1->next;
			}
			p=p->next;
		}
	fclose(fp1);
	fclose(fp2);
}

#include"xitong.h"
void gengxin(stu *x)
{
	FILE *fp;
	stu *p;
	p=x;
	if((fp=fopen("student.txt","w"))==NULL)
		perror("fopen");
	else
		while(p!=NULL)
		{
			fwrite(p,sizeof(stu),1,fp);
			p=p->next;
		}
	fclose(fp);
}

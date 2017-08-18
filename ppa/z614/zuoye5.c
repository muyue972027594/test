/***第五题：求最大值***/
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,*p;
	p=malloc(4*sizeof(int));
	printf("请输入三个整数\n");
	scanf("%d%d%d",p,p+1,p+2);
	*(p+3)=*p;
	for(i=1;i<3;i++)
		if(*(p+3)<*(p+i))
			*(p+3)=*(p+i);
	printf("最大值为：%d\n",*(p+3));
	free(p);
}

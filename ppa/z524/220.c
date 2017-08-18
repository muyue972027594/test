#include<stdio.h>
int main()
{
	int l,h,w,v;
	printf("请依次输入长度、宽度、高度, 用空格键隔开\n");
	scanf("%d%d%d",&l,&w,&h);
	v=l*w*h;	
	printf("l=%d，w=%d,h=%d,v=%d\n",l,w,h,v);
	
}	

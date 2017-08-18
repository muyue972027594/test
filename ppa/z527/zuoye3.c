/*************************************************************************

		  					出租车计费

**************************************************************************/
#include<stdio.h>
int main()
{
	float mon1,mon2,s1,s2, a=0;
	do
	{
		printf("请选择查询模式：\n#输入里程查询金额请按 1\n#输入金额查询里程请按 2\n");
		scanf("%f",&a);
//		printf("a = %f\n",a);
	}
	while(a!=1&&a!=2); 
	if(a==1)
	 {
		printf("请输入里程数(KM)\n");
		scanf("%f",&s1);
		printf("s1 = %f\n",s1);
		if(s1>0)
		 {
		 	if(s1>(int)s1) s1+=1;
            if(s1>3) mon1=8+((int)s1-3)*1.6;
			else mon1=8;
			printf("需要金额%g元\n",mon1);
		 }
		else printf("不要捣乱^_^\n");
	 }
	if(a==2)
	 {
		printf("请输入金额(元)\n");
        scanf("%f",&mon2);
        if(mon2>=8)
         {
            if(mon2<9.6) printf("可走0--3KM\n");
			else
			 {
				s2=(mon2-8)/1.6+3;
            	printf("可走%d-%dKM\n",(int)s2-1,(int)s2);
			 }
         }
        else printf("不要捣乱^_^\n");

	 }
}

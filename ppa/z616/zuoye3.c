/***第三题：统计字符***/
#include<stdio.h>
#include<string.h>
int main()
{
    char *a[3]={"FI GI587;',./3a","hq1 hq 2&*us1*="," ^ wwji8j;2 11."};
    int i,j,big=0,small=0,shu=0,kong=0,other=0;
    for(i=0;i<3;i++)
		for(j=0;j<16;j++)
    	{
        	if(a[i][j]=='\0') break;
        	if(a[i][j]>='A'&&a[i][j]<='Z') big++;
        	else if(a[i][j]>='a'&&a[i][j]<='z') small++;
        	else if(a[i][j]>='0'&&a[i][j]<='9') shu++;
        	else if(a[i][j]==' ') kong++;
        	else other++;
    	}
    printf("大写字母有%d个，小写字母有%d个，数字有%d个\n",big,small,shu);
    printf("空格有%d个，其他标点符号有%d个\n",kong,other);
}


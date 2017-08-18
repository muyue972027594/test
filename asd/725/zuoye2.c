/*************************************************
文件名：zuoye2.c
功	能：统计文件中英文字母个数并输出出现最多的字母
版本号：0.0.1
*************************************************/
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int i,j,fd1=0,rd_data=0,letter[26]={0},max;
    char ch;
    
	/*打开文件*/
    fd1=open("file.txt",O_RDONLY);
    if(fd1<0)
    {
        perror("file.txt open error");
        return -1;
    }


    while(1)
    {
		/*统计字母（不区分大小写）*/
        rd_data=read(fd1,&ch,1);
		if(rd_data<=0) break;
		for(i=65;i<91;i++)
		{
			if(ch==i||ch==i+32)
				letter[i-65]++;
		}
    }

	/*查找出现最多的字母*/
	max=letter[0];j=0;
	for(i=65;i<91;i++)
	{
		if(letter[i-65]>max)
		{
			max=letter[i-65];
			j=i;
		}
	}
	printf("出现最多的字母为%c，出现了%d次\n",j,max);
	close(fd1);
}


/***有几个单词***/
#include<stdio.h>
int main()
{
	char ch[50];int i=0,j,t=0,word=0;
	printf("请输入一行字符(最多50个)\n");
	do
	{
		scanf("%c",&ch[i]);
		i++;
	}
	while(ch[i-1]!='\n');
	for(j=0;j<i-1;j++)
		if(ch[j]==' ') word=0;
		else if(word==0)
				{
					word=1;t++;
				}
	printf("输入了%d个单词\n",t);
}

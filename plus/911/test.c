/*
 *
 *
 *
 *
 *
 *
*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>

int main()
{
	int num = 0;
	int newnum = 0;
	int i = 0;
	char ch[50] = {0};
	char rel_ch[50] = {0};

	printf("请输入一个整数\r");
	scanf("%d",&num);

	newnum = num;

	while(newnum != 0)
	{
		ch[i] = newnum % 10 + 48;
		i++;
		newnum /= 10;
	}

	for(i = 0;i < strlen(ch);i++)
		rel_ch[i] = ch[strlen(ch) - 1 - i];

	puts(rel_ch);
}







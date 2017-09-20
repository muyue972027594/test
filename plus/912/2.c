/*
 *
 *功  能：判断回文数
 *
 *
 *
 *
 *
 *
*/
#include<stdio.h>
#include<stdlib.h>

int test(int x)
{
	int y,z;

	for(y = 0,z = x;z > 0;z /= 10)
		y = y * 10 + z % 10;
	
	if(y != x)
		return -1;
	else 
		return 1;
}



int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("未输入要测试的数！\n");
		return 0;
	}
	if(argc > 2)
		printf("只能测试一个数！多余数据不做测试！\n\n");

	if(test(atoi(argv[1])) > 0)
		printf("该数是回文数！\n");
	else
		printf("该数不是回文数！\n");

	return 0;
}



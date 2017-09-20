/*
 *
 *功  能：比较字符串，输出它们第一个不同字母的位置，大小写不敏感
 *
 *
 *
 *
 *
*/
#include<stdio.h>
#include<string.h>

int main(int argc,char *argv[])
{
	int i = 0;
	if(argc < 3)
	{
		printf("命令错误，缺少比较的字符串\n");
		return 0;
	}
	if(argc > 3)
	{
		printf("超出要求的字符串不做比较\n");
	}
	

	
	int s_len = strlen(argv[1]) > strlen(argv[2]) ? strlen(argv[2]):strlen(argv[1]);

	for(i = 0;i < s_len;i++)
	{
		if(*(argv[2] + i) != *(argv[1] + i))
		{
			if((*(argv[1] + i) >= 'A' && *(argv[1] + i) <= 'Z')
				&& *(argv[2] + i) == *(argv[1] + i) + 32)
				continue;
			if((*(argv[1] + i) >= 'a' && *(argv[1] + i) <= 'z')
				&& *(argv[2] + i) == *(argv[1] + i) - 32)
				continue;
			break;
		}
	}
	
	printf("两个字符串第 %d 位出现不同\n",i + 1);

	return 0;
}

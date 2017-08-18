/******************************************************************
					输出数据类型空间大小

*****************************************************************/
#include<stdio.h>
int main()
{
	printf("int型数据的空间大小为%d个字节\n",sizeof(int));
	printf("short型数据的空间大小为%d个字节\n",sizeof(short));
	printf("long型数据的空间大小为%d个字节\n",sizeof(long));
	printf("char型数据的空间大小为%d个字节\n",sizeof(char));
	printf("float型数据的空间大小为%d个字节\n",sizeof(float));
	printf("double型数据的空间大小为%d个字节\n",sizeof(double));
	printf("unsigned型数据的空间大小为%d个字节\n",sizeof(unsigned));
}


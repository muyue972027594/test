/*
 *
 *
 8
 *
 *
 *
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main()
{
	char c[50]={"123456"};
	FILE * fd = fopen("tes.txt","r");
	
	for(int i = 0;i < 5;i++ )
	{
		printf("hello!\r");
		getchar();		
//		fgets(&c,1,fd);
//		printf("%s\n",c);
		sleep(1);
		printf("nihao!\r");
//		fgets(&c,1,fd);
//		printf("%c\t",c);
//		sleep(1);
		//scanf("%s",c);
		getchar();
		sleep(1);
	}

	fclose(fd);
}




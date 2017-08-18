/****************************************************
文件名：myls.c
功  能：显示指定目录下文件名、文件类型、权限、大小、最后修改时间
版本号：0.0.1
***************************************************/
#include<sys/types.h>
#include<sys/stat.h>
#include<dirent.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/*解析类型和权限（部分）*/
char * quanxian(int x)
{
	char *y;
	switch(x)
	{
		case 040777:y = "drwxrwxrwx";break;
		case 040700:y = "drwx------";break;
		case 040600:y = "drw-------";break;
		case 040755:y = "drwxr-xr-x";break;
		case 040644:y = "drwxr--r--";break;
		case 0100777:y = "-rwxrwxrwx";break;
		case 0100700:y = "-rwx------";break;
		case 0100600:y = "-rw-------";break;
		case 0100755:y = "-rwxr-xr-x";break;
		case 0100644:y = "-rwxr--r--";break;
		default: y="No such Or";
	}
	return y;
}

int main(int argc,char *argv[])
{
	DIR *open_data = NULL;
	struct dirent *read_data = NULL;
	struct stat buf;
	int i,close_data = 0,stat_data = 0;
	char file_name[50] = {0};
	char time_p[30] = {0};
	char *time = time_p;
//	char quanx[12] = {0};

	/*打开目录*/
	open_data = opendir(argv[1]);
	if(open_data == NULL)
	{
		perror("open error");
		exit(-1);
	}

	/*查找文件，获取类型、权限、大小、最近修改时间*/
	while((read_data = readdir(open_data)) != NULL)
	{
		memset(file_name,0,50);
		memset(time,0,30);
//		memset(quanx,0,12);

		strcpy(file_name,argv[1]);
		strcat(file_name,"/");
		strcat(file_name,read_data->d_name);

		stat_data = stat(file_name,&buf);
		time = ctime(&buf.st_mtime);

		printf("%s  %5ld  ",quanxian(buf.st_mode),buf.st_size);
		for(i=4;i<19;i++)
			printf("%c",time[i]);
		printf("  %s\n",read_data->d_name);
	}

	/*关闭目录*/
	close_data = closedir(open_data);
	if(close_data < 0)
		perror("close error");
	
	return 0;
}

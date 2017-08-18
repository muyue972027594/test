/*********************************************
文件名：zuoye3.c
功  能：找到目录下文件名较长的文件，用新名字重命名
版本号：0.0.1
*********************************************/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
	DIR *open_data = NULL;
	struct dirent *read_data = NULL;
	int i = 0,j = 0;
	int name_len = 0,rename_data = 0,close_data = 0;
	char name[10] = {0},old_name[100] = {0},new_name[100] = {0};

	if(argc != 2)
	{
		printf("CMD error!");
		exit -1;
	}
	/*打开目录*/
	open_data = opendir(argv[1]);
	if(open_data == NULL)
	{
		perror("open error");
		return -1;
	}
	
	/*找到文件名较长的文件*/
	while((read_data=readdir(open_data))!=NULL)
	{
		name_len = strlen(read_data->d_name);
//		printf("%s,%d\n",read_data->d_name,name_len);		
		if(read_data->d_type == 8 && name_len > 30)
		{
			memset(name,0,10);
			memset(old_name,0,100);
			memset(new_name,0,100);

			strcpy(old_name,argv[1]);
			strcat(old_name,"/");
			strcat(old_name,read_data->d_name);

			name[0] = read_data->d_name[0];
			for(j = name_len - 6,i = 1;j < name_len;j++)
				name[i++] = read_data->d_name[j];

			strcpy(new_name,argv[1]);
			strcat(new_name,"/");
			strcat(new_name,name);
//			printf("%s  %s\n",old_name,new_name);		

			/*重命名*/	
			rename_data = rename(old_name,new_name);
//			rename_data = rename(read_data->d_name,name);
			if(rename_data<0)
			{
				perror("rename error");
				return -1;
			}
			printf("%s改为%s\n",read_data->d_name,name);		
		}
	}

	/*关闭目录*/
	close_data = closedir(open_data);
	if(close_data < 0)
		perror("close error");

	return 0;
}

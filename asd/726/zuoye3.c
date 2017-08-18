/*****************************************************
文件名：zuoye3.c
功  能：统计文件中的单词和有效行数，并将指定位置单词保存
版本号：0.0.1
*****************************************************/
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int i,j,fd1 = 0,fd2 = 0;
	int rd_data = 0,wr_data = 0 ,line = 0 ,line_ok = 0,word = 0,word_ok = 0;
    char ch,ch1=' ';
  
	/*打开英文文件*/
    fd1 = open("file.txt",O_RDONLY);
    if( fd1 < 0 )
    {
        perror("file.txt open error");
        exit -1;
    }

	/*实现功能*/
    while(1)
    {

		/*读文件*/
        rd_data = read(fd1,&ch,1);
        if( rd_data == 0 ) break;
        if( rd_data < 0 ) 
		{
			perror("read");
			exit -1;
		}

		/*统计行数*/
		if(ch != '\n' && ch != ' ')
		{
			if(line_ok == 0) line++;
			line_ok = 1;
		}
		if(ch == '\n') line_ok = 0;

		/*统计单词并保存*/
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') )
        {
			if(word_ok == 0) word++;

			/*新建文件*/
			if(word == 3 && word_ok == 0)
			{
				fd2 = open("zuoye3.txt",O_WRONLY|O_CREAT,0644);
				if( fd2 < 0 )
				{
					perror("zuoye3.txt open error");
        			exit -1;
				}
			}

			/*保存单词*/
			if(word%3 == 0 && word != 0)
			{
				printf("%c\n",ch);
				wr_data = write(fd2,&ch,1);
				if(wr_data < 0)
				{
					perror("write");
					exit -1;
				}
			}

			/*单次间加空格*/
			if(word%3 == 1 && word >= 3 && word_ok == 0)
			{
				wr_data = write(fd2,&ch1,1);
				if(wr_data < 0)
				{
					perror("write");
					exit -1;
				}
			}
            word_ok=1;
        }
		else word_ok=0;
    }
	printf("该文件有效行数%d行，%d个单词\n",line,word);
	close(fd1);
	if(word>3)
		close(fd2);
}

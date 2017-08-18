#include"xitong.h"
int main()
{
	stu *head=NULL;
	int menu,coun=0;
	printf("\n欢迎使用学生管理系统\n");
	do
	{
		printf("\n1.录入\t2.浏览\t3.查询\n4.删除\t5.修改\t6.退出\n");
		scanf("%d",&menu);
		switch(menu)
		{
			case 1:head=luru(head,&coun);break;
			case 2:liulan(head);break;
			case 3:chaxun(head);break;
			case 4:head=shanchu(head,&coun);break;
			case 5:head=xiugai(head);break;
		}	
	}while(menu!=6);
	head=fr(head,coun);
	printf("\n欢迎下次使用\n");
}

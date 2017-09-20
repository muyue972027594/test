/*
 *文件名：guozhi.cpp
 *功  能：
 *版本号：0.0.1
*/ 

#include<iostream>
#include<string.h>
#include<unistd.h>

using namespace std;

class juicer
{
	char type[10];
	char kind[20];

	public:
		juicer(char *type1,char *kind1)
		{
			strcpy(type,type1);
			strcpy(kind,kind1);
		}
		void work();
};

void juicer::work()
{
	if(strcmp(type,"food") == 0)
	{
		cout<<"请耐心等待10分钟！"<<endl;
		sleep(1);
		cout<<"loading..."<<endl;
		sleep(1);
		cout<<"loading..."<<endl;
		sleep(1);
		cout<<"loading..."<<endl;
		sleep(1);
		cout<<"loading..."<<endl;
		sleep(1);
		cout<<"您的"<<kind<<"豆浆已经打好！"<<endl;
	}
	if(strcmp(type,"fruit") == 0)
	{
		cout<<"请耐心等待3分钟！"<<endl;
		sleep(1);
		cout<<"loading..."<<endl;
		sleep(1);
		cout<<"loading..."<<endl;
		sleep(1);
		cout<<"您的"<<kind<<"果汁已经打好！"<<endl;
	}
	
}


int main(int argc,char *argv[])
{

	if(argc != 3) 
	{
		cout<<"操作错误！\n"<<"必须选择类型与种类"<<endl;
	}
	else
	{
		juicer jc1(argv[1],argv[2]);
		jc1.work();
	}

	return 0;
}

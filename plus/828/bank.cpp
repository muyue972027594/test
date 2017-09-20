/*
 *文件名：bank.cpp
 *功  能：
 *版本号：0.0.1
 *
 *
*/

#include<iostream>
#include<string.h>

using namespace std;

class bank
{
	char cardID[8] = "1234567";
	int money = 666666;
	char password[8] = "123456";

	public:
		int login(char *id,char *pass);		
		void save(int num);
		void draw(int num);
		void edit(char *pass);
};

int bank::login(char *id,char *pass)
{
	if(strcmp(cardID,id) == 0 && strcmp(password,pass) == 0)
	{
		cout<<"余额："<<money<<endl;
		return 1;
	}
	else	
		return 0;
}

void bank::save(int num)
{
	money += num;
	cout<<"余额："<<money<<endl;
}

void bank::draw(int num)
{
	money -= num;
	cout<<"余额："<<money<<endl;
}

void bank::edit(char *pass)
{
	strcpy(password,pass);
	cout<<"新密码："<<password<<endl;
}

int main()
{
	int i;
	int num;
	char id[8] = {0};
	char pass[8] = {0};
	bank user1;

	for(i = 0;i < 3;i++)
	{
		cout<<"请输入卡号(七位)    密码(六位)（卡号、密码空格隔开）"<<endl;		
		cin>>id;
		cin>>pass;

		if(user1.login(id,pass)== 0) continue;
		
		while(1)
		{
			cout<<"请选择服务：1.存款  2.取款  3.修改密码  0.退出"<<endl;
			cin>>i;
		
			if(i == 0) 
			{
				i = 3;
				break;
			}	
			if(i == 3)
			{
				cout<<"请输入新密码"<<endl;
				cin>>pass;
			}
			else
			{
				cout<<"请输入操作金额"<<endl;
				cin>>num;
			}

			switch(i)
			{
				case 1:user1.save(num);break;
				case 2:user1.draw(num);break;
				case 3:user1.edit(pass);
			}

		}

	}



}




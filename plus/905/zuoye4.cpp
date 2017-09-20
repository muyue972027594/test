/*
 *文件名：zuoye4.cpp
 *功  能：笔记本类、学生类、教师类
 *版本号：0.0.1
 *
*/
#include<iostream>
#include<string.h>
#include<unistd.h> 
using namespace std;

class computer
{
	string brand;//品牌
	string type;//型号
	string work_tp;//运行状态，显示当前运行的软件
	public:
	computer(string a,string b);
	void power_on();//开机
	void power_off();//关机
	void install(string a);//安装软件
	void uninsta(string a);//卸载软件
	void openit(string a);//打开应用
	void closeit(string a);//关闭应用
	string show();//显示当前运行的软件
};
	computer::computer(string a,string b)
	{
		brand = a;
		type = b;
	}
	void computer::power_on()
	{
		cout<<brand<<" 电脑 "<<type<<" 正在开机 "<<endl;
		sleep(1);
		cout<<"loading......"<<endl;
		sleep(1);
		cout<<"loading......"<<endl;
		sleep(1);
		cout<<"loading......"<<endl;
		sleep(1);
		cout<<brand<<" 电脑 "<<type<<" 已开机，请使用！ "<<endl;
	}
	void computer::power_off()
	{
        cout<<brand<<" 电脑 "<<type<<" 正在关机 "<<endl;
		sleep(1);
        cout<<"loading......"<<endl;
		sleep(1);
        cout<<"loading......"<<endl;
		sleep(1);
        cout<<"loading......"<<endl;
		sleep(1);
        cout<<brand<<" 电脑 "<<type<<" 已关机！ "<<endl;
    }
	void computer::install(string a)
	{
		cout<<"正在安装 "<<a<<endl;
		sleep(1);
		cout<<"loading......"<<endl;
		sleep(1);
		cout<<a<<" 安装完成"<<endl;
	}
	void computer::openit(string a)
	{
		cout<<"打开并运行 "<<a<<endl;
		work_tp = a;
	}
	void computer::closeit(string a)
	{
		cout<<a<<" 已关闭"<<endl;
		work_tp = "\0";
	}
	void computer::uninsta(string a)
	{
		cout<<"正在卸载 "<<a<<endl;
		sleep(1);
		cout<<"loading......"<<endl;
		sleep(1);
		cout<<a<<" 卸载完成"<<endl;
	}
	string computer::show()
	{
		return work_tp;
	}


class person
{
	public:
	string name;
	person(string a)
	{
		name = a;
	}
};

class student;

class teacher:public person
{
	int id;//工号
	public:
	teacher(string a,int b);
	void amd_stu(student a);//管理学生	
	void look_stu(student &a,computer b);//查看学生
};


class student:public person
{
	int id;//学号
	int amd_tp;//被管状态，0为没有被管（初值为0），1为被管
	public:
	student(string a,int b,int c);
	void use_cpt(computer a);//开机
	void close_cpt(computer a);//关机
	void use_inst(computer a,string b);//安装
	void use_unst(computer a,string b);//卸载
	void use_open(computer a,string b);//打开
	void playit(computer a,string b);//玩
	void use_close(computer a,string b);//关闭
	void be_amd(teacher a,computer b,string c,string d);//被管
	void set_amd_tp(int x);//改变被管状态
};
	student::student(string a,int b,int c):person(a)
	{
		id = b; 
		amd_tp = c;
	}
	void student::use_cpt(computer a)
	{
		cout<<name<<" 准备开机"<<endl;
		a.power_on();
	}
	void student::close_cpt(computer a)
	{
		cout<<name<<" 准备关机"<<endl;
		a.power_off();
	}
	void student::use_inst(computer a,string b)
	{
		cout<<name<<" 准备安装 "<<b<<endl;
		a.install(b);
	}
	void student::use_unst(computer a,string b)
	{
		cout<<name<<" 准备卸载 "<<b<<endl;
		a.uninsta(b);
	}
	void student::use_open(computer a,string b)
	{
		cout<<name<<" 准备打开 "<<b<<endl;
		a.openit(b);
	}
	void student::playit(computer a,string b)
	{
		cout<<name<<" 一直在玩 "<<b<<endl;
		sleep(3);
	}
	void student::use_close(computer a,string b)
	{
		cout<<name<<" 准备关闭 "<<b<<endl;
		a.closeit(b);
	}
	void student::be_amd(teacher a,computer b,string c,string d)
	{
		if(amd_tp)
		{
			cout<<name<<" 在玩游戏，被 "<<a.name<<" 发现"<<endl;
			cout<<name<<" 准备关闭 "<<c<<" 打开 "<<d<<" 进行学习"<<endl;
			use_close(b,c);
			cout<<endl;
			use_open(b,d);
			cout<<endl;
			playit(b,d);
			cout<<endl;
			sleep(3);
			use_close(b,d);
			amd_tp = 0;
		}
		
	}
	void student::set_amd_tp(int x)
	{
		amd_tp = x;
	}



	teacher::teacher(string a,int b):person(a)
	{
		id = b;
	}
	void teacher::look_stu(student &a,computer b)
	{	
		if(b.show() != "金山打字")
		{
			amd_stu(a);
			a.set_amd_tp(1);
		}
		else
			a.set_amd_tp(0);
	}	
	void teacher::amd_stu(student a)
	{
		cout<<name<<" 发现 "<<a.name<<" 在玩游戏，然后教育了 "<<a.name<<endl;
	}




int main()
{
	computer com("DELL","灵越15R");//DELL电脑，型号灵越15R
	string game = "英雄联盟";//游戏软件
	string study = "金山打字";//学习软件
	student stu1("mike",10001,0);//学生mike，学号10001,没有被管
	teacher tch1("lucy",20001);//老师lucy，工号20001

	stu1.use_cpt(com);//学生开机
	cout<<endl;
	stu1.use_inst(com,game);//安装游戏
	cout<<endl;
	stu1.use_open(com,game);//打开游戏
	cout<<endl;
	stu1.playit(com,game);//玩游戏
	cout<<endl;

	tch1.look_stu(stu1,com);//老师查看，并管理
	cout<<endl;
	stu1.be_amd(tch1,com,game,study);//被管
	cout<<endl;

	stu1.close_cpt(com);//学完关机
	cout<<endl;




}

/*
 *文件名：sys_stu.cpp
 *功  能：学生管理系统
 *版本号：0.0.1
 *
*/
#include<iostream>
#include<string>

using namespace std;

class student
{
	int id;
	string name;
	int age;
	string g_class;
	
	public:
	student()
	{
		id = 0;
	}
	student(int a,string b,int c,string d);
	void inse(int a,string b,int c,string d);
	void dele();
	void set_id(int a);
	void set_name(string b);
	void set_age(int c);
	void set_g_class(string d);
	int get_id();
	string get_name();
	void show();
};

student::student(int a,string b,int c,string d)
{
	id = a;
	name = b;
	age = c;
	g_class = d;
}

void student::inse(int a,string b,int c,string d)
{
	id = a;
	name = b;
	age = c;
	g_class = d;
}

void student::dele()
{
	id = 0;
	name = "\0";
	age = 0;
	g_class = "\0";
}

void student::set_id(int a)
{
	id = a;
}

void student::set_name(string b)
{
	name = b;
}

void student::set_age(int c)
{
	age = c;
}

void student::set_g_class(string d)
{
	g_class = d;
}

int student::get_id()
{
	return id;
}

string student::get_name()
{
	return name;
}

void student::show()
{
	cout<<"学号 "<<id<<" 姓名 "<<name<<" 年龄 "<<age<<" 班级 "<<g_class<<endl;
}

void my_inse();
void my_dele();
void my_selc();
void my_upset();
student *stu[30] = {NULL};


int main()
{
	int menu = 1;
	int i = 0;

	while(menu)
	{
		cout<<"请选择： 1.增加  2.删除  3.查询  4.修改  0.退出"<<endl<<endl;
		cin>>menu;
	
		switch(menu)
		{
			case 1:my_inse();break;
			case 2:my_dele();break;
			case 3:my_selc();break;
			case 4:my_upset();break;
		}
	}

}

void my_inse()
{
	int i = 0;
	int id;
	string name;
	int age;
	string g_class;
	for(i = 0;i < 30;i++)
	{
		if(stu[i] == NULL)
			break;
	}

	stu[i] = new student;

	cout<<"请输入学生的  学号 姓名 年龄 班级  "<<endl;
	cin>>id>>name>>age>>g_class;

//	cout<<id<<name<<age<<g_class<<endl;
	stu[i]->inse(id,name,age,g_class);
//	stu[i]->show();
}

void my_dele()
{
	int i = 0;
	int menu = 0;
	int id;
	string name;

	cout<<"请选择删除方式  1.使用学号  2.使用姓名"<<endl;
	cin>>menu;

	if(menu == 1)
	{
		cout<<"请输入要删除的学生的学号"<<endl;
		cin>>id;

		for(i = 0;i < 30;i++)
		{
			if(stu[i] == NULL) continue;
			if(stu[i]->get_id() == id)
				break;
		}

		if(stu[i] != NULL) 
		{
			stu[i]->dele();
			delete stu[i];
			stu[i] = NULL;
		}
	}

	if(menu == 2)
	{
		cout<<"请输入要删除的学生的姓名"<<endl;
		cin>>name;

		for(i = 0;i < 30;i++)
		{
			if(stu[i] == NULL) continue;
			if(stu[i]->get_name() == name)
				break;
		}

		if(stu[i] != NULL) 
		{
			stu[i]->dele();
			delete stu[i];
			stu[i] = NULL;
		}
	}

}

void my_selc()
{
	int i = 0;
	int menu = 0;
	int id;
	string name;

	cout<<"请选择查询方式  1.使用学号  2.使用姓名"<<endl;
	cin>>menu;

	if(menu == 1)
	{
		cout<<"请输入要查询的学生的学号"<<endl;
		cin>>id;

		for(i = 0;i < 30;i++)
		{
			if(stu[i] == NULL) continue;
			if(stu[i]->get_id() == id)
				break;
		}

		if(stu[i] != NULL) 
			stu[i]->show();
	}

	if(menu == 2)
	{
		cout<<"请输入要查询的学生的姓名"<<endl;
		cin>>name;

		for(i = 0;i < 30;i++)
		{
			if(stu[i] == NULL) continue;
			if(stu[i]->get_name() == name)
				break;
		}

		if(stu[i] != NULL)
			stu[i]->show();
	}

}




void my_upset()
{
	int i = 0;
	int menu = 0,menu1 = 0;
	int id;
	string name;
	int age;
	string g_class;

	cout<<"请选择修改方式  1.使用学号  2.使用姓名"<<endl;
	cin>>menu;

	if(menu == 1)
	{
		cout<<"请输入要修改的学生的学号"<<endl;
		cin>>id;

		for(i = 0;i < 30;i++)
		{
			if(stu[i] == NULL) continue;
			if(stu[i]->get_id() == id)
				break;
		}

		if(stu[i] != NULL)
		{
			cout<<"请选择要修改的项 1.姓名 2.年龄 3.班级"<<endl;
			cin>>menu1;	
			switch(menu1)
			{
				case 1:cout<<"请输入正确的姓名"<<endl;
						cin>>name;
						stu[i]->set_name(name);
						break;
				case 2:cout<<"请输入正确的年龄"<<endl;
						cin>>age;
						stu[i]->set_age(age);
						break;
				case 3:cout<<"请输入正确的班级"<<endl;
						cin>>g_class;
						stu[i]->set_g_class(g_class);
						break;
			}
		}

	}

	if(menu == 2)
	{
		cout<<"请输入要修改的学生的姓名"<<endl;
		cin>>name;

		for(i = 0;i < 30;i++)
		{
			if(stu[i] == NULL) continue;
			if(stu[i]->get_name() == name)
				break;
		}

		if(stu[i] != NULL)
		{
			cout<<"请选择要修改的项 1.学号 2.年龄 3.班级"<<endl;
			cin>>menu1;	
			switch(menu1)
			{
				case 1:cout<<"请输入正确的学号"<<endl;
						cin>>id;
						stu[i]->set_id(id);
						break;
				case 2:cout<<"请输入正确的年龄"<<endl;
						cin>>age;
						stu[i]->set_age(age);
						break;
				case 3:cout<<"请输入正确的班级"<<endl;
						cin>>g_class;
						stu[i]->set_g_class(g_class);
						break;
			}	
		}
	}

}


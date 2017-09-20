/*
 *文件名：lianxi.cpp
 *功  能：继承
 *版本号：0.0.1
*/
#include<iostream>
#include<string>

using namespace std;

class AA
{
	int x;
	public:
	AA(int a)
	{
		x = a;
		cout<<"AA 构造"<<endl;
	}
	~AA()
	{
		cout<<"AA 析构"<<endl;
	}
	void show()
	{
		cout<<"x = "<<x<<endl;
	}
};

class BB
{
	int y;
	public:
	BB()
	{
		cout<<"BB 构造"<<endl;
	}
	BB(int a)
	{
		y = a;
		cout<<"BB 构造"<<endl;
	}
	~BB()
	{
		cout<<"BB 析构"<<endl;
	}
	void show()
	{
		cout<<"y = "<<y<<endl;
	}
};

class AC:public AA
{
	int xc;
	BB yc;
	public:
	AC(int a,int b,int c):AA(a),yc(c)
	{
		xc = b;
		cout<<"AC 构造"<<endl;
	}
	~AC()
	{
		cout<<"AC 析构"<<endl;
	}
	void show()
	{
		AA::show();
		yc.show();
		cout<<"xc = "<<xc<<endl;
	}
};

int main()
{
	AC ac_test(1,2,3);

	ac_test.show();
}








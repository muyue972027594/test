/*
 *文件名：shape.cpp
 *功  能：形状派生矩形，圆，方
 *版本号：0.0.1
 *
*/

#include<iostream>
#include<math.h>

#define P 3.14
using namespace std;


class point
{
	int x;
	int y;
	public:
	point(){}
	point(int a,int b)
	{
		x = a;y = b;
	}
	int get_x()
	{
		return x;
	}
	int get_y()
	{
		return y;
	}
	void set_x(int a)
	{
		x = a;
	}
	void set_y(int b)
	{
		y = b;
	}
	void show()
	{
		cout<<"("<<x<<","<<y<<")"<<endl;
	}
};

class shape
{
	public:
	point a;
	shape(point x)	
	{
		a = x;
	}
	void show()
	{
		a.show();
	}
};

class rectangle:public shape
{
	public:
	point b;
	point c;
	point d;
	rectangle(point x1,point x2,point x3,point x4):shape(x1)
	{
		b = x2; c = x3; d = x4;
		/*判定是否为矩形*/
		/*两组对边相等，相邻边垂直*/
	}
	int get_area()
	{
		int lx;
		int ly;
		lx = sqrt((b.get_x() - a.get_x()) * (b.get_x() - a.get_x()) 
				+ (b.get_y() - a.get_y()) * (b.get_y() - a.get_y()));
		ly = sqrt((c.get_x() - d.get_x()) * (c.get_x() - d.get_x()) 
				+ (c.get_y() - d.get_y()) * (c.get_y() - d.get_y()));
		return lx * ly;
	}
	void show()
	{
		cout<<"矩形的四个点为"<<endl;
		a.show();b.show();c.show();d.show();
	}
};

class circle:public shape
{
	int r;
	public:
	circle(point a,int b):shape(a)
	{
		r = b;
	}
	float get_area()
	{
		return P * r * r;
	}
	void show()
	{
		cout<<"圆的起点 ";
		shape::show();
		cout<<"半径为 "<<r<<endl;
	}
};

class square:public rectangle
{
	public:
	square(point x1,point x2,point x3,point x4):rectangle(x1,x2,x3,x4)
	{  
		/*判断是否为正方形*/
	}
	int get_area()
	{
		int lx;
		lx = sqrt((b.get_x() - a.get_x()) * (b.get_x() - a.get_x()) 
				+ (b.get_y() - a.get_y()) * (b.get_y() - a.get_y()));
		return lx * lx;
	}
	void show()
	{
		cout<<"正方形形的四个点为"<<endl;
		a.show();b.show();c.show();d.show();
	}
};

int main()
{
	point a(0,0),b(0,5),c(5,5),d(5,0);
	rectangle rec(a,b,c,d);
	circle cir(a,5);
	square squ(a,b,c,d);

	rec.show();
	cout<<"该矩形面积为 "<<rec.get_area()<<endl<<endl;;

	cir.show();
	cout<<"该圆的面积为 "<<cir.get_area()<<endl<<endl;;

	squ.show();
	cout<<"该正方形面积为 "<<squ.get_area()<<endl;
}


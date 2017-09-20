/*
 *文件名：juxing.cpp
 *功  能：
 *版本号：0.0.1
 *
*/

#include<iostream>

using namespace std;

class point
{
	int x;
	int y;
	public:
		point()
		{
			x = 0;
			y = 0;
		}
		point(int x1,int y1)
		{
			x = x1;
			y = y1;
		}
		void edit(int x1,int y1)
		{
			x = x1;
			y = y1;
		}
		void show()
		{
			cout<<"("<<x<<","<<y<<")"<<endl;
		}
};

class juxing
{
	point pp1;	
	point pp2;
	public:
		juxing(point a,point c)
		{
			pp1 = a;			
			pp2 = c;
		}
		void edit(point a,point c)
		{
			pp1 = a;
			pp2 = c;
		}
		void show()
		{
			cout<<"pp1:";
			pp1.show();
			
			cout<<"pp2:";
			pp2.show();
		}
};


int main()
{
	point a(2,2),b(4,4);
	juxing a_b(a,b);


	a.show();
	b.show();
	cout<<endl;
	a_b.show();

}

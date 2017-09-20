/*
 *文件名：youyuan1.cpp
 *功  能：友元
 *版本号：0.0.1
 *
*/

#include<iostream>
#include<string>
using namespace std;

class A;
void show(A &x);
class B;
class C;

class C
{
	public:
	void show(A &x);
};

class A
{
	string a;
	string b;
	public:
	A(string x,string y)
	{
		a = x;b = y;
	}

	friend class B;
	friend void C::show(A &x);
	friend void show(A &x);
};

void show(A &x)
{
	x.b = "show change!";
	cout<<x.a<<"   "<<x.b<<endl;
}

class B
{
	int a;
	string b;
	public:
	void show(A &x)
	{
		b = x.a + x.b;
		a = x.a.length();
		cout<<x.a<<"  "<<a<<"  "<<b<<endl;
	}

};

void C::show(A &x)
{
	x.a = "C change!";
	cout<<x.a<<"   "<<x.b<<endl;
}
int main()
{
	A a("123456","abcdef");
	B b;
	C c;
	b.show(a);
	c.show(a);
	show(a);
}

/*
 *文件名：zuoye2.cpp
 *功  能：
 *版本号：0.0.1
 *
*/
#include<iostream>

using namespace std;

class N
{
	int n;
	public:
	N(int x)
	{
		n = x;		
	}
	void set_n(int x)
	{
		n = x;
	}
	void show()
	{
		cout<<n<<endl;
	}
};

N &fun1(N &x)
{
	x.set_n(5);
	cout<<"fun1  ";
	x.show();
	return x;
}

void fun2(N *x)
{
	x->set_n(8);
	cout<<"fun2  ";
	x->show();
}

void fun3(N x)
{
	x.set_n(10);
	cout<<"fun3  ";
	x.show();
}

int main()
{
	N a(0),b(0),c(0);

	cout<<"before  \n";
	a.show();
	b.show();
	c.show();
	cout<<endl<<endl;
	a = fun1(a);
	fun2(&b);
	fun3(c);

	cout<<"after  \n";
	a.show();
	b.show();
	c.show();
}


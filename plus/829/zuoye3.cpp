/*
 *
 *文件名：zuoye3.cpp
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
	N()
	{
		n = 0;
	}
	N(int x)
	{
		n = x;
	}
	N(N &x)
	{
		n = x.n + 1;
	}
	void show()
	{
		cout<<n<<endl;
	}
};

int main()
{
	N a;
	a.show();

	N b(a);
	b.show();
	
	N c(b);
	c.show();

	N d(c);
	d.show();

}

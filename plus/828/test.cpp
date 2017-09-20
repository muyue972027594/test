/*
 *文件名：test.cpp
 *功  能：
 *版本号：0.0.1
 *
*/


#include<iostream>

using namespace std;

class Test
{
	int a,b;
	
	public:
		void init(int x,int y)
		{
			a = x;
			b = y;
		}
		void print()
		{
			cout<<a<<"-"<<b<<"="<<a-b<<endl;
		}
};


int main()
		{
			Test a;
			a.init(68,55);
			a.print();
		}




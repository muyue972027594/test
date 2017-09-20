/*
 *文件名：zuoye6.cpp
 *功  能：
 *版本号：0.0.1
 *
*/


#include<iostream>
#include<stdio.h>
using namespace std;
namespace t1
{
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
			std::cout<<"space t1\t"<<a<<"-"<<b<<"="<<a-b<<std::endl;
		}
	};
}

namespace t2
{
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
			std::cout<<"space t2\t"<<a<<"-"<<b<<"="<<a-b<<std::endl;
		}
	};
};

using namespace t1;
int main()
		{
			Test a;
			a.init(96,48);
			a.print();

		}




/*
 *文件名：zuoye1.cpp
 *功  能：
 *版本号：0.0.1
 *
 *
*/

#include<iostream>

using namespace std;


class data
{
	int num;
	public:
		data()
		{
			num = 0;
		}
		data(int x)
		{
			num = x;
		}
		void set_data(int x)
		{
			num = x;
		}
		void disp()
		{
			cout<<num<<endl;
		}
};

int main()
{
	data *p = new data[10]; 

	for(int i = 0;i < 10;i++)
	{
		p[i].set_data(i+i);
		p[i].disp();
	}



	delete []p;

}

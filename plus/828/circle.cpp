/*
 *文件名：circle.cpp
 *功  能：
 *版本号：0.0.1
 */

#include<iostream>
#include<string.h>


#define P 3.14
using namespace std;

class circle
{
	private:
		int cir_r;
		
	public:
		circle(int r)
		{
			cir_r = r;
		}

		float area()
		{
			return P*cir_r*cir_r;
		}

		float girth()
		{
			return 2*P*cir_r;
		}
};


int main(int argc,char *argv[])
{
	circle cir1(5);

	cout<<"面积："<<cir1.area()<<"  周长："<<cir1.girth()<<endl;
}











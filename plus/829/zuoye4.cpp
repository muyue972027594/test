/*
 *文件名：zuoye4.cpp
 *功  能：
 *版本号：0.0.1
*/

#include <iostream>
#include <string.h>
using namespace std;

class car
{
	char name[15];
	int num;//载客数
	int price;//售价
	float speed;//速度
	public:
		car(char *name1,int num1,int price1,float speed1)
		{
			strcpy(name,name1);
			num = num1;
			price = price1;
			speed = speed1;
		}
		void test(int s,int count,int pri);
		void show()
		{
			cout<<name<<" 载客 "<<num<<" 人，售价 "<<price
					<<" 万 平均速度 "<<speed<<" Km/h "<<endl;
		}
};

void car::test(int s,int count,int pri)
{
	int cost,gain,aa;
	float time;
	if(count % num)
		cost = (count / num + 1) * price;
	else
		cost = count / num * price;

	gain = count * pri;

	time = s / speed;

	if(cost * 10000 % gain)
		aa = cost * 10000 / gain + 1;
	else
		aa = cost * 10000 / gain;

	cout<<"成本:"<<cost<<" 万元 单次获利:"<<gain<<" 元 单次用时:"<<time<<endl;
	cout<<"收回成本需要 "<<aa<<" 次 "<<"最快回收成本 "<<(int)((aa + 1) / 2.0)
			<<" 天 "<<endl;
}


int main()
{
	car c1("abc",7,10,80);
	car c2("def",15,25,90);
	car c3("hig",26,80,100);
	car c4("xyz",54,120,110);

	c1.show();
	c1.test(1000,500,350);
	cout<<endl;

	c2.show();
	c2.test(1000,500,350);
	cout<<endl;

	c3.show();
	c3.test(1000,500,350);
	cout<<endl;

	c4.show();
	c4.test(1000,500,350);
}


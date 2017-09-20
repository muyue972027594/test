/*
 *文件名：jisuanqi.cpp
 *功  能：
 *版本号：0.0.1
 *
*/

#include<iostream>
#include<string.h>

using namespace std;

class calculater
{
	char a[8];
	char type[3];
	char b[8];

	public:
		calculater(char *a1,char *type1,char *b1)
		{
			strcpy(a,a1);
			strcpy(type,type1);
			strcpy(b,b1);
		}

		float sum();//加
		float sub();//减
		float mul();//乘
		float div();//除
		float com();//余
};

float calculater::sum()
{
	float num = atoi(a) + atoi(b);
	return num;
}

float calculater::sub()
{
	float num = atoi(a) - atoi(b);
	return num;
}

float calculater::mul()
{
	float num = atoi(a) * atoi(b);
	return num;
}

float calculater::div()
{
	float num = atoi(a) / atoi(b);
	return num;
}

float calculater::com()
{
	float num = atoi(a) % atoi(b);
	return num;
}


int main(int argc,char *argv[])
{
	char a[8];
	char type[3];
	char b[8];

	cout<<"请输入算式"<<endl;
	cout<<"例：55 + 55"<<endl;
	cin>>a;
	cin>>type;
	cin>>b;

	calculater cal(a,type,b);

	switch(type[0])
	{
		case '+':cout<<"和："<<cal.sum()<<endl;break;
		case '-':cout<<"差："<<cal.sub()<<endl;break;
		case '*':cout<<"积："<<cal.mul()<<endl;break;
		case '/':cout<<"商："<<cal.div()<<endl;break;
		case '%':cout<<"余："<<cal.com()<<endl;
	}
}

/*
 *文件名：zuoye5.cpp
 *功  能：双人对战
 *版本号：0.0.1
*/

#include<iostream>
#include<string.h>
#include<time.h>
#include<unistd.h>
using namespace std;

class dota
{
	int maxblood;
	public:
	string name;
	int blood;
//	char *tab[6];
	string skill[4];
	dota(string a,int b,string c,string d,string e,string f);
	void attack(dota &x,int i);
	void show_me();
	int  get_blood();
};

dota::dota(string a,int b,string c,string d,string e,string f)
{
	name = a;
	blood = maxblood = b;
	skill[0] = c;
	skill[1] = d;
	skill[2] = e;
	skill[3] = f;
}

void dota::attack(dota &x,int i)
{
	if(i == 3)
	{
		cout<<name<<" 使用 "<<skill[i]<<" 为自己疗伤 "<<endl;
		blood += 10;
	}
	else
	{
		cout<<name<<" 使用 "<<skill[i]<<" 攻击 "<<x.name<<endl;
		x.blood -= 5 + 5 * i;
	}
	if(x.blood < 0) x.blood = 0;
	if(blood > maxblood ) blood = maxblood;
	cout<<x.name<<" 剩余 "<<x.blood<<" 血量 "<<endl;
}

void dota::show_me()
{
	cout<<name<<" 血量  "<<blood<<endl<<" 技能一  "<<skill[0];
	cout<<" 技能二  "<<skill[1]<<" 技能三  "<<skill[2]<<" 技能四  "<<skill[3]<<endl;
}

int dota::get_blood()
{
	return blood;
}

int main()
{
	dota per1("西门吹雪",100,"落花吹雪","剑神一笑","一剑西来","妙手回春");
	dota per2("叶孤城",100,"白云剑法","独孤九剑","天外飞仙","妙手回春");
	int i = 0;		

	per1.show_me();
	cout<<endl<<endl;
	per2.show_me();
	cout<<endl<<endl;

	cout<<"开始战斗"<<endl<<endl;
		
	while(1)
	{
		srand((int)time(0));
    	i = 0 + (int)(4.0 * rand() / (RAND_MAX + 1.0));
//		cout<<i<<endl;

		per1.attack(per2,i);
		cout<<endl;

		if(per2.get_blood() == 0)
		{
			cout<<per2.name<<" 不敌 "<<per1.name<<endl;
			break;
		}
		sleep(2);

		srand((int)time(0));
    	i = 0 + (int)(4.0 * rand() / (RAND_MAX + 1.0));
//		cout<<i<<endl;

		per2.attack(per1,i);
		cout<<endl;

		if(per1.get_blood() == 0)
		{
			cout<<per1.name<<" 不敌 "<<per2.name<<endl;
			break;
		}
		sleep(2);
	}
	
	cout<<"战斗结束"<<endl<<endl;
}





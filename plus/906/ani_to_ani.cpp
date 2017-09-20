/*
 *文件名：ani_to_ani.cpp
 *功  能：动物混战
 *版本号：0.0.1
 *
*/
#include<iostream>
#include<cstring>
#include<unistd.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
class animal
{
	public:
	string name;//名字
	int hp;//血量
	int atk;//攻击力
	int def;//防御力
	animal(string a)
	{
		name = a;
	}
	virtual void attack(animal *p) = 0;//攻击
	virtual void be_att(animal *p) = 0;//被攻击
	virtual int get_hp() = 0;//显示血量
};

class bird:public animal 
{
	public:
	bird(string a,int b,int c,int d);
	void attack(animal *p);
	void be_att(animal *p);
	int  get_hp();
};
	bird::bird(string a,int b,int c,int d):animal(a)
	{
		hp = b;
		atk = c;
		def = d;
	}
	void bird::attack(animal *p)
	{
		cout<<name<<"  攻击了  "<<p->name<<endl;
		p->be_att(this);
	}
	void bird::be_att(animal *p)
	{
		int x = 0;
		if(p->atk > def)
			x = p->atk - def;
		else 
			x = 0;
		hp -= x;
		if(hp < 0) hp = 0;
		cout<<name<<"  被  "<<p->name<<"  攻击了,"<<"剩余血量  "<<hp<<endl;
	}
	int  bird::get_hp()
	{
		return hp;
	}

class suckler:public animal 
{
	public:
	suckler(string a,int b,int c,int d);
	void attack(animal *p);
	void be_att(animal *p);
	int  get_hp();
};
	suckler::suckler(string a,int b,int c,int d):animal(a)
	{
		hp = b;
		atk = c;
		def = d;
	}
	void suckler::attack(animal *p)
	{
		cout<<name<<"  攻击了  "<<p->name<<endl;
		p->be_att(this);
	}
	void suckler::be_att(animal *p)
	{
		int x = 0;
		if(p->atk > def)
			x = p->atk - def;
		else 
			x = 0;
		hp -= x;
		if(hp < 0) hp = 0;
		cout<<name<<"  被  "<<p->name<<"  攻击了,"<<"剩余血量  "<<hp<<endl;
	}
	int  suckler::get_hp()
	{
		return hp;
	}
	

int main()
{
	int x,y,z;
	int HP1,HP2;
	animal *ani[] = {	new bird("青鸾",500,150,50),
						new bird("苍鹰",400,120,40),
						new bird("墨鸦",300,100,30),
						new suckler("青龙",750,80,70),
						new suckler("白泽",600,70,60),
						new suckler("玄武",500,60,50)	};
	
	while(1)
	{
		HP1 = HP2 = 0;
		for(int i = 0;i < 3;i++)
		{
			HP1 += ani[i]->get_hp();
			HP2 += ani[i + 3]->get_hp();
		}
//		cout<<HP1<<"    "<<HP2<<endl;
		if(HP1 == 0) 
		{
			cout<<"鸟类战败"<<endl;
			break;
		}
		if(HP2 == 0) 
		{
			cout<<"兽类战败"<<endl;
			break;
		}

		srand((int)time(0));
		x = (int)(2.0 * rand() / (RAND_MAX + 1.0));
		y = (int)(3.0 * rand() / (RAND_MAX + 1.0));
		sleep(1);
		z = (int)(3.0 * rand() / (RAND_MAX + 1.0));


		if(x)
		{
			while(ani[y]->get_hp() == 0)
			{
				y = y + 1;
				if(y > 2) y = 0;
			}
			while(ani[3 + z]->get_hp() == 0)
			{
				z = z + 1;
				if(z > 2) z = 0;
			}
			ani[y]->attack(ani[3 + z]);
		}
		else
		{
			while(ani[3 + y]->get_hp() == 0)
			{
				y = y + 1;
				if(y > 2) y = 0;
			}
			while(ani[z]->get_hp() == 0)
			{
				z = z + 1;
				if(z > 2) z = 0;
			}
			ani[3 + y]->attack(ani[z]);
		}
		

		cout<<endl<<endl;
	}
}




/*
 *文件名：football.cpp
 *功  能：足球游戏1
 *作  者：张
 *日  期：9.7
 *版本号：0.0.1
*/

#include<iostream>
#include<string>
#include<time.h>
#include<stdlib.h>

using namespace std;

class person
{
	public:
	string name;//名字
	int age;//年龄
};

class coach: public person
{
	string level;//级别
	public:
	coach(){}
	coach(string a,int b,string c);
	string get_level();//获取级别
};
	coach::coach(string a,int b,string c)
	{
		name = a;
		age = b;
		level = c;
	}
	string coach::get_level()
	{
		return level;
	}


	/*角色 :     前锋     中锋   后卫      守门   */
enum ROLETYPE { STRIKER,CENTER,DEFENDER,GOALKEEPER };

class player: public person
{
	float run;//奔跑速度
	float strong;//强壮度
	float flexible;//灵活度
	ROLETYPE type;//角色类型
	public:
	player(){}
	player(string a,int b,float c,float d,float e);
	void be_allot(ROLETYPE x);//被分配角色
	void be_drill(coach &x);//被教练训练
	void play(float x);//上场(x为0—1之间的数)	
	float get_state();//获取状态
};
	player::player(string a,int b,float c,float d,float e)
	{
		name = a;
		age = b;
		run = c;
		strong = d;
		flexible = e;
	}
	void player::be_allot(ROLETYPE x)
	{
		type = x;
		if(type == STRIKER && run > 80)
			run *= 1.1;
		if((type == CENTER || type == GOALKEEPER) && flexible > 80)
			flexible *= 1.1;
		if(type == DEFENDER && strong > 80)
			strong *= 1.1;
	}
	void player::be_drill(coach &x)
	{
		if(x.get_level() == "一级")
		{
			run *= 1.1;
			strong *= 1.1;
			flexible *= 1.1;
		}
		if(x.get_level() == "三级")
		{
			run *= 0.9;
			strong *= 0.9;
			flexible *= 0.9;
		}
	}
	void player::play(float x)
	{
		run *= x;
		strong *= x;
		flexible *= x; 
	}
	float player::get_state()
	{
		return run + strong + flexible;
	}
	

class team
{
	coach coa;//教练
	player role[12];//球员
	ROLETYPE ro[4];//角色
	int true1;
	int true2;
	int true3;
	public:
	string name;
	team(string a,coach b,player *c[11]);
	void drill();//训练球员
	void allot();//角色分配
	float play_on();//球员上场
	float attack();//进攻
	float defend();//防守
	float keeper();//守门
};
	team::team(string a,coach b,player *c[11])
	{
		name = a;
		coa = b;
		for(int i = 0;i < 11;i++)
			role[i + 1] = *c[i];
		ro[0] = STRIKER;
		ro[1] = CENTER;
		ro[2] = DEFENDER;
		ro[3] = GOALKEEPER;
		true1 = true2 = true3 = 0;
	}
	void team::drill()
	{
		for(int i = 1;i < 12;i++)
		{
			role[i].be_drill(coa);
		}
	} 
	void team::allot()
	{
		for(int i = 1;i < 4;i++)
		{
			role[i].be_allot(ro[0]);
		}
		for(int i = 4;i < 7;i++)
		{
			role[i].be_allot(ro[1]);
		}
		for(int i = 7;i < 11;i++)
		{
			role[i].be_allot(ro[2]);
		}
		role[11].be_allot(ro[3]);
	}
	float team::play_on()
	{
		float x = 0;
		if(true1) 
		{
			role[true1].play(0.6);
			x += role[true1].get_state();
		}
		if(true2) 
		{
			role[true2].play(0.6);
			x += role[true2].get_state();
		}
		if(true3) 
		{
			role[true3].play(0.6);
			x += role[true3].get_state();
		}
		return x;
	}
	float team::attack()
	{
		int pout1,pout2,pout3;
		true1 = 0,true2 = 0,true3 = 0;
		float power = 0;
		cout<<"请输入  "<<name<<"  第一位出击队员的编号"<<endl;
		cin>>pout1;		
		cout<<"请输入  "<<name<<"  第二位出击队员的编号"<<endl;
		cin>>pout2;		
		cout<<"请输入  "<<name<<"  第三位出击队员的编号"<<endl;
		cin>>pout3;
		
		if(pout1)
		{
			cout<<name<<"  派  "<<pout1<<"  号球员  "<<role[pout1].name
						<<"  出击，战力  "<<role[pout1].get_state()<<endl;	
			power += role[pout1].get_state();
			true1 = pout1;
		}
		if(pout2 && pout2 != pout1)
		{
			cout<<name<<"  派  "<<pout2<<"  号球员  "<<role[pout2].name
						<<"  出击，战力  "<<role[pout2].get_state()<<endl;	
			power += role[pout2].get_state();
			true2 = pout2;	
		}
		if(pout3 && pout3 != pout1 && pout3 != pout2)
		{
			cout<<name<<"  派  "<<pout3<<"  号球员  "<<role[pout3].name
						<<"  出击，战力  "<<role[pout3].get_state()<<endl;	
			power += role[pout2].get_state();
			true3 = pout3;
		}
		cout<<name<<"  进攻的总战力  "<<power<<endl;	

		return power;
	}
	float team::defend()
	{
		int pout1,pout2,pout3;
		true1 = 0,true2 = 0,true3 = 0;
		float power = 0;
		cout<<"请输入  "<<name<<"  第一位防守队员的编号"<<endl;
		cin>>pout1;		
		cout<<"请输入  "<<name<<"  第二位防守队员的编号"<<endl;
		cin>>pout2;		
		cout<<"请输入  "<<name<<"  第三位防守队员的编号"<<endl;
		cin>>pout3;
		
		if(pout1)
		{
			cout<<name<<"  派  "<<pout1<<"  号球员  "<<role[pout1].name
						<<"  防守，战力  "<<role[pout1].get_state()<<endl;	
			power += role[pout1].get_state();
			true1 = pout1;
		}
		if(pout2 && pout2 != pout1)
		{
			cout<<name<<"  派  "<<pout2<<"  号球员  "<<role[pout2].name
						<<"  防守，战力  "<<role[pout2].get_state()<<endl;	
			power += role[pout2].get_state();
			true2 = pout2;
		}
		if(pout3 && pout3 != pout1 && pout3 != pout2)
		{
			cout<<name<<"  派  "<<pout3<<"  号球员  "<<role[pout3].name
						<<"  防守，战力  "<<role[pout3].get_state()<<endl;	
			power += role[pout2].get_state();
			true3 = pout3;
		}
		cout<<name<<"  防守的总战力  "<<power<<endl;	

		play_on();	

		return power;
	}
	float team::keeper()
	{
		float x = role[11].get_state();
		role[11].play(0.8);
		return x;
	}

int main()
{
	player *pl1[11] = {	new player("zhang 1",25,85,90,76),
						new player("zhang 2",25,85,90,76),
						new player("zhang 3",25,85,90,76),
						new player("zhang 4",25,85,90,76),
						new player("zhang 5",25,85,90,76),
						new player("zhang 6",25,85,90,76),
						new player("zhang 7",25,85,90,76),
						new player("zhang 8",25,85,90,76),
						new player("zhang 9",25,85,90,76),
						new player("zhang 10",25,85,90,76),
						new player("zhang 11",25,85,90,76)	};

	player *pl2[11] = { new player("wang 1",25,85,90,76),
                        new player("wang 2",25,85,90,76),
                        new player("wang 3",25,85,90,76),
                        new player("wang 4",25,85,90,76),
                        new player("wang 5",25,85,90,76),
                        new player("wang 6",25,85,90,76),
                        new player("wang 7",25,85,90,76),
                        new player("wang 8",25,85,90,76),
                        new player("wang 9",25,85,90,76),
                        new player("wang 10",25,85,90,76),
                        new player("wang 11",25,85,90,76)   };

	coach coc1("王教练",45,"一级"),coc2("李教练",50,"一级");

	team tete1("一队",coc1,pl1),tete2("二队",coc2,pl2);


	tete1.allot();//一队分配角色
	tete1.drill();//一队训练
	tete2.allot();//二队分配角色
	tete2.drill();//二队训练


	int fight_time = 0;
	float t1_power = 0;
	float t2_power = 0;

	int t1_score = 0,t2_score = 0;

	int win1_time = 0,win2_time = 0;
	int x;

	while(1)
	{
		srand((int)time(0));
		x = (int)(2.0 * rand() / (RAND_MAX + 1.0));

		fight_time++;
		if(fight_time > 5) break;

		if(x)
		{
			T1ATT:t1_power = tete1.attack();
			win1_time = 0;
							cout<<endl<<endl;
			T2DEF:t2_power = tete2.defend();
							cout<<endl<<endl;

			if(t1_power > t2_power)
        	{
				t1_power = tete1.play_on();
				win1_time++;
				if(win1_time == 1)
				{
        	    	cout<<tete1.name<<"  穿过第一道防线，继续进攻"<<endl;
        	    	cout<<tete2.name<<"  准备第二道防线"<<endl;
                            cout<<endl<<endl;
				}
				if(win1_time == 2)
				{
					cout<<tete1.name<<"  越踢越强，穿过第二道防线，继续进攻"<<endl;
					cout<<tete2.name<<"  准备第三道防线"<<endl;
							cout<<endl<<endl;
				}
				if(win1_time == 3)
				{
					cout<<tete1.name<<"  势不可挡，穿过第三道防线，准备射门"<<endl;
					if(t1_power > tete2.keeper())
					{
						t1_score++;
							cout<<endl<<endl;
						cout<<tete1.name<<"  进球，得一分"<<endl;
					}
				}
				if(win1_time < 3)
					goto T2DEF;
			}
			else
			{
				t1_power = tete1.play_on();
				cout<<tete2.name<<"  防御成功，转为进攻"<<endl;
							cout<<endl<<endl;
				goto T2ATT;
			}
		}
		else
		{
			T2ATT:t2_power = tete2.attack();
			win2_time = 0;
							cout<<endl<<endl;
			T1DEF:t1_power = tete1.defend();
							cout<<endl<<endl;

			if(t2_power > t1_power)
        	{
				t2_power = tete2.play_on();
				win2_time++;
				if(win2_time == 1)
				{
        	    	cout<<tete2.name<<"  穿过第一道防线，继续进攻"<<endl;
        	    	cout<<tete1.name<<"  准备第二道防线"<<endl;
                            cout<<endl<<endl;
				}
				if(win2_time == 2)
				{
					cout<<tete2.name<<"  越踢越强，穿过第二道防线，继续进攻"<<endl;
					cout<<tete1.name<<"  准备第三道防线"<<endl;
							cout<<endl<<endl;
				}
				if(win2_time == 3)
				{
					cout<<tete2.name<<"  势不可挡，穿过第三道防线，准备射门"<<endl;
					if(t2_power > tete1.keeper())
					{
						t2_score++;
							cout<<endl<<endl;
						cout<<tete2.name<<"  进球，得一分"<<endl;
					}
				}
				if(win2_time < 3)
					goto T1DEF;
			}
			else
			{
				t2_power = tete2.play_on();
				cout<<tete1.name<<"  防御成功，转为进攻"<<endl;
							cout<<endl<<endl;
				goto T1ATT;
			}
		}
			

	}

							cout<<endl<<endl;
	cout<<"比赛结束，比分 "<<tete1.name<<" "<<t1_score<<" : "
								<<t2_score<<" "<<tete2.name<<endl;

	for(int i = 0;i < 11;i++)
	{
		delete pl1[i];
		delete pl2[i];
	}
}

















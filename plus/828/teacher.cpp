/*
 *文件名：teacher.cpp
 *功  能：
 *版本号：0.0.1
 */

#include<iostream>
#include<string.h>


using namespace std;

class teacher
{
	private:
		char name[16];
		int age;
		char sex[8];
	public:
		teacher()
		{
			strcpy(name,"No_one");
			age = 0;
			strcpy(sex,"Un_know");
		}
	
		teacher(char newname[16],int newage,char newsex[8])
		{
			strcpy(name,newname);
			age = newage;
			strcpy(sex,newsex);
		}

		void introduce()
		{
			cout<<"我叫"<<name<<","<<sex<<",今年"<<age<<"岁."<<endl;
		}

};


int main(int argc,char *argv[])
{
	teacher tch1,tch2("张",30,"男");

	tch1.introduce();
	tch2.introduce();
}






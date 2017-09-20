/*
 *文件名：cat.cpp
 *功  能：
 *版本号：0.0.1
 */

#include<iostream>
#include<string.h>



using namespace std;

class cat
{
	private:
		char name[16];
		int age;
		
	public:
		cat()
		{
			strcpy(name,"No_one");
			age = 0;
		}
	
		cat(char newname[16],int newage)
		{
			strcpy(name,newname);
			age = newage;
		}

		void introduce()
		{
			cout<<"我叫"<<name<<","<<"今年"<<age<<"岁."<<endl;
		}

};


int main(int argc,char *argv[])
{
	cat pet1;

	pet1.introduce();
}











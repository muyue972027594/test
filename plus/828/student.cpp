/*
 *文件名：student.cpp
 *功  能：
 *版本号：0.0.1
 */

#include<iostream>
#include<string.h>



using namespace std;

class student
{
	private:
		char name[16];
		int age;
		int score[3];
		
	public:
		student()
		{
			strcpy(name,"No_one");
			age = 0;
			score[0] = 0;
			score[1] = 0;
			score[2] = 0;
		}
	
		student(char newname[16],int newage,int a_sc,int b_sc,int c_sc)
		{
			strcpy(name,newname);
			age = newage;
			score[0] = a_sc;
			score[1] = b_sc;
			score[2] = c_sc;
		}

		int count_sc()
		{
			int sum = 0;
			for(int i = 0;i < 3;i++)
				sum += score[i];

			return sum;
		}

		int ave_sc()
		{
			int sum = 0;
			int i;
			for(i = 0;i < 3;i++)
				sum += score[i];

			return sum/i;
		}

		void introduce()
		{
			cout<<"我叫"<<name<<","<<"今年"<<age<<"岁."<<endl;
		}

};


int main(int argc,char *argv[])
{
	student stu1,stu2("张",30,89,90,94);

	stu1.introduce();
	cout<<"stu1总分:"<<stu1.count_sc()<<" 平均分:"<<stu1.ave_sc()<<endl;
	
	stu2.introduce();
	cout<<"stu2总分:"<<stu2.count_sc()<<" 平均分:"<<stu2.ave_sc()<<endl;
}











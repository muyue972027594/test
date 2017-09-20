/*
 *文件名：overload.cpp
 *功  能：日期 重载
 *版本号：0.0.1
*/
#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class date
{
	int year;
	int month;
	int day;

	public:
	date(){}
	date(int y,int m,int d)
	{
		year = y;
		month = m;
		day = d;
	}	
	date(int m,int d)
	{
		time_t timep;
		struct tm *p;
		time(&timep);
		p = gmtime(&timep);

		year = 1900 + p->tm_year;
		month = m;
		day = d;
	}

	int get_days(int y,int m)
	{
		int i = 0;
		int days[2][13] = {0,31,28,31,30,31,30,31,31,30,31,30,31,
							0,31,29,31,30,31,30,31,31,30,31,30,31};		
		if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			i = 1;
	
		return days[i][m];
	}

	date operator +(int d)
	{
		date olddate = *this;
		d = d + day;

		while(d > get_days(year,month))
		{



		}

	}


};

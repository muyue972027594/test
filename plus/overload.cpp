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

	int get_days(int y)
	{
		int i = 0;
		int days[2] = {365,366};
		if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			i = 1;

		return days[i];
	}

	date operator +(int d)
	{
		date newdate = *this;
		d = d + newdate.day;

		while(d > get_days(newdate.year,newdate.month))
		{
			d = d - get_days(newdate.year,newdate.month);
			newdate.month = newdate.month + 1;

			if(newdate.month > 12)
			{
				newdate.year = newdate.year + 1;
				newdate.month = 1;
			}
		}

		newdate.day = d;

		return newdate;
	}

	date operator -(int d)
	{
		date newdate = *this;
		if(d < newdate.day)
			newdate.day = newdate.day - d;
		else
		{
			while(d > newdate.day)
			{
				d = d - newdate.day;
				newdate.month = newdate.month - 1;
	
				if(newdate.month  < 1)
				{
					newdate.year = newdate.year - 1;
					newdate.month = 12;
				}
				newdate.day = get_days(newdate.year,newdate.month);
			}
			if(d == newdate.day)
			{
				newdate.month = newdate.month - 1;
				newdate.day = get_days(newdate.year,newdate.month);
			}
			else
				newdate.day = newdate.day - d;
		}
		return newdate;
	}

	int operator -(date x)
	{
		date y = *this;
		int dx = 0,dy = 0;
		
		while(x.month > 0)
		{
			dx = dx + x.day;
			x.month = x.month - 1;
			x.day = get_days(x.year,x.month);
		}			
		
		while(y.month > 0)
		{
			dy = dy + y.day;
			y.month = y.month - 1;
			y.day = get_days(y.year,y.month);
		}			

		while(x.year > y.year)
		{
			dx = dx + get_days(y.year);
			y.year = y.year + 1;
		}

		while(y.year > x.year)
		{
			dy = dy + get_days(x.year);
			x.year = x.year + 1;
		}
		
		if(dx > dy)
			return (dx - dy);
		else
			return (dy - dx);
	}

	void operator ++()
	{
		day = day + 1;
		if(day > get_days(year,month))
		{
			month = month + 1;
			if(month > 12)
			{
				year = year + 1;
				month = 1;
			}
			day = 1;
		}
	}	
	
	void operator --()
	{
		day = day - 1;
		if(day < 1)
		{
			month = month - 1;
			if(month < 1)
			{
				year = year - 1;
				month = 12;
			}
			day = get_days(year,month);
		}
	}
/*
	void operator +++()
	{
		month = month + 1;
	}	
	
	void operator ---()
	{
		month = month - 1;
	}
*/
	void show()
	{
		cout<<year<<"-"<<month<<"-"<<day<<endl;
	}
};



int main()
{
	date aa(2016,8,1);

	date bb = aa + 365;

	date cc = aa - 365;

	bb.show();
	cc.show();

	date dd(2017,12,31);
	date ee(2017,1,1);	
	cout<<bb - cc<<endl;

	++dd;
	dd.show();
	--ee;
	ee.show();
}

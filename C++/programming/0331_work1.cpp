#include <bits/stdc++.h>
using namespace std;

struct date
{
	int year;
	int month;
	int day;

	date(int year , int month , int day){
		this -> year = year;
		this -> month = month;
		this -> day = day;
	}
};


int main () {
	
	date holiday(2004,4,26);
	date festival(0,0,0);

	int year,month,day;
	cout<<"Please input: \n";
	cin>>year>>month>>day;
	festival = date(year,month,day);


	cout<<"Year: "<<festival.year<<"\nMonth: "<<festival.month<<"\nDay: "<<festival.day<<"\n";

	system("pause");

	return 0;
}


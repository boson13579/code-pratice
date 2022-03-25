/*
*Pratice 8
*Name: 陳柏燊
*Student Number: 110502529
*Course 2021-CE1003-A
*/

#include <bits/stdc++.h>
using namespace std;

int main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	string N;
	string I;
	double E;
	double M;
	double C;
	int WE;
	int WM;
	int WC;
	cout<<"Please input your name : ";cin>>N;
	cout<<"Please input your student ID : ";cin>>I;
	cout<<"English score : ";cin>>E;
	cout<<"Math score : ";cin>>M;
	cout<<"Chinese score : ";cin>>C;
	cout<<"English weight : ";cin>>WE;
	cout<<"Math weight : ";cin>>WM;
	cout<<"Chinese weight : ";cin>>WC;
	cout<<"\n";
	cout<<"Student name : "<<N<<"\n";
	cout<<"Student ID : "<<I<<"\n";
	cout<<"Arithmetic average : "<<int((E+M+C)/3)<<"\n";
	cout<<"Weighted average : "<<int(((E*WE)+(M*WM)+(C*WC))/(WE+WM+WC))<<"\n";

	return 0;
}


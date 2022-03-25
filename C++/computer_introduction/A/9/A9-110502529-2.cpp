/*
*Assignment 9-2
*Name: 陳柏燊
*Student Number: 110502529
*Course 2021-CE1003-A
*/
#include <bits/stdc++.h>
using namespace std;

int a[3];

int main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	cout<<"Please key in first number:\n";
	cin>>a[0];
	cout<<"Please key in second number:\n";
	cin>>a[1];
	cout<<"Please key in third number:\n";
	cin>>a[2];
	sort(a,a+3);
	if(a[0]+a[1]<=a[2]){
		cout<<"Not triangle\n";
		return 0;
	}
	if(a[0]==a[1] and a[1]==a[2]){
		cout<<"Regular triangle\n";
	}
	else{
		bool right = false;
		if(a[0]*(a[0]) + a[1]*(a[1]) == a[2]*(a[2]))
			right = true;
		bool equ = false;
		if(a[0]==a[1] or a[1]==a[2])
			equ = true;
		if(right and equ)
			cout<<"Isosceles right triangle\n";
		else if(right)
			cout<<"Right triangle\n";
		else if(equ)
			cout<<"Isosceles triangle\n";
		else
			cout<<"Not triangle\n";
	}

	return 0;
}


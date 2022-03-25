/*
*Pratice 13
*Name: 陳柏燊
*Student Number: 110502529
*Course 2021-CE1003-A
*/
#include <bits/stdc++.h>
using namespace std;

char arr[3][3];
string filename = "ox1.txt";

void input();
void solve(int a);

int main () {

	for(int i=1 ; i<=3 ; i++){
		filename[2] = char(i+int('0'));
		ifstream in(filename);
		cin.rdbuf(in.rdbuf());
		input();
		solve(i);
	}

	return 0;
}

void input(){
	for(int i=0 ; i<3 ; i++)
		for(int t=0 ; t<3 ; t++)
			cin >> arr[i][t];
}

void solve(int a){

	char win = 'N';
	bool findwin = false;

	//checkline
	for(int i=0 ; i<3 and !findwin; i++){

		bool hodif = false;
		for(int t=0 ; t<3 ; t++)
			if(arr[i][t] != arr[i][0])
				hodif = true;

		if(!hodif){
			findwin = true;
			win = arr[i][0];
		}

		bool vedif = false;
		for(int t=0 ; t<3 and !findwin; t++)
			if(arr[t][i] != arr[0][i])
				vedif = true;
		
		if(!vedif){
			findwin = true;
			win = arr[0][i];
		}
	}

	//check slant
	bool lsldif = false;
	for(int i=0 ; i<3 and !findwin ; i++)
		if(arr[i][i] != arr[0][0])
			lsldif = true;

	if(!lsldif){
		findwin = true;
		win = arr[0][0];
	}

	bool rsldif = false;
	for(int i=0 ; i<3 and !findwin; i++)
		if(arr[i][2-i] != arr[0][2])
			rsldif = true;
	if(!rsldif){
		findwin = true;
		win = arr[0][2];
	}

	if(findwin and win != 'N')
		cout<<"ox"<<a<<": "<<win<<"win\n";
	else	
		cout<<"ox"<<a<<": "<<"tie\n";
}
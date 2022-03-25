#include <bits/stdc++.h>
using namespace std;

int arr[9][9];
string filename = "sudo1.txt";

void solve(int a);
bool checkline(int a);
bool checkmatrix(int a , int b);
void input();

int main () {

		input();
		solve(1);

	return 0;
}

void solve(int a){

	bool ans = true;
	
	for(int i=0 ; i<9 and ans; i++)
		ans = checkline(i);

	for(int i=0 ; i<9 and ans; i+=3)
		for(int t=0 ; t<9 and ans; t+=3)
			ans = checkmatrix(i,t);
		
	if(ans)
		cout<<"Y\n";
	else
		cout<<"N\n";

}

void input(){

	for(int i=0 ; i<9 ; i++)
		for(int t=0 ; t<9 ; t++)
			cin>>arr[i][t];	
	
}

bool checkline(int a){

	set<int> check;
	bool ans = true;

	for(int i=0 , temp ; i<9 and ans; i++){
		temp = arr[a][i];
		if(check.find(temp) != check.end())
			ans = false;
		check.emplace(temp);
	}
	check.clear();

	for(int i=0 , temp ; i<9 and ans; i++){
		temp = arr[i][a];
		if(check.find(temp) != check.end())
			ans = false;
			check.emplace(temp);
	}

	return ans;
}

bool checkmatrix(int a , int b){
	
	bool ans = true;
	set <int> check;

	for(int i=a ; i<a+3 ; i++){
		for(int t=b ,temp ; t<b+3 ; t++ ){
			temp = arr[i][t];
			if(check.find(temp) != check.end())
				ans = false;
			check.emplace(temp);
		}
	}

	return ans;
}

/*
ifstream qq("text,txt");
auto reord = cin.rdbuf();
cin.rdbuf(qq);
cin.rdbuf(record);
qq >> int;
*/
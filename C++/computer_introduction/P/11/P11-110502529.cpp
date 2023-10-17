/*
*Pratice 11
*Name: 陳柏燊
*Student Number: 110502529
*Course 2021-CE1003-A
*/
#include <bits/stdc++.h>
using namespace std;

set<char> solve;

int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	//ios::sync_with_stdio(0), cin.tie(0);
	int a;char temp;
	
	while(cin>>a and a != -1){

		solve.clear();

		for(int i=0 ; i<a ; i++){
			cin>>temp;
			solve.insert(temp);
		}

		for(auto i:solve)
			cout<<i<<" ";
		cout<<"\n";

		cin>>temp;
		if(solve.find(temp) != solve.end()){
			cout<<distance(solve.begin(),solve.find(temp))<<"\n\n";
		}
		else
			cout<<"-1\n\n";		
	}

	return 0;
}
/*
*Assignment 10
*Name: 陳柏燊
*Student Number: 110502529
*Course 2021-CE1003-A
*/
#include <bits/stdc++.h>
using namespace std;

vector <char> arr;
string temp;

int main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	while(cin>>temp && (temp == "list" or temp == "pop" or temp == "push")){
		if(temp == "push"){
			char temp1;cin>>temp1;
			arr.emplace_back(temp1);
		}
		else if(temp == "pop"){
			if(arr.size()==0){
				cout<<"empty\n";
				continue;
			}
			cout<<*(arr.end()-1)<<"\n";
			arr.erase(arr.end()-1);
		}
		else{
			if(arr.size()==0){
				cout<<"\n";
				continue;
			}
			for(auto i:arr)
				cout<<i<<" ";
			cout<<"\n";
		}
	}

	return 0;
}


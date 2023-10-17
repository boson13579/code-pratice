/*
*Pratice 10
*Name: 陳柏燊
*Student Number: 110502529
*Course 2021-CE1003-A
*/

#include <bits/stdc++.h>
using namespace std;

int main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	string temp;
	while(cin>>temp and temp != "-1"){
		bool ok = true;
		for(int i=0 ; i<temp.size() ; i++){
			if(temp[i]!=temp[temp.size()-i-1]){
				ok = false;
				break;
			}
		}
		if(ok)
			cout<<"Palindrome!\n";
		else
			cout<<"Not Palindrome!\n";
	}

	return 0;
}


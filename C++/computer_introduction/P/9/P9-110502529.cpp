/*
*Pratice 9
*Name: 陳柏燊
*Student Number: 110502529
*Course 2021-CE1003-A
*/
#include <bits/stdc++.h>
using namespace std;

int main () {
	//ios::sync_with_stdio(0), cin.tie(0);
	int n;cin>>n;cin.ignore();
	while(n--){
		string temp;
		getline(cin,temp);

		if(temp != ""){
			char now;
			int count = 1;
			int len = temp.size();

			for(int i=0 ; i<len ; i++){
				if(i==0){
					now = temp[0];
				}
				else if(temp[i] != now){
					cout<<now<<count;
					now = temp[i];
					count = 1;
				}	
				else{
					count++;
				}
						
			}

			cout<<now<<count;
		}

		cout<<"\n";
	}
	return 0;
}


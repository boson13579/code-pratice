#include <bits/stdc++.h>
using namespace std;

int a,num,sum=0;
string temp;
bool canput[210];

int main () {
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>a;
	cin.ignore();
	while(a--){
		getline(cin,temp);
		memset(canput , false , sizeof(canput) );
		canput[0] = true;
		stringstream tempint(temp);
		sum = 0;
		while(tempint >> num){
			sum += num;
			for(int i=201 ; i>=0 ; i--){
				if(canput[i])
					canput[i+num] = true;
			}
		}
		if(sum%2==1)
			cout<<"NO\n";
		else if(canput[sum/2])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}


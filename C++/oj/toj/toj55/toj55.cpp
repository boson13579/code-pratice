#include <bits/stdc++.h>
using namespace std;

unordered_map< int , int > mp ;
int a , b;

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>a;
	for(int i=0 ; i<a ; i++){
		cin>>b;
		mp[b] +=1;
	}
	cin>>a;
	for(int i=0 ; i<a ; i++){
		cin>>b;
		cout<<mp[b]<<"\n";
	}

	return 0;
}

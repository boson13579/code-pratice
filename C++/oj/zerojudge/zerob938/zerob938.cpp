#include <bits/stdc++.h>
using namespace std;

int n,m,temp;
set<int> s;
bool ard[1000005];

int main () {
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n ; i++) s.insert(i);
	for(int i=0 , ki ; i<m ; i++){
		cin>>ki;
		if(ard[ki]){
			cout<<"0u0 ...... ?\n";
			continue;
		}
		auto iter = s.upper_bound(ki);
		if( iter == s.end()){
			cout<<"0u0 ...... ?\n";
			continue;
		}
		cout<< *iter << "\n";
		ard[*iter] = true;
		s.erase(iter); 

	}
		
	return 0;
}


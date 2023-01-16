#include <bits/stdc++.h>
using namespace std;



int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	string s;
	char now = '1';
	int ans = 1, temp=0;
	cin>>s;
	for(auto i : s){
		if(i==now){
			temp++;
			ans = max(ans,temp);
		}
		else{
			now = i;
			temp = 1;
		}

	}
	cout<<ans;
	return 0;
}


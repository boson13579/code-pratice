#include <bits/stdc++.h>
using namespace std;

int main () {
	ios::sync_with_stdio(0), cin.tie(0);

	int a,ans=1;
	cin>>a;
	while(a--){
		ans *= 2;
		ans %= 1000000007;
	}

	cout<<ans<<"\n";

	return 0;
}


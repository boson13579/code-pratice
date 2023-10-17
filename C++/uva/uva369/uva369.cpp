#include <bits/stdc++.h>
using namespace std;

long long ans[101][101];

long long uppper_down(int n ,int m){
	if (m>n)
		return 0;
	else if(ans[n][m]!=-0)
		return ans[n][m];
	else {
		ans[n][m] = uppper_down(n-1,m-1) + uppper_down(n-1,m);
		return ans[n][m];
	}
}


int main () {
	//freopen("test.in", "r", stdin);
	//freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	//init
	for(int i=0 ; i<101 ; i++){
		ans[i][1] = i;
	}

	int n,m;
	while(cin>>n>>m and n!=0 and m!=0){
		cout<<n<<" things taken "<<m<<" at a time is "<<uppper_down(n,m)<<" exactly.\n";
	}

	return 0;
}


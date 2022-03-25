#include <iostream>
#include <sstream>
#include <string.h>
using namespace std;
bool dp[201];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	string s;
	cin >> t;
	getline(cin,s);
    cout<<s<<"\n";
	while ( t-- && getline(cin,s) ) {
		int x, sum = 0;
		memset(dp,false,sizeof(dp));
		dp[0] = true;
		stringstream ss(s);
		while ( ss >> x ) {
			sum += x;
			for ( int i=200; i>=0; --i )
				if ( dp[i] )
					dp[i+x] = true;
		}
		cout << (sum%2 ? "NO" : (dp[sum/2] ? "YES" : "NO")) << '\n';
	}
	return 0;
}
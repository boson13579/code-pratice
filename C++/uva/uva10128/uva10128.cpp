#include <bits/stdc++.h>
using namespace std;

int main () 
{
	ios::sync_with_stdio(0), cin.tie(0);
	int a;cin >> a;
	while(a--) {
		int n, p, r;cin >> n >> p >> r;
		vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(p + 1, vector<int>(r + 1, 0)));
		dp[1][1][1] = 1;
		for(int i = 2; i <= n; ++i) for(int j = 1; j <= p; ++j) for(int k = 1; k <= r; ++k) 
		dp[i][j][k] = dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i - 1][j][k - 1];
		cout << dp[n][p][r]<<"\n";
	}
	return 0;
}
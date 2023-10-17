#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> v(n + 1);
	vector<long long> dp(n + 1);

	for (int i = 1; i <= n; i++) cin >> v[i];

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		if (mp.find(a) != mp.end()) mp[a] = min(mp[n], b);
		mp.emplace(a, b);
	}
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1e18;
		for (auto t : mp) {
			if (t.first >= v[i] and dp[i] > t.second) dp[i] = t.second;
			else {
				auto iter = prev(upper_bound(v.begin(), v.end(), v[i] - t.first));
				dp[i] = min(dp[i], dp[iter - v.begin()] + t.second);
			}
		}
	}
	cout << dp.back() << "\n";
	return 0;
}


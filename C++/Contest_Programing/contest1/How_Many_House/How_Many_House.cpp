#include <bits/stdc++.h>
using namespace std;

vector<int> path[50005];
vector<int> unpath[50005];
vector<bitset<50005>> dp(50005, 0);
vector<bitset<50005>> undp(50005, 0);

void dfs(int head, bool un) {
	if (un) {
		if (undp[head].count() != 0)
			return;
		undp[head][head] = 1;
		for (auto i : unpath[head]) {
			dfs(i, true);
			undp[head] |= undp[i];
		}
	}

	else {
		if (dp[head].count() != 0)
			return;
		dp[head][head] = 1;
		for (auto i : path[head]) {
			dfs(i, false);
			dp[head] |= dp[i];
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m, q;
	cin >> n >> m >> q;

	vector<int> in(n + 1, 0);
	vector<int> unin(n + 1, 0);

	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		path[a].emplace_back(b);
		in[b]++;
		unpath[b].emplace_back(a);
		unin[a]++;
	}

	for (int i = 1; i <= n; i++)
		if (!in[i])
			dfs(i, false);


	for (int i = 1; i <= n; i++)
		if (!unin[i])
			dfs(i, true);

	int countl[50005] = {}, countr[50005] = {};
	for (int i = 1; i <= n; i++) {
		countl[i] = -1;
		countr[i] = -1;
	}

	char dir;
	for (int i = 0, a, b; i < q; i++) {
		cin >> a >> b >> dir;
		if (dir == 'R') {
			if (countl[a] == -1) {
				countl[a] = (int)undp[a].count() - 1;
				countr[a] = (int)dp[a].count() - 1;
			}
			if (b >= countr[a] and b < n - countl[a])
				cout << "NO\n";
			else
				cout << "YES\n";
		}
		if (dir == 'L') {
			if (countl[a] == -1) {
				countl[a] = undp[a].count() - 1;
				countr[a] = dp[a].count() - 1;
			}
			if (b >= countl[a] and b < n - countr[a])
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}

	return 0;
}
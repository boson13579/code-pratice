#include <bits/stdc++.h>
using namespace std;

vector<int> path[100005], ans;
int parent[100005];
bool vis[100005], tv[100005];

void dfs(int i, int p) {

	vis[i] = true;
	tv[i] = true;
	parent[i] = p;

	for (int t : path[i]) {

		if (vis[t]) {
			parent[t] = i;
			int now = i;
			ans.emplace_back(t);
			do {
				ans.emplace_back(now);
				now = parent[now];
			} while (now != i);
			cout << ans.size() << "\n";
			for (auto k = ans.rbegin(); k != ans.rend(); k++) cout << *k << " ";
			cout << "\n";
			exit(0);

		}
		if (!tv[t])dfs(t, i);
	}

	vis[i] = false;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m, a, b;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		path[a].emplace_back(b);
	}

	for (int i = 1; i <= n; i++) {
		if (!tv[i]) dfs(i, i);
	}
	cout << "IMPOSSIBLE\n";

	return 0;
}

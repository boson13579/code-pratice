#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;

vector<pair<int, int>> path[100005], repath[100005];

long long dis[100005];
int minroute[100005], maxroute[100005];
int DP[100005];

int findRoutes(int n) {

	if (DP[n] != 0)
		return DP[n];

	int ans = 0;

	for (auto i : repath[n]) {
		if (dis[n] - i.second == dis[i.first]) ans += findRoutes(i.first);
		ans %= int(1e9 + 7);
	}

	DP[n] = ans;
	return ans;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		path[a].emplace_back(b, c);
		repath[b].emplace_back(a, c);
	}

	for (int i = 0; i <= n; i++) dis[i] = 1e18;

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	pq.emplace(0, 1);
	dis[1] = 0;

	while (!pq.empty()) {
		auto now = pq.top();
		pq.pop();

		if (dis[now.second] < now.first) continue;

		for (auto i : path[now.second]) {
			if (dis[i.first] > dis[now.second] + i.second) {
				dis[i.first] = dis[now.second] + i.second;
				pq.emplace(dis[i.first], i.first);
				minroute[i.first] = minroute[now.second] + 1;
				maxroute[i.first] = maxroute[now.second] + 1;
			}
			else if (dis[i.first] == dis[now.second] + i.second) {
				minroute[i.first] = min(minroute[i.first], minroute[now.second] + 1);
				maxroute[i.first] = max(maxroute[i.first], maxroute[now.second] + 1);
			}
		}
	}

	DP[1] = 1;
	int routes = findRoutes(n);

	cout << dis[n] << " " << routes << " " << minroute[n] << " " << maxroute[n] << "\n";

	return 0;
}


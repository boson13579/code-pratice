#include <bits/stdc++.h>
using namespace std;
#define int long long

vector<pair<int, int>> path[200005];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m, dt, nt;

	cin >> n >> m >> dt >> nt;

	vector<long long> dis(n + 1);

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		path[a].emplace_back(b, c);
		path[b].emplace_back(a, c);
	}

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	fill(dis.begin(), dis.end(), 1e18);
	pq.emplace(0, 1);
	dis[1] = 0;

	auto cango = [&](long long now, int len) -> long long{
		now %= (dt + nt);
		if (now + len <= dt)
			return len;
		else if (len <= dt)
			return (dt + nt) - now + len;
		else
			return 1e18;
	};

	while (!pq.empty()) {

		auto [nd, now] = pq.top();
		pq.pop();

		if (nd > dis[now]) continue;

		for (auto i : path[now]) {
			if (int t = cango(dis[now], i.second); t != 1e18) {
				if (dis[i.first] > dis[now] + t) {
					dis[i.first] = dis[now] + t;
					pq.emplace(dis[i.first], i.first);
				}
			}
		}
	}

	if (dis[n] == 1e18)
		cout << "-1\n";
	else
		cout << dis[n] << "\n";


	return 0;
}

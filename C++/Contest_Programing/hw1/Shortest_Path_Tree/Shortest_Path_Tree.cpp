#include <bits/stdc++.h>
using namespace std;

struct road {
	int to, dis, n;
	road(int a, int b, int c);
};

vector<road> path[200005];
long long dis[200005];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 1, a, b, c; i <= m; i++) {
		cin >> a >> b >> c;
		path[a].emplace_back(i, b, c);
		path[b].emplace_back(i, a, c);
	}

	vector<int> ans(n + 1, 0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n + 1; i++) dis[i] = 1e18;

	pq.emplace(0, 1);
	dis[1] = 0;

	while (!pq.empty()) {

		auto now = pq.top();
		pq.pop();

		if (now.first > dis[now.second])continue;

		for (auto i : path[now.second]) {
			if (dis[i.to] > dis[now.second] + i.dis) {
				dis[i.to] = dis[now.second] + i.dis;
				ans[i.to] = i.n;
				pq.emplace(dis[i.to], i.to);
			}
		}

	}

	for (int i = 2; i <= n; i++)
		cout << ans[i] << " ";

	return 0;
}

road::road(int a, int b, int c) {
	this->n = a;
	this->to = b;
	this->dis = c;
}

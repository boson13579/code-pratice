#include <bits/stdc++.h>
using namespace std;

struct road {
	int n, t, k;
	road(int& a, int& b, int& c);
};

long long ans[100005];

vector<road> path[100005];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m, from, to;
	cin >> n >> m >> from >> to;

	for (int i = 0, a, b, c, d; i < m; i++) {
		cin >> a >> b >> c >> d;
		path[a].emplace_back(b, c, d);
		path[b].emplace_back(a, c, d);
	}

	for (int i = 1; i <= n; i++) ans[i] = 1e18;

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

	pq.emplace(0, from);
	ans[from] = 0;

	while (!pq.empty()) {

		auto now = pq.top();
		pq.pop();

		if (ans[now.second] < now.first)continue;

		for (auto i : path[now.second]) {
			int wait = i.k - ans[now.second] % i.k;
			if (wait == i.k)
				wait = 0;
			if (ans[i.n] > ans[now.second] + wait + i.t) {
				ans[i.n] = ans[now.second] + wait + i.t;
				pq.emplace(ans[i.n], i.n);
			}
		}

	}

	cout << (ans[to] == 1e18 ? -1 : ans[to]) << "\n";

	return 0;
}

road::road(int& a, int& b, int& c) {
	this->n = a;
	this->t = b;
	this->k = c;
}
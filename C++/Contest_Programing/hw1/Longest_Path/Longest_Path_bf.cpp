#include <bits/stdc++.h>
using namespace std;

struct road {
	int a, b, c;
	road(int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

long long dis[1005];
vector<road> path;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		path.emplace_back(a, b, -c);

	}

	for (int i = 0; i <= n; i++) dis[i] = 1e18;

	dis[1] = 0;
	for (int i = 1; i < n; i++) {
		for (auto t : path) {
			if (t.a != 1e18) {
				if (dis[t.b] > dis[t.a] + t.c)
					dis[t.b] = dis[t.a] + t.c;
			}
		}
	}

	long long tmp = dis[n];

	for (int i = 1; i < n; i++) {
		for (auto t : path) {
			if (t.a != 1e18) {
				if (dis[t.b] > dis[t.a] + t.c)
					dis[t.b] = dis[t.a] + t.c;
			}
		}
	}

	if (tmp != dis[n])
		cout << "inf\n";
	else
		cout << -dis[n] << "\n";

	return 0;
}


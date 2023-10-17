#include <bits/stdc++.h>
using namespace std;

struct dot {
	int n, coupon;
	long long dis;
	dot(long long a, int b, int c) {
		this->dis = a;
		this->n = b;
		this->coupon = c;
	}

};

vector<pair<int, int>> path[100005];

long long ans[100005][2];
// ans[i][0] means to dot 1 minimum dis ans[i][1] means the same but use coupon

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i <= n; i++) {
		ans[i][0] = 1e18;
		ans[i][1] = 1e18;
	}



	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		path[a].emplace_back(b, c);
		// path[b].emplace_back(a, c);
	}


	priority_queue < dot, vector<dot>, decltype([](dot& a, dot& b) { return a.dis > b.dis; }) > pq;


	pq.emplace(0, 1, 0);
	ans[1][0] = 0;
	ans[1][1] = 0;

	while (!pq.empty()) {
		dot now = pq.top();
		pq.pop();


		if (now.dis > ans[now.n][now.coupon]) continue;

		for (auto i : path[now.n]) {
			if (now.coupon) {
				if (ans[i.first][1] > ans[now.n][1] + i.second) {
					ans[i.first][1] = ans[now.n][1] + i.second;
					pq.emplace(ans[i.first][1], i.first, 1);
				}
			}
			else {
				if (ans[i.first][0] > ans[now.n][0] + i.second) {
					ans[i.first][0] = ans[now.n][0] + i.second;
					pq.emplace(ans[i.first][0], i.first, 0);
				}
				if (ans[i.first][1] > ans[now.n][0] + i.second / 2) {
					ans[i.first][1] = ans[now.n][0] + i.second / 2;
					pq.emplace(ans[i.first][1], i.first, 1);
				}
			}

		}
	}

	cout << ans[n][1] << "\n";


	return 0;
}

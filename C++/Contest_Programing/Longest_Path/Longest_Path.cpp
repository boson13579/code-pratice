#include <bits/stdc++.h>
using namespace std;
/*

	Wrong Answer

*/

long long dis[1005];
vector<pair<int, long long>> path[1005];
int deep[1005];
bool inqueue[1005];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		path[a].emplace_back(b, -c);

	}

	for (int i = 0; i <= n; i++) dis[i] = 1e18;

	deque<int> dq;

	dis[1] = 0;
	inqueue[1] = true;
	dq.emplace_back(1);
	deep[1] = 0;

	int now;
	bool circle = false;
	while (!dq.empty()) {

		now = dq.front();
		dq.pop_front();

		inqueue[now] = false;

		if (deep[now] > n - 1) {
			circle = true;
			break;
		}

		for (auto i : path[now]) {
			if (dis[i.first] > dis[now] + i.second) {
				dis[i.first] = dis[now] + i.second;
				if (!inqueue[i.first]) {
					inqueue[i.first] = true;
					dq.emplace_back(i.first);
					// deep[i.first] = deep[now] + 1;
				}
				deep[i.first] = deep[now] + 1;
			}
		}
	}

	if (circle)
		cout << "inf\n";
	else
		cout << -dis[n] << "\n";

	return 0;
}

//spfa 可能出現在非1~n路徑上形成負環
//需先踢除不能連接1~n的路徑
//如果 1不能到u or v不能到n 那們 uv路徑就需要踢除
//可先對1 bfs 跟對n 反bfs

// 我懶得寫，感覺很麻煩XD

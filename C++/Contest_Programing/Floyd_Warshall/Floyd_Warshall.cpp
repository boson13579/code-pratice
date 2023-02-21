#include <bits/stdc++.h>
using namespace std;

long long dis[305][305];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int t = 1; t <= n; t++)
			cin >> dis[i][t];

	int k;
	cin >> k;

	for (int i = 0, a, b, c; i < k; i++) {
		cin >> a >> b >> c;
		if (dis[a][b] <= c) continue;
		for (int fr = 1; fr <= n; fr++) {
			for (int to = 1; to <= n; to++) {
				if (fr == to) continue;
				if (dis[fr][a] + c + dis[b][to] < dis[fr][to]) {
					dis[fr][to] = dis[fr][a] + c + dis[b][to];
					dis[to][fr] = dis[fr][to];
				}
				if (dis[fr][b] + c + dis[a][to] < dis[fr][to]) {
					dis[fr][to] = dis[fr][b] + c + dis[a][to];
					dis[to][fr] = dis[fr][to];
				}
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int t = i + 1; t <= n; t++) {
				ans += dis[i][t];
			}
		}
		cout << ans << " ";
	}

	return 0;
}
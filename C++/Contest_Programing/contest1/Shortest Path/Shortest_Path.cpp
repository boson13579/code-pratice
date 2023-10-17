#include <bits/stdc++.h>
using namespace std;
#define int long long

long long dis[155][155];

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int cases;
	cin >> cases;
	while (cases--) {
		int n, m, q;
		cin >> n >> m >> q;

		for (int i = 0; i <= n; i++)
			for (int t = 0; t <= n; t++)	dis[i][t] = 1e18;

		for (int i = 0; i <= n; i++) dis[i][i] = 0;

		for (int i = 0, a, b, c; i < m; i++) {
			cin >> a >> b >> c;
			dis[a][b] = min(dis[a][b], c);
		}

		

		for (int i = 0; i < n; i++) {
			for (int t = 0; t < n;t++) {
				for (int k = 0; k < n; k++) {
					if(dis[t][k] < -1e9) continue;
					if (dis[t][k] > dis[t][i] + dis[i][k] and dis[t][i] != 1e18 and dis[i][k] != 1e18)
						dis[t][k] = dis[t][i] + dis[i][k];
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int t = 0; t < n; t++) {
				for (int k = 0; k < n; k++) {
					if (dis[i][i] < 0 and dis[t][i] != 1e18 and dis[i][k] != 1e18) {
						dis[t][k] = -1e18;
					}
				}
			}
		}

		for (int i = 0, a, b; i < q; i++) {
			cin >> a >> b;
			if (dis[a][b] == 1e18)
				cout << "Impossible\n";
			else if (dis[a][b] == -1e18)
				cout << "-Infinity\n";
			else
				cout << dis[a][b] << "\n";
		}

	}

	return 0;
}


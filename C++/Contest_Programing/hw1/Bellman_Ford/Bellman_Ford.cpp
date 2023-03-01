#include <bits/stdc++.h>
using namespace std;

long long dis[155][155];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m, q;
	while (cin >> n >> m >> q and n) {

		for (int i = 0; i < n; i++)
			for (int t = 0; t < n; t++)
				dis[i][t] = 1e18;

		for (int i = 0; i < n; i++)
			dis[i][i] = 0;

		for (int i = 0, a, b, c; i < m; i++) {
			cin >> a >> b >> c;
			dis[a][b] = min(dis[a][b], (long long)c);
		}

		for (int i = 0; i < n; i++) {
			for (int t = 0; t < n; t++) {
				for (int k = 0; k < n; k++) {
					if (dis[t][i] != 1e18 and dis[i][k] != 1e18)
						dis[t][k] = min(dis[t][k], dis[t][i] + dis[i][k]);
				}
			}
		}

		for (int i = 0, a, b; i < q; i++) {
			cin >> a >> b;

			bool con = false;
			for (int i = 0; i < n; i++) {
				if (dis[a][i] != 1e18 and dis[i][b] != 1e18 and dis[i][i] < 0) {
					cout << "-Infinity\n";
					con = true;
					break;
				}
			}

			if (con)
				continue;

			if (dis[a][b] == 1e18) {
				cout << "Impossible\n";
				continue;
			}

			cout << dis[a][b] << "\n";

		}

		cout << "\n";
	}

	return 0;
}
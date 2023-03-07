#include <bits/stdc++.h>
using namespace std;

int maze[105][105];
int BFSdis[105][105];
int dis[15][15];
int dp[1 << 16][15];
//dp[i][j] i change to binary 1 bits means already go and stop at j 

vector<pair<int, int>> candy;
pair<int, int> start, endP;

vector<pair<int, int>> dir{{0, -1}, { 1, 0 }, { 0, 1 }, { -1, 0 }};

void bfs(pair<int, int> a);

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, m;
		cin >> n >> m;

		//init outer to zero
		for (int i = 0; i <= m + 1; i++) {
			maze[0][i] = 0;
			maze[n + 1][i] = 0;
		}
		for (int i = 0; i <= n + 1; i++) {
			maze[i][0] = 0;
			maze[i][m + 1] = 0;
		}
		candy.clear();

		//input
		char temp;
		for (int i = 1; i <= n; i++) {
			for (int t = 1; t <= m; t++) {
				cin >> temp;
				maze[i][t] = (temp == '#' ? 0 : 1);
				if (temp == 'T') start = { i,t };
				if (temp == 'W') endP = { i,t };
				if (temp == 'C') candy.emplace_back(i, t);
			}
		}

		//replace in a vector
		vector<pair<int, int>> dot(candy.size() + 2);
		dot[0] = start;
		for (int i = 0; i < candy.size(); i++) dot[i + 1] = candy[i];
		dot[candy.size() + 1] = endP;

		// cal each min dis
		bool cant = false;
		for (int i = 0; i < dot.size() and !cant; i++) {
			memset(BFSdis, 0, sizeof(BFSdis));
			bfs(dot[i]);

			for (int t = 0; t < dot.size(); t++) {
				if (i == t) continue;
				dis[i][t] = BFSdis[dot[t].first][dot[t].second];
				if (!dis[i][t]) {
					cant = true;
					break;
				}
			}
		}

		if (cant) {
			cout << "Mission Failed!\n";
			continue;
		}

		//Hamiltonian path
		for (int i = 0; i < (1 << dot.size()); i++) {
			for (int t = 0; t < dot.size(); t++) {
				dp[i][t] = 1e9;
			}
		}

		dp[1][0] = 0;

		for (int i = 1; i < (1 << dot.size()); i++) {
			for (int t = 0; t < dot.size(); t++) {
				if (!(i & (1 << t))) continue;
				for (int k = 0; k < dot.size(); k++) {
					if (t == k) continue;
					dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][t] + dis[t][k]);
				}
			}
		}

		cout << dp[(1 << dot.size()) - 1][dot.size() - 1] << "\n";

	}

	return 0;
}

void bfs(pair<int, int> a) {

	queue<pair<int, int>> q;
	q.emplace(a);

	while (!q.empty()) {

		auto now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int x = now.first + dir[i].first;
			int y = now.second + dir[i].second;

			if (maze[x][y] and !BFSdis[x][y]) {
				BFSdis[x][y] = BFSdis[now.first][now.second] + 1;
				q.emplace(x, y);
			}

		}
	}
}
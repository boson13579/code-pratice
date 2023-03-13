#include <bits/stdc++.h>
using namespace std;

struct point {
	int x, y, p;

	point(int x, int y, int p) {
		this->x = x;
		this->y = y;
		this->p = p;
	}
};

char maze[55][55];

vector<pair<int, int>> dir{{0, -1}, { 1, 0 }, { 0, 1 }, { -1, 0 }};

dis[1 << 12][55][55];
//dis[i][j][k]
//i change to binary and if 1 on nth bits means n protal have been gone
//stop at (j,k)

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m;
	cin >> n >> m;
	pair<int, int> start, endP;

	for (int i = 0; i <= m + 1; i++) {
		maze[0][i] = '#';
		maze[n + 1][i] = '#';
	}
	for (int i = 0; i <= n + 1; i++) {
		maze[i][0] = '#';
		maze[i][m + 1] = '#';
	}

	for (int i = 1; i <= n; i++) {
		for (int t = 1; t <= m; t++) {
			cin >> maze[i][t];
			if (maze[i][t] == 'S') start = { i,t };
			if (maze[i][t] == 'T') endP = { i,t };
		}
	}

	queue<point> q;
	dis[0][start.first][start.second] = 1;
	q.emplace(start.first, start.second, 0);

	while (!q.empty()) {

		auto now = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = now.x + dir[i].first;
			int ny = now.y + dir[i].second;

			if(maze[nx][ny] == '#') continue;

			if((int)maze[nx][ny] >= 65 and (int)maze[nx][ny] <= 76){
				
				int pr = (int)maze[nx][ny] - 'A';
				

				
			}

		}





	}


	return 0;
}


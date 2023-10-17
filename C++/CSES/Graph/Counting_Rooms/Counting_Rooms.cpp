#include <bits/stdc++.h>
using namespace std;

char maze[1005][1005];
int n, m, v[1005][1005];
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int x, int y) {
    v[x][y] = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i].first;
        int ny = y + dir[i].second;
        if (nx >= 0 and nx < n and ny >= 0 and ny < m and !v[nx][ny] and
            maze[nx][ny] == '.')
            dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int t = 0; t < m; t++) cin >> maze[i][t];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int t = 0; t < m; t++) {
            if (!v[i][t] and maze[i][t] != '#') {
                ans++;
                dfs(i, t);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

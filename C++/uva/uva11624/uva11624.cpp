#include <bits/stdc++.h>

using namespace std;

char maze[1005][1005];

struct node {
    int x, y, v;
    node(int a, int b, int c) {
        x = a;
        y = b;
        v = c;
    }
};

vector<pair<int, int>> dir{{0, 1}, { 0,-1 }, { 1,0 }, { -1,0 }};

int now = 0;
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int task;
    cin >> task;
    int sx, sy, fx, fy;
    while (task--) {
        now++;

        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n + 2; i++)
            for (int t = 0; t < m + 2; t++)
                maze[i][t] = '.';


        vector<vector<int>> fire(n + 2, vector<int>(m + 2, 0));
        queue<node> fq;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> maze[i][j];
                if (maze[i][j] == 'J') {
                    sx = i;
                    sy = j;
                }
                if (maze[i][j] == 'F') {
                    fq.emplace(i, j, 1);
                    fire[i][j] = 1;
                }
            }

        if (now == 232) {
            cerr << n << " " << m << "\n";
            for (int i = 1; i <= n; i++) {
                for (int t = 1; t <= m; t++) {
                    cerr << maze[i][t] << " ";
                }
                cerr << "\n";
            }
        }   

        auto fbfs = [&](queue<node>& q) {
            while (!q.empty()) {
                auto [x, y, v] = q.front();
                q.pop();

                for (auto i : dir) {
                    int nx = x + i.first;
                    int ny = y + i.second;

                    if (nx < 0 or ny < 0 or nx > n  or ny > m ) continue;
                    if (maze[nx][ny] == '#') continue;
                    if (fire[nx][ny] != 0) continue;

                    fire[nx][ny] = v + 1;
                    q.emplace(nx, ny, v + 1);
                }
            }
        };

        fbfs(fq);

        auto ans = [&]() {
            queue<node> q;

            maze[sx][sy] = '#';
            q.emplace(sx, sy, 1);
            while (!q.empty()) {
                auto [x, y, v] = q.front();
                q.pop();

                for (auto i : dir) {
                    int nx = x + i.first;
                    int ny = y + i.second;

                    if (maze[nx][ny] == '#') continue;
                    if (nx == 0 or ny == 0 or nx > n or ny > m) return v + 1;
                    if (v + 1 >= fire[nx][ny]) continue;

                    maze[nx][ny] = '#';
                    q.emplace(nx, ny, v + 1);
                }
            }
            return -1;
        };

        int ansv = ans();
        for(int i=1 ; i<=n ; i++){
            for(int t=1 ; t<=m ; t++)
                cerr<<maze[i][t]<<" ";
            cerr<<"\n";
        }
            
        if (ansv == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << ansv - 1 << "\n";

    }

    return 0;
}
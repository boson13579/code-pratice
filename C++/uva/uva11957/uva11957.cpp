#include <bits/stdc++.h>
using namespace std;
// x = second y = first
char maze[105][105];
int n;

long long int dfs(pair<int, int> now) {
    // cout<<now.first<<" "<<now.second<<"\n";
    if (now.first < 0 or now.first >= n or now.second < 0 or now.second >= n)
        return 0;
    if (maze[now.first][now.second] == 'B') return 0;
    if (now.first == 0 and maze[now.first][now.second] == '.') return 1;
    if (now.first == 0) return 0;
    long long int ans = 0;
    if (now.first - 1 >= 0 and now.second + 1 < n and
        maze[now.first - 1][now.second + 1] == '.') {
        ans += dfs(make_pair(now.first - 1, now.second + 1));
        ans = ans % 1000007;
    }
    if (now.first - 1 >= 0 and now.second + 1 < n and
        maze[now.first - 1][now.second + 1] == 'B') {
        ans += dfs(make_pair(now.first - 2, now.second + 2));
        ans = ans % 1000007;
    }
    if (now.first - 1 >= 0 and now.second - 1 >= 0 and
        maze[now.first - 1][now.second - 1] == '.') {
        ans += dfs(make_pair(now.first - 1, now.second - 1));
        ans = ans % 1000007;
    }
    if (now.first - 1 >= 0 and now.second - 1 >= 0 and
        maze[now.first - 1][now.second - 1] == 'B') {
        ans += dfs(make_pair(now.first - 2, now.second - 2));
        ans = ans % 1000007;
    }
    ans = ans % 1000007;
    return ans;
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a;
    cin >> a;
    int task = 1;
    pair<int, int> w;
    while (a--) {
        cout << "Case " << task++ << ": ";
        cin >> n;
        memset(maze, ' ', sizeof(maze));
        for (int i = 0; i < n; i++) {
            for (int t = 0; t < n; t++) {
                cin >> maze[i][t];
                if (maze[i][t] == 'W') {
                    w = make_pair(i, t);
                }
            }
        }
        cout << dfs(w) << "\n";
    }

    return 0;
}

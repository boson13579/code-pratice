#include <bits/stdc++.h>
using namespace std;

int ans[1005][1005];
char maze[1005][1005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    ans[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int t = 1; t <= n; t++) cin >> maze[i][t];

    for (int i = 1; i <= n; i++) {
        for (int t = 1; t <= n; t++) {
            if (maze[i][t] != '*') {
                if (maze[i][t - 1] != '*') ans[i][t] += ans[i][t - 1];
                if (maze[i - 1][t] != '*') ans[i][t] += ans[i - 1][t];
            } else
                ans[i][t] = 0;

            ans[i][t] %= 1000000007;
        }
    }

    cout << ans[n][n] << "\n";

    return 0;
}

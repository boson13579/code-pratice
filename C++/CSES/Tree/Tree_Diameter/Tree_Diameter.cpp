#include <bits/stdc++.h>
using namespace std;

vector<int> path[200005];
int v[200005];

void dfs(int n, int d) {
    v[n] = d;
    for (int i : path[n]) {
        if (!v[i]) dfs(i, d + 1);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, a, b;
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        path[a].emplace_back(b);
        path[b].emplace_back(a);
    }

    dfs(1, 1);
    int f, di = 0;
    for (int i = 1; i <= n; i++)
        if (v[i] > di) {
            di = v[i];
            f = i;
        }

    memset(v, 0, (n + 1) * 4);
    dfs(f, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, v[i]);
    cout << ans - 1 << "\n";

    return 0;
}
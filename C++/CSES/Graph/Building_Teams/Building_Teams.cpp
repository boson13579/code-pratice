#include <bits/stdc++.h>
using namespace std;

int team[100005];
vector<int> line[100005];

void dfs(int n, int t) {
    team[n] = t;

    for (auto i : line[n]) {
        if (team[i] == t) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
        if (!team[i]) dfs(i, t == 1 ? t + 1 : t - 1);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        line[a].emplace_back(b);
        line[b].emplace_back(a);
    }

    for (int i = 1; i <= n; i++)
        if (!team[i]) dfs(i, 1);

    for (int i = 1; i <= n; i++) cout << team[i] << " ";

    return 0;
}

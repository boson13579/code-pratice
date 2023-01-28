#include <bits/stdc++.h>
using namespace std;

int team[100005];
vector<int> line[1000005];
bool cant = false;

void dfs(int n, int t) {
    team[n] = t;

    for (auto i : line[n]) {
        if (cant) return;
        if (team[i] == t) {
            cant = true;
            return;
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

    if (!cant)
        for (int i = 1; i <= n; i++) cout << team[i] << " ";
    else
        cout << "IMPOSSIBLE\n";
    return 0;
}

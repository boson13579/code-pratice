#include <bits/stdc++.h>
using namespace std;

bool v[100005];

vector<int> ans, road[100005];

void dfs(int i) {
    v[i] = true;
    for (auto t : road[i])
        if (!v[t]) dfs(t);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, fr, to;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> fr >> to;
        road[fr].emplace_back(to);
        road[to].emplace_back(fr);
    }

    for (int i = 1; i <= n; i++) {
        if (!v[i]) {
            ans.emplace_back(i);
            dfs(i);
        }
    }

    cout << ans.size() - 1 << "\n";
    for (int i = 0; i < ans.size() - 1; i++)
        cout << ans[i] << " " << ans[i + 1] << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> path[100005], ans;
int parent[100005];

void dfs(int i, int p) {
    parent[i] = p;

    for (int q : path[i]) {
        if (parent[q] and parent[i] != q) {
            parent[q] = i;
            int now = i;
            do {
                ans.emplace_back(now);
                now = parent[now];
            } while (now != i);
            ans.emplace_back(now);
            cout << ans.size() << "\n";
            for (int t : ans) cout << t << " ";
            exit(0);
        }
        if (!parent[q]) dfs(q, i);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        path[a].emplace_back(b);
        path[b].emplace_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!parent[i]) dfs(i, i);
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}

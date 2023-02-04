#include <bits/stdc++.h>
using namespace std;

vector<int> path[100005], ans;
bool v[100005], in[100005];

void dfs(int i) {
    v[i] = in[i] = true;
    for (int t : path[i])
        if (!v[t])
            dfs(t);
        else if (in[t]) {
            cout << "IMPOSSIBLE\n";
            exit(0);
        }
    in[i] = false;
    ans.emplace_back(i);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        path[a].emplace_back(b);
    }

    m = 0;

    for (int i = 1; i <= n; i++)
        if (!v[i]) dfs(i);

    for (int i = n - 1; i >= 0; i--) cout << ans[i] << " ";

    return 0;
}

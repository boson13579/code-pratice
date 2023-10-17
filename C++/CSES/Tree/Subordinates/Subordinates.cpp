#include <bits/stdc++.h>
using namespace std;

int ans[200005];
vector<int> child[200005];

int dfs(int p) {
    if (child[p].size() == 0) return 0;
    for (int i : child[p]) ans[p] += dfs(i) + 1;
    return ans[p];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, temp;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        cin >> temp;
        child[temp].emplace_back(i);
    }

    int b = dfs(1);
    for (int i = 1; i <= n; i++) cout << ans[i] << " ";

    return 0;
}

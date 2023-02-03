#include <bits/stdc++.h>
using namespace std;

vector<int> path[200005];
int n, child[200005];

void dfs(int r, int p) {
    child[r] = 1;

    for (int i : path[r])
        if (i != p) {
            dfs(i, r);
            child[r] += child[i];
        }
}

int solve(int r, int p) {
    for (int i : path[r])
        if (i != p and child[i] * 2 >= n) return solve(i, r);

    return r;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n;

    for (int i = 1, a, b; i < n; i++) {
        cin >> a >> b;
        path[a].emplace_back(b);
        path[b].emplace_back(a);
    }
    dfs(1, 0);
    cout << solve(1, 1) << "\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

vector<int> in[100005], ans;
int out[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        in[a].emplace_back(b);
        out[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
        if (!out[i]) q.emplace(i);

    while (!q.empty()) {
        int now = q.front();
        ans.emplace_back(now);
        q.pop();

        for (auto i : in[now]) {
            out[i]--;
            if (!out[i]) q.emplace(i);
        }
    }

    if (ans.size() == n)
        for (auto i : ans) cout << i << " ";
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}

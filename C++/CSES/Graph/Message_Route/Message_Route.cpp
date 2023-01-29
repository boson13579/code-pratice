#include <bits/stdc++.h>
using namespace std;

vector<int> path[100005];
int from[100005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, a, b;
    cin >> n >> m;

    while (m--) {
        cin >> a >> b;
        path[a].emplace_back(b);
        path[b].emplace_back(a);
    }

    queue<int> q;
    q.emplace(1);
    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (int i : path[now]) {
            if (!from[i]) {
                from[i] = now;
                q.emplace(i);
            }
        }
    }

    if (from[n] == 0) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    vector<int> ans;

    int now = n;
    while (now != 1) {
        ans.emplace_back(now);
        now = from[now];
    }

    ans.emplace_back(1);
    cout << ans.size() << "\n";
    for (auto i = ans.rbegin(); i != ans.rend(); i++) cout << *i << " ";
    return 0;
}

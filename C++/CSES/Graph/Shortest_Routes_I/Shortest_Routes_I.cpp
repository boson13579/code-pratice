#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> path[100005];
long long ans[1000005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, a, b, c;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        path[a].emplace_back(b, c);
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<pair<long long, int>>>
        pq;
    // dis to

    pq.emplace(0, 1);

    while (!pq.empty()) {
        pair<long long, int> now = pq.top();
        pq.pop();

        if (ans[now.second] < now.first) continue;

        for (auto i : path[now.second]) {
            if ((ans[i.first] == 0 and i.first != 1) or
                ans[i.first] > now.first + i.second) {
                ans[i.first] = now.first + i.second;
                pq.emplace(ans[i.first], i.first);
            }
        }
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << " ";
    return 0;
}

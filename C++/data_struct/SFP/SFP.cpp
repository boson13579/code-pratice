#include <bits/stdc++.h>
using namespace std;

int dis[105][105];
int ans[105];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int n, from, to;
    cin >> n >> from >> to;
    for (int i = 0; i < n; i++)
        for (int t = 0; t < n; t++) cin >> dis[i][t];

    priority_queue<pair<int, int>, vector<pair<int, int>>,greater<pair<int, int>>> pq;

    set<int> in;

    for (int i = 0; i < n; i++) ans[i] = INT_MAX;
    ans[from] = 0;
    pq.emplace(0, from);

    while (in.find(to) == in.end()) {
        pair<int, int> now = pq.top();
        pq.pop();

        if (in.find(now.second) != in.end()) continue;
        in.emplace(now.second);

        for (int i = 0; i < n; i++)
            if (dis[now.second][i] != 0) {
                if (now.first + dis[now.second][i] < ans[i]) {
                    ans[i] = now.first + dis[now.second][i];
                    pq.emplace(ans[i], i);
                }
            }
    }
    cout << ans[to] << "\n";
    return 0;
}

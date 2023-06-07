#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, source, sink, m;
    cin >> n >> source >> sink >> m;

    vector<pair<int, int>> path[n + 1];
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        path[a].emplace_back(b, c);
        path[b].emplace_back(a, 0);
    }

    int p[n + 1];
    auto maxpath = [&]() {

        memset(p, 0, sizeof(p));
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        int maxflow[n + 1];
        memset(maxflow, 0, sizeof(maxflow));
        maxflow[source] = 1e9;

        pq.emplace(1e9, source);

        while (!pq.empty()) {
            auto [flow, now] = pq.top();
            pq.pop();

            if (flow < maxflow[now]) continue;

            for (auto [x, capacity] : path[now]) {
                if (capacity > 0 and maxflow[x] < min(flow, capacity)) {
                    p[x] = now;
                    maxflow[x] = min(flow, capacity);
                    pq.emplace(min(flow, capacity), x);
                }
            }
        }
        return maxflow[sink];
    };

    int ans = 0;
    while (int flow = maxpath()) {
        ans += flow;

        int cur = sink, from;
        while (cur != source) {
            from = p[cur];
            for (int i = 0; i < path[from].size(); i++)
                if (path[from][i].first == cur)
                    path[from][i].second -= flow;
            for (int i = 0; i < path[cur].size(); i++)
                if (path[cur][i].first == from)
                    path[cur][i].second += flow;
            cur = from;
        }
    }

    cout << ans << "\n";
    return 0;
}
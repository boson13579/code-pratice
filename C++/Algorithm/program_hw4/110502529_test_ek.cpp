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
    auto bfs = [&]() {

        memset(p, 0, sizeof(p));
        queue<pair<int, int>> q;

        q.emplace(source, 1e9);
        p[source] = source;
        while (!q.empty()) {
            auto [now, flow] = q.front();
            q.pop();
            for (auto [x, dis] : path[now]) {
                if (p[x] == 0 and dis > 0) {
                    p[x] = now;
                    if (x == n)
                        return min(flow, dis);
                    q.emplace(x, min(flow, dis));
                }
            }
        }
        return 0;
    };

    int ans = 0;
    while (int flow = bfs()) {
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
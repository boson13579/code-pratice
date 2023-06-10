#include <bits/stdc++.h>

using namespace std;

long long path[5010][5010];
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    int n, source, sink, m;
    cin >> n >> source >> sink >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        path[a][b] += c;
    }

    int p[n + 1];
    auto maxpath = [&]() {

        memset(p, 0, sizeof(p));
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, less<pair<long long, int>>> pq;
        long long maxflow[n + 1];
        memset(maxflow, 0, sizeof(maxflow));
        maxflow[source] = 1e18;

        pq.emplace(1e18, source);

        while (!pq.empty()) {
            auto [flow, now] = pq.top();
            pq.pop();

            if (flow < maxflow[now]) continue;

            for (int x = 1; x <= n; x++) {
                if (x != now and path[now][x] > 0 and p[x] == 0) {
                    p[x] = now;
                    maxflow[x] = min(flow, path[now][x]);
                    pq.emplace(min(flow, path[now][x]), x);
                }
            }
        }
        return maxflow[sink];
    };

    long long ans = 0;
    while (long long flow = maxpath()) {
        ans += flow;

        int cur = sink, from;
        while (cur != source) {
            from = p[cur];
            path[from][cur] -= flow;
            path[cur][from] += flow;
            cur = from;
        }
    }

    cout << ans << "\n";
    return 0;
}
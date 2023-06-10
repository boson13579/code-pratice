#include <bits/stdc++.h>

long long path[5010][5010];
using namespace std;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    freopen("test.in", "r", stdin);

    int n, source, sink, m;
    cin >> n >> source >> sink >> m;

    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        path[a][b] += c;
    }

    int p[n + 1];
    auto bfs = [&]() {

        memset(p, 0, sizeof(p));
        queue<pair<int, long long>> q;

        q.emplace(source, 1e18);
        p[source] = source;
        while (!q.empty()) {
            auto [now, flow] = q.front();
            q.pop();
            for (int i = 1; i <= n; i++) {
                if (i != now and path[now][i] > 0 and p[i] == 0) {
                    p[i] = now;
                    if (i == sink)
                        return min(flow, path[now][i]);
                    q.emplace(i, min(flow, path[now][i]));
                }
            }
        }
        return (long long)0;
    };

    long long ans = 0;
    while (long long flow = bfs()) {
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
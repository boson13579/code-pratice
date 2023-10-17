#include <bits/stdc++.h>

long long path[105][105];
using namespace std;
using namespace std::chrono;
int Ti = 100;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    freopen("test.in", "r", stdin);
    freopen("ek_1000-10000E.out", "w", stdout);

    int n, source, sink, m;
    while (cin >> n >> source >> sink >> m) {

        unordered_set<int> nei[n + 1];

        for (int i = 0, a, b, c; i < m; i++) {
            cin >> a >> b >> c;
            nei[a].insert(b);
            nei[b].insert(a);
            path[a][b] += c;
        }

        int p[n + 1];
        auto bfs = [&]() {

            memset(p, 0, sizeof(p));
            queue<pair<int, long long>> q;

            q.emplace(source, LONG_LONG_MAX);
            p[source] = source;
            while (!q.empty()) {
                auto [now, flow] = q.front();
                q.pop();
                for (int i : nei[now]) {
                    if (path[now][i] > 0 and p[i] == 0) {
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

        auto start = high_resolution_clock::now();
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
        // cout << ans << "\n";

        auto end = high_resolution_clock::now();
        auto during = duration_cast<nanoseconds>(end - start);
        cout << " " << during.count() / n << "\n";
        cerr << Ti << "\n";
        Ti += 100;
    }

    return 0;
}
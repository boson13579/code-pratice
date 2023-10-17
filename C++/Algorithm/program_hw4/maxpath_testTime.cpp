#include <bits/stdc++.h>
using namespace std;

long long path[105][105];
using namespace std::chrono;
int Ti = 100;
int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    freopen("test.in", "r", stdin);
    freopen("mathpath_1000-10000E.out", "w", stdout);

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
        auto maxpath = [&]() {

            memset(p, 0, sizeof(p));
            priority_queue<pair<long long, int>, vector<pair<long long, int>>> pq;
            long long maxflow[n + 1];
            memset(maxflow, 0, sizeof(maxflow));

            maxflow[source] = LONG_LONG_MAX;
            pq.emplace(LONG_LONG_MAX, source);

            while (!pq.empty()) {
                auto [flow, now] = pq.top();
                pq.pop();

                if (flow != maxflow[now]) continue;

                for (int x : nei[now]) {
                    if (path[now][x] > 0 and maxflow[x] < min(flow, path[now][x])) {
                        p[x] = now;
                        maxflow[x] = min(flow, path[now][x]);
                        pq.emplace(maxflow[x], x);
                    }
                }
            }
            return maxflow[sink];
        };

        long long ans = 0;
        auto start = high_resolution_clock::now();
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
        // cout << ans << "\n";
        auto end = high_resolution_clock::now();
        auto during = duration_cast<nanoseconds>(end - start);
        cout << " " << during.count() / n << "\n";
        cerr << Ti << "\n";
        Ti += 100; 
    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("6.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> path[n + 1];
    for (int i = 0, a, b, c; i < m; i++) {
        cin >> a >> b >> c;
        path[a].emplace_back(b, c);
        path[b].emplace_back(a, 0);
    }

    vector<int> p(n + 1, 0);
    auto bfs = [&]() {
        fill(p.begin(), p.end(), 0);
        queue<pair<int, int>> q;
        q.emplace(1, 1e9);

        while (!q.empty()) {

            auto printq = [&]() {

                cout << "Queue: \n";
                int si = q.size();
                for (int i = 0; i < si; i++) {
                    cout << q.front().first << ' ' << q.front().second << '\n';
                    q.push(q.front());
                    q.pop();
                }
                cout << "----------\n";
            };

            printq();

            cout << "Parents\n";
            for (int i = 1; i <= n; i++)
                cout << p[i] << ' ';
            cout << "\n----------\n";

            auto [now, flow] = q.front();
            q.pop();

            for (auto [x, dis] : path[now]) {
                if (x != 1 and p[x] == 0 and dis > 0) {
                    p[x] = now;
                    if (x == n)
                        return min(flow, dis);
                    q.emplace(x, min(flow, dis));
                }
            }
        }
        return 0;

    };

    int step = 1;
    int ans = 0, flow;
    while (flow = bfs()) {

        ans += flow;
        int cur = n;

        cout << "step: " << step++ << '\n';
        cout << "\nflow: " << flow << '\n';
        vector<int> v;

        while (cur) {
            int from = p[cur];
            v.emplace_back(cur);
            for (int i = 0; i < path[from].size(); i++)
                if (path[from][i].first == cur)
                    path[from][i].second -= flow;
            for (int i = 0; i < path[cur].size(); i++)
                if (path[cur][i].first == from)
                    path[cur][i].second += flow;
            cur = from;
        }

        cout << "Path:\n";
        reverse(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << (i == v.size() - 1 ? '\n' : ' ');
        cout << "----------\n\n";

    }

    cout << ans << "\n";
    return 0;
}

/*
6 9
1 2 16
1 3 13
2 4 12
4 3 9
4 6 20
3 2 4
3 5 14
5 4 7
5 6 4

*/
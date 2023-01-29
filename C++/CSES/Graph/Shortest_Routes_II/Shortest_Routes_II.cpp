#include <bits/stdc++.h>
using namespace std;

vector<pair<int, long long>> path[505];
long long ans[505][505];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, q, a, b, c;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        path[a].emplace_back(b, c);
        path[b].emplace_back(a, c);
    }

    for (int f = 1; f <= n; f++) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        pq.emplace(0, f);

        while (!pq.empty()) {
            pair<long long, int> now = pq.top();
            pq.pop();

            if (ans[f][now.second] < now.first) continue;

            for (auto i : path[now.second]) {
                if ((ans[f][i.first] == 0 and i.first != f) or
                    ans[f][i.first] > now.first + i.second) {
                    ans[f][i.first] = now.first + i.second;
                    pq.emplace(ans[f][i.first], i.first);
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }

        cout << (ans[a][b] == 0 ? -1 : ans[a][b]) << "\n";
    }

    return 0;
}

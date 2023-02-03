#include <bits/stdc++.h>
using namespace std;

long long ans[505][505];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    long long n, m, q, a, b, c;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++)
        for (int t = 1; t <= n; t++) ans[i][t] = 1e18;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        ans[a][b] = min(ans[a][b], c);
        ans[b][a] = min(ans[b][a], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int f = 1; f <= n; f++) {
            if (f == i) continue;
            for (int t = 1; t <= n; t++) {
                if (t == f or t == i) continue;
                ans[f][t] = min(ans[f][t], ans[f][i] + ans[i][t]);
            }
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        if (a == b) {
            cout << 0 << "\n";
            continue;
        }

        cout << (ans[a][b] == 1e18 ? -1 : ans[a][b]) << "\n";
    }
    return 0;
}

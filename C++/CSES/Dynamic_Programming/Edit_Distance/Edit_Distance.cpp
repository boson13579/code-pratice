#include <bits/stdc++.h>
using namespace std;

int DP[5005][5005];  // DP[i][j] means a[:i] to b[:j] distance

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string a, b;
    cin >> a >> b;

    for (int i = 0; i <= a.size(); i++)
        for (int t = 0; t <= b.size(); t++) DP[i][t] = INT_MAX;

    DP[0][0] = 0;

    for (int i = 0; i <= a.size(); i++) {
        for (int t = 0; t <= b.size(); t++) {
            if (i) DP[i][t] = min(DP[i][t], DP[i - 1][t] + 1);
            if (t) DP[i][t] = min(DP[i][t], DP[i][t - 1] + 1);
            if (i and t)
                DP[i][t] =
                    min(DP[i][t], DP[i - 1][t - 1] + (a[i - 1] != b[t - 1]));
        }
    }

    cout << DP[a.size()][b.size()] << "\n";

    return 0;
}

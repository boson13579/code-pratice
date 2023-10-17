#include <bits/stdc++.h>
using namespace std;

vector<int> arr;
int MOD = 1e9 + 7;

int DP[100005][105];  // DP[i][j] means arr 前i位且地i位為j

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, u, temp;
    cin >> n >> u;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.emplace_back(temp);
    }

    if (arr[0] == 0)
        for (int i = 1; i <= u; i++) DP[1][i] = 1;
    else
        DP[1][arr[0]] = 1;

    for (int i = 2; i <= n; i++) {
        if (arr[i - 1] != 0) {
            DP[i][arr[i - 1]] += DP[i - 1][arr[i - 1] - 1];
            DP[i][arr[i - 1]] %= MOD;
            DP[i][arr[i - 1]] += DP[i - 1][arr[i - 1]];
            DP[i][arr[i - 1]] %= MOD;
            DP[i][arr[i - 1]] += DP[i - 1][arr[i - 1] + 1];
            DP[i][arr[i - 1]] %= MOD;
        }
        else {
            for (int t = 1; t <= u; t++) {
                DP[i][t] += DP[i - 1][t - 1];
                DP[i][t] %= MOD;
                DP[i][t] += DP[i - 1][t];
                DP[i][t] %= MOD;
                DP[i][t] += DP[i - 1][t + 1];
                DP[i][t] %= MOD;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= u; i++) {
        ans += DP[n][i];
        ans %= MOD;
    }

    cout << ans << "\n";
    return 0;
}

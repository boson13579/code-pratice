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

	for(int i=0 ; i<=u ; i++) DP[0][i] = 1;
    for (int i = 1; i <= n; i++) {
        if (arr[i - 1] != 0)
            for (int t = 1; t <= u; t++) DP[i][t] = DP[i - 1][t];

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
    for (int i = 0; i <= u; i++) ans = max(ans, DP[n][i]);

    cout << ans << "\n";
    return 0;
}

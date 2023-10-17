#include <bits/stdc++.h>
using namespace std;

vector<long long> arr, presum;
long long DP[5005][5005];
// DP[i][j] means from arr[i] to arr[j] max selection sum

long long dfs(int l, int r) {
    if (r - l <= 1) return max(arr[l], arr[r]);

    if (DP[l][r] != 0) return DP[l][r];

    DP[l][r] = arr[l] + presum[r] - presum[l] - dfs(l + 1, r);
    DP[l][r] =
        max(DP[l][r], arr[r] + presum[r - 1] - presum[l - 1] - dfs(l, r - 1));

    return DP[l][r];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, tmp;
    cin >> n;
    presum.emplace_back(0);
    arr.emplace_back(0);

    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.emplace_back(tmp);
        presum.emplace_back(*presum.rbegin() + tmp);
    }

    cout << dfs(1, n) << "\n";

    return 0;
}
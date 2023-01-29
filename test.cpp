#include <bits/stdc++.h>
using namespace std;

vector<int> arr, presum;
int DP[5005][5005];  // DP[i][j] means from arr[i] to arr[j] max selection sum

int dfs(int l, int r) {
    if (DP[l][r] != 0) return DP[l][r];
    if (r - l <= 1) return max(arr[l], arr[r]);

    // DP[l][r] = INT_MIN;

    // DP[l][r] = max(DP[l][r], arr[l] + presum[r] - presum[l] - dfs(l + 1, r));

    DP[l][r] = arr[l] + presum[r] - presum[l] - dfs(l + 1, r);
    cout << arr[r] << " " << presum[r - 1] << " " << presum[l - 1] << " "
         << dfs(l, r - 1)<<"\n";
    DP[l][r] =
        max(DP[l][r], arr[r] + presum[r - 1] - presum[l - 1] - dfs(l, r - 1));

    return DP[l][r];
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);

    int n, tmp;
    cin >> n;
    presum.emplace_back(0);
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        arr.emplace_back(tmp);
        presum.emplace_back(*presum.rbegin() + tmp);
    }

    cout << dfs(0, n - 1) << "\n";

    return 0;
}
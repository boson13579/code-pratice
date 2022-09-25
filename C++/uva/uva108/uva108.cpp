#include <bits/stdc++.h>
using namespace std;

int arr[105][105];

int maxsubarray(int *a, int n) {

    int ans = -2147483640, dp[n]; //dp[i] means the max sum of the subarray when a[i] is the last element

    dp[0] = a[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1] + a[i], a[i]);
    }

    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[i]);
    }

    return ans;
}

int maxsubmatrix(int n) {
    int ans = -2147483640;
    int sum[n];

    for (int i = 0; i < n; i++) {
        for (int t = i; t < n; t++) {
            memset(sum, 0, sizeof(sum));
            for (int q = i; q <= t; q++) {
                for (int w = 0; w < n; w++) {
                    sum[w] += arr[w][q];
                }
            }

            ans = max(ans, maxsubarray(sum, n));
        }
    }

    return ans;
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    while (cin >> n and n > 0) {
        for (int i = 0; i < n; i++)
            for (int t = 0; t < n; t++) cin >> arr[i][t];

        cout << maxsubmatrix(n) << "\n";
    }

    return 0;
}

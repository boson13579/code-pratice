#include <bits/stdc++.h>
using namespace std;

int DP[1000005];

int dfs(int n) {
    if (DP[n] != 0 or n == 0) return DP[n];

    int sum = 0;

    for (int i = 1; i <= min(n, 6); i++) {
        DP[n - i] = dfs(n - i);
        sum += DP[n - i];
        sum %= 1000000007;
    }
    DP[n] == sum;
    return sum;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    DP[0] = 1;
    DP[1] = 1;
    DP[2] = 2;

    int a;
    cin >> a;
    cout << dfs(a) << "\n";

    return 0;
}

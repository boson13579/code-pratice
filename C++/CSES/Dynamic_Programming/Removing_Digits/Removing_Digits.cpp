#include <bits/stdc++.h>
using namespace std;

int DP[1000005];

int dfs(int n) {
    
    if (DP[n] != 0 or n == 0) return DP[n];

    DP[n] = n;
    for (auto i : to_string(n))
        if (i != '0') DP[n] = min(DP[n], dfs(n - i + '0') + 1);

    return DP[n];
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 1; i < 10; i++) DP[i] = 1;

    int n;
    cin >> n;
    cout << dfs(n) << "\n";

    return 0;
}

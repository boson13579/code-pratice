#include <bits/stdc++.h>
using namespace std;

bitset<100001> dp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    dp[0] = 1;
    int n;
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        dp |= (dp << x);
    }
    cout << dp.count() - 1 << "\n";
    for (int i = 1; i <= 100000; i++)
        if (dp[i]) cout << i << " ";

    return 0;
}
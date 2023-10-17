#include <bits/stdc++.h>
using namespace std;

long long DP[35];

long long solve(int k, int m) {  // 0~m rows in k**2 matrix red ball

    if (m == 0) return 0;
    if (m == (1 << k))  // 1<<k = pow(2,k)
        return DP[k];
    k--;
    if (m <= (1 << k))
        return 2 * solve(k, m);
    else
        return 2 * DP[k] + solve(k, m - (1 << k));
}

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    DP[0] = 1;
    for (int i = 1; i < 32; i++) {
        DP[i] = DP[i - 1] * 3;
    }

    int times, a, b, c;
    cin >> times;
    int cases = 1;
    while (times--) {
        cin >> a >> b >> c;
        long long ans = solve(a, c) - solve(a, b - 1);
        cout << "Case " << cases << ": " << ans << "\n";
		cases++;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    long long n, a, b, ans;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        ans = 1;
        while (b) {
            if (b & 1) ans = (ans * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        cout << ans << "\n";
    }

    return 0;
}
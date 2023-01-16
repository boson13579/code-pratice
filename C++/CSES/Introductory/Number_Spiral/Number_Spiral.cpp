#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int a, n, m;
    cin >> a;
    for (int i = 0; i < a; i++) {
        cin >> n >> m;
        long long larger = max(n, m);
        long long ans = 0;
        if (larger % 2 == 0) {
            if (n > m) {
                ans -= m - 1;
                ans += larger * larger;
            } else {
                ans += n;
                ans += (larger - 1) * (larger - 1);
            }
        } else {
            if (n < m) {
                ans -= n - 1;
                ans += larger * larger;
            } else {
                ans += m;
                ans += (larger - 1) * (larger - 1);
            }
        }
        cout << ans << "\n";
    }

    return 0;
}

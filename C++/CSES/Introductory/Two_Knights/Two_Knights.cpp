#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int a;
    cin >> a;
    long long ans = 0;
    for (int i = 1; i <= a; i++) {
        ans = i*i;
		ans *= ans - 1;
        ans /= 2;
        if (i >= 3) ans -= 4 * (i - 1) * (i - 2);
        cout << ans << "\n";
    }

    return 0;
}

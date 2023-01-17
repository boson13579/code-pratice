#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    long long n, ans = 0, temp1, temp2;
    cin >> n >> temp1;

    for (int i = 1; i < n; i++) {
        cin >> temp2;
        ans += max(0, int(temp1 - temp2));
        temp1 = max(temp1, temp2);
    }

    cout << ans << "\n";

    return 0;
}

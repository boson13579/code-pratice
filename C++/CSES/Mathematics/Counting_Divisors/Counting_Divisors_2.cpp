#include <bits/stdc++.h>
using namespace std;

long long ans[1000005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int i;
    for (i = 2; i <= 500000; ++i)
        for (int j = i; j <= 1000000; j += i) ++ans[j];

    int n, a, x;
    cin >> n;
    while (n--) {
        cin >> a;
        x = 1;
        if (a >= i) ++x;
        cout << ans[a] + x << "\n";
    }

    return 0;
}

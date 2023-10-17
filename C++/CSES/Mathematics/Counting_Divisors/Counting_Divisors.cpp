#include <bits/stdc++.h>
using namespace std;

long long ans[1000005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    for (int i = 1; i < 1000001; i++)
        for (int t = i; t < 1000001; t += i) ans[t]++;
    int n, x;

    cin >> n;
    while (n--) {
        cin >> x;
        cout << ans[x] << "\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int cases;
    cin >> cases;
    while (cases--) {
        int n, first, second;
        cin >> n >> first >> second;
        int ans = first - second;
        int maxN = max(first, second);
        for (int i = 0; i < n - 2; i++) {
            int temp;
            cin >> temp;
            ans = max(ans, maxN - temp);
            maxN = max(maxN, temp);
        }
        cout << ans << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a;
    while (cin >> a and a != 0) {
        string temp;
        int ans = a;
        while (ans >= 10) {
            int q = 0;
            while (ans!=0) {
                q += ans % 10;
                ans /= 10;
            }
            ans = q;
        }
        cout << ans << " ";
    }

    return 0;
}

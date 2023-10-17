#include <bits/stdc++.h>
using namespace std;

int countbits(int q) {
    int temp = 0;
    while (q) {
        if (q & 1)
            temp++;
        q >>= 1;
    }
    return temp;
}

int reli[25], unreli[25];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a, b;
    while (cin >> a >> b and !(a == 0 and b == 0)) {
        memset(reli, 0, sizeof(reli));
        memset(unreli, 0, sizeof(unreli));

        for (int i = 0; i < b; i++) {
            int x, y;
            cin >> x >> y;
            if (y > 0)
                reli[x] |= (1 << y - 1);
            else
                unreli[x] |= (1 << -y - 1);
        }

        int ans = 0, maxCombi = (1 << a + 1);
        for (int i = 0; i < maxCombi; i++) {
            bool flag = true;
            for (int t = 1; t <= i and flag; t *= 2) {
                if ((i & t) and
                    ((i & unreli[t]) or ((i & reli[t]) != reli[t]))) {
                    flag = false;
                }
            }
            if (flag) ans = max(ans, countbits(i));
        }
        cout << ans << "\n";
    }

    return 0;
}

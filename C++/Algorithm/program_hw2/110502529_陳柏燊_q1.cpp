#include<bits/stdc++.h>
using namespace std;

int ans[1005][1005], block[1005][1005];

int main() {

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int W, H, K;
    cin >> W >> H >> K;

    while (K--) {
        int numBlock;
        cin >> numBlock;

        for (int i = 0; i <= W; i++)
            for (int t = 0; t <= H; t++) block[i][t] = 0;

        for (int i = 0, a, b, c, d; i < numBlock; i++) {
            cin >> a >> b >> c >> d;
            if (a == c) block[c][d] += 2;
            else block[c][d] += 1;
        }

        auto add = [&](int a, int b) {
            if (!a or !b) return 1;
            return ans[a][b];
        };

        for (int i = 1; i <= W; i++) {
            // 0 all // 1 down // 2 left // 3 none
            for (int t = 1; t <= H; t++) {
                ans[i][t] = 0;
                if (!(block[i][t] & 1)) ans[i][t] += add(i - 1, t);
                if (block[i][t] < 2) ans[i][t] += add(i, t - 1);
                ans[i][t] %= 2552;
            }
        }
        cout << ans[W][H] << "\n";
    }

    return 0;
}
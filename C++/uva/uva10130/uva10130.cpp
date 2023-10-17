#include <bits/stdc++.h>
using namespace std;

int DP[1010][35], P[1010], W[1010];

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    // ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int ans = 0;
        int a;
        cin >> a;

        for (int i = 0; i < a; i++) cin >> P[i] >> W[i];

        int b;
        cin >> b;

        for (int i = 0; i < b; i++) {
            int weight;
            cin >> weight;

            memset(DP, 0, sizeof(DP));

            for (int i = 0; i < a; i++) {
                for (int t = weight; t > 0; t--) {
                    DP[i][t] = max(DP[i][t], DP[i][t - W[i]] + P[i]);
                }
            }

            cout << "--------------------------\n";
            for (int i = 0; i < a; i++) {
                for (int t = 0; t < weight; t++) {
                    cout << DP[i][t]<<" ";
                }
                cout << "\n";
            }

            int mp = 0;
            for (int i = 0; i < a; i++) mp = max(mp, DP[i][weight]);
            ans += mp;
        }
        cout << ans << "\n";
    }

    return 0;
}

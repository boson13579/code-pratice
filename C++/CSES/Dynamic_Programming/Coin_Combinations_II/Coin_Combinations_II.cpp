#include <bits/stdc++.h>
using namespace std;

int DP[1000005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    DP[0] = 1;
    int n, sum, temp;
    cin >> n >> sum;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        for (int i = 0; i + temp <= sum; i++) {
            DP[i + temp] += DP[i];
            DP[i + temp] %= 1000000007;
        }
    }

    cout << DP[sum] << "\n";
    return 0;
}

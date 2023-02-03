#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;

long long divideB(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    long long tmp = divideB(a, b / 2);
    if (b % 2) return ((tmp * tmp) % MOD * a) % MOD;
    return (tmp * tmp) % MOD;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << divideB(a, b) << "\n";
    }

    return 0;
}

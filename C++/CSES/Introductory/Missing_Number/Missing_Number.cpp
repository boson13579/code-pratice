#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    long long a, sum = 0, temp;
    cin >> a;
    for (int i = 0; i < a - 1; i++) {
        cin >> temp;
        sum += temp;
    }

    cout << ((a + 1) * a) / 2 - sum << "\n";

    return 0;
}

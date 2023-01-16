#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a;
    cin >> a;
    if (a == 2 or a == 3)
        cout << "NO SOLUTION\n";
    else {
        for (int i = 2; i <= a; i += 2) cout << i << " ";
        for (int i = 1; i <= a; i += 2) cout << i << " ";
        cout << "\n";
    }

    return 0;
}

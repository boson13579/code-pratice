#include <bits/stdc++.h>
using namespace std;

void solve(int n, int a, int b, int c) {
    
    if (!n) return;

    solve(n - 1, a, c, b);
    cout << a << " " << c << "\n";
    solve(n - 1, b, a, c);
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;
    cout << (1 << n) - 1 << "\n";
    solve(n, 1, 2, 3);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int DP[505][505];

int dfs(int a, int b) {
    if (a == b) return 0;

    if (a < b) swap(a, b);
    if (DP[a][b] != 0) return DP[a][b];

    DP[a][b] = a + b;
    for (int i = 1; i < a; i++)
        DP[a][b] = min(DP[a][b], 1 + dfs(a - i, b) + dfs(i, b));

    for (int i = 1; i < b; i++)
        DP[a][b] = min(DP[a][b], 1 + dfs(a, b - i) + dfs(a, i));

    return DP[a][b];
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int a, b;
    cin >> a >> b;
    cout << dfs(a, b);

    return 0;
}

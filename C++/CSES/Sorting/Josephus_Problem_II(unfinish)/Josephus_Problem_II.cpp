#include <bits/stdc++.h>
using namespace std;

// keyword BIT or gnu_pbds indexed_set

vector<int> children;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, skip, now = -1;
    cin >> n >> skip;

    for (int i = 1; i <= n; i++) children.emplace_back(i);

    for (int i = 0; i < n; i++) {
        now = (now + skip + 1) % n;
        while (children[now] == 0) now++;
        cout << children[now];
        children[now] = 0;
    }

    return 0;
}

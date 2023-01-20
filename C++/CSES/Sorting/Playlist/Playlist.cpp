#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> mp;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, start = 0, ans = 0, temp;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        start = max(start, mp[temp]);
        ans = max(ans, i - start + 1);
        mp[temp] = i + 1;
    }

    cout << ans << "\n";
    return 0;
}

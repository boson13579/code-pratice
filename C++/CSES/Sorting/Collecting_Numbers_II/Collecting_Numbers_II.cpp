#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, tmp, ans = 1;
    cin >> n >> m;
    vector<int> pos(n + 2), val(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
        pos[val[i]] = i;
    }

    for (int i = 1; i < n; i++) {
        if (pos[i] > pos[i + 1]) ans += 1;
    }

    auto cal = [&](set<int> &s) -> int {
        int ret = 0;
        for (int x : s) ret += pos[x] > pos[x + 1];
        return ret;
    };

    while (m--) {
        int x, y;
        cin >> x >> y;
        swap(val[x], val[y]);
        set<int> s{val[x] - 1, val[x], val[y] - 1, val[y]};

        ans -= cal(s);
        swap(pos[val[x]], pos[val[y]]);
        ans += cal(s);

        cout << ans << endl;
    }

    return 0;
}
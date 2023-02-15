#include <bits/stdc++.h>
using namespace std;

map<int, long long> DP;  // DP[i] means end in i time max value

struct movie {
    int f, e, v;
    movie(int a, int b, int c) {
        this->f = a;
        this->e = b;
        this->v = c;
    }
};

bool cmp(const movie a, const movie b) {
    if (a.e != b.e) return a.e < b.e;
    return a.f > b.f;
}

vector<movie> arr;

main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0, f, t, v; i < n; i++) {
        cin >> f >> t >> v;
        arr.emplace_back(movie(f, t, v));
    }

    sort(arr.begin(), arr.end(), cmp);

    DP.emplace(0, 0);

    long long ans = 0;
    for (auto i : arr) {
        auto pre = DP.lower_bound(i.f);
        pre--;
        ans = max(ans, DP[i.e]);
        ans = max(ans, (*pre).second + i.v);
        DP[i.e] = ans;
    }

    cout << ans << "\n";
    return 0;
}

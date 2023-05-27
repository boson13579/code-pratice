#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

struct Info {
    int x, s, t;
    Info(int _x, int _s, int _t) : x(_x), s(_s), t(_t) {}
    bool operator<(const Info& rhs) const {
        return s == rhs.s ? (t > rhs.t) : (s < rhs.s);
    }
};

void solve() {
    int n, k;
    cin >> k >> n;

    vector<int> vec(n);
    vector<int> val;
    for (int& x : vec) cin >> x;

    auto disc = [&]() -> int {
        gp_hash_table<int, int> id;
        int t = 0;
        for (int& x : vec) {
            if (auto it = id.find(x); it != id.end())
                x = it->second;
            else x = id[x] = t++;
        }
        val.resize(t);
        for (auto& [v, i] : id) val[i] = v;
        return t;
    };

    int D = disc();

    vector<int> nex(n), pos(D, n);
    for (int i = n - 1; i >= 0; i--) {
        nex[i] = pos[vec[i]];
        pos[vec[i]] = i;
    }

    vector<bool> inque(D);
    vector<__gnu_pbds::priority_queue<Info>::point_iterator> its(D);
    __gnu_pbds::priority_queue<Info> pq;
    for (int i = 0; i < n; i++) {
        int x = vec[i];
        if (inque[x]) {
            pq.modify(its[x], Info(x, nex[i], its[x]->t));
            cout << "hit\n";
        }
        else {
            cout << "miss\n";
            if (pq.size() == k) {
                int y = pq.top().x; pq.pop();
                inque[y] = 0;
                cout << "evict " << val[y] << '\n';
            }
            inque[x] = 1;
            its[x] = pq.push(Info(x, nex[i], i));
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    solve();
    return 0;
}

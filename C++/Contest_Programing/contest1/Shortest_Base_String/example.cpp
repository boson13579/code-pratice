#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

#ifdef LOCAL
void dbg() { cerr << '\n'; }
template<class T, class ...U> void dbg(T a, U ...b) { cerr << a << ' ', dbg(b...); }
template<class T> void org(T l, T r) { while (l != r) cerr << *l++ << ' '; cerr << '\n'; }
#define debug(args...) (dbg("(" + string(#args) + ") = (", args, ")"))
#define orange(args...) (cerr << "[" + string(#args) + ") = ", org(args))
#else
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define debug(...) ((void)0)
#define orange(...) ((void)0)
#endif
template<class T> bool chmin(T& a, T b) { return b < a and (a = b, true); }
template<class T> bool chmax(T& a, T b) { return b > a and (a = b, true); }
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ff first
#define ss second
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<double, double> pdd;

template<class T>
using BST = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int INF = 0x3f3f3f3f;
const long long mod = 998244353;

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> G(n), rG(n);

    while (m--) {
        int u, v;
        cin >> u >> v; u--, v--;
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }

    auto getord = [&](const vector<vector<int>>& g) -> vector<pii> {
        vector<bool> vis(n);
        vector<pii> edg;
        function<void(int)> dfs = [&](int u) {
            if (vis[u]) return; vis[u] = 1;
            for (const int v : g[u])
                dfs(v), edg.emplace_back(u, v);
        };
        for (int i = 0; i < n; i++) dfs(i);
        reverse(all(edg));
        return edg;
    };

    auto cal = [&](vector<pii> ord) -> vector<int> {
        vector<int> ret(n);
        auto run = [&](int l, int r) -> void {
            vector<long long> sta(n);
            for (int i = l; i < r; i++) sta[i] = 1ll << (i - l);
            for (auto& [u, v] : ord) sta[v] |= sta[u];
            for (int i = 0; i < n; i++) ret[i] += __builtin_popcountll(sta[i]);
        };
        for (int i = 0; i < n; i += 64) run(i, min(i + 64, n));
        return ret;
    };

    auto L = cal(getord(G)), R = cal(getord(rG));

    while (q--) {
        int x, k; char d;
        cin >> x >> k >> d; x--;
        if (d == 'L') cout << ((L[x] - 1 <= k and k <= n - R[x]) ? "NO\n" : "YES\n");
        if (d == 'R') cout << ((R[x] - 1 <= k and k <= n - L[x]) ? "NO\n" : "YES\n");
    }
}

signed main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}
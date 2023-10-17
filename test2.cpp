#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
template<class ...T> void dbg(T ...x) { char e{}; ((cerr << e << x, e = ' '), ...); }
template<class T> void org(T l, T r) { while (l != r) cerr << ' ' << *l++; cerr << '\n'; }
#define debug(x...) dbg("(", #x, ") = ", x, '\n')
#define orange(x...) dbg("[", #x, ") = "), org(x)
#else
#define debug(...) ((void)0) 
#define orange(...) ((void)0) 
#endif
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()

using i64 = long long;

template<class T> bool chmin(T& a, T b) { return b < a and (a = b, true); }
template<class T> bool chmax(T& a, T b) { return a < b and (a = b, true); }
constexpr i64 INF = 1LL << 60;

// typedef long long i64


void solve() {
    int n;
    cin >> n;

    int ni = 1;
    for (int i = 1; i <= n; i++) ni *= i;

    int q = 2;
    int tmp = ni;
    for(int i=0 ; i<100 ; i++){
        tmp *= 2;
        if(tmp > 180) break;
    }

    tmp/= 2;
    int qn = 1;

    int p = 1;
    vector<vector<int>> ans(n);
    for (int w = 0; w < qn; w++) {
        vector<int> V;
        for (int i = 0; i < n; i++) V.push_back(i);
        for (int e = 0; e < ni/2; e++) {
            for (int r = 0; r < n; r++) ans[V[r]].push_back(p++);
            p%= n;
            for (int r = n - 1; r >= 0; r--) ans[V[r]].push_back(p++);
            p%= n;
            next_permutation(all(V));
        }

    }

    cout << ni * qn << "\n";
    for (int i = 0; i < n;i++) {
        for (int t : ans[i]) cout << t << " ";
        cout << "\n";
    }

}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    cout << fixed << setprecision(6) << 0.12345678 <<"\n";
    // solve();
    return 0;
}



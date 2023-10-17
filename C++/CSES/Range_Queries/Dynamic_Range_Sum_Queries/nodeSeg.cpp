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

const long long INF = 1ll << 30;

struct Seg {
    Seg* ls = nullptr, * rs = nullptr;
    long long sum, tag, l, r;
    Seg(int _l, int _r, const vector<int>& v): l(_l), r(_r), sum(0), tag(0) {
        if (r - l == 1) sum = v[l];
        else {
            int mid = l + r >> 1;
            ls = new Seg(l, mid, v);
            rs = new Seg(mid, r, v);
        }
    }
    void pull() {
        sum = ls->sum + rs->sum;
    }
    void upd(long long x) {
        tag += x;
        sum += (r - l) * x;
    }
    void push() {
        if (tag) {
            ls->upd(tag);
            rs->upd(tag);
            tag = 0;
        }
    }
    void modify(int ml, int mr, int x) {
        if (ml <= l and r <= mr) return upd(x);
        else if (mr <= l or r <= ml) return;
        int mid = l + r >> 1;
        push();
        ls->modify(ml, mr, x);
        rs->modify(ml, mr, x);
        pull();
    }
    long long query(int ql, int qr) {
        if (ql <= l and r <= qr) return sum;
        else if (qr <= l or r <= ql) return 0;
        push();
        return ls->query(ql, qr) + rs->query(ql, qr);
    }
};
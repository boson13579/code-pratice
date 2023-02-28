#include <bits/stdc++.h>
template <typename Tp>
inline void read(Tp& x) {
    x = 0; bool fg = 0; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') fg ^= 1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (Tp)(ch ^ 48), ch = getchar();
    if (fg) x = -x;
}
template <typename Tp, typename... Args>
void read(Tp& t, Args& ...args) { read(t); read(args...); }
using namespace std;
typedef long long ll;
const int N = 100010;
const int M = 200010;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;
struct edge { int v, w; };
vector<edge> e[N];
ll ds[N];
bool vis[N];
int n, m, cnt[N], mn[N], mx[N];
void dij(int s) {
    memset(vis, 0, sizeof(vis));
    memset(ds, 0x3f, sizeof(ds));
    priority_queue<pair<ll, int>> q;
    ds[s] = 0; q.push({ 0, s });
    cnt[s] = 1; mn[s] = mx[s] = 0;
    while (!q.empty()) {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto i : e[u]) {
            if (ds[u] + i.w < ds[i.v]) {
                ds[i.v] = ds[u] + i.w;
                q.push({ -ds[i.v], i.v });
                cnt[i.v] = cnt[u], mn[i.v] = mn[u] + 1, mx[i.v] = mx[u] + 1;
            }
            else if (ds[u] + i.w == ds[i.v]) {
                cnt[i.v] = (cnt[i.v] + cnt[u]) % mod;
                mn[i.v] = min(mn[i.v], mn[u] + 1);
                mx[i.v] = max(mx[i.v], mx[u] + 1);
            }
        }
    }
}

int main() {
    read(n, m);
    for (int i = 1; i <= m; ++i) {
        int u, v, w; read(u, v, w);
        e[u].push_back({ v, w });
    }
    dij(1);
    printf("%lld %d %d %d\n", ds[n], cnt[n], mn[n], mx[n]);
    return 0;
}
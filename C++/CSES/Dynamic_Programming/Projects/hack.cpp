#include <bits/stdc++.h>
template <typename Tp>
inline void read(Tp& x) {
    x = 0;
    bool fg = 0;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-') fg ^= 1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (Tp)(ch ^ 48), ch = getchar();
    if (fg) x = -x;
}
template <typename Tp, typename... Args>
void read(Tp& t, Args&... args) {
    read(t);
    read(args...);
}
using namespace std;
typedef long long ll;
const int N = 200010;
struct pp {
    int l, r, v;
} p[N];
int n;
ll dp, mx[N];
int main() {
    read(n);
    for (int i = 1; i <= n; ++i) read(p[i].l, p[i].r, p[i].v);
    sort(p + 1, p + n + 1, [](pp a, pp b) { return a.r < b.r; });
    for (int i = 1; i <= n; ++i) {
        int ps = lower_bound(p + 1, p + i + 1, p[i].l,
                             [](pp a, int b) { return a.r < b; }) -
                 p - 1;
        dp = mx[ps] + p[i].v;
        mx[i] = max(mx[i - 1], dp);
    }
    cout << mx[n] << endl;
    return 0;
}
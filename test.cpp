#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
 
vector <int> g[N];
int m, topo[N];
bool visited[N], in_dfs[N];
 
inline int read_int() {
    register char c;
    while (!isdigit(c = getchar_unlocked()));
    int x = c - 48;
    while (isdigit(c = getchar_unlocked()))
        x = (x << 1) + (x << 3) + c - 48;
    return x;
}
 
inline void write_int(int x) {
    if (x > 9)
        write_int(x / 10);
    putchar_unlocked(x%10 + 48);
}
 
void dfs(int u) {
    visited[u] = in_dfs[u] = true;
 
    for (int v: g[u])
        if (!visited[v])
            dfs(v);
        else if (in_dfs[v]) {
            puts("IMPOSSIBLE");
            exit(0);
        }
 
    in_dfs[u] = false;
    topo[m++] = u;
}
 
int main() {
    int n = read_int();
    m = read_int();
 
    while (m--) {
        int u = read_int(), v = read_int();
        g[u].push_back(v);
    }
 
    m = 0;
    for (int u = 1; u <= n; ++u)
        if (!visited[u])
            dfs(u);
 
    for (int i = m - 1; i >= 0; --i) {
        write_int(topo[i]);
        putchar_unlocked(32);
    }
 
}
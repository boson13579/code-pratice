#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v;

int parent(int a) {
    if (v[a] < 0) return a;
    v[a] = parent(v[a]);
    return v[a];
}

int add(int a, int b) {
    int pa = parent(a);
    int pb = parent(b);

    if (pa == pb) return pa;
    n--;
    if (v[pa] > v[pb]) swap(pa, pb);

    v[pa] += v[pb];
    v[pb] = pa;

    return pa;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> n >> m;
    v = vector<int>(n + 1, -1);

    int maxind = 0;
    for (int i = 0, a, b; i < m; i++) {
        cin >> a >> b;
        int temp = add(a, b);
        if (v[temp] < v[maxind]) {
            maxind = temp;
        }
        cout << n << " " << -v[maxind] << "\n";
    }

    return 0;
}

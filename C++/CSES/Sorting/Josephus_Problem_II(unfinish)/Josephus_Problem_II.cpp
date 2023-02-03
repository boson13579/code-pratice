#include <bits/stdc++.h>
using namespace std;

// keyword BIT or gnu_pbds indexed_set

vector<int> children;

struct BIT {
    int n;
    vector<int> v;

    int lowerbit(int x) return x & (-x);

    BIT(int n) {
        this->n = n;
        v = vector<int>(n + 1, 0);
    }

    void add(int x, int p) {
        for (int i = p; i; i -= lowerbit(i)) v[i] += x;
    }

    int que(int p){
        int ret = 0;
        for(int i=p ; i-=lowerbit )
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, skip;
    cin >> n >> skip;

    for (int i = 1; i <= n; i++) children.emplace_back(i);

    return 0;
}

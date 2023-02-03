#include <bits/stdc++.h>
using namespace std;

// keyword BIT or gnu_pbds indexed_set

vector<int> children;

struct BIT {
    int n;
    vector<int> v;

    int lowbit(int x) { return (x & (-x)); }

    BIT(int n) {
        this->n = n;
        v = vector<int>((1 << n) + 1, 0);
    }

    void add(int x, int p) {
        for (int i = p; i <= (1 << n); i += lowbit(i)) v[i] += x;
    }

    int que(int p) {
        int ret = 0;
        for (int i = p; i; i -= lowbit(i)) ret += v[i];
        return ret;
    }

    int bs(int k) {
        int ret = 0, sum = 0;
        for (int i = n; i >= 0; i--)
            if (ret | (1 << i) <= (1 << n) and sum + v[ret | (1 << i)] < k) {
                sum += v[ret | (1 << i)];
                ret |= (1 << i);
            }
        return ret + 1;
    }
};
int main() {
    // ios::sync_with_stdio(0), cin.tie(0);

    int n, skip;
    cin >> n >> skip;
    int pow = 1;
    while ((1 << pow) <= n) pow++;

    BIT b(pow);

    for (int i = 1; i <= n; i++) b.add(1, i);

    int now = (skip % n);

    while (n--) {
        cout << b.bs(now + 1) << " ";
        b.add(-1, b.bs(now + 1));
        if (n) now = (now % n + skip) % n;
    }

    return 0;
}

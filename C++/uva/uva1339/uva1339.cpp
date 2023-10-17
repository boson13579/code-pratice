#include <bits/stdc++.h>
using namespace std;

int ae[128];
int be[128];
multiset<int> as, bs;

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    string a, b;
    while (cin >> a >> b) {
        memset(ae, 0, sizeof(ae));
        memset(be, 0, sizeof(be));
		as.clear();
		bs.clear();
        bool flag = true;
        for (auto i : a) ae[int(i)]++;
        for (auto i : b) be[int(i)]++;
        for (int i = 65; i <= 90; i++) {
            as.emplace(ae[i]);
            bs.emplace(be[i]);
        }
        auto asq = as.begin();
        auto bsq = bs.begin();
        for (int i = 0; i <= 26; i++) {
            //cout << *asq << " " << *bsq << "\n";
            if (*asq != *bsq) flag = false;
            asq++;
            bsq++;
        }
        if (flag)
            cout << "YES\n";
        else {
            cout << "NO\n";
        }
    }

    return 0;
}

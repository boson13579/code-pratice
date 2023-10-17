#include <bits/stdc++.h>
using namespace std;

map<long long int, int> fcombi, ecombi;
vector<int> f, e;

void dfs(long long int a, bool front, bool preadd, int index) {
    if (front) {
        if (!preadd) {
            if (fcombi.find(a) != fcombi.end())
                fcombi[a]++;
            else
                fcombi.insert(make_pair(a, 1));
        }
        if (index == f.size() - 1)
            return;
        else {
            index++;
            int temp = f[index];
            dfs(a + temp, true, false, index);
            dfs(a, true, true, index);
        }

    } else {
        if (!preadd) {
            if (ecombi.find(a) != ecombi.end())
                ecombi[a]++;
            else
                ecombi.insert(make_pair(a, 1));
        }
        if (index == e.size() - 1)
            return;
        else {
            int temp = e[++index];
            dfs(a + temp, false, false, index);
            dfs(a, false, true, index);
        }
    }
}

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a, b;
    while (cin >> a >> b) {
        fcombi.clear();
        ecombi.clear();
        f.clear();
        e.clear();
        for (int i = 0; i < int(a / 2); i++) {
            int temp;
            cin >> temp;
            f.emplace_back(temp);
        }
        for (int t = int(a / 2); t < a; t++) {
            int temp;
            cin >> temp;
            e.emplace_back(temp);
        }

        dfs(0, true, true, -1);
        dfs(0, false, true, -1);

        unsigned long long int ans = 0;

        for (auto i : fcombi) {
            if (ecombi.find(b - i.first) == ecombi.end()) continue;
            ans += (long long int)(i.second) *
                   (long long int)(ecombi[b - i.first]);
        }
        ans = ans + fcombi[b] + ecombi[b];

        cout << ans << "\n";
    }

    return 0;
}

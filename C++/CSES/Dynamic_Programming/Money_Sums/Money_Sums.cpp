#include <bits/stdc++.h>
using namespace std;

vector<int> money;
set<int> sum;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, temp;
    cin >> n;
    while (n--) {
        cin >> temp;
        money.emplace_back(temp);
    }

    sum.emplace(0);

    for (auto i : money)
        for (auto t = sum.rbegin(); t != sum.rend(); t++) sum.emplace(*t + i);

    cout << sum.size() - 1 << "\n";
    for (auto i = next(sum.begin()); i != sum.end(); i++) cout << *i << " ";

    return 0;
}
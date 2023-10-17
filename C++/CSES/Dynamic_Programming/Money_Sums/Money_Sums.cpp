#include <bits/stdc++.h>
using namespace std;

set<int> sum;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, temp;
    cin >> n;
    sum.emplace(0);
    while (n--) {
        cin >> temp;
        for (auto t = sum.rbegin(); t != sum.rend(); t++)
            sum.emplace(*t + temp);
    }

    cout << sum.size() - 1 << "\n";
    for (auto i = next(sum.begin()); i != sum.end(); i++) cout << *i << " ";

    return 0;
}
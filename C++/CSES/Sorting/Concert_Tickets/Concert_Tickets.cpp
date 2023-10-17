#include <bits/stdc++.h>
using namespace std;

multiset<int> price;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int p, n, temp;
    cin >> p >> n;

    for (int i = 0; i < p; i++) {
        cin >> temp;
        price.emplace(temp);
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (*price.begin() == 0 or *price.begin() > temp) {
            cout << "-1 ";
            continue;
        }
        auto it = price.lower_bound(temp);
        if (*it != temp) it--;
        cout << *it << " ";
        price.erase(it);
    }

    return 0;
}

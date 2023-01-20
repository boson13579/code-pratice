#include <bits/stdc++.h>
using namespace std;

multiset<int> dis;
set<int> light;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int x, n, temp;
    cin >> x >> n;

    light.emplace(0);
    light.emplace(x);
    dis.emplace(x);

    while (n--) {
        cin >> temp;
        light.emplace(temp);
        auto preiter = light.find(temp);
        auto nextiter = next(preiter--);
        dis.erase(dis.find(*nextiter - *preiter));
        dis.emplace(temp - *preiter);
        dis.emplace(*nextiter - temp);
        cout << *(prev(dis.end())) << "\n";
    }

    return 0;
}

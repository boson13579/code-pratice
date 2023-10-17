#include <bits/stdc++.h>
using namespace std;

set<int> children;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) children.emplace(i);

    auto iter = children.begin();
    iter++;
    while (1) {
        if (iter == children.end()) {
            iter = children.begin();
        }
        cout << *iter << " ";
        children.erase(iter++);
        if (children.empty()) break;
        if (iter == children.end()) iter = children.begin();
        iter++;
    }

    return 0;
}

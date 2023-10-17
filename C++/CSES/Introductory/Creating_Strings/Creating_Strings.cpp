#include <bits/stdc++.h>
using namespace std;

set<string> ans;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string a;
    cin >> a;
    sort(a.begin(), a.end());

    do ans.emplace(a);
    while (next_permutation(a.begin(), a.end()));

    cout << ans.size() << "\n";
    for (auto i : ans) cout << i << "\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> arr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, temp, ans = 1;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.emplace_back(make_pair(temp, i));
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++)
        if (arr[i].second > arr[i + 1].second) ans++;

    cout << ans << "\n";

    return 0;
}

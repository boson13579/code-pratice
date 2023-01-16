#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> playlist;  // to from

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, fr, to, now = 0, ans = 0;
    cin >> n;
    while (n--) {
        cin >> fr >> to;
        playlist.emplace_back(to, fr);
    }
    sort(playlist.begin(), playlist.end(), cmp);
    for (auto i : playlist) {
        if (i.second >= now) {
            ans++;
            now = i.first;
        }
    }

    cout << ans << "\n";
    return 0;
}

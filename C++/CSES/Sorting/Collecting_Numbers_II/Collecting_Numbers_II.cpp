#include <bits/stdc++.h>
using namespace std;

map<int, int> arr;
int ind[200005];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, temp, ans = 1, a, b, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> temp;
		ind[i] = temp;
        arr.emplace(make_pair(temp, i));
    }

    while (m--) {
        cin >> a >> b;
        int temp = arr[ind[a-1]];
        arr[ind[a-1]] = arr[ind[b-1]];
        arr[ind[b-1]] = temp;
        ans = 1;
        for (auto i = arr.begin(); i != arr.end(); i++) {
            auto t = i;
            t++;
            if (t == arr.end()) break;
            if (i->second > t->second) ans++;
        }
        cout << ans << "\n";
    }

    return 0;
}

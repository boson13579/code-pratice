#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> line[2010];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

set<int> unions;
int n, m, from, to, dis;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> dis;
        line[from].emplace_back(make_pair(dis, to));
        line[to].emplace_back(make_pair(dis, from));
    }

    unions.emplace(0);
    for (auto i : line[0]) pq.emplace(i);

    while (unions.size() < n) {
        int now = pq.top().second;
        if (unions.find(now) != unions.end()) {
            pq.pop();
            continue;
        }

        ans += pq.top().first;
        unions.emplace(now);
        pq.pop();
        for (auto i : line[now]) pq.emplace(i);
    }

    cout << ans;
    return 0;
}

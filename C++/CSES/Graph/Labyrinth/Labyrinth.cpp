#include <bits/stdc++.h>
using namespace std;

int dir[1005][1005];
char maze[1005][1005];
vector<pair<int, int>> dirInt{{0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m;
    cin >> n >> m;

    queue<pair<int, int>> q;
    pair<int, int> start, destination;

    for (int i = 0; i < n; i++) {
        for (int t = 0; t < m; t++) {
            cin >> maze[i][t];
            if (maze[i][t] == 'A') start = {i, t};
            if (maze[i][t] == 'B') destination = {i, t};
        }
    }

    q.emplace(start);
    bool find = false;

    while (!q.empty() and !find) {
        pair<int, int> now = q.front();
        q.pop();

        for (int i = 1; i <= 4 and !find; i++) {
            pair<int, int> next = {now.first + dirInt[i].first,
                                   now.second + dirInt[i].second};

            if (next.first < 0 or next.first >= n or next.second < 0 or
                next.second >= m)
                continue;
            if (maze[next.first][next.second] == '#' or
                dir[next.first][next.second])
                continue;
            if (next.first == destination.first and
                next.second == destination.second)
                find = true;

            dir[next.first][next.second] = i;
            q.emplace(next);
        }
    }

    if (!find) {
        cout << "NO\n";
        return 0;
    }

    vector<char> v;

    while (!(start.first == destination.first and
             start.second == destination.second)) {
        switch (dir[destination.first][destination.second]) {
            case 1:
                v.emplace_back('D');
                destination.first -= 1;
                break;
            case 2:
                v.emplace_back('R');
                destination.second -= 1;
                break;
            case 3:
                v.emplace_back('U');
                destination.first += 1;
                break;
            case 4:
                v.emplace_back('L');
                destination.second += 1;
                break;
        }
    }
    cout << "YES\n";
    cout << v.size() << '\n';
    reverse(v.begin(), v.end());
    for (auto i : v) cout << i;
    return 0;
}
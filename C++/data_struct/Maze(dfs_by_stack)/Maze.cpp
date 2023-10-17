#include <bits/stdc++.h>
using namespace std;

struct dot {
    int x, y, dis;

    dot(int a, int b, int c) {
        this->x = a;
        this->y = b;
        this->dis = c;
    }
};

bool maze[90][90];
int pass[90][90];

stack<dot> path;

pair<int, int> dir[4] = {make_pair(-1, 0), make_pair(0, 1), make_pair(1, 0),
                         make_pair(0, -1)};

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
        for (int t = 0; t < b; t++) cin >> maze[i][t];

    dot temp = dot(0, 0, 1);
    pass[0][0] = 1;
    path.emplace(temp);

    bool findpath = (a == b and a == 1);
    while (!path.empty() and !findpath) {
        dot now = path.top();
        path.pop();

        for (int i = 0; i < 4 and !findpath; i++) {
            dot newDot =
                dot(now.x + dir[i].first, now.y + dir[i].second, now.dis + 1);

            bool y = (newDot.x < 0 or newDot.y < 0 or newDot.x >= a or
                      newDot.y >= b);

            if (!maze[newDot.x][newDot.y] and pass[newDot.x][newDot.y] == 0 and
                !y) {
                path.emplace(newDot);
                pass[newDot.x][newDot.y] = newDot.dis;
            }

            if (newDot.x == a - 1 and newDot.y == b - 1) findpath = true;
        }
    }

    // for (int i = 0; i < a; i++) {
    //     for (int t = 0; t < b; t++) {
    //         cout << pass[i][t];
    //     }
    //     cout << "\n";
    // }

    if (!findpath)
        cout << "Can't reach the exit!\n";
    else {
        vector<dot> finalPath;
        dot now = dot(a - 1, b - 1, pass[a - 1][b - 1]);
        finalPath.emplace_back(now);
        int dis = now.dis;

        for (int t = pass[a - 1][b - 1] - 1; t >= 1; t--) {
            for (int i = 0; i < 4; i++) {
                dot newDot =
                    dot(now.x + dir[i].first, now.y + dir[i].second,
                        pass[now.x + dir[i].first][now.y + dir[i].second]);
                if (pass[newDot.x][newDot.y] == t) {
                    now = newDot;
                    finalPath.emplace_back(now);
                }
            }
        }

        // while(now.dis>1.5){
        //     for (int i = 0; i < 4; i++) {
        //         dot newDot =
        //             dot(now.x + dir[i].first, now.y + dir[i].second,
        //                 pass[now.x + dir[i].first][now.y + dir[i].second]);
        //         if (pass[newDot.x][newDot.y] == now.dis-1) {
        //             now = newDot;
        //             finalPath.emplace_back(now);
        //         }
        //     }
        // }

        reverse(finalPath.begin(), finalPath.end());
        for (int i = 0; i < finalPath.size(); i++) {
            if (i != finalPath.size() - 1)
                cout << "(" << finalPath[i].x << "," << finalPath[i].y << ") ";
            else
                cout << "(" << finalPath[i].x << "," << finalPath[i].y << ")\n";
        }
    }

    return 0;
}

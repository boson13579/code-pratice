#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int lx, ly;
    int x, y;
    char dir;
    int indexdir = 0;
    vector<pair<int, int>> dirct;
    vector<pair<int, int>> lostpos;
    dirct.emplace_back(make_pair(1, 0));
    dirct.emplace_back(make_pair(0, 1));
    dirct.emplace_back(make_pair(-1, 0));
    dirct.emplace_back(make_pair(0, -1));
    map<int, char> indtochar;

    indtochar.insert(make_pair(0, 'E'));
    indtochar.insert(make_pair(1, 'N'));
    indtochar.insert(make_pair(2, 'W'));
    indtochar.insert(make_pair(3, 'S'));

    cin >> lx >> ly;
    while (cin >> x >> y >> dir) {
        if (dir == 'E')
            indexdir = 0;
        else if (dir == 'N')
            indexdir = 1;
        else if (dir == 'W')
            indexdir = 2;
        else if (dir == 'S')
            indexdir = 3;
        string inst;
        cin >> inst;
        bool lost = false;
        for (int i = 0; i < inst.size(); i++) {
            if (inst[i] == 'R') {
                indexdir--;
                if (indexdir == -1) indexdir = 3;
            }
            if (inst[i] == 'L') {
                indexdir++;
                if (indexdir == 4) indexdir = 0;
            }
            if (inst[i] == 'F') {
                x += dirct[indexdir].first;
                y += dirct[indexdir].second;
                if (x > lx or y > ly or x < 0 or y < 0) {
                    x -= dirct[indexdir].first;
                    y -= dirct[indexdir].second;
                    bool already = false;
                    for (auto i : lostpos) {
                        if (i.first == x and i.second == y) already = true;
                    }
                    if (!already) {
                        lostpos.emplace_back(make_pair(x, y));
                        lost = true;
                        break;
                    }
                }
            }
        }
        if (!lost) {
            cout << x << " " << y << " " << indtochar[indexdir] << "\n";
        } else {
            cout << x << " " << y << " " << indtochar[indexdir] << " LOST\n";
        }
    }

    return 0;
}

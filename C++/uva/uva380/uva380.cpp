#include <bits/stdc++.h>
using namespace std;

map<string, map<int, string>> trance;

int main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a, cases = 1;
    cin >> a;
    cout << "CALL FORWARDING OUTPUT\n";
    while (a--) {
        string sorce, start, during, target;
        trance.clear();
        while (cin >> sorce and sorce != "0000") {
            cin >> start >> during >> target;
            if (trance.find(sorce) == trance.end()) {
                map<int, string> temp;
                trance.insert(make_pair(sorce, temp));
            }
            int startInt = stoi(start);
            int durInt = stoi(during);
            for (int i = startInt; i <= startInt + durInt; i++)
                trance[sorce].insert(make_pair(i, target));
        }
        cout << "SYSTEM " << cases++ << "\n";
        string callTime, to;
        while (cin >> callTime and callTime != "9000") {
            cin >> to;
            string orto = to;
            set<string> already;
            int callTimeint = stoi(callTime);

            if (trance.find(to) == trance.end()) {
                cout << "AT " << callTime << " CALL TO " << to << " RINGS "
                     << to << "\n";
                continue;
            }

            bool circle = false;
            bool find = false;
            while (!circle and !find) {
                if (trance[to].find(callTimeint) == trance[to].end()) {
                    find = true;
                } else {
                    already.insert(to);
                    to = trance[to][callTimeint];
                    if (already.find(to) != already.end()) {
                        circle = true;
                    }
                }
            }
            if (circle) {
                cout << "AT " << callTime << " CALL TO " << orto
                     << " RINGS 9999\n";
            } else if (find) {
                cout << "AT " << callTime << " CALL TO " << orto << " RINGS "
                     << to << "\n";
            }
        }
    }

    cout << "END OF OUTPUT\n";

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    //  freopen("test.in", "r", stdin);
    //  freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    int a, cases = 1;
    map<int, vector<pair<int, int>>, greater<int>> row;
    string ss;
    cin >> a;
    while (a--) {
        cout << "Case #" << cases++ << ":\n";
        cin >> ss;
        int rowIndex = 50;
        for (int i = 0; i < ss.size(); i++) {
            if (ss[i] == 'R') {
                if (row.find(rowIndex) == row.end()) {
                    vector<pair<int, int>> temp;
                    temp.emplace_back(make_pair(i, 1));
                    row.insert(make_pair(rowIndex, temp));
                } else {
                    row[rowIndex].emplace_back(make_pair(i, 1));
                }
                rowIndex++;
            } else if (ss[i] == 'C') {
                if (row.find(rowIndex) == row.end()) {
                    vector<pair<int, int>> temp;
                    temp.emplace_back(make_pair(i, 0));
                    row.insert(make_pair(rowIndex, temp));
                } else {
                    row[rowIndex].emplace_back(make_pair(i, 0));
                }
            } else if (ss[i] == 'F') {
                rowIndex--;
                if (row.find(rowIndex) == row.end()) {
                    vector<pair<int, int>> temp;
                    temp.emplace_back(make_pair(i, -1));
                    row.insert(make_pair(rowIndex, temp));
                } else {
                    row[rowIndex].emplace_back(make_pair(i, -1));
                }
            }
        }
        for (auto i = row.begin(); i != row.end(); i++) {
            cout << "| ";
            int nowCol = 0;
            for (auto t : (*i).second) {
                for (int a = nowCol; a < t.first; a++) {
                    cout << " ";
                    nowCol++;
                }
                if (t.second == 1)
                    cout << "/";
                else if (t.second == 0)
                    cout << "_";
                else if (t.second == -1)
                    cout << "\\";
                nowCol++;
            }
            cout << "\n";
        }
        cout << "+";
        for (int i = 0; i <= ss.size() + 1; i++) cout << "-";
        cout << "\n\n";
        row.clear();
    }

    return 0;
}

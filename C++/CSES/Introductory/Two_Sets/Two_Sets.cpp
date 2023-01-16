#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    stack<int> fi, se;
    long long a = 0, b;
    cin >> a;
    if (((a + 1) * a / 2) % 2 == 0) {
        cout << "YES ";
        b = (a + 1) * a / 4;
        for (int i = a; i > 0; i--) {
            if (i <= b) {
                fi.emplace(i);
                b -= i;
            } else {
                se.emplace(i);
            }
        }
        cout << fi.size() << " ";
        while (!fi.empty()) {
            cout << fi.top() << " ";
            fi.pop();
        }
        cout << se.size() << " ";
        while (!se.empty()) {
            cout << se.top() << " ";
            se.pop();
        }
        cout << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}

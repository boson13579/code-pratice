#include <bits/stdc++.h>
using namespace std;

int main() {
    //freopen("test.in", "r", stdin);
    //freopen("test.out","w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    long long int a, b;
    while (cin >> a >> b) {
        queue<long long int> q;
        q.push(a);
        bool flag = false;
        if (a == 1 or b == 0 or b == 1 or a == 0) flag = true;
        while (a > 1 and a % b == 0 and !flag) {
            a = a / b;
            q.push(a);
        }
        if (a != 1 or flag)
            cout << "Boring!\n";

        else {
            while (!q.empty()) {
                if (q.size()!=1)
                    cout << q.front() << " ";
                else
                    cout << q.front() << "\n";
                q.pop();
            }
        }
    }

    return 0;
}

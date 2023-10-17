#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    long long n, x1, y1, x2, y2, x3, y3;
    cin >> n;
    while (n--) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        long long ans = (y3 - y1)*(x2 - x1) - (y2 - y1)*(x3 - x1);

        if (ans == 0)
            cout << "TOUCH\n";
        else if (ans > 0)
            cout << "LEFT\n";
        else
            cout << "RIGHT\n";
    }

    return 0;
}

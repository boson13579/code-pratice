#include <bits/stdc++.h>
using namespace std;
char unsigned tab[1000005]{};
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, x, i;
    short a;

    for (i = 2; i <= 500000; i++) {
        for (int j = i; j <= 1000000; j += i) {
            tab[j]++;
        }
    }

    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> x;
        a = 1;
        if (x >= i) {
            a++;
        }
        cout << tab[x] + a << "\n";
    }

    return 0;
}
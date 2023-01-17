#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a = 0, i;
    cin >> n;
    for (i = 5; i <= n; i *= 5) a += n / i;
    cout << a;
    return 0;
}

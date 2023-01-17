#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    long long a;
    cin >> a;
	cout<<a<<" ";
    while (a != 1) {
        if (a % 2 == 0)
            a /= 2;
        else {
            a *= 3;
            a++;
        }
        cout << a << " ";
    }

    return 0;
}

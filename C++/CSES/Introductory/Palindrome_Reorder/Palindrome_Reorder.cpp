#include <bits/stdc++.h>
using namespace std;

int num[256];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    string a, ans;
    cin >> a;

    for (auto i : a) num[i]++;

    int odd = 0, oddind = 0;
    for (int i = int('A'); i < int('Z'); i++)
        if (num[i] % 2 != 0) {
            oddind = i;
            odd++;
        }

    if (odd > 1)
        cout << "NO SOLUTION\n";
    else {
        for (int i = int('A'); i <= int('Z'); i++)
            if (i != oddind)
                for (int t = 0; t < num[i]/2 ; t++) cout << char(i);

        if (oddind != 0)
            for (int i = 0; i < num[oddind]; i++) cout << char(oddind);

        for (int i = int('Z'); i >= int('A'); i--)
            if (i != oddind)
                for (int t = 0; t < num[i]/2 ; t++) cout << char(i);
    }
    return 0;
}

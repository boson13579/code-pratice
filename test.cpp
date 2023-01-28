#include <bits/stdc++.h>
using namespace std;
int DP[100010];
int main() {
    int n, a, sum = 0;
    string ans, tmp;
    vector<int> v;
    cin >> n;
    DP[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        v.push_back(a);
    }

    sort(v.begin(), v.end());

    for (auto vi : v) {
        for (int i = sum; i - vi >= 0; i--) {
            if (DP[i - vi] == 1) DP[i] = 1;
        }
    }

    a = 0;
    for (int i = 1; i <= sum; i++) {
        if (DP[i]) a++;
    }
    cout << a << endl;
    for (int i = 1; i <= sum; i++) {
        if (DP[i]) cout << i;
        if (DP[i] && i != sum) cout << " ";
    }
}
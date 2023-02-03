#include <bits/stdc++.h>
using namespace std;

vector<int> LIS;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, temp;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (LIS.empty())
            LIS.emplace_back(temp);
        else {
            if (temp > *LIS.rbegin())
                LIS.emplace_back(temp);
            else {
                auto it = lower_bound(LIS.begin(), LIS.end(), temp);
                *it = temp;
            }
        }
    }
    cout << LIS.size() << "\n";

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long DP[1000005];
vector<int> arr;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, sum, temp;
    cin >> n >> sum;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        DP[temp] = 1;
        arr.emplace_back(temp);
    }

    for (int i = 1; i < sum; i++)
        for (auto t : arr)
            if (i + t <= sum) DP[i + t] = (DP[i + t] + DP[i]) % 1000000007;

    cout << DP[sum] << "\n";
    return 0;
}

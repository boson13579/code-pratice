#include <bits/stdc++.h>
using namespace std;

int DP[100005];  // max pages in n money

vector<int> price, pages;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, money, temp;

    cin >> n >> money;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        price.emplace_back(temp);
    }

    for (int i = 0; i < n; i++) {
        cin >> temp;
        pages.emplace_back(temp);
    }

    for (int i = 0; i < n; i++)
        for (int t = money; t >= 0; t--)
            if (t >= price[i]) DP[t] = max(DP[t], DP[t - price[i]] + pages[i]);

    cout << DP[money] << "\n";

    return 0;
}

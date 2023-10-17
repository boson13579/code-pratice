#include <bits/stdc++.h>
using namespace std;

void print(int n, int val) {
    while (n--) cout << int((val >> n) & 1);
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n;
    cin >> n;

    vector<int> arr = {0, 1};

    for (int i = 1; i < n; i++)
        for (int t = arr.size()-1 ; t >= 0; t--)
            arr.emplace_back(arr[t] | (1 << i));

    for (auto i : arr) print(n, i);

    return 0;
}

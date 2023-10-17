#include <bits/stdc++.h>
using namespace std;

int ans[10];

vector<int> tozero(int a) {
    vector<int> temp;
    for (int i = 0; i < 10; i++) {
        temp.emplace_back(0);
    }
    int N = to_string(a).size();
    for (int i = a / pow(10, N - 1); i != 0; i--) {
        if (i == int(a / pow(10, N - 1)))
            temp[i] += a % int(pow(10, N - 1)) + 1;
        else
            temp[i] += pow(10, N - 1);
    }
    for (int i = N - 1; i != 0; i--) {
        for (int t = 0; t < 10; t++) {
            if (t == 0)  // 001 0'0'1 不算
                temp[t] += ((a / int(pow(10, i))) - 1) * pow(10, i - 1);
            else  // 012 0'1'2 算
                temp[t] += ((a / int(pow(10, i)))) * pow(10, i - 1);
        }
        temp[(a / int(pow(10, i - 1))) % 10] += (a % int(pow(10, i - 1))) + 1;
        for (int q = ((a / int(pow(10, i - 1))) % 10) - 1; q >= 0; q--) {
            temp[q] += pow(10, i - 1);
        }
    }
    return temp;
}

int main() {
    int a, b;
    while (cin >> a >> b and !(a == 0 and b == 0)) {
        if (a > b) swap(a, b);
        vector<int> all = tozero(b);
        vector<int> back = tozero(a - 1);
        for (int i = 0; i < 10; i++) {
            ans[i] = all[i] - back[i];
        }
        for (int i = 0; i < 10; i++) {
            if (i == 9)
                cout << ans[i] << "\n";
            else
                cout << ans[i] << " ";
        }
    }

    return 0;
}

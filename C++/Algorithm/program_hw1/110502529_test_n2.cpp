#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

vector<int> stov(string s) {

    vector<int> ret;

    for (int i = s.size() - 1; i >= 0; i--)
        ret.emplace_back(int(s[i]) - '0');

    return ret;

}

vector<int> mul(vector<int>& a, vector<int>& b) {

    vector<int> ret(a.size() + b.size(), 0);

    for (int i = 0; i < a.size(); i++)
        for (int t = 0; t < b.size(); t++) {
            ret[i + t] += a[i] * b[t];
        }

    for (int i = 0; i < a.size() + b.size(); i++)
        if (ret[i] >= 10) {
            ret[i + 1] += ret[i] / 10;
            ret[i] %= 10;
        }

    if (ret.back() == 0)
        ret.pop_back();

    return ret;
}

void print(vector<int> a) {
    for (auto i = a.rbegin(); i != a.rend(); i++)
        cout << *i;
    cout << "\n";
}

int main() {

    freopen("test3.in", "r", stdin);
    freopen("n2test3.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);

    string n1, n2;
    int n = 1;
    int trash = 2;
    while (cin >> n1 >> n2) {

        vector<int> a = stov(n1);
        vector<int> b = stov(n2);
        vector<int> temp;

        auto start = high_resolution_clock::now();
        for (int i = 0; i < n; i++) {
            // cin >> n1 >> n2;
            temp = mul(a, b);
        }
        auto end = high_resolution_clock::now();
        auto during = duration_cast<nanoseconds>(end - start);

        // print(temp);
        cout << trash << " " << during.count() / n << "\n";
        trash += 100;
    }

    return 0;

}
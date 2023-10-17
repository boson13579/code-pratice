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

vector<int> add(vector<int>& a, vector<int>& b) {

    vector<int> ret(max(a.size(), b.size() + 1));

    int mid = (max(a.size(), b.size()), min(a.size(), b.size()));

    vector<int> x = (a.begin(), a.begin() + mid),
        w = (a.begin() + mid, a.end()),
        z = (b.begin(), b.begin() + mid),
        y = (b.begin() + mid, b.end());

    vector<int> r = 

}


void print(vector<int> a) {
    for (auto i = a.rbegin(); i != a.rend(); i++)
        cout << *i;
    cout << "\n";
}

int main() {

    string n1, n2;
    cin >> n1 >> n2;

    vector<int> a = stov(n1);
    vector<int> b = stov(n2);

    int n = 200;
    vector<int> temp;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
        temp = mul(a, b);

    auto end = high_resolution_clock::now();
    auto during = duration_cast<nanoseconds>(end - start);

    print(temp);
    cout << during.count() / n << "\n";

    return 0;

}
#include <bits/stdc++.h>
#include <time.h>

using namespace std;

struct BigNum : vector<int> {
    BigNum(int n) : vector<int>(n) {}

    BigNum(string s) {
        copy(s.rbegin(), s.rend(), back_inserter(*this));
        for (auto it = begin(); it != end(); *it++ -= '0');
    }

    BigNum(vector<int>::const_iterator start, vector<int>::const_iterator end) : vector<int>(start, end) {
        if (empty()) emplace_back();
    }

    void show() {
        for (auto it = rbegin(); it != rend(); cout << *it++);
        cout << '\n';
    }

    friend BigNum operator+(const BigNum &lhs, const BigNum &rhs) {
        BigNum ans((int) max(lhs.size(), rhs.size()) + 1);
        int carry = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (carry) ans[i] = 1, carry = 0;
            if (i < lhs.size()) ans[i] += lhs[i];
            if (i < rhs.size()) ans[i] += rhs[i];
            if (ans[i] > 9) ans[i] -= 10, ++carry;
        }
        while (ans.size() > 1 && !ans.back()) ans.pop_back();
        return ans;
    }

    friend BigNum operator-(const BigNum &lhs, const BigNum &rhs) {
        BigNum ans((int) (lhs.size()) + 1);

        for (int i = 0; i < ans.size() - 1; i++) {
            ans[i] += lhs[i];
            if (i < rhs.size()) ans[i] -= rhs[i];
            while (ans[i] < 0) {
                ans[i + 1] -= 1;
                ans[i] += 10;
            }
        }

        while (ans.size() > 1 and ans.back() == 0) ans.pop_back();

        return ans;
    };

    friend BigNum operator*(const BigNum &lhs, const BigNum &rhs) {
        BigNum ans((int) (lhs.size() + rhs.size()));
        for (int i = 0; i < lhs.size(); i++) {
            for (int j = 0; j < rhs.size(); j++) {
                ans[i + j] += lhs[i] * rhs[j];
            }
            for (int j = 1; j < ans.size(); j++) {
                ans[j] += (ans[j - 1] / 10);
                ans[j - 1] %= 10;
            }
        }
        while (ans.size() > 1 && ans.back() == 0) ans.pop_back();
        return ans;
    }

    BigNum &shift(int p) {
        resize(size() + p);
        rotate(begin(), end() - p, end());

        return *this;
    }

    friend BigNum operator^(const BigNum &lhs, const BigNum &rhs) {
        int mid = (int) min(max(lhs.size(), rhs.size()) / 2, min(lhs.size(), rhs.size()));

        BigNum l_lhs(lhs.begin(), lhs.begin() + mid),
                r_lhs(lhs.begin() + mid, lhs.end()),
                l_rhs(rhs.begin(), rhs.begin() + mid),
                r_rhs(rhs.begin() + mid, rhs.end());


        BigNum l_tmp = (l_lhs + r_lhs),
                r_tmp = (l_rhs + r_rhs),
                total = (min(l_tmp.size(), r_tmp.size()) > 2) ? (l_tmp ^ r_tmp) : (l_tmp * r_tmp),
                lv = (l_lhs.size() > 2) ? (l_lhs ^ l_rhs) : (l_lhs * l_rhs),
                rv = (r_lhs.size() > 2) ? (r_lhs ^ r_rhs) : (r_lhs * r_rhs),
                cv = (total - lv - rv);

        return (lv + cv.shift(mid) + rv.shift(mid * 2));
    }

    friend ostream &operator<<(ostream &os, const BigNum &num) {
        for (auto it = num.rbegin(); it != num.rend(); os << *it++);
        return os;
    }

};

int main(int argc, char *argv[]) {
    string A, B;
    cin >> A , B;
    BigNum a(A), b(B);
    clock_t start, end;
    start = clock();
    for (int i = 0; i < 200; i++) {
        (a ^ b);
    }
    end = clock();

    cout << (a ^ b) << endl;
    cout << (double) (end - start) * 1e9 / CLOCKS_PER_SEC << endl; 
}

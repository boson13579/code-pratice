#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

struct Big : vector<int> {
	Big() : Big(1) {}	

	Big(int n) : vector<int>(max(1, n)) {}

	Big(vector<int>::const_iterator start, vector<int>::const_iterator end) : vector<int>(start, end) {
		if (empty()) emplace_back();
	}

	Big(string s) {
		copy(s.rbegin(), s.rend(), back_inserter(*this));
		for (auto it = begin(); it != end(); *it++ -= '0');
		while (size() > 1 and back() == 0) pop_back();
	}
	
	friend istream& operator>>(istream &is, Big &num) {
		string s;
		cin >> s;
		num = Big(s);
		return is;
	}

	friend ostream& operator<<(ostream &os, const Big &num) {
		for (auto it = num.rbegin(); it != num.rend(); os << *it++);
		return os;
	}

	Big& shift(int p) {
		fill_n(back_inserter(*this), p, 0);
		rotate(begin(), end() - p, end());
		return *this;
	}

	bool iszero() const { return (*this) == vector<int>{0}; }

	friend Big operator+(const Big &lhs, const Big &rhs) {
		const int n = lhs.size(), m = rhs.size();

		Big res(max(n, m) + 1);
		for (int i = 0; i < res.size() - 1; i++) {
			if (i < n) res[i] += lhs[i];
			if (i < m) res[i] += rhs[i];
			if (res[i] > 9) res[i] -= 10, res[i + 1] += 1;
		}

		while (res.size() > 1 and res.back() == 0) res.pop_back();

		return res;
	}
	friend Big operator-(const Big &lhs, const Big &rhs) { // lhs >= rhs;
		const int n = lhs.size(), m = rhs.size();

		Big res(max(n, m) + 1);
		for (int i = 0; i < res.size() - 1; i++) {
			if (i < n) res[i] += lhs[i];
			if (i < m) res[i] -= rhs[i];
			while (res[i] < 0) res[i] += 10, res[i + 1] -= 1;
		}

		while (res.size() > 1 and res.back() == 0) res.pop_back();

		return res;
	}
	friend Big operator*(const Big &lhs, const Big &rhs) {
		if (lhs.iszero() or rhs.iszero()) return Big();

		const int n = lhs.size(), m = rhs.size();

		Big res(n + m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				res[i + j] += lhs[i] * rhs[j];

		for (int i = 0; i < n + m - 1; i++)
			res[i + 1] += res[i] / 10, res[i] %= 10;

		while (res.size() > 1 and res.back() == 0) res.pop_back();

		return res;
	}
};

void solve() {
	Big a, b, c;
	cin >> a >> b;


	const int T = 200;
	auto st = high_resolution_clock::now();
	for (int t = 0; t < T; t++) {
		c = a * b;
	}
	auto ed = high_resolution_clock::now();
	auto dt = duration_cast<nanoseconds>(ed - st);

	cout << c << '\n';
	cout << dt.count() / T << '\n';
	
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	solve();
	return 0;
}

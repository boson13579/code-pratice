#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

const long long mod = 998244353, G = 3, iG = (mod + 1) / G;

long long ksm(long long a, long long b) {
	long long ret = 1;
	for (; b; b >>= 1, a = a * a % mod)
		if (b & 1) ret = ret * a % mod;
	return ret;
};

void NTT(vector<long long> &v, bool inv) {
	int n = v.size();
	for (int i = 0, j = 0; i < n; i++) {
		if (i < j) swap(v[i], v[j]);
		for (int k = n / 2; (j ^= k) < k; k /= 2);
	}

	for (int mid = 1; mid < n; mid *= 2) {
		long long w = ksm((inv ? iG : G), (mod - 1) / (mid + mid));
		for (int i = 0; i < n; i += mid * 2) {
			long long now = 1;
			for (int j = i; j < i + mid; j++, now = now * w % mod) {
				long long x = v[j], y = v[j + mid];
				v[j] = (x + y * now) % mod;
				v[j + mid] = (x - y * now) % mod;
			}
		}
	}

	if (inv) {
		long long in = ksm(n, mod - 2);
		for (int i = 0; i < n; i++) v[i] = v[i] * in % mod;
	}
}

struct Big:vector<int> {
	Big() : Big(1) {}

	Big(int n) : vector<int>(max(1, n)) {}

	Big(vector<int>::const_iterator start, vector<int>::const_iterator end) : vector<int>(start, end) {
		if (empty()) emplace_back();
	}

	Big(vector<long long>::const_iterator start, vector<long long>::const_iterator end) : vector<int>(start, end) {
		if (empty()) emplace_back();
	}

	Big(string s) {
		copy(s.rbegin(), s.rend(), back_inserter(*this));
		for (auto it = begin(); it != end(); *it++ -= '0');
		while (size() > 1 and back() == 0) pop_back();
	}

	Big& shift(int p) {
		fill_n(back_inserter(*this), p, 0);
		rotate(begin(), end() - p, end());
		return *this;
	}

	bool iszero() const { return (*this) == vector<int>{0}; }

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

	friend Big operator*(Big lhs, Big rhs) {
		vector<long long> L(lhs.begin(), lhs.end()), R(rhs.begin(), rhs.end());

		int sum = lhs.size() + rhs.size() - 1, len = 1;
		while (len < sum) len <<= 1;

		L.resize(len), NTT(L, 0);
		R.resize(len), NTT(R, 0);

		for (int i = 0; i < len; i++) L[i] = L[i] * R[i] % mod;
		NTT(L, 1);

		L.resize(sum);

		for (int i = 0; i < sum; i++) if (L[i] < 0) L[i] += mod;
		for (int i = 0; i < sum - 1; i++) L[i + 1] += L[i] / 10, L[i] %= 10;

		return Big(L.begin(), L.end());
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

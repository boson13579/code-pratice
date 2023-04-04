#include<bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int threadhold = 1419;

vector<int> stov(string s) {
	vector<int> ret;

	for (int i = s.size() - 1; i >= 0; i--)
		ret.emplace_back(int(s[i]) - '0');

	return ret;

}

vector<int> add(vector<int>& a, vector<int>& b) {
	vector<int> ret(max(a.size(), b.size()) + 1);
	for (int i = 0; i < a.size(); i++) ret[i] += a[i];
	for (int i = 0; i < b.size(); i++) ret[i] += b[i];
	for (int i = 0; i < ret.size() - 1; i++) ret[i + 1] += ret[i] / 10, ret[i] %= 10;
	while (!ret.empty() and !ret.back()) ret.pop_back();
	return ret;
}

vector<int> tminus(vector<int>& a, vector<int>& b) {
	/*
		need to be a minus b
	*/

	vector<int> ret(max(a.size(), b.size()));
	for (int i = 0; i < a.size(); i++)ret[i] += a[i];
	for (int i = 0; i < b.size(); i++)ret[i] -= b[i];
	for (int i = 0; i < ret.size() - 1; i++)
		if (ret[i] < 0) ret[i] += 10, ret[i + 1] -= 1;
	while (!ret.empty() and !ret.back()) ret.pop_back();
	return ret;
}

vector<int> mul(vector<int>& a, vector<int>& b) {

	const int n = a.size();
	const int m = b.size();

	vector<int> ret(n + m, 0);
	for (int i = 0; i < n; i++)
		for (int t = 0; t < m; t++) {
			ret[i + t] += a[i] * b[t];
		}

	for (int i = 0; i < n + m; i++)
		if (ret[i] >= 10) {
			ret[i + 1] += ret[i] / 10;
			ret[i] %= 10;
		}

	if (ret.back() == 0)
		ret.pop_back();

	return ret;
}

vector<int>& shift(vector<int>& a, int p) {
	fill_n(back_inserter(a), p, 0);
	rotate(a.begin(), a.end() - p, a.end());
	return a;
}

vector<int> kmul(vector<int>& a, vector<int>& b) {

	// cerr << "我還活著\n";
	const int n = a.size();
	const int m = b.size();
	// cerr << a.size() << " " << b.size() << "\n";
	if (n < threadhold and m < threadhold) return mul(a, b);

	const int mid = min(max(a.size(), b.size()) / 2, min(a.size(), b.size()));

	vector<int> x = vector<int>(a.begin(), a.begin() + mid),
		w = vector<int>(a.begin() + mid, a.end()),
		z = vector<int>(b.begin(), b.begin() + mid),
		y = vector<int>(b.begin() + mid, b.end());

	vector<int> wandx = add(w, x),
		yandz = add(y, z),
		r = kmul(wandx, yandz),
		wy = kmul(w, y),
		xz = kmul(x, z),
		temp = tminus(r, wy);
	temp = tminus(temp, xz);

	vector<int> ret = xz;
	if (temp.size() > 0) ret = add(ret, shift(temp, mid));
	ret = add(ret, shift(wy, mid * 2));

	return ret;
}

void print(vector<int>& a) {
	for (auto i = a.rbegin(); i != a.rend(); i++)
		cout << *i;
	cout << "\n";
}

int main() {

	freopen("test3.in", "r", stdin);
	freopen("karatest3_1419.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	string n1, n2;
	int n = 1;
	int s = 5000;
	while (cin >> n1 >> n2) {

		vector<int> a = stov(n1);
		vector<int> b = stov(n2);
		vector<int> temp;
		auto start = high_resolution_clock::now();
		for (int i = 0; i < n; i++) {
			temp = kmul(a, b);
		}
		auto end = high_resolution_clock::now();
		auto during = duration_cast<nanoseconds>(end - start);

		// print(temp);
		cout << s << " " << during.count() / n << "\n";
		s += 100;
	}
	return 0;

}
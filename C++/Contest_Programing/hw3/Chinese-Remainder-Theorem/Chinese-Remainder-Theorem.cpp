#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> prime(int a) {

	vector<pair<int, int>> ret;
	for (int i = 2; i <= a; i++) {
		if (a % i == 0) {
			ret.emplace_back(i, 0);
			while (a % i == 0) {
				ret.back().second++;
				a /= i;
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) cin >> v[i];

	auto primes = prime(k);

	for (auto i : primes) {
		bool can = false;
		for (auto t : v) {
			int n = 0;
			while (t % i.first == 0) {
				t /= i.first;
				n++;
			}
			if (n >= i.second) can = true;
		}
		if (!can) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";

	return 0;
}


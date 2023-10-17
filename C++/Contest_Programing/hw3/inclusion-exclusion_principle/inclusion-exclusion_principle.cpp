#include <bits/stdc++.h>
using namespace std;

#define int long long

long long lcm(long long a, long long b) {
	return a * b / __gcd(a, b);
}

signed main() {

	ios::sync_with_stdio(0), cin.tie(0);

	int n, m;
	while (cin >> n >> m) {

		vector<int> v(m), lc(1<<m);

		long long ans = 0;

		for (int i = 0; i < m; i++) cin >> v[i];

		for (int i = 1; i < (1 << m); i++) {

			int lcs = 1;
			int lb = (i & -i);
			if (lb == i) lc[lb] = v[__lg(i)];
			else lc[i] = lcm(lc[i - lb], lc[lb]);
			// for (int t = 0; t < m; t++)
			// 	if (i & 1 << t and lcs < n)
			// 		lcs = (lcs * v[t]) / gcd(lcs, v[t]);

			if (__builtin_popcountll(i) % 2) ans += n / lc[i];
			else ans -= n / lc[i];
		}

		cout << n - ans << "\n";
	}

	return 0;
}


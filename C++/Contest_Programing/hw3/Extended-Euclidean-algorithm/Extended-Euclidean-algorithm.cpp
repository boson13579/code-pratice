#include <bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;

vector<long long> fact(4005 + 1);
vector<long long> refact(4005 + 1);

long long qpow(long long a, long long b) {
	long long ret = 1;
	while (b) {
		if (b & 1) ret = ret * a % MOD;
		a = a * a % MOD;
		b = b >> 1;

	}
	return ret;

}

void init() {

	fact[0] = 1;
	for (long long i = 1; i < 4005; i++)
		fact[i] = (fact[i - 1] * i) % MOD;

	refact[4004] = qpow(4004, MOD - 2);
	for (long long i = 4003; i >= 1; i--)
		refact[i] = refact[i + 1] * i % MOD;

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	init();

	int T;
	cin >> T;

	while (T--) {
		int n, m;
		cin >> n >> m;

		vector<vector<int>> v(n + 1);
		vector<bool> head(n + 1, true);
		for (int i = 0, a, b; i < m; i++) {
			cin >> a >> b;
			v[b].emplace_back(a);
			head[a] = false;
		}

		vector<int> size(n + 1, 1);

		function<int(int)> dfssize = [&](int n) ->  int {
			for (auto i : v[n])
				size[n] += dfssize(i);
			return size[n];
		};

		for (int i = 1; i <= n; i++)
			if (head[i]) dfssize(i);

		vector<int> per(n + 2, 1);

		function<int(int)> dfs = [&](int x) -> int {

			per[x] = fact[size[x]];
			for (auto i : v[x])
				per[x] = per[x] * refact[size[i]] % MOD * dfs(i) % MOD;
			return per[x];
		};

		long long ans = fact[n];
		for (int i = 1; i <= n; i++)
			if (head[i])
				ans = ans * refact[size[i]] % MOD * dfs(i) % MOD;
		cout << ans << "\n";
	}

	return 0;
}
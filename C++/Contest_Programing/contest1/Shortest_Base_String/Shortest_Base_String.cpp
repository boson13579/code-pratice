#include <bits/stdc++.h>
using namespace std;

vector<queue<int>> E;
vector<int> ans;
unordered_set<int> s;
int n, m;
void dfs(int x) {

	if ((x % m == x / (pow(m, n - 1)) or x/m == 0) and s.find(x) == s.end()) {
		int head = x / pow(m, n - 1);
		head *= pow(m, n - 1);
		ans.emplace_back(x - head);
		s.emplace(x);
	}

	while (!E[x].empty()) {
		int next = E[x].front();
		int head = next / pow(m, n - 1);
		head *= pow(m, n - 1);
		ans.emplace_back(next - head);
		E[x].pop();

		dfs(next);
	}
}

void print(int x) {
	for (int i = n - 2; i >= 0; i--) {
		cout << (int)(x / pow(m, i)) % m;
	}
	return;
}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> n >> m;

	E.resize(pow(m, n - 1) + 1);

	if (n == 1) {
		for (int i = 0; i < m; i++)
			cout << i;
		cout << "\n";
		return 0;
	}

	if (m == 1) {
		cout << "0\n";
		return 0;
	}

	for (int i = 0; i < pow(m, n); i++) {

		int head = i / pow(m, n - 1);
		head *= pow(m, n - 1);
		int erhead = i - head;
		if ((i / m) != erhead)
			E[i / m].emplace(erhead);
	}

	dfs(0);

	for (int i = 0; i < ans.size(); i++)
		print(ans[i]);

	cout << "\n";

	return 0;
}
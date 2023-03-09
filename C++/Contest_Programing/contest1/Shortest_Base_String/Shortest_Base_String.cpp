#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<vector<int>> E;
int n, m;
void dfs(int x) {

	while (!E[x].empty()) {
		int next = *E[x].rbegin();
		E[x].pop_back();
		dfs(next);
		ans.emplace_back(next % m);
	}
}

int main() {
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
		E[i / m].emplace_back(erhead);
	}

	dfs(0);
	for (auto i = ans.rbegin(); i != ans.rend(); i++)	cout << *i;

	cout << "\n";

	return 0;
}
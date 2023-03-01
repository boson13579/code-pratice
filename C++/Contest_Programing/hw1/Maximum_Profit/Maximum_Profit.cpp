#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;
double ans[305][305];
int cases = 1;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n;
	while (cin >> n and n) {

		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < n; i++) ans[i][i] = 1;
		mp.clear();

		string name;
		for (int i = 0; i < n; i++) {
			cin >> name;
			mp.emplace(name, i);
		}

		int m;
		cin >> m;
		string from, to;
		double tran;
		while (m--) {
			cin >> from >> tran >> to;
			ans[mp[from]][mp[to]] = tran;
		}

		for (int i = 0; i < n; i++) {
			for (int t = 0; t < n; t++) {
				for (int k = 0; k < n; k++) {
					if (ans[t][k] < ans[t][i] * ans[i][k])
						ans[t][k] = ans[t][i] * ans[i][k];
				}
			}
		}

		bool can = false;
		for (int i = 0; i < n; i++)
			if (ans[i][i] > 1)
				can = true;


		if (can)
			cout << "Case " << cases++ << ": Yes\n";
		else
			cout << "Case " << cases++ << ": No\n";
	}

	return 0;
}


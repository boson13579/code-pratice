#include <bits/stdc++.h>
using namespace std;

int n = 8;
vector<int> arr = { 5, 10, 3, 12, 5, 50, 6 ,1};

int DP[10][10];
//from i to j min cost

struct dot {
	int l, i, r, n;
};

bool cmp(dot& a, dot& b) {

	if (a.r - a.l != b.r - b.l)
		return a.r - a.l < b.r - b.l;
	else if (a.l != b.l)
		return a.l < b.l;
	else if (a.r != b.r)
		return a.r < b.r;
	else if (a.i != b.i)
		return a.i < b.i;
}
vector<dot> ans;

int c = 0;

int dfs(int l, int r) {

	if (r - l < 2)
		return 0;

	if (DP[l][r] != 0)
		return DP[l][r];

	if (r - l == 2) {
		DP[l][r] = arr[l] * arr[l + 1] * arr[l + 2];
		c++;
		return DP[l][r];
	}

	DP[l][r] = 1e9;
	for (int i = l + 1; i <= r - 1; i++) {
		dfs(l, i);
		dfs(i, r);
		// cout << l << " " << i << " " << r << " " << DP[l][i] + DP[i][r] + arr[l] * arr[i] * arr[r] << "\n";
		ans.emplace_back(l, i, r, DP[l][i] + DP[i][r] + arr[l] * arr[i] * arr[r]);
		DP[l][r] = min(DP[l][r], DP[l][i] + DP[i][r] + arr[l] * arr[i] * arr[r]);
		c++;
	}

	return DP[l][r];

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	cout << dfs(0, n - 1) << "\n";

	for (int i = 0; i < n; i++) {
		for (int t = i + 2; t < n; t++) {
			cout << i << " " << t << " " << DP[i][t] << " ";
		}
		cout << "\n";
	}

	sort(ans.begin(), ans.end(), cmp);


	cout << ans.size() << "\n";

	return 0;
}

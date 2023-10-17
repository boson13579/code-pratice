#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int table[1005][1005], T, W, H, K, Q;

bool cmp(array<int, 4> a, array<int, 4> b) {
	if (a[0] != b[0])
		return a[0] < b[0];
	else
		return a[1] < b[1];
}

void sam() {
	for (int i = 0; i < 1005; i++) {
		table[0][i] = 1;
		table[i][0] = 1;
	}

	for (int i = 1; i < 1005; i++) {
		for (int j = 1; j < 1005; j++) {
			table[i][j] += table[i - 1][j] + table[i][j - 1];
			table[i][j] %= 2552;
		}
	}
}

int main() {
	sam();

	T = 1;

	freopen("in10000.txt", "r", stdin);
	freopen("dptime.txt", "w", stdout);



	while (T--) {

		while (cin >> W >> H >> K) {
			auto st = high_resolution_clock::now();
			while (K--) {
				cin >> Q;

				vector<int> dp(Q + 1);
				vector<array<int, 4>> block(Q);

				for (int i = 0; i < Q; i++)
					cin >> block[i][0] >> block[i][1] >> block[i][2] >> block[i][3];
				block.push_back({ W, H, W, H });
				sort(block.begin(), block.end(), cmp);

				for (int i = 0; i < Q + 1; i++) {
					dp[i] = table[block[i][0]][block[i][1]];

					for (int j = 0; j < i; j++) {
						if (block[j][2] > block[i][0] || block[j][3] > block[i][1])
							continue;
						dp[i] -= dp[j] * table[block[i][0] - block[j][2]][block[i][1] - block[j][3]];
						dp[i] = ((dp[i] % 2552) + 2552) % 2552;
					}
				}
			}
			auto ed = high_resolution_clock::now();
			auto dt = duration_cast<nanoseconds>(ed - st);
			cout << dt.count() << '\n';
		}

	}

	return 0;
}
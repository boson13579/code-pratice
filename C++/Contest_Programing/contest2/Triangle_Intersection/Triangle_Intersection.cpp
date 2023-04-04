#include <bits/stdc++.h>
using namespace std;

struct BIT {
	int n;
	vector<int> v;

	int lowbit(int x) { return (x & (-x)); }

	BIT(int n) {
		this->n = n;
		v = vector<int>(n + 1, 0);
	}

	void add(int x, int p) {
		for (int i = p; i <= n; i += lowbit(i)) v[i] += x;
	}

	int que(int p) {
		int ret = 0;
		for (int i = p; i; i -= lowbit(i)) ret += v[i];
		return ret;
	}

	int bs(int k) {
		int ret = 0, sum = 0;
		for (int i = n; i >= 0; i--)
			if (ret | (1 << i) <= (1 << n) and sum + v[ret | (1 << i)] < k) {
				sum += v[ret | (1 << i)];
				ret |= (1 << i);
			}
		return ret + 1;
	}
};


int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;

	vector<array<int, 3>> arr(n);
	vector<int> bef;
	vector<int> xbef;
	for (int i = 0; i < n; i++) {
		cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
		if (arr[i][1] > arr[i][2]) swap(arr[i][1], arr[i][2]);
		bef.emplace_back(arr[i][0]);
		xbef.emplace_back(arr[i][1]);
		xbef.emplace_back(arr[i][2]);
	}

	sort(bef.begin(), bef.end());

	bef.erase(unique(bef.begin(), bef.end()), bef.end());

	auto mp = [&](int x) -> int {
		return lower_bound(bef.begin(), bef.end(), x) - bef.begin() + 1;
	};


	sort(xbef.begin(), xbef.end());
	xbef.erase(unique(xbef.begin(), xbef.end()), xbef.end());

	auto xmp = [&](int x) -> int {
		return lower_bound(xbef.begin(), xbef.end(), x) - xbef.begin() + 1;
	};

	vector<vector<pair<int, int>>> high(bef.size() + 5);

	for (auto& [x, y, z] : arr) {
		x = mp(x);
		y = xmp(y);
		z = xmp(z);
		high[x].emplace_back(y, z);
	}

	// for(auto i:high)
	// 	for(auto t:i)
	// 		cerr<<t.first<<" "<<t.second<<"\n";

	long long ans = 1ll * n * (n - 1) / 2;

	BIT bit(xbef.size() + 5);
	for (auto& i : high) {
		long long tmp = 0;
		for (auto& [x, y] : i) {
			// cerr << x << " " << y << "\n";
			tmp += bit.que(x - 1);
		}
		// cerr << tmp << "\n";
		ans -= tmp;
		for (auto& [x, y] : i) {
			bit.add(1, y);
		}
	}

	cout << ans << '\n';

	return 0;
}
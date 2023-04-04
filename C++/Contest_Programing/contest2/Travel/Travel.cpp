#include <bits/stdc++.h>
#define ll long long
#define cl(x) (2*x + 1)
#define cr(x) (2*(x + 1))
#define int long long

using namespace std;

struct seg {

	vector<pair<int,int>> v;

	seg(int _n): v(vector<pair<int,int>>(_n << 2)) {}

	void pull(int i, int l, int r) {
		if (l == r) return;
		// int mid = (l + r) / 2;
		// push(cl(i), l, mid);
		// push(cr(i), mid + 1, r);
		v[i] = max(v[cl(i)], v[cr(i)]);
	}

	void build(vector<ll>& arr, int i, int l, int r) {
		if (l == r)
			v[i] ={arr[l],-l};
		else {
			int mid = (l + r) / 2;
			build(arr, cl(i), l, mid);
			build(arr, cr(i), mid + 1, r);
			pull(i, l, r);
		}
	}

	void update(int i, int l, int r, int p, int x) {
		if (l == r) {
			v[i].first = x;
			return;
		}

		int mid = (l + r) / 2;
		if (p <= mid)
			update(cl(i), l, mid, p, x);
		if (p > mid)
			update(cr(i), mid + 1, r, p, x);
		pull(i, l, r);
	}

	pair<int, int> query(int i, int l, int r, int nl, int nr) {
		if (l >= nl and r <= nr) return v[i];

		int mid = (l + r) / 2;

		pair<int, int> ret = make_pair(-999999, 1);
		if (nl <= mid)
			ret = max(ret, query(cl(i), l, mid, nl, nr));

		if (nr > mid)
			ret = max(ret, query(cr(i), mid + 1, r, nl, nr));

		return ret;
	}
};


signed main() {
	// ios::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n >> q;
	seg segtree(n);

	vector<int> arr(n + 1);
	for (int i = 0; i < n; i++) cin >> arr[i];

	segtree.build(arr, 0, 0, n - 1);

	for (int i = 0, a, b, c; i < q; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			segtree.update(0, 0, n - 1, b - 1, c);
		}
		else {
			cin >> b >> c;
			cout << (-segtree.query(0, 0, n - 1, b - 1, c - 1).second) + 1 << "\n";
		}
	}

	return 0;
}


#include <bits/stdc++.h>
#define ll long long
#define cl(x) (2*x + 1)
#define cr(x) (2*(x + 1))
#define int long long

using namespace std;

struct seg {

	vector<ll> v;
	vector<ll> lazy;

	seg(int _n): v(vector<ll>(_n << 2, 0)), lazy(vector<ll>(_n << 2, 0)) {}

	void pull(int i, int l, int r) {
		if (l == r) return;
		int mid = (l + r) / 2;
		push(cl(i), l, mid);
		push(cr(i), mid + 1, r);
		v[i] = v[cl(i)] + v[cr(i)];
	}

	void push(int i, int l, int r) {
		if (lazy[i]) {
			v[i] += lazy[i] * (r - l + 1);
			if (l != r) {
				lazy[cl(i)] += lazy[i];
				lazy[cr(i)] += lazy[i];
			}
			lazy[i] = 0;
		}
	}

	void build(vector<ll>& arr, int i, int l, int r) {
		if (l == r)
			v[i] = arr[l];
		else {
			int mid = (l + r) / 2;
			build(arr, cl(i), l, mid);
			build(arr, cr(i), mid + 1, r);
			pull(i, l, r);
		}
	}

	void update(int i, int l, int r, int nl, int nr, int x) {
		push(i, l, r);

		if (l >= nl and r <= nr) {
			lazy[i] += x;
			return;
		}

		int mid = (l + r) / 2;
		if (nl <= mid)
			update(cl(i), l, mid, nl, nr, x);
		if (nr > mid)
			update(cr(i), mid + 1, r, nl, nr, x);
		pull(i, l, r);
	}

	ll query(int i, int l, int r, int nl, int nr) {
		push(i, l, r);
		if (l >= nl and r <= nr) return v[i];

		int mid = (l + r) / 2;

		ll ret = 0;
		if (nl <= mid)
			ret += query(cl(i), l, mid, nl, nr);

		if (nr > mid)
			ret += query(cr(i), mid + 1, r, nl, nr);

		return ret;
	}
};

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n >> q;
	vector<ll> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];

	seg segtree(n);
	segtree.build(arr, 0, 0, n - 1);

	for (int i = 0, a, b, c; i < q; i++) {
		cin >> a;
		if (a == 1) {
			cin >> a >> b >> c;
			segtree.update(0, 0, n - 1, a - 1, b - 1, c);
		}
		else {
			cin >> a;
			cout << segtree.query(0, 0, n - 1, a - 1, a - 1) << "\n";
		}
	}
	return 0;
}
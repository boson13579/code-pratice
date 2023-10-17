#include <bits/stdc++.h>
#define ll long long
#define cl(x) (2*x + 1)
#define cr(x) (2*(x + 1))
// #define int long long

using namespace std;

struct seg {

	struct node {
		bool allone = false;
		int left = 0, right = 0;
		int ans = 0;
	};

	vector<node> v;


	seg(int _n) : v(vector<node>(_n << 2)) {}

	void pull(int i, int l, int r) {
		if (l == r) return;
		// int mid = (l + r) / 2;
		// push(cl(i), l, mid);
		// push(cr(i), mid + 1, r);
		// v[i] = max(v[cl(i)], v[cr(i)]);
		v[i].allone = v[cl(i)].allone and v[cr(i)].allone;
		if (v[i].allone) {
			v[i].left = v[cl(i)].right + v[cr(i)].left;
			v[i].right = v[cl(i)].right + v[cr(i)].left;
			v[i].ans = v[i].left;
		}
		else {
			v[i].left = v[cl(i)].left;
			if (v[cl(i)].allone) v[i].left += v[cr(i)].left;
			v[i].right = v[cr(i)].right;
			if (v[cr(i)].allone) v[i].right += v[cl(i)].right;
		}
		v[i].ans = max(v[i].ans, v[cl(i)].ans);
		v[i].ans = max(v[i].ans, v[cr(i)].ans);
		v[i].ans = max(v[i].ans, v[cl(i)].right + v[cr(i)].left);
		v[i].ans = max(v[i].ans, v[i].right);
		v[i].ans = max(v[i].ans, v[i].left);

	}

	void build(vector<int>& arr, int i, int l, int r) {
		if (l == r) {
			if (arr[i] == 0) {
				v[i].left = 1;
				v[i].right = 1;
				v[i].allone = true;
				v[i].ans = 1;
			}
			else {
				v[i].allone = false;
				v[i].left = 0;
				v[i].right = 0;
				v[i].ans = 0;
			}
		}
		else {
			int mid = (l + r) / 2;
			build(arr, cl(i), l, mid);
			build(arr, cr(i), mid + 1, r);
			pull(i, l, r);
		}
	}

	void update(int i, int l, int r, int p, int x) {
		if (l == r) {
			v[i].allone = !bool(x);
			v[i].right = x == 0 ? 1 : 0;
			v[i].left = x == 0 ? 1 : 0;
			v[i].ans = x == 0 ? 1 : 0;
			return;
		}

		int mid = (l + r) / 2;
		if (p <= mid)
			update(cl(i), l, mid, p, x);
		if (p > mid)
			update(cr(i), mid + 1, r, p, x);
		pull(i, l, r);
		for (auto i : v)
			cout << i.ans << " ";
		cout << "\n";
	}

	// pair<int, int> query(int i, int l, int r, int nl, int nr) {
	// 	if (l >= nl and r <= nr) return v[i];

	// 	int mid = (l + r) / 2;

	// 	pair<int, int> ret = make_pair(-999999, 1);
	// 	if (nl <= mid)
	// 		ret = max(ret, query(cl(i), l, mid, nl, nr));

	// 	if (nr > mid)
	// 		ret = max(ret, query(cr(i), mid + 1, r, nl, nr));

	// 	return ret;
	// }

};


signed main() {
	// ios::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n >> q;
	seg segtree(n);

	vector<int> arr(n + 1);
	string temp;
	cin >> temp;
	for (int i = 0; i < n; i++) arr[i] = int(temp[i]) - '0';

	segtree.build(arr, 0, 0, n - 1);
	cout << segtree.v[0].ans + 1 << "\n";

	for (int i = 0, a, b, c; i < q; i++) {
		cin >> a;
		arr[a] = arr[a] == 1 ? 0 : 1;
		segtree.update(0, 0, n - 1, a, arr[a]);
		cout << segtree.v[0].ans + 1 << "\n";
	}

	return 0;
}
//	segtree.update(0, 0, n - 1, b - 1, c);

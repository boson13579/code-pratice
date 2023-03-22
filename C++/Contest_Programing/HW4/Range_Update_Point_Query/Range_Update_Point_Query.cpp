#include <bits/stdc++.h>
#define int long long
using namespace std;

struct dot {
	int p, type, n, ind;
	dot(int a, int b, int c, int d): p(a), type(b), n(c), ind(d) {};
};

bool cmp(dot& a, dot& b) {

	if (a.p != b.p)
		return a.p < b.p;
	if (a.type != b.type)
		return a.type < b.type;

	return false;

}

signed main() {
	ios::sync_with_stdio(0), cin.tie(0);

	int n, q;
	cin >> n >> q;

	vector<dot> v;

	for (int i = 0, a, b, c; i < n; i++) {
		cin >> a >> b >> c;
		v.emplace_back(a, 0, c, -1);
		v.emplace_back(b + 1, 0, -c, -1);
	}

	for (int i = 0, a; i < q; i++) {
		cin >> a;
		v.emplace_back(a, 1, -1, i);
	}

	sort(v.begin(), v.end(), cmp);


	vector<int> ans(q + 1);

	long long now = 0;

	for (dot i : v) {
		if (i.type == 0)
			now += i.n;
		else
			ans[i.ind] = now;
	}

	sort(ans.begin(), ans.end(), [](auto a, auto b) {return a.first < b.first;});

	for (auto i : ans)
		if (i.second)
			cout << "It rained " << i.second << " units of rain.\n";
		else
			cout << "Oh! It is midterm exam day.\n";

	return 0;
}
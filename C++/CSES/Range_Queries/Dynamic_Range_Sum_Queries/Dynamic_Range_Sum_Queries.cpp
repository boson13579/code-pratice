#include <bits/stdc++.h>
#define ll long long
#define cl(x) = (2*x + 1)
#define cr(x) = (2*x)

using namespace std;

struct seg {

	vector<ll> v;

	seg(int _n): v(vector<ll>(_n << 4, 0)){}

	pull(int i) { v[i] = v[cl(i)] + v[cr(i)]; }

	build(vector<ll>& arr, int i, int l, int r) {
		if (l == r)
			v[i] = arr[l];
		else {
			int mid = (l + r) / 2;
			build(arr, cl(i), l, mid);
			build(arr, cr(x), mid, r);
			pull(i);
		}
	}

	update(int i, int x){
		
	}


};

int main() {
	ios::sync_with_stdio(0), cin.tie(0);




	return 0;
}


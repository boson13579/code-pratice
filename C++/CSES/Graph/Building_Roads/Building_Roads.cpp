#include <bits/stdc++.h>
using namespace std;

int parent[100005];

vector<pair<int, int>> ans;

int findParent(int n){
	if(parent[n] = n)
		return n;
	return findParent(parent[n]);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    int n, m, fr, to;
    cin >> n >> m;

    for (int i = 0; i <= n; i++) parent[i] = i;

    for (int i = 0; i < m; i++) {
        cin >> fr >> to;

    }

    return 0;
}

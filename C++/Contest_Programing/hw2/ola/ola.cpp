#include<bits/stdc++.h>
using namespace std;

vector<int> path[1000005];
int in[1000005], out[1000005];
unordered_set<int> us;
set<int> s;

void dfs(int a) {
	us.emplace(a);
	for (int i : path[a]) {
		if (us.find(i) == us.end()) {
			dfs(i);
		}
	}
}

void clears() {
	for (int i : s) {
		path[i].clear();
		in[i] = 0;
		out[i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, t;
	cin >> t;
	while (t--) {
		cin >> n;

		//init
		us.clear();
		s.clear();
		queue<int> q;

		//input
		for (int i = 0, a; i < n; i++) {
			cin >> a;
			q.push(a);
			s.insert(a);
			out[a]++;
		}
		for (int i = 0, a, b; i < n; i++) {
			cin >> b;
			a = q.front();
			q.pop();
			s.insert(b);
			in[b]++;
			path[a].push_back(b);
		}

		bool cant = false;
		int sta = 1e9, end = 1e9;

		for (auto x : s) {
			if (abs(in[x] - out[x]) > 1) {
				cant = true;
				break;
			}
			if (in[x] - out[x] == 1) {
				if (end != 1e9) {
					cant = true;
					break;
				}
				end = x;
			}
			if (out[x] - in[x] == 1) {
				if (sta != 1e9) {
					cant = true;
					break;
				}
				sta = x;
			}
		}

		if (cant) {
			cout << "-1\n";
			clears();
			continue;
		}
		if (sta == 1e9)
			dfs(*(s.begin()));
		else
			dfs(sta);

		if (us.size() == s.size()) {
			if (sta == 1e9)
				cout << *(s.begin()) << " " << *(s.begin()) << "\n";
			else
				cout << sta << " " << end << "\n";
			clears();
			continue;
		}
		clears();
		cout << "-1\n";

	}

	return 0;
}
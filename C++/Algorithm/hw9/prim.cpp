#include <bits/stdc++.h>
using namespace std;

struct element {
	int d, to, from;

	auto operator <(const element& other) const {
		if (d != other.d)
			return d > other.d;
		return to < other.to;
	}
};

int main() {
	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> v[n + 1];

	for (int i = 0, a, b, c; i < m; i++) {
		cin >> a >> b >> c;
		v[a].emplace_back(b, c);
		v[b].emplace_back(a, c);
	}

	priority_queue < element, vector<element>> pq;
	for (auto i : v[1]) pq.emplace(i.second, i.first, 1);

	set<int> in;
	in.emplace(1);

	while (!pq.empty() and in.size() != n) {

		auto print = [&]() {
			queue<element> q;
			while (!pq.empty()) {
				auto [d, to, from] = pq.top();
				pq.pop();
				q.emplace(d, to, from);
				cout << d << " " << to << " " << from << "\n";
			}
			cout << "\n";
			while (!q.empty()) {
				pq.emplace(q.front());
				q.pop();
			}
		};

		print();
		auto [d, to, from] = pq.top();
		pq.pop();

		if (in.find(to) != in.end()) continue;

		in.emplace(to);
		cout << "add point: " << to << "\n";
		for (auto i : v[to]) {
			if (in.find(i.first) == in.end())
				pq.emplace(i.second, i.first, to);
		}

	}

	return 0;
}

/*
6 10
1 2 6
1 3 1
1 4 5
2 3 5
2 5 3
3 5 6
3 4 5
3 6 4
4a 6 2
5 6 6*/

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono;
#define MAX 10000005

vector<int> cache;
vector<int> nextPos;

struct node {
	int i, x, next;
	node(int i, int x, int next) : i(i), x(x), next(next) {}
};

auto cmp = [](node& a, node& b) {
	if (a.next != b.next) return a.next < b.next;
	return a.i > b.i;
};

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out","w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);

	int K, N;
	cin >> K >> N;

	cache.resize(N);
	nextPos.resize(N);
	for (int i = 0; i < N; i++) cin >> cache[i];

	auto st = high_resolution_clock::now();
	//pregenerate nextPos
	gp_hash_table<int, int> pos;
	for (int i = N - 1; i >= 0; i--) {
		if (pos.find(cache[i]) == pos.end()) {
			pos[cache[i]] = i;
			nextPos[i] = MAX;
		}
		else {
			nextPos[i] = pos[cache[i]];
			pos[cache[i]] = i;
		}
	}

	__gnu_pbds::priority_queue<node, decltype(cmp), pairing_heap_tag> pq(cmp);
	gp_hash_table<int, __gnu_pbds::priority_queue<node>::point_iterator> pqPos;

	for (int i = 0; i < N; i++) {
		if (pqPos.find(cache[i]) != pqPos.end()) {
			cout << "hit\n";
			pq.modify(pqPos[cache[i]], node(i, cache[i], nextPos[i]));
			continue;
		}

		cout << "miss\n";
		if (pq.size() < K)
			pqPos[cache[i]] = pq.push(node(i, cache[i], nextPos[i]));
		else {
			cout << "evict " << pq.top().x << "\n";
			pqPos.erase(pq.top().x);
			pq.pop();
			pqPos[cache[i]] = pq.push(node(i, cache[i], nextPos[i]));
		}
	}

	auto ed = high_resolution_clock::now();
	auto dt = duration_cast<nanoseconds>(ed - st);
	cerr << dt.count() << '\n';
	//14104375700
	//16984697400
	return 0;
}
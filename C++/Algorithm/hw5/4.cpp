#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

// map<char, __gnu_pbds::priority_queue<int, char>::point_iterator> mp;

__gnu_pbds::priority_queue<pair<int, char>> pq;

string s1 = "ACTGCCTAGCG";
string s2 = "TCAGGTCGA";

int main() {
	ios::sync_with_stdio(0), cin.tie(0);

	auto it = pq.push({ 5,'a' });
	pq.modify(it, { 7,'a' });

	return 0;
}


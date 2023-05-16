#include <bits/stdc++.h>
using namespace std;
int b[10000000], nextb[10000000];

auto cmp = [](pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
};

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++)
        cin >> b[i];
    unordered_map<int, int> next_rec_um;
    for (int i = k - 1; i >= 0; i--) {
        if (next_rec_um.count(b[i]))
            nextb[i] = next_rec_um[b[i]];
        else
            nextb[i] = k;
        next_rec_um[b[i]] = i;
    }

    unordered_set<int> us;
    map<pair<int, int>, int, decltype(cmp)> next_pos_m(cmp);
    unordered_map<int, pair<int, int>> next_pos_key_um;
    for (int i = 0; i < k; i++) {
        if (us.count(b[i])) {
            us.insert(b[i]);
            next_pos_m.erase(next_pos_key_um[i]);
            next_pos_m[make_pair(nextb[i], i)] = b[i];
            // next_pos_key_um.erase(i);
            next_pos_key_um[nextb[i]] = make_pair(nextb[i], i);
            cout << "hit\n";
            continue;
        }
        cout << "miss\n";
        if (us.size() >= n) {
            pair<pair<int, int>, int> tmp = *next_pos_m.rbegin();
            cout << "evict " << tmp.second << "\n";
            us.erase(tmp.second);
            next_pos_m.erase(tmp.first);
            // next_pos_key_um.erase(tmp.first.first);
        }
        next_pos_m[make_pair(nextb[i], i)] = b[i];
        us.insert(b[i]);
        next_pos_key_um[nextb[i]] = make_pair(nextb[i], i);
    }
}
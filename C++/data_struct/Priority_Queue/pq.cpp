#include <bits/stdc++.h>
using namespace std;

pair<int, string> heap[100];

void in(pair<int, string> now);
string out();

int last = 0;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);

    int a;
    cin >> a;
    for (int i = 0; i < a; i++) {
        pair<int, string> temp;
        cin >> temp.second >> temp.first;
        in(temp);
    }
    cout << "First three things to do:\n";
    cout << out() << "\n";
    cout << out() << "\n";
    cout << out() << "\n";

    return 0;
}

void in(pair<int, string> now) {
    int i = ++last;
    heap[i] = now;
    while (i != 1 and heap[i].first > heap[i / 2].first) {
        swap(heap[i], heap[i / 2]);
        i /= 2;
    }
}

string out() {
    swap(heap[1], heap[last]);
    int i = 1;
    while (i < last and (heap[i].first < heap[i * 2].first or
                         heap[i].first < heap[i * 2 + 1].first)) {
        if (heap[i].first < heap[i * 2].first and
            (heap[i * 2 + 1].first < heap[i * 2].first or i * 2 + 1 >= last)) {
            if (i * 2 >= last) break;
            swap(heap[i], heap[i * 2]);
            i *= 2;
            continue;
        }
        if (heap[i].first < heap[i * 2 + 1].first and
            heap[i * 2].first < heap[i * 2 + 1].first) {
            if (i * 2 + 1 >= last) break;
            swap(heap[i], heap[i * 2 + 1]);
            i = i * 2 + 1;
            continue;
        }
        break;
    }
    last--;
    int r = last + 1;
    return heap[r].second;
}

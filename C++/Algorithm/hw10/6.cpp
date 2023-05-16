#include<bits/stdc++.h>

using namespace std;

map<char, char> pa;
struct node {
    int dis;
    char to;
};

auto cmp = [](node& a, node& b) {
    return a.dis > b.dis;
};

map<char, vector<pair<char, int>>> g;
map<char, int> dis;
int main() {

    int V;
    cin >> V;
    for (int i = 0; i < V; i++) {
        char a, b;
        int d;
        cin >> a >> b >> d;
        if (g.find(a) == g.end()) g[a] = vector<pair<char, int>>();
        g[a].push_back({ b,d });
        if (dis.find(a) == dis.end()) dis[a] = INT_MAX;
        if (dis.find(b) == dis.end()) dis[b] = INT_MAX;
    }
    priority_queue<node, vector<node>, decltype(cmp)> pq(cmp);
    pq.push({ 0, 'z' });
    int count = 0;
    while (!pq.empty()) {

        cout << count++ << "-------------\n";
        cout << "pq\n";
        queue<node> temp;
        while (!pq.empty()) {
            cout << pq.top().to << " " << pq.top().dis << "\n";
            temp.push(pq.top());
            pq.pop();
        }
        while (!temp.empty()) {
            pq.push(temp.front());
            temp.pop();
        }
        cout << "\n";

        cout << "dis\n";
        //cout dis 
        for (auto i : dis)
            cout << i.first << " " << i.second << "\n";
        cout << "\n";

        cout << "pa\n";
        //cout pa
        for (auto i : pa)
            cout << i.first << " " << i.second << "\n";
        cout << "\n";

        auto [nowdis, x] = pq.top();
        pq.pop();
        if (nowdis > dis[x]) continue;
        dis[x] = nowdis;
        for (auto i : g[char(x)]) {
            if (nowdis + i.second < dis[i.first]) {
                dis[i.first] = nowdis + i.second;
                pa[i.first] = x;
                pq.push({ dis[i.first], i.first });
                pa[i.first] = x;
            }
        }
    }

    return 0;
}
/*
10
s t 10
s y 5
t y 2
t x 1
y t 3
y z 2
y x 9
x z 4
z s 7
z x 6
*/
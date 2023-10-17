#include<bits/stdc++.h>
using namespace std;
using namespace chrono;

struct obs {
    int a, b, v;
};

bool cmp(obs a, obs b) {
    if (a.a == b.a)
        return a.b < b.b;
    return a.a < b.a;
}

vector<obs> v;
int p[1001][1001];
unordered_map<int, int> have_solved;

int solve(int h, int w) {
    if (v.size()) {
        int position = (h << 10) + w;
        if (have_solved.count(position))
            return have_solved[position];
        obs tmp = v[v.size() - 1];
        v.pop_back();
        int ans = solve(h, w), h2 = h - tmp.a, w2 = w - tmp.b;
        if (h2 >= 0 && w2 >= 0) {
            int h1 = tmp.a + tmp.v - 1, w1 = tmp.b - tmp.v;
            ans += (p[h1][w1] - solve(h1, w1)) * p[h2][w2];
        }

        v.push_back(tmp);

        ans %= 2552;
        if (ans < 0)
            ans += 2552;
        have_solved[position] = ans;
        return ans;
    }
    return 0;
}

int main() {

    freopen("in10000.txt", "r", stdin);
    freopen("testhu.txt", "w", stdout);

    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int h, w, k, a, b, c, d, q, ans;
    cin >> h >> w >> k;

    p[0][0] = 1;
    for (int i = 1; i <= h; i++)
        p[i][0] = p[i - 1][0];
    for (int i = 1; i <= w; i++)
        p[0][i] = p[0][i - 1];
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            p[i][j] += p[i][j - 1];
            p[i][j] += p[i - 1][j];
            while (p[i][j] >= 2552)
                p[i][j] -= 2552;
        }
    }

    auto st = high_resolution_clock::now();
    while (k--) {
        cin >> q;
        v.clear();
        have_solved.clear();
        while (q--) {
            cin >> a >> b >> c >> d;
            if (a < c) {
                obs* newobs = new obs;
                newobs->a = c;
                newobs->b = d;
                newobs->v = 0;
                v.push_back(*newobs);
            }
            else if (b < d) {
                obs* newobs = new obs;
                newobs->a = c;
                newobs->b = d;
                newobs->v = 1;
                v.push_back(*newobs);
            }
        }
        sort(v.begin(), v.end(), cmp);
        ans = p[h][w] - solve(h, w);
        if (ans < 0)
            ans += 2552;
        // cout << ans << "\n";
    }
    auto ed = high_resolution_clock::now();
    auto dt = duration_cast<nanoseconds>(ed - st);
    cout << dt.count() << '\n';
}